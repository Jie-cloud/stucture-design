#pragma once
#include"Graph.h"
using namespace std;

struct Edge {
	int dest;    //��һ��������±�
	int cost;    //�ߵ�Ȩֵ 
	Edge * next = NULL;  //��һ����
	Edge * prior = NULL; //ǰһ����
	Edge * link = NULL; //�ڱ� eg:��1,2����2,1��
};

struct Vertex {
	int degree;   //���Ķ�
	string name;  //�羰��
	Edge * adj = NULL;   //ͷָ��
};

/*struct hashver {                            //���hash������������ݣ�������->�±꣩
	int dest;
}ver[MaxVeitices];

struct hashe {                              //�ߵ�hash�������������
	Edge * p;  //�ñ����ڽӱ�ĵ�ַ
			   /*int v1;    //Object1��Ӧ���±�
			   int v2;
			   int cost;
}e[(MaxVeitices*MaxVeitices - 1) / 2];*/

class Graphlnk :public Graph {
public:
	Graphlnk(int sz);
	~Graphlnk() {};
	void getValue(int i) {
		/*string name;
		if (i >= 0 && i < numVertices) {
			int j,length = Nodeintable[i].name.length();
			for (j = 0; j < length; j++) {
				name[j] = Nodeintable[i].name[j];
			}name[j] = '\0';
		}
		
		return n;*/
		int length = 10 - Nodeintable[i].name.length();
		cout << Nodeintable[i].name;
		for (int i = 0; i < length; i++) {
			cout << " ";
		}
	}
	//int mydegree(int v);                            //ȥv��Ķ���
	int getWeight(int v1, int v2);					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int getFirstNeighbor(int v);				    //ȡ����v�ĵڸ��ڽӶ���
	int getNextNeighbor(int v, int w);			    //ȡ�ڽӶ���w����һ���ڽӶ���
	bool insertVertex(string vertex);			  //����һ������vertex
	bool insertEdge(int v1, int v2, int cost);		//�����(v1,v2),ȨΪcost
	bool removeVertex(int v);					    //ɾȥ����v��������v��صı�
	//bool removeEdge(int v1, int v2);				//ɾȥ��(v1,v2)
	//void shortest();                                //����С������
	Vertex * Nodeintable;
};
