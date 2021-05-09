#ifndef DLIST_NODE_H
#define DLIST_NODE_H
#include <iostream>
template <class T>
class DoublyLinkedList;

// DoublyLinkedListNode methods
template <class T>
class DoublyLinkedListNode { //nodes to be contained with a DoublyLinkedList
private:
	T data; //templatized data stored in node
	DoublyLinkedListNode* next; //pointer to the next node in DoublyLinkedList
	DoublyLinkedListNode* prev; //pointer to the previous node in DoublyLinkedList

public:
	friend class DoublyLinkedList<T>;
	friend class LinkedList<T>;

	DoublyLinkedListNode() :next(nullptr), prev(nullptr) {}
	DoublyLinkedListNode(const T& dataIn) :data(dataIn), next(nullptr), prev(nullptr) {}
	T& getData(){ return data; }
};
#endif