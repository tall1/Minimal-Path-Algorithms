#include "MinimalWeightAlgorithms.h"
MinimalWeightAlgorithms::MinimalWeightAlgorithms(const Graph& G, const int& s) :G(G), s(s) {
	// INIT:
	int size = G.getN();
	this->d = new Distance[size]; // d[1..n] = infinity
	this->d[s - 1] = 0; // d[s] = 0
	this->p = new int[size];// p[x] = -1 <=> p[x] = null
	for (int i = 0; i < size; i++) {
		this->p[i] = -1;
	}
}

MinimalWeightAlgorithms::~MinimalWeightAlgorithms() {
	delete[] d;
	delete[] p;
}