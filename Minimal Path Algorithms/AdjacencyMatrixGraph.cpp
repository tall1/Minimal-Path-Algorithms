#include "AdjacencyMatrixGraph.h"


AdjacencyMatrixGraph::AdjacencyMatrixGraph(const int& m) {
	this->n = m;
	this->arr = new Edge * [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new Edge[m];
	}
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph() {
	for (int i = 0; i < this->n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

bool AdjacencyMatrixGraph::isAdjacent(const int& u, const int& v)const {
	if (u >= n || u < 0 || v >= n || v < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		return this->arr[u][v].exists;
	}
}
void AdjacencyMatrixGraph::addEdge(const int& u, const int& v, const int& c) {
	if (u >= n || u < 0 || v >= n || v < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		this->arr[u][v].exists = true;
		this->arr[u][v].weight = c;
	}
}
void AdjacencyMatrixGraph::removeEdge(const int& u, const int& v) {
	if (u >= n || u < 0 || v >= n || v < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		this->arr[u][v].exists = false;
	}
}
LinkedList<int> AdjacencyMatrixGraph::GetAdjList(const int& u)const {
	if (u >= n || u < 0) {
		throw exception("Vertex does not exist");
	}
	else{
		LinkedList<int> adjLst;
		for (int i = 0; i < n; i++) {
			if (this->arr[u][i].exists) {
				adjLst.insertEnd(i, this->arr[u][i].weight);
			}
		}
		return adjLst;
	}
}

void AdjacencyMatrixGraph::printGraph()const {
	int i, j;
	cout << "  | ";
	for (i = 0; i < this->n; i++) {
		cout << i << " ";
	}
	cout << "\n---";
	for (i = 0; i < this->n; i++) {
		cout << "--";
	}
	cout << endl;
	for (i = 0; i < this->n; i++) {
		cout << i << " | ";
		for (j = 0; j < this->n; j++) {
			if (this->arr[i][j].exists) {
				cout << this->arr[i][j].weight << " ";
			}
			else {
				cout << "_ ";
			}
		}
		cout << endl;
	}
}