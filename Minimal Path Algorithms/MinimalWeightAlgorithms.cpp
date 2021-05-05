#include "MinimalWeightAlgorithms.h"
MinimalWeightAlgorithms::MinimalWeightAlgorithms(const Graph& G, const int& s) {
	int size = G.getN();
	this->d = new Distance[size];
	this->d[s] = 0;
	this->p = new int[size] {-1};
	/*this->run(G, s);*/
}
MinimalWeightAlgorithms::~MinimalWeightAlgorithms() {
	delete[] d;
	delete[] p;
}