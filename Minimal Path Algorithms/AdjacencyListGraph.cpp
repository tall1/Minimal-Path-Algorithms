#include "AdjacencyListGraph.h"

void AdjacencyListGraph::MakeEmptyGraph(const int& m) {
	delete[] arr;// Delete current array if exists
	arr = new DoublyLinkedList<Graph::Edge>[m];
	if (!arr) {
		throw bad_alloc();
	}
	this->n = m;
	edge_list.empty();// Empty edge list
}
bool AdjacencyListGraph::isAdjacent(const int& u, const int& v)const {
	if (u > this->n || u < 1 || v < 1 || v > n) {
		throw exception("Invalid input - vertex not in range");
	}
	else {
		return this->arr[u - 1].doesExists(Edge(u, v)); // true <=> (u,v) belongs to E
	}
}
void AdjacencyListGraph::addEdge(const int& u, const int& v, const double& c) {
	if (u > this->n || u < 1 || v < 1 || v > n) {
		throw exception("Invalid input - vertex not in range");
	}
	else if (u == v) {
		throw exception("Vertexes are identical(loop): not a simple graph");
	}
	else if (c < 0) {
		throw exception("Invalid input - negative weight");
	}
	else {
		Edge e(u, v, c);
		if (!this->arr[u - 1].doesExists(e)) {// Check if there is an edge already
			this->arr[u - 1].insertEnd(e);// Insert if not.
			edge_list.insertEnd(&this->arr[u - 1].back());// Insert the new edge to the edge list
		}
		else {
			throw exception("Edge already exists: not a simple graph");
		}
	}
}
void AdjacencyListGraph::removeEdge(const int& u, const int& v) {
	if (u > this->n || u < 1 || v < 1 || v > n) {
		throw exception("Invalid input - vertex not in range");
	}
	else {
		Edge e(u, v);
		DoublyLinkedListNode<Edge>* node = arr[u - 1].search(e);// Search for the edge (u,v)
		if (node) {
			edge_list.deleteNode(&(node->getData()));// Remove edge from edge list
			this->arr[u - 1].deleteNode(e);// Delete edge from graph
		}
	}
}
LinkedList<Graph::Edge> AdjacencyListGraph::GetAdjList(const int& u)const {
	if (u > this->n || u < 1) {
		throw exception("Invalid input - vertex not in range");
	}
	else {
		return arr[u - 1];
	}
}
void AdjacencyListGraph::printGraph()const {
	int i;
	cout << endl;
	for (i = 0; i < n; i++) {
		cout << " " << i + 1 << ": ";
		arr[i].print();
		cout << endl;
	}
}
