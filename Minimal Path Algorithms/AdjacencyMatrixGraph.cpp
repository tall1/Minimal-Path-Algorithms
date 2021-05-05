#include "AdjacencyMatrixGraph.h"


AdjacencyMatrixGraph::AdjacencyMatrixGraph(const int& m) : Graph(m) {
	int i, j;
	this->arr = new Edge * [m];
	for (i = 0; i < m; i++) {
		arr[i] = new Edge[m];

		for (j = 0; j < m; j++) {
			arr[i][j].exists = false;
			arr[i][j].from = i;
			arr[i][j].to = j;
		}
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
		if (!this->arr[u][v].exists) {// If edge does not exist, need to insert new one to edge list.
			this->edge_list.insertEnd(&this->arr[u][v]);
		}// else: only update edge members

		this->arr[u][v].exists = true;
		this->arr[u][v].weight = c;
	}
}
void AdjacencyMatrixGraph::removeEdge(const int& u, const int& v) {
	if (u >= n || u < 0 || v >= n || v < 0) {
		throw exception("Vertex does not exist");
	}
	else {
		edge_list.deleteNode(&this->arr[u][v]);//Delete edge from edge list.
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
				adjLst.insertEnd(i);
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