#pragma once
#include "MinimalWeightAlgorithms.h"
class Dijkstra :
    public MinimalWeightAlgorithms
{
public:
	enum class queue_type{ HEAP, UNSORTED_ARRAY };
	Dijkstra(const Graph& G, const int& s, const queue_type& qt)
		:MinimalWeightAlgorithms(G, s), qt(qt) {}
	virtual void run();
private:
	queue_type qt;// flag: heap or unsorted array
	PriorityQueue* buildQueue()const;// supportive method
};

