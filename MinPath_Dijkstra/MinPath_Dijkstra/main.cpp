#include "Dijkstra.h"

typedef struct tagPath
{
	vector<int> node;
	int dis;
}PATH;


int main()
{
	int nodeNum;
	int roadNum;
	int beginNode;

	cin  >> nodeNum  >> roadNum >> beginNode;

	Dijkstra dijkstra(nodeNum, roadNum);
	dijkstra.readGraph();
	dijkstra.conductDijkstra(beginNode);
	dijkstra.printPath();
	
	system("pause");
}