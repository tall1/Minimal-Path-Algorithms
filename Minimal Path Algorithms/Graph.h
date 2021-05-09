#pragma once
#include "DynamicArray.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
class Graph
{
protected:
	struct Edge;
	int n;// n = amount of vertices
	DoublyLinkedList<Edge*> edge_list; //Every Graph contains an updated list of existing edges.
public:
	struct Edge {// (u,v)
		int from, to;
		double weight; // weight of the edge
		bool exists; // true <=> (u,v) belongs to E

		Edge() :from(-1), to(-1), weight(0), exists(false) {}
		Edge(const int& u, const int& v, const double& w = 0) :from(u), to(v), weight(w), exists(true) {}

		bool operator==(const Edge& other);
		friend ostream& operator<<(ostream& output, const Graph::Edge& e);
	};

	Graph() :n(0) {}
	Graph(const int& m) :n(m) {}

	virtual void MakeEmptyGraph(const int& n) = 0;// Makes an empty graph
	virtual bool isAdjacent(const int& u, const int& v)const = 0;// true <=> (u,v) belongs to E
	virtual LinkedList<Edge> GetAdjList(const int& u)const = 0;// Returns adjency list
	virtual void addEdge(const int& u, const int& v, const double& c) = 0;// Add edge
	virtual void removeEdge(const int& u, const int& v) = 0;// Remove edge
	virtual void printGraph()const = 0;
	const DoublyLinkedList<Edge*>& getEdgeList()const { return edge_list; }
	void printEdgeList()const;
	const int& getN()const { return n; }



};
