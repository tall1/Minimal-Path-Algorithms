#pragma once
#include "Graph.h"
#include "AdjacencyList.h"
#include "DynamicArray.h"
#include "LinkedList.h"

class AdjacencyListGraph :
    public Graph
{
private:
    DoublyLinkedList<Graph::Edge>* arr;
public:
    AdjacencyListGraph() :Graph(), arr(nullptr) {}
	AdjacencyListGraph(const int& m) :Graph(m), arr(new DoublyLinkedList<Graph::Edge>[m]) {}
    ~AdjacencyListGraph() {}

    virtual void MakeEmptyGraph(const int& n);// Makes an empty graph
    virtual bool isAdjacent(const int& u, const int& v)const;// true <=> (u,v) belongs to E
    virtual LinkedList<Edge> GetAdjList(const int& u)const;// Returns adjency list
    virtual void addEdge(const int& u, const int& v, const double& c);// Add edge
    virtual void removeEdge(const int& u, const int& v);// Remove edge

    virtual void printGraph()const;
};

