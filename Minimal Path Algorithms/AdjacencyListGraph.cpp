#include "AdjacencyListGraph.h"

//void AdjacencyListGraph::MakeEmptyGraph(const int& n) {} // This method is implemented by Ctor
bool AdjacencyListGraph::isAdjacent(const int& u, const int& v)const {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return false;
	}
	else {
		return this->arr[u].doesExists(v); // return: v is a neighbore of u?
	}
}
void AdjacencyListGraph::addEdge(const int& u, const int& v, const int& c) {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return;
	}
	else {
		if (!this->arr[u].doesExists(v))// Check if there is an edge already
			this->arr[u].insertEnd(v, c);// Insert if not.
	}
}
void AdjacencyListGraph::removeEdge(const int& u, const int& v) {
	if (u >= this->n || u < 0 || v < 0 || v >= n) {
		return;
	}
	else {
		this->arr[u].deleteNode(v);
	}
}
LinkedList<int> AdjacencyListGraph::GetAdjList(const int& u)const {
	if (u >= this->n || u < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		return this->arr[u];
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
