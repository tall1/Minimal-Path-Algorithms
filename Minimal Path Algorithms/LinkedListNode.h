#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <iostream>
template <class T>
class LinkedList;

// LinkedListNode methods
template <class T>
class LinkedListNode { //nodes to be contained with a LinkedList
private:
	T data1, data2; //templatized data stored in node
	LinkedListNode* next; //pointer to the next node in LinkedList

public:
	friend class LinkedList<T>;
	LinkedListNode() :next(nullptr) {}
	LinkedListNode(T data1In, T data2In = 0) :data1(data1In), data2(data2In), next(nullptr) {}

};
#endif