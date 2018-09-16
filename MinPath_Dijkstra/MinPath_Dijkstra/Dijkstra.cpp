#include "Dijkstra.h"

Dijkstra::Dijkstra(int nodeNum, int roadNum)
{
	this->nodeNum = nodeNum + 1;	//����ԭ��Ҳ��Ϊͼ��һ���ڵ�
	this->roadNum = roadNum;

	/* ������ʾͼ���ڽӾ��� */
	graph = new int *[this->nodeNum];
	for (int i = 0; i < this->nodeNum; i++)
	{
		graph[i] = new int[this->nodeNum];
		for (int j = 0; j < this->nodeNum; j++)
		{
			graph[i][j] = INT_MAX;
		}
	}

	dis = new DIS[this->nodeNum];
}

Dijkstra::~Dijkstra()
{
	delete[] dis;
	for (int i = 0; i < nodeNum; i++)
	{
		delete[] graph[i];
	}
	delete[] graph;
}

void Dijkstra::readGraph()
{
	int start;
	int end;
	int weight;
	
	for (int i = 0; i < roadNum; i++)
	{
		cin >> start >> end >> weight;
			
		graph[start][end] = weight;
	}
}

void Dijkstra::conductDijkstra(int beginNode)
{
	/* ��ʼ��dis���� */
	for (int i = 0; i < nodeNum; i++)
	{
		dis[i].path.push_back(beginNode);
		dis[i].path.push_back(i);
		dis[i].weight = graph[beginNode][i];
	}

	 int minWeightInedx = 0;
	 int minWeight = 0;

	 for (int j = 0; j < nodeNum; j++)
	 {
		 minWeight = INT_MAX;

		 /* �ҵ���ǰ���·�� */
		 for (int i = 0; i < nodeNum; i++)
		 {
			 if (minWeight > dis[i].weight && !dis[i].hasVisit)
			 {
				 minWeight = dis[i].weight;
				 minWeightInedx = i;
			 }
		 }
		 dis[minWeightInedx].hasVisit = true;

		 /* ��������·�� */
		 for (int i = 0; i < nodeNum; i++)
		 {
			 if (!dis[i].hasVisit 
				 && graph[minWeightInedx][i] != INT_MAX
				 && graph[minWeightInedx][i] + dis[minWeightInedx].weight < dis[i].weight)
			 {
				dis[i].weight = graph[minWeightInedx][i] + dis[minWeightInedx].weight;

				/* ����·�� */
				dis[i].path.pop_back();
				dis[i].path.push_back(minWeightInedx);
				dis[i].path.push_back(i);
			 }
		 }
	 }
}

void Dijkstra::printPath()
{
	int pathLen;
	for (int i = 1; i < nodeNum; i++)
	{
		if (dis[i].weight != INT_MAX)
		{
			pathLen = dis[i].path.size();
			for (int j = 0; j < pathLen - 1; j++)
			{
				cout << dis[i].path[j] << " -> ";
			}
			cout << dis[i].path[pathLen - 1] << endl;;
		}
		else
		{
			cout << i << " ��·������" << endl;
		}

	}
}