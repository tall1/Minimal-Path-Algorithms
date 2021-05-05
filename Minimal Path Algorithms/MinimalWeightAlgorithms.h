#pragma once
#include "Graph.h"
class MinimalWeightAlgorithms
{
public:
	struct Distance {
		int value = 0;
		bool infinity = true;
		void operator=(const int& num) { value = num; infinity = false; }
	};
	MinimalWeightAlgorithms(const Graph& G, const int& s);
	~MinimalWeightAlgorithms();

protected:
	Distance* d;
	int* p;

	virtual void run(const Graph& G, const int& s) = 0;
};

