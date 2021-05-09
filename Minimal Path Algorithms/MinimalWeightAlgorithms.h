#pragma once
#include "Graph.h"
#include "Distance.h"
#include "MinHeap.h"
#include "UnsortedMinArray.h"
#include "PriorityQueue.h"

class MinimalWeightAlgorithms
{
public:
	MinimalWeightAlgorithms(const Graph& G, const int& s);
	virtual ~MinimalWeightAlgorithms();
	virtual void run() = 0;// Method used to run the algorithm
	const Distance& getDistanceByVertex(const int& u)const { return d[u - 1]; }
	const int& getParentByVertex(const int& u)const { return p[u - 1]; }

protected:
	Distance* d;// distances array
	int* p;// Parent array
	const Graph& G;// Graph
	const int& s;// Source
};

