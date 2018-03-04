#include<algorithm>
#include"Graphlnk.h"
#include"Minheap.h"

int Graphlnk::getFirstNeighbor(int v) {
	if (v != -1)
	{
		Edge * p = Nodeintable[v].adj;
		if (p != NULL) return p->dest;
	}
	return -1;
}

int Graphlnk::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge * p = Nodeintable[v].adj;
		while (p != NULL && p->dest != w)
		{
			p = p->next;
		}
		if (p != NULL && p->next != NULL)
			return p->next->dest;
	}
	return -1;
}

int Graphlnk::getWeight(int v1, int v2)
{
	if (v1 != -1 && v2 != -1)
	{
		Edge *p = Nodeintable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->next;
		}
		if (p != NULL) {
			return p->cost;
		}
		else return maxWeight;
	}
}

bool Graphlnk::removeVertex(int v)
{
	if (numVertices == 0 || v<0 || v >= numVertices)return false;
	Edge *p, *s;
	while (Nodeintable[v].adj != NULL)
	{
		
		p = Nodeintable[v].adj;
		if (p->next != NULL) {
			p = p->next;
		    s = p->link;                 //s为要删除p这条边的邻边（半条边）
			//删除p和s并连接前后指针
			p->prior->next = p->next;
			if (p->next != NULL) {
				p->next->prior = p->prior;
			}
			if (s->prior != NULL)
				s->prior->next = s->next;
			else Nodeintable[p->dest].adj = s->next;
			if (s->next != NULL) {
				s->next->prior = s->prior;
			}
		}
		else {
			s = p->link;
			if (s->prior != NULL)
			s->prior->next = s->next;
			else Nodeintable[p->dest].adj = s->next;
			if (s->next != NULL) {
				s->next->prior = s->prior;
			}
			Nodeintable[v].adj = NULL;
		}
		delete p;
		delete s;
		numEdges--;      //边数减一
	}
	//删除完点后将最后一个点移过来 eg：（1，numVertices）->（1，v）
	if (v == numVertices) {
		numVertices--;
		return true;
	}
	Nodeintable[v].name = Nodeintable[numVertices-1].name;
	Nodeintable[v].adj = Nodeintable[numVertices-1].adj;
	p = Nodeintable[numVertices-1].adj;
    while (p != NULL)
	{
		s = p->link;
		s->dest = v;   //将dest下标为numVertices的都修改为v
		p = p->next;
	}
	Nodeintable[numVertices-1].adj = NULL;
	numVertices--;
	return true;
}

bool Graphlnk::insertVertex(string vertex)
{
	if (numVertices == maxVertices) return false;
	Nodeintable[numVertices].name = vertex;
	numVertices++;
	return true;
}

bool Graphlnk::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 0 && v1< numVertices && v2 >= 0 && v2<numVertices)
	{
		Edge *q, *p = Nodeintable[v1].adj;
		p = new Edge;
		q = new Edge;
		p->dest = v2;
		p->cost = cost;
		p->next = Nodeintable[v1].adj;
		if (p->next != NULL) {
            p->next->prior = p;
		}
		Nodeintable[v1].adj = p;
		q->dest = v1;
		q->cost = cost;
		q->next = Nodeintable[v2].adj;
		if (q->next != NULL) {
			q->next->prior = q;
		}
		Nodeintable[v2].adj = q;
		q->link = p;
		p->link = q;
		numEdges++;
		return true;
	}
	return false;
}

void init(Graphlnk &g)
{
	int num = -1;
	string name[t2];
	ifstream in("city.txt");
	while (!in.eof()) {
		in >> name[++num];
	}
	for (int i = 0; i <= num; i++) {
		g.insertVertex(name[i]);
	}
	in.close();
	ifstream in2("lines.txt");
	while (!in2.eof()) {
		int v1, v2, cost1, cost2;
		string name1, name2;
		in2 >> name1 >> name2 >> cost1 >> cost2;
		for (int i = 0; i <= num; i++) {
			if (name1 == name[i])v1 = i;
			if (name2 == name[i])v2 = i;
		}
		g.insertEdge(v1, v2, cost1);
	}
}

Graphlnk::Graphlnk(int sz = MaxVeitices) {
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	Nodeintable = NULL;

	try
	{
		Nodeintable = new Vertex[maxVertices];
	}
	catch (bad_alloc & memExp)
	{
		cerr << memExp.what() << endl;
	}
	for (int i = 0; i<maxVertices; i++)
	{
		Nodeintable[i].adj = NULL;
		//	NodeTable[i].adj->cost = maxWeight;
	}
};

