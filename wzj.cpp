#include"Graphlnk.h"

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
		    s = p->link;                 //sΪҪɾ��p�����ߵ��ڱߣ������ߣ�
			//ɾ��p��s������ǰ��ָ��
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
		numEdges--;      //������һ
	}
	//ɾ���������һ�����ƹ��� eg����1��numVertices��->��1��v��
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
		s->dest = v;   //��dest�±�ΪnumVertices�Ķ��޸�Ϊv
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
	string name[100];
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
	int i, j;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                          �羰·�߹滮ϵͳ" << endl;
	cout << "                                                                                            �����ˣ�Mr.Li & Mr.Wei             " << endl;
	cout << "                                                                                            �������ڣ�2018.1-2                 " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "                                               �羰��    : " << G.NumberOfVertices() << endl<<endl;
	cout << "                                               �羰·����: " << G.NunberOfEdges() << endl<<endl;
	cout << "                                               �羰���ƣ� ";
	for (i = 0; i < G.NumberOfVertices(); i++) {
		G.getValue(i); 
		cout << endl<<"                                                          ";
	}
	cout << "\n";
	/*cout << "    �羰����:       ";
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
	}*/
	cout << endl;
}