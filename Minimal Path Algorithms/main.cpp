// Name: Tal Lev
// Id: 312495955
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "myString.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
using namespace std;
using namespace myStr;
int main(int argc, char** argv) {
	AdjacencyListGraph g1(5);
	AdjacencyMatrixGraph g2(5);

	for (int i = 0; i < 5; i++) {
		g1.addEdge(i, (i + 1) % 5, 1);
		g2.addEdge(i, (i + 1) % 5, 1);
		g1.addEdge(i, (i + 2) % 5, 5);
		g2.addEdge(i, (i + 2) % 5, 5);

	}

	g1.printGraph();
	g2.printGraph();
}