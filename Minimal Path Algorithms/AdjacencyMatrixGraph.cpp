#include "AdjacencyMatrixGraph.h"


void AdjacencyMatrixGraph::MakeEmptyGraph(const int& m) {
	int i, j;
	// Erase current graph:
	for (i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	edge_list.empty();// Empty edge list
	// Create new graph
	arr = new Edge * [m];
	if (!arr) {
		throw bad_alloc();
	}
	for (i = 0; i < m; i++) {
		arr[i] = new Edge[m];
		if (!arr[i]) {
			throw bad_alloc();
		}
		for (j = 0; j < m; j++) {
			// Set init values
			arr[i][j].exists = false;
			arr[i][j].from = i + 1;
			arr[i][j].to = j + 1;
		}
	}
	this->n = m;// Update n
}


AdjacencyMatrixGraph::AdjacencyMatrixGraph(const int& m) : Graph(m) {
	int i, j;
	this->arr = new Edge * [m];
	if (!arr) {
		throw bad_alloc();
	}
	for (i = 0; i < m; i++) {
		arr[i] = new Edge[m];
		if (!arr[i]) {
			throw bad_alloc();
		}
		for (j = 0; j < m; j++) {
			// Set init values
			arr[i][j].exists = false;
			arr[i][j].from = i + 1;
			arr[i][j].to = j + 1;
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
	if (u > this->n || u < 1 || v < 1 || v > n) {
		throw exception("Invalid input - vertex not in range");
	}
	else {
		return this->arr[u - 1][v - 1].exists;// true <=> (u,v) belongs to E
	}
}
void AdjacencyMatrixGraph::addEdge(const int& u, const int& v, const double& c) {
	if (u > this->n || u < 1 || v < 1 || v > n) {// Unrecognized vertices
		throw exception("Invalid input - vertex not in range");
	}
	else if (u == v) {// Loop
		throw exception("Vertexes are identical(loop): not a simple graph");
	}
	else if (c < 0) { // Negative weight edge
		throw exception("Invalid input - negative weight");
	}
	else {
		if (!this->arr[u - 1][v - 1].exists) {// If edge does not exist, need to insert new one to edge list.
			this->edge_list.insertEnd(&(this->arr[u - 1][v - 1]));
		}
		else {
			throw exception("Edge already exists: not a simple graph");
		}
		// Insert edge
		this->arr[u - 1][v - 1].exists = true;
		this->arr[u - 1][v - 1].weight = c;
	}
}
void AdjacencyMatrixGraph::removeEdge(const int& u, const int& v) {
	if (u > this->n || u < 1 || v < 1 || v > n) {
		throw exception("Invalid input - vertex not in range");
	}
	else {
		edge_list.deleteNode(&(this->arr[u - 1][v - 1]));//Delete edge from edge list.
		this->arr[u - 1][v - 1].exists = false;
	}
}
LinkedList<Graph::Edge> AdjacencyMatrixGraph::GetAdjList(const int& u)const {
	if (u > n || u <= 0) {
		throw exception("Invalid input - vertex not in range");
	}
	else{
		LinkedList<Edge> adjLst;//Adjency list
		for (int i = 0; i < n; i++) {
			if (this->arr[u - 1][i].exists) {
				adjLst.insertEnd(this->arr[u - 1][i]);// Insert vertex to list
			}
		}
		return adjLst;
	}
}

void AdjacencyMatrixGraph::printGraph()const {
	int i, j;
	cout << "  | ";
	for (i = 0; i < this->n; i++) {
		cout << i + 1<< " ";
	}
	cout << "\n---";
	for (i = 0; i < this->n; i++) {
		cout << "--";
	}
	cout << endl;
	for (i = 0; i < this->n; i++) {
		cout << i + 1 << " | ";
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