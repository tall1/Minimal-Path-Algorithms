
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "LinkedListNode.h"
using namespace std;


template <typename T>
class LinkedList {
private:
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;
	LinkedListNode<T>* search(T key)const {
		bool found = false;
		LinkedListNode<T>* nodePtr = head;

		while ((!found) && (nodePtr != nullptr)) //runs through LinkedList until data is found within a node or end of LinkedList is reached
		{
			if (nodePtr->data1 == key) //if the node's data equals the key then the node has been found
				found = true;
			else
				nodePtr = nodePtr->next;
		}
		return nodePtr;
	}

public:
	LinkedList() :head(nullptr), tail(nullptr) {}
	LinkedList(const LinkedList<T>& other) :head(nullptr), tail(nullptr) {
		if (!other.isEmpty()) {
			LinkedListNode<T>* nodePtr = other.head;
			while (nodePtr) {
				this->insertEnd(nodePtr->data1, nodePtr->data2);
				nodePtr = nodePtr->next;
			}
		}
	}
	~LinkedList() {
		if (!isEmpty()) // LinkedList is not empty
		{
			LinkedListNode<T>* currentPtr = head;
			LinkedListNode<T>* tempPtr;

			while (currentPtr != nullptr) // delete remaining nodes
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->next;
				delete tempPtr;
			}
		}
	}

	bool isEmpty()const {
		if (head == nullptr && tail == nullptr) //if the start pointer and end pointer are nullptr then the LinkedList is empty
			return true;
		else
			return false;
	}
	void insertBegin(T data1In, T data2In) {
		LinkedListNode<T>* newPtr = new LinkedListNode<T>(data1In, data2In);
		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;

		}
		else {
			newPtr->next = head;
			head = newPtr;
		}
	}
	void insertEnd(T data1In, T data2In) {
		LinkedListNode<T>* newPtr = new LinkedListNode<T>(data1In, data2In);

		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;
		}
		else {
			tail->next = newPtr;
			tail = newPtr;
		}
	}
	void deleteNode(T key) {
		LinkedListNode<T>* prev, * cur;
		if (isEmpty()) {
			return;
		}
		else if (this->head->data1 == key) {// head is the node to delete
			if (this->tail == this->head) {// head==tail
				delete head;
				this->head = this->tail = nullptr;
			}
			else {// head!=tail
				cur = this->head->next;
				delete head;
				this->head = cur;
			}
		}
		else { // head is not the node to delete
			cur = this->head;
			prev = cur;

			while (cur) {
				cur = cur->next;
				if (cur->data1 == key) {
					prev->next = cur->next;
					if (cur == tail) {
						this->tail = prev;
					}
					delete cur;
					break;
				}
				prev = cur;
			}
		}
	}
	bool doesExists(T key)const {
		if (search(key) != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void print() const
	{
		LinkedListNode<T>* cur = this->head;

		if (isEmpty()) {
			cout << "The list is empty" << endl;
		}
		else {
			//cout << "The contents of the list is: ";
			while (cur != nullptr) //prints until the end of the list is reached
			{
				cout << cur->data1 << '\\' << cur->data2 << ' ';
				cur = cur->next; //moves to next node in list
			}
			cout << endl;
		}
	}
};

#endif