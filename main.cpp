#include<iostream>
#include"Graphlnk.h"
using namespace std;
void init(Graphlnk &g);     
void mylnk(Graphlnk & G);



void main() {
	Graphlnk g(100);
	init(g);
	mylnk(g);
	cout << "ɾ���밴1������������˳�:";
	char j; cin >> j;
	while (j == '1') {
		cout <<  "������Ҫɾ�����У�";
		string name; cin >> name; int v;
		for (int i = 0; i < g.NumberOfVertices(); i++) {
			if (g.Nodeintable[i].name == name) {
				v = i; break;
			}
		}
		g.removeVertex(v);
		mylnk(g);
		cout << "����ɾ���밴1������������˳�:";
		cin >> j;
	}
}