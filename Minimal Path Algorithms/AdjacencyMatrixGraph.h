#pragma once
#include "Graph.h"
#include "LinkedList.h"
class AdjacencyMatrixGraph :
    public Graph
{
protected:
    Edge** arr;
public:
    AdjacencyMatrixGraph(const int& m);
    ~AdjacencyMatrixGraph();

	//virtual void MakeEmptyGraph(const int& n); // Already done by Ctor
    virtual bool isAdjacent(const int& u, const int& v)const;
    virtual LinkedList<int> GetAdjList(const int& u)const;
    virtual void addEdge(const int& u, const int& v, const int& c);
    virtual void removeEdge(const int& u, const int& v);

    virtual void printGraph()const;
};

