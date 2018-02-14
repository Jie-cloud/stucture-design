#include<iostream>
#include"Graphlnk.h"
using namespace std;
void init(Graphlnk &g);     
void mylnk(Graphlnk & G);



void main() {
	Graphlnk g(100);
	init(g);
	mylnk(g);
	cout << "删除请按1，其它任意键退出:";
	char j; cin >> j;
	while (j == '1') {
		cout <<  "请输入要删除的市：";
		string name; cin >> name; int v;
		for (int i = 0; i < g.NumberOfVertices(); i++) {
			if (g.Nodeintable[i].name == name) {
				v = i; break;
			}
		}
		g.removeVertex(v);
		mylnk(g);
		cout << "继续删除请按1，其它任意键退出:";
		cin >> j;
	}
}