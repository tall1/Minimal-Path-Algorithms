#pragma once
#include "MinimalWeightAlgorithms.h"
class BellmanFord :
    public MinimalWeightAlgorithms
{
protected:
	virtual void run(const Graph& G, const int& s);
};

