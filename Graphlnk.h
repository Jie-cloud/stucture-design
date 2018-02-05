#pragma once
#include"Graph.h"
using namespace std;

struct Edge {
	int dest;    //下一个顶点
	int cost;    //边的权值 
	Edge * link;  //下一条边
	Edge * prior; //前一条边
};

struct Vertex {
	int degree;   //结点的度
	char * num;
	Edge * adj;   //头指针
};

struct RowColWeight
{
	int row = -1;							//行下标
	int col = -1;							//列下标
	int weight = 0;							//权值
};

struct node {
	char * num;
};

struct hashver {                            //点的hash表中所存的数据（即点名->下标）
	int dest;
}ver[MaxVeitices];

struct hashe {                              //边的hash表中所存的数据
	Edge * p;  //该边在邻接表的地址
			   /*int v1;    //Object1对应的下标
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
	int mydegree(int v);                            //去v点的度数
	int getWeight(int v1, int v2);					//取边（v1，v2）上的权值
	int getFirstNeighbor(int v);				    //取顶点v的第个邻接顶点
	int getNextNeighbor(int v, int w);			    //取邻接顶点w的下一个邻接顶点
	bool insertVertex(char * vertex);			//插入一个顶点vertex
	bool insertEdge(int v1, int v2, int cost);		//插入边(v1,v2),权为cost
	bool removeVertex(int v);					    //删去顶点v和所有与v相关的边
	bool removeEdge(int v1, int v2);				//删去边(v1,v2)
	void shortest();                                //求最小生成树
	Vertex * Nodeintable;
};
