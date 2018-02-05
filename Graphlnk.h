#pragma once
#include"Graph.h"
using namespace std;

struct Edge {
	int dest;    //��һ������
	int cost;    //�ߵ�Ȩֵ 
	Edge * link;  //��һ����
	Edge * prior; //ǰһ����
};

struct Vertex {
	int degree;   //���Ķ�
	char * num;
	Edge * adj;   //ͷָ��
};

struct RowColWeight
{
	int row = -1;							//���±�
	int col = -1;							//���±�
	int weight = 0;							//Ȩֵ
};

struct node {
	char * num;
};

struct hashver {                            //���hash������������ݣ�������->�±꣩
	int dest;
}ver[MaxVeitices];

struct hashe {                              //�ߵ�hash�������������
	Edge * p;  //�ñ����ڽӱ�ĵ�ַ
			   /*int v1;    //Object1��Ӧ���±�
			   int v2;
			   int cost;*/
}e[(MaxVeitices*MaxVeitices - 1) / 2];

class Graphlnk :public Graph {
public:
	Graphlnk(int sz);
	~Graphlnk() {};
	char * getValue(int i) {
		if (i >= 0 && i < numVertices)
			return Nodeintable[i].num;
	}
	int mydegree(int v);                            //ȥv��Ķ���
	int getWeight(int v1, int v2);					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int getFirstNeighbor(int v);				    //ȡ����v�ĵڸ��ڽӶ���
	int getNextNeighbor(int v, int w);			    //ȡ�ڽӶ���w����һ���ڽӶ���
	bool insertVertex(char * vertex);			//����һ������vertex
	bool insertEdge(int v1, int v2, int cost);		//�����(v1,v2),ȨΪcost
	bool removeVertex(int v);					    //ɾȥ����v��������v��صı�
	bool removeEdge(int v1, int v2);				//ɾȥ��(v1,v2)
	void shortest();                                //����С������
	Vertex * Nodeintable;
};
