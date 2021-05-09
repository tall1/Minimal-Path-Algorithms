// Name: Tal Lev
// Id: 312495955
#include <iostream>
#include "IO.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "BellmanFord.h"
#include "Dijkstra.h"

using namespace std;
int main(int argc, char** argv) {
	DynamicArray<MinimalWeightAlgorithms*> algArr(6);
	AdjacencyListGraph g1;
	AdjacencyMatrixGraph g2;
	int u, v;
	//Read from file and create graphs:
	try {
		IO::readFromFile(argv[1], g1, u, v);// g1 is an adjency list
		IO::readFromFile(argv[1], g2, u, v);// g2 is a matrix
	}
	catch (exception& e) {
		cout << e.what() << endl;
		exit(1);
	}

	// Fill in algorithms
	algArr[0] = new Dijkstra(g1, u, Dijkstra::queue_type::HEAP);
	algArr[1] = new Dijkstra(g1, u, Dijkstra::queue_type::UNSORTED_ARRAY);
	algArr[2] = new BellmanFord(g1, u);
	algArr[3] = new Dijkstra(g2, u, Dijkstra::queue_type::HEAP);
	algArr[4] = new Dijkstra(g2, u, Dijkstra::queue_type::UNSORTED_ARRAY);
	algArr[5] = new BellmanFord(g2, u);

	// Run and calculate runtime
	try {
		IO::writeToFile(argv[2], algArr, v);
	}
	catch (exception& e) {
		cout << e.what() << endl;
		exit(1);
	}
	// Delete used algorithms
	for (MinimalWeightAlgorithms*& i : algArr) {
		delete i;
	}
}