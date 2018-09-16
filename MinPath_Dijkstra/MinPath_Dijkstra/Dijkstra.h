#include <iostream>
#include <vector>
using namespace std;

struct DIS
{
	vector<int> path;
	int weight;
	bool hasVisit;
	DIS(){
		weight = 0;
		hasVisit = false;
	}

};

class Dijkstra
{
public:
	Dijkstra(int nodeNum, int roadNum);
	~Dijkstra();

	/* ∂¡»°Õº */
	void readGraph();

	void conductDijkstra(int beginNode);

	void printPath();
private:
	int nodeNum;
	int roadNum;
	int **graph;
	DIS *dis;

};