// Name: Tal Lev
// Id: 312495955
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "myString.h"
#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
using namespace std;
using namespace myStr;
//int main(int argc, char** argv) {
//	AdjacencyListGraph g1(5);
//	AdjacencyMatrixGraph g2(5);
//
//	for (int i = 0; i < 5; i++) {
//		try {
//			g1.addEdge(i, (i + 1) % 5, 1);
//			g2.addEdge(i, (i + 1) % 5, 1);
//			g1.addEdge(i, (i + 2) % 5, 5);
//			g2.addEdge(i, (i + 2) % 5, 5);
//		}
//		catch (exception& e) {
//			cout << e.what() << endl;
//		}
//
//	}
//
//	g1.printGraph();
//	g2.printGraph();
//	cout << "g1 list: ";
//	g1.GetAdjList(3).print();
//	cout << endl;
//	cout << "g2 list: ";
//	g2.GetAdjList(3).print();
//	cout << endl;
//
//}

int main(int argc, char** argv) {
	DoublyLinkedList<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.insertEnd(i);
	}
	for (const int& j : l1) {
		cout << j << " ";
	}
	cout << endl;
	l1.deleteNode(2);
	l1.print();
	cout << endl;
	l1.deleteNode(0);
	l1.print();
}