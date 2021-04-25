#pragma once
#include "AdjacencyList.h"
#include "LinkedList.h"
class Graph
{
public:
	//virtual void MakeEmptyGraph(const int& n) = 0; // Impleneted by Ctors.
	virtual bool isAdjacent(const int& u, const int& v)const = 0;
	virtual LinkedList<int> GetAdjList(const int& u)const = 0;
	virtual void addEdge(const int& u, const int& v, const int& c) = 0;
	virtual void removeEdge(const int& u, const int& v) = 0;

	virtual void printGraph()const = 0;
};