void mylnk(Graphlnk & G)
{
	int i;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                          风景路线规划系统" << endl;
	cout << "                                                                                            制作人：Mr.Li & Mr.Wei             " << endl;
	cout << "                                                                                            制作日期：2018.1-2                 " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                               风景数    : " << G.NumberOfVertices() << endl<<endl;
	cout << "                                               风景路径数: " << G.NunberOfEdges() << endl<<endl;
	cout << "                                               风景名称： ";
	for (i = 0; i < G.NumberOfVertices(); i++) {
		G.getValue(i); 
		cout << endl<<"                                                          ";
	}
	cout << "\n";
	/*cout << "    风景名称:       ";
	for (i = 0; i < G.NumberOfVertices(); i++) {
        G.getValue(i);
	}cout << endl;
	for (i = 0; i < G.NumberOfVertices(); i++)
	{
		cout << "    ";
        G.getValue(i);
		for (j = 0; j < G.NumberOfVertices(); j++)
		{
			if (G.getWeight(i, j) == maxWeight)
				cout << right << setw(10) << "Max";
			else
				cout << setw(10) << G.getWeight(i, j);
		}
		cout << "\n";
	}
	cout << endl;*/
}


void mintree(Graphlnk&g,MinHeap<int>&h) {
	int *matrix = new int[2*g.NumberOfVertices()-2];
	for (int i=0; i < 2 * g.NumberOfVertices()-2; i++) {
		matrix[i] = 0;
	}
	for (int i = 0; i < g.NumberOfVertices(); i++) {
		Edge * p = g.Nodeintable[i].adj;
		while (p != NULL) {
			int cost;
			/*c.dest1 = i;
			c.dest2 = p->dest;
			c.cost = p->cost;*/
			if (p->dest > i)
				cost = t1 * p->cost + t2 * p->dest + i;
			else cost = t1 * p->cost + t2 * i + p->dest;
			p = p->next;
			h.Insert(cost);
		}
	}
	int *a = new int[g.NumberOfVertices()];
	for (int i = 0; i < g.NumberOfVertices(); i++) {
		a[i] = t1;
	}
	int count = 0;
	while (count != g.NumberOfVertices() - 1) {
		int x1, x2, pa, ra, pb, rb, pnum, rnum;
		h.RemoveMin(x1);
		pa = x1 - x1 / t1 * t1 - (x1 - x1 / t1 * t1) / t2 * t2;
		pb = (x1 - x1 / t1 * t1) / t2;
		pnum = x1 / t1;
		h.RemoveMin(x2);
		ra = (x2 - x2 / t1 * t1) / t2;
		rb = x2 - x2 / t1 * t1 - (x2 - x2 / t1 * t1) / t2 * t2;
		rnum = x2 / t1;
		if (a[pa] == t1 && a[pb] == t1) {
			a[pa] = pb;
			a[pb] = -2;
		}
		else {
			if (a[pa] < t1 && a[pb] == t1) {
				a[pb] = pa;
				int i = pa;
				while (a[i] >= 0) {
					i = a[i];
				}a[i]--;
			}
			else if (a[pb] < t1 && a[pa] == t1) {
				a[pa] = pb;
				int i = pb;
				while (a[i] >= 0) {
					i = a[i];
				}a[i]--;
			}
			else if (a[pb] < 0 && a[pa] < 0) {
				a[pb] += a[pa];
				a[pa] = pb;
			}
			else if (a[pb] < t1 && a[pa] < t1) {
				int j = pa, k = pb;
				while (a[j] >= 0) {
					j = a[j];
				}
				while (a[k] >= 0) {
					k = a[k];
				}
				if (a[j] == a[k])continue;
				else {
					a[j] += a[k];
					int cur1 = pb;
					int cur2 = a[pb];
					a[pb] = pa;
					while (cur2 >= 0) {
						int cur3 = cur2;
						cur2 = a[cur2];
						a[cur3] = cur1;
						cur1 = cur3;
					}
				}
			}
		}
		matrix[count] = pa*t1*10 + pb*t2*10 + pnum;
		matrix[count+g.NumberOfVertices()-1] = ra*t1*10 + rb*t2*10 + rnum;
		count++;
	}
	sort(matrix, matrix + 2 * g.NumberOfVertices() - 2);
	/*for (int j = 0; j < 2 * g.NumberOfVertices() - 2; j++) {
		cout << matrix[j] << endl;
	}*/
	//for (int i = 0; i < g.NumberOfVertices(); ) 	cout << a[i++] << endl;
	cout << "    风景名称:       ";
	for (int i = 0; i < g.NumberOfVertices(); i++) {
		g.getValue(i);
	}cout << endl;
	count = 0;
	for (int i = 0; i < g.NumberOfVertices(); i++)
	{
		cout << "    ";
		g.getValue(i);
		for (int j = 0; j < g.NumberOfVertices(); j++)
		{
			if (i != matrix[count] / (10 * t1) || j != (matrix[count] - matrix[count] / (10 * t1) * 10 * t1) / (10 * t2))
				cout << right << setw(10) << "Max";
			else {
				cout << setw(10) << matrix[count] - matrix[count] / (10 * t1) * 10 * t1 - (matrix[count] - matrix[count] / (10 * t1) * 10 * t1) / (10 * t2) * 10 * t2;
				count++;
			}
		}
		cout << "\n";
	}
	cin >> a[0]; //保留输出矩阵
}


