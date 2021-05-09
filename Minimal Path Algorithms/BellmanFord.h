#pragma once
#include "Graph.h"
#include "MinimalWeightAlgorithms.h"
class BellmanFord :
    public MinimalWeightAlgorithms
{
public:
	BellmanFord(const Graph& G, const int& s) 
		:MinimalWeightAlgorithms(G, s) {}
	virtual void run();
};

