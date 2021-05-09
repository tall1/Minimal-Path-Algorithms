#pragma once
#include "Graph.h"
#include "LinkedList.h"
class AdjacencyMatrixGraph :
    public Graph
{
protected:
    Edge** arr;
public:
	AdjacencyMatrixGraph() :arr(nullptr) {}
    AdjacencyMatrixGraph(const int& m);
    ~AdjacencyMatrixGraph();

	virtual void MakeEmptyGraph(const int& m);
    virtual bool isAdjacent(const int& u, const int& v)const;
    virtual LinkedList<Edge> GetAdjList(const int& u)const;
    virtual void addEdge(const int& u, const int& v, const double& c);
    virtual void removeEdge(const int& u, const int& v);

    virtual void printGraph()const;
};

