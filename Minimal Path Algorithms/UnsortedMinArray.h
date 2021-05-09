#pragma once
#include "PriorityQueue.h"
class UnsortedMinArray :
    public PriorityQueue
{
protected:
	int min_index;// minimum key index in array
	void fixMinIndex();// fix minimum key index
public:
	UnsortedMinArray(const int& m) :PriorityQueue(m), min_index(0) {}
	const int& getSize()const { return logSize; }

	virtual void push(const int& data, const Distance& ds);
	virtual PriorityQueue::Pair pop();
	virtual const PriorityQueue::Pair& top() { return arr[min_index]; }
	virtual void empty() { logSize = 0; }
	virtual bool isEmpty() { return logSize == 0; }
	virtual void update(const Pair& p);
	virtual void printPriorityQueue()const;
};

