#pragma once
#include "Graph.h"
#include "AdjacencyList.h"
#include "DynamicArray.h"
#include "LinkedList.h"

class AdjacencyListGraph :
    public Graph
{
private:
    DynamicArray<LinkedList<Graph::Edge>> arr;
public:
	AdjacencyListGraph(const int& m) :Graph(m), arr(m) {}
    ~AdjacencyListGraph() {}

	//virtual void MakeEmptyGraph(const int& n);


    virtual bool isAdjacent(const int& u, const int& v)const;
    virtual LinkedList<int> GetAdjList(const int& u)const;
    virtual void addEdge(const int& u, const int& v, const int& c);
    virtual void removeEdge(const int& u, const int& v);

    virtual void printGraph()const;
};