void mintree2(Graphlnk&g, MinHeap<int>&h) {
	int *matrix = new int[2 * g.NumberOfVertices() - 2];
	cout << "您想从何点发散：";
	int i; cin >> i;        //用hash表替代选择
	int *num = new int[g.NumberOfVertices()];
	int count = 0;
	int *a = new int[g.NumberOfVertices()];
	for (int j = 0; j < g.NumberOfVertices(); j++) {
		a[j] = 0;
	}
	Edge * p = g.Nodeintable[i].adj;
	while (p != NULL) {
		int cost;
		cost = t1 * p->cost + t2 * i + p->dest;
		p = p->next;
		h.Insert(cost);
	}
	a[i] = 1;
	while (count !=g.NumberOfVertices()-1) {
		int x; h.RemoveMin(x);
		int pa = (x - x / t1 * t1) / t2;
		int pb = x - x / t1 * t1 - (x - x / t1 * t1) / t2 * t2;
		int pnum = x / t1;
		if (a[pa] == 0 && a[pb] == 1) {
			a[pa] = 1;
			p = g.Nodeintable[pa].adj;
			num[count] = pa * t2 + pb;
			matrix[count] = pa*t1 * 10 + pb*t2 * 10 + pnum;
			matrix[count + g.NumberOfVertices() - 1] = pb*t1 * 10 + pa*t2 * 10 + pnum;
			count++;
			i = pa;
			while (p != NULL) {
				int cost;
				cost = t1 * p->cost + t2 * i + p->dest;
				p = p->next;
				h.Insert(cost);
			}
		}
		else if (a[pa] == 1 && a[pb] == 0) {
			a[pb] = 1;
			p = g.Nodeintable[pb].adj;
			num[count] = pa * t2 + pb;
			matrix[count] = pa*t1 * 10 + pb*t2 * 10 + pnum;
			matrix[count + g.NumberOfVertices() - 1] = pb*t1 * 10 + pa*t2 * 10 + pnum;
			count++;
			i = pb;
			while (p != NULL) {
				int cost;
				cost = t1 * p->cost + t2 * i + p->dest;
				p = p->next;
				h.Insert(cost);
			}
		}
		else continue;
	}
    /*	for (int j = 0; j < g.NumberOfVertices()-1; j++) {
		cout << num[j] << endl;
	}*/
	sort(matrix, matrix + 2 * g.NumberOfVertices() - 2);
	cout << "    风景名称:       ";
	for (int i = 0; i < g.NumberOfVertices(); i++) {
		g.getValue(i);
	}cout << endl;
	count = 0;
	for (int i = 0; i < g.NumberOfVertices(); i++)
	{
		cout << "    ";
		g.getValue(i);
		for (int j = 0; j < g.NumberOfVertices(); j++)
		{
			if (i != matrix[count] / (10 * t1) || j != (matrix[count] - matrix[count] / (10 * t1) * 10 * t1) / (10 * t2))
				cout << right << setw(10) << "Max";
			else {
				cout << setw(10) << matrix[count] - matrix[count] / (10 * t1) * 10 * t1 - (matrix[count] - matrix[count] / (10 * t1) * 10 * t1) / (10 * t2) * 10 * t2;
				count++;
			}
		}
		cout << "\n";
	}
	cin >> num[0];
}