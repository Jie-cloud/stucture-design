#pragma once
#include"Graph.h"
using namespace std;

struct Edge {
	int dest;    //下一个顶点的下标
	int cost;    //边的权值 
	Edge * next = NULL;  //下一条边
	Edge * prior = NULL; //前一条边
	Edge * link = NULL; //邻边 eg:（1,2）（2,1）
};

struct Vertex {
	int degree;   //结点的度
	string name;  //风景名
	Edge * adj = NULL;   //头指针
};

/*struct hashver {                            //点的hash表中所存的数据（即点名->下标）
	int dest;
}ver[MaxVeitices];

struct hashe {                              //边的hash表中所存的数据
	Edge * p;  //该边在邻接表的地址
			   /*int v1;    //Object1对应的下标
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
	//int mydegree(int v);                            //去v点的度数
	int getWeight(int v1, int v2);					//取边（v1，v2）上的权值
	int getFirstNeighbor(int v);				    //取顶点v的第个邻接顶点
	int getNextNeighbor(int v, int w);			    //取邻接顶点w的下一个邻接顶点
	bool insertVertex(string vertex);			  //插入一个顶点vertex
	bool insertEdge(int v1, int v2, int cost);		//插入边(v1,v2),权为cost
	bool removeVertex(int v);					    //删去顶点v和所有与v相关的边
	//bool removeEdge(int v1, int v2);				//删去边(v1,v2)
	//void shortest();                                //求最小生成树
	Vertex * Nodeintable;
};
