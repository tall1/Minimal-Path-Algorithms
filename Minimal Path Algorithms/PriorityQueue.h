#pragma once
#include "Graph.h"
#include "Distance.h"
class PriorityQueue
{
public:
	// Pair(distance, data):
	//		- distance = distance from source
	//		- data = vertex no.
	struct Pair {
		int data;
		Distance key;
		Pair() :data(-1) {}
		Pair(const Pair& other) :data(other.data), key(other.key) {}
		Pair(const int& data, const Distance& ds) :data(data), key(ds) {}
		bool operator==(const Pair& other) const{ return data == other.data && key == other.key; }
		friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
	};
	
	virtual void push(const int& data, const Distance& ds) = 0;
	virtual Pair pop() = 0;
	virtual const Pair& top() = 0;
	virtual void empty() = 0;
	virtual bool isEmpty() = 0;
	virtual void update(const Pair& p) = 0;
	virtual void printPriorityQueue()const = 0;

	virtual ~PriorityQueue();
protected:
	Pair* arr;
	int n, logSize;
	PriorityQueue(const int& m);
};

