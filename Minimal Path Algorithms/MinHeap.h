#pragma once
#include "PriorityQueue.h"
#include "DynamicArray.h"
class MinHeap :
	public PriorityQueue
{
protected:
	int parent(const int& node) { return (node - 1) / 2; }
	int left(const int& node) { return (2 * node + 1); }
	int right(const int& node) { return (2 * node + 2); }
	void fixHeap(const int& node);
	void swap(const int& a, const int& b);
public:
	MinHeap(const int& m) :PriorityQueue(m) {}

	virtual void push(const int& data, const Distance& ds);
	virtual PriorityQueue::Pair pop();
	virtual const PriorityQueue::Pair& top() { return arr[0]; }
	virtual void empty() { logSize = 0; }
	virtual bool isEmpty() { return logSize == 0; }
	virtual void update(const Pair& p);
	virtual void printPriorityQueue()const;
};

