#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <iostream>
template <class T>
class LinkedList;

// LinkedListNode methods
template <class T>
class LinkedListNode { //nodes to be contained with a LinkedList
private:
	T data; //templatized data stored in node
	LinkedListNode* next; //pointer to the next node in LinkedList

public:
	friend class LinkedList<T>;
	LinkedListNode() :next(nullptr) {}
	LinkedListNode(const T& dataIn) :data(dataIn), next(nullptr) {}

};
#endif