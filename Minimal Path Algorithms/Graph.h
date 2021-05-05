#pragma once
#include "DynamicArray.h"
#include "LinkedList.h"
class Graph
{
protected:
	struct Edge;
	struct EdgePair;

	int n;
	LinkedList<Edge*> edge_list; //Every Graph contains an updated list of existing edges.
public:
	struct Edge {
		int from, to, weight; // weight of the edge
		bool exists; // true if exists,false otherwise

		Edge() :from(-1), to(-1), weight(0), exists(false) {}
		Edge(const int& u, const int& v, const int& w = 0) :from(u), to(v), weight(w), exists(true) {}

		bool operator==(const Edge& other);
		friend ostream& operator<<(ostream& output, const Graph::Edge& e);
	};
	struct EdgePair { // Graphs contain a pair of (Edge,Listnode*) to the edge Linkedlist
		Edge edge;
		LinkedListNode<Edge*> node_ptr;
	};


	Graph(const int& m) :n(m) {}

	//virtual void MakeEmptyGraph(const int& n) = 0; // Impleneted by Ctors.
	virtual bool isAdjacent(const int& u, const int& v)const = 0;
	virtual LinkedList<int> GetAdjList(const int& u)const = 0;
	virtual void addEdge(const int& u, const int& v, const int& c) = 0;
	virtual void removeEdge(const int& u, const int& v) = 0;

	virtual void printGraph()const = 0;


	const int& getN()const { return n; }


};
