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
	cout << "�����밴1������������˳�:";
	char j; cin >> j;
	while (j == '1') {
		/*cout <<  "������Ҫɾ�����У�";
		string name; cin >> name; int v;
		for (int i = 0; i < g.NumberOfVertices(); i++) {
			if (g.Nodeintable[i].name == name) {
				v = i; break;
			}
		}
		g.removeVertex1(v);*/
		mylnk(g);
		cout << "����ɾ���밴1��ϡ��ͼ��С�������밴2������ͼ��С�������밴3������������˳�:";
		cin >> j;
		//��Ϊ�������·��
		if (j == '2') {
			mintree(g,h);
		}
		if (j == '3'){
			mintree2(g, h);
		}
	}
}