#pragma once
#include "Graph.h"
#include "AdjacencyList.h"
#include "DynamicArray.h"
#include "LinkedList.h"

class AdjacencyListGraph :
    public Graph
{
private:
    DynamicArray<LinkedList<int>> arr;
    int n;
public:
    AdjacencyListGraph(const int& m) :arr(m), n(m) {}
    ~AdjacencyListGraph() {}

    virtual void MakeEmptyGraph(const int& n);
    virtual bool isAdjacent(const int& u, const int& v);
    virtual const AdjacencyList& GetAdjList(const int& u);
    virtual void addEdge(const int& u, const int& v, const int& c);
    virtual void removeEdge(const int& u, const int& v);
};

