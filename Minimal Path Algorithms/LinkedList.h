
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "LinkedListNode.h"
#include "DoublyLinkedList.h"
using namespace std;


template <typename T>
class LinkedList {
private:
	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;

public:
	LinkedList() :head(nullptr), tail(nullptr) {}
	LinkedList(const DoublyLinkedList<T>& other) :head(nullptr), tail(nullptr) {
		if (!other.isEmpty()) {
			DoublyLinkedListNode<T>* nodePtr = other.head;
			while (nodePtr) {
				this->insertEnd(nodePtr->data);
				nodePtr = nodePtr->next;
			}
		}
	}
	LinkedList(const LinkedList<T>& other) :head(nullptr), tail(nullptr) {
		if (!other.isEmpty()) {
			LinkedListNode<T>* nodePtr = other.head;
			while (nodePtr) {
				this->insertEnd(nodePtr->data);
				nodePtr = nodePtr->next;
			}
		}
	}
	~LinkedList() { empty(); }
	

	bool isEmpty()const {
		if (head == nullptr && tail == nullptr) //if the start pointer and end pointer are nullptr then the LinkedList is empty
			return true;
		else
			return false;
	}
	void empty() {
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
		head = tail = nullptr;
	}
	void insertBegin(const T& dataIn) {
		LinkedListNode<T>* newPtr = new LinkedListNode<T>(dataIn);
		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;

		}
		else {
			newPtr->next = head;
			head = newPtr;
		}
	}
	void insertEnd(const T& dataIn) {
		LinkedListNode<T>* newPtr = new LinkedListNode<T>(dataIn);

		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;
		}
		else {
			tail->next = newPtr;
			tail = newPtr;
		}
	}
	void deleteNode(const T& key) {
		LinkedListNode<T>* prev, * cur;
		if (isEmpty()) {
			return;
		}
		else if (this->head->data == key) {// head is the node to delete
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
				if (cur->data == key) {
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
	bool doesExists(const T& key)const {
		if (search(key) != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	LinkedListNode<T>* search(const T& key)const {
		bool found = false;
		LinkedListNode<T>* nodePtr = head;

		while ((!found) && (nodePtr != nullptr)) //runs through LinkedList until data is found within a node or end of LinkedList is reached
		{
			if (nodePtr->data == key) //if the node's data equals the key then the node has been found
				found = true;
			else
				nodePtr = nodePtr->next;
		}
		return nodePtr;
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
				cout << cur->data << ' ';
				cur = cur->next; //moves to next node in list
			}
			cout << endl;
		}
	}
	void operator=(const LinkedList<T>& other) {
		empty();
		if (!other.isEmpty()) {
			LinkedListNode<T>* nodePtr = other.head;
			while (nodePtr) {
				this->insertEnd(nodePtr->data);
				nodePtr = nodePtr->next;
			}
		}
	}

	T& front() const { return head->data; }
	T& back() const { return tail->data; }

	//ITERATOR
	//========
	//const_iterator
	class const_iterator;

	// Root of LinkedList wrapped in const_iterator type
	const_iterator begin() const { return const_iterator(head); }

	// End of LinkedList wrapped in const_iterator type
	const_iterator end() const { return const_iterator(nullptr); }

	// const_iterator class can be used to
	// sequentially access nodes of linked list
	class const_iterator
	{
	private:
		const LinkedListNode<T>* cur_node;
	public:
		using const_iterator_category = std::bidirectional_iterator_tag;
		// other options exist, e.g., std::forward_iterator_tag
		using different_type = std::ptrdiff_t;
		using value_type = const T;
		using pointer = const T*;
		using reference = const T&;


		const_iterator() noexcept :
			cur_node(head) { }

		const_iterator(const LinkedListNode<T>* pNode) noexcept :
			cur_node(pNode) { }

		const_iterator& operator=(LinkedListNode<T>* pNode)
		{
			this->cur_node = pNode;
			return *this;
		}

		// Prefix ++ overload
		const_iterator& operator++()
		{
			if (cur_node)
				cur_node = cur_node->next;
			return *this;
		}

		// Postfix ++ overload
		const_iterator operator++(int)
		{
			const_iterator const_iterator = *this;
			++* this;
			return const_iterator;
		}

		bool operator!=(const const_iterator& const_iterator)
		{
			return cur_node != const_iterator.cur_node;
		}

		const T& operator*()
		{
			return cur_node->data;
		}

	
	};
};

#endif