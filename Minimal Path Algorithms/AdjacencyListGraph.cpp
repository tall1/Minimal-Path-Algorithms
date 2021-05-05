#include "AdjacencyListGraph.h"

//void AdjacencyListGraph::MakeEmptyGraph(const int& n) {} // This method is implemented by Ctor
bool AdjacencyListGraph::isAdjacent(const int& u, const int& v)const {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return false;
	}
	else {
		return this->arr[u].doesExists(Edge(u,v)); // return: v is a neighbore of u?
	}
}
void AdjacencyListGraph::addEdge(const int& u, const int& v, const int& c) {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return;
	}
	else {
		Edge e(u, v, c);
		if (!this->arr[u].doesExists(e)) {// Check if there is an edge already
			this->arr[u].insertEnd(e);// Insert if not.
			edge_list.insertEnd(&this->arr[u].back());// Insert the new edge to the edge list
		}
	}
}
void AdjacencyListGraph::removeEdge(const int& u, const int& v) {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return;
	}
	else {
		Edge e(u, v);
		LinkedListNode<Edge>* node = this->arr[u].search(e);
		this->arr[u].deleteNode(e);
	}
}
LinkedList<int> AdjacencyListGraph::GetAdjList(const int& u)const {
	if (u >= this->n || u < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		LinkedList<int> adjLst;
		for (const Graph::Edge& i : this->arr[u]) {
			adjLst.insertBegin(i.to);
		}
		return adjLst;
	}
}
void AdjacencyListGraph::printGraph()const {
	int i;
	cout << endl;
	for (i = 0; i < n; i++) {
		cout << " " << i << ": ";
		arr[i].print();
		cout << endl;
	}
}
