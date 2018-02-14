#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
const int maxWeight = 1000;
const int MaxVeitices = 100;			//������󶥵��� =n

class Graph
{
	//friend istream& operator >> (istream& in, Graphlnk & G);
public:
	Graph(int sz = MaxVeitices) {};
	~Graph() {}
	bool GraphEmpty()const
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		//���ص�ǰ������
	int NunberOfEdges() { return numEdges; }			//���ص�ǰ����
	virtual int getWeight(int v1, int v2) = 0;					//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	virtual int getFirstNeighbor(int v) = 0;				//ȡ����v�ĵڸ��ڽӶ���
	virtual int getNextNeighbor(int v, int w) = 0;			//ȡ�ڽӶ���w����һ���ڽӶ���
	//virtual bool insertVertex(string vertex);			//����һ������vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;		//�����(v1,v2),ȨΪcost
	virtual bool removeVertex(int v) = 0;					//ɾȥ����v��������v��صı�
	//virtual bool removeEdge(int v1, int v2) = 0;				//ɾȥ��(v1,v2)
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
};
