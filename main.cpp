#include<iostream>
#include"Graphlnk.h"
#include"Minheap.h"
using namespace std;
void init(Graphlnk &g);
void mylnk(Graphlnk & G);
void mintree(Graphlnk &g, MinHeap<int> &h);
void mintree2(Graphlnk &g, MinHeap<int> &h);

void main() {
	Graphlnk g(100); MinHeap<int> h;
	init(g);
	mylnk(g);
	cout << "进入请按1，其它任意键退出:";
	char j; cin >> j;
	while (j == '1') {
		/*cout <<  "请输入要删除的市：";
		string name; cin >> name; int v;
		for (int i = 0; i < g.NumberOfVertices(); i++) {
			if (g.Nodeintable[i].name == name) {
				v = i; break;
			}
		}
		g.removeVertex1(v);*/
		mylnk(g);
		cout << "继续删除请按1，稀疏图最小生成树请按2，稠密图最小生成树请按3，其它任意键退出:";
		cin >> j;
		//下为计算最短路径
		if (j == '2') {
			mintree(g,h);
		}
		if (j == '3'){
			mintree2(g, h);
		}
	}
}