#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "DoublyLinkedListNode.h"
using namespace std;


template <typename T>
class DoublyLinkedList {
private:
	DoublyLinkedListNode<T>* head;
	DoublyLinkedListNode<T>* tail;

public:
	friend class LinkedList<T>;
	DoublyLinkedList() :head(nullptr), tail(nullptr) {}
	DoublyLinkedList(const DoublyLinkedList<T>& other) :head(nullptr), tail(nullptr) {
		if (!other.isEmpty()) {
			DoublyLinkedListNode<T>* nodePtr = other.head;
			while (nodePtr) {
				this->insertEnd(nodePtr->data);
				nodePtr = nodePtr->next;
			}
		}
	}
	~DoublyLinkedList() {
		empty();
	}

	bool isEmpty()const {
		if (head == nullptr && tail == nullptr) //if the start pointer and end pointer are nullptr then the DoublyLinkedList is empty
			return true;
		else
			return false;
	}
	void insertBegin(const T& dataIn) {
		DoublyLinkedListNode<T>* newPtr = new DoublyLinkedListNode<T>(dataIn);
		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;
		}
		else {
			newPtr->next = head;
			head->prev = newPtr;
			head = newPtr;
		}
	}
	void insertEnd(const T& dataIn) {
		DoublyLinkedListNode<T>* newPtr = new DoublyLinkedListNode<T>(dataIn);

		if (isEmpty()) {
			head = newPtr;
			tail = newPtr;
		}
		else {
			newPtr->prev = tail;
			tail->next = newPtr;
			tail = newPtr;
		}
	}
	void deleteNode(const T& key) {
		DoublyLinkedListNode<T>* cur;
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
				cur->prev = nullptr;
				delete head;
				this->head = cur;
			}
		}
		else { // head is not the node to delete
			cur = this->head;
			while (cur) {
				cur = cur->next;
				if (cur->data == key) {
					cur->prev->next = cur->next;
					if (cur == tail) {
						this->tail = cur->prev;
					}
					else {
						cur->next->prev = cur->prev;
					}
					delete cur;
					break;
				}
			}
		}
	}
	void empty() {
		if (!isEmpty()) // DoublyLinkedList is not empty
		{
			DoublyLinkedListNode<T>* currentPtr = head;
			DoublyLinkedListNode<T>* tempPtr;

			while (currentPtr != nullptr) // delete remaining nodes
			{
				tempPtr = currentPtr;
				currentPtr = currentPtr->next;
				delete tempPtr;
			}
			head = tail = nullptr;
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
	DoublyLinkedListNode<T>* search(const T& key)const {
		bool found = false;
		DoublyLinkedListNode<T>* nodePtr = head;

		while ((!found) && (nodePtr != nullptr)) //runs through DoublyLinkedList until data is found within a node or end of DoublyLinkedList is reached
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
		DoublyLinkedListNode<T>* cur = this->head;

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

	T& front() const { return head->data; }
	T& back() const { return tail->data; }

	//ITERATOR
	//========
	//const_iterator
	class const_iterator;

	// Root of DoublyLinkedList wrapped in const_iterator type
	const_iterator begin() const { return const_iterator(head); }

	// End of DoublyLinkedList wrapped in const_iterator type
	const_iterator end() const { return const_iterator(nullptr); }

	// const_iterator class can be used to
	// sequentially access nodes of linked list
	class const_iterator
	{
	private:
		const DoublyLinkedListNode<T>* cur_node;
	public:
		using const_iterator_category = std::bidirectional_iterator_tag;
		// other options exist, e.g., std::forward_iterator_tag
		using different_type = std::ptrdiff_t;
		using value_type = const T;
		using pointer = const T*;
		using reference = const T&;


		const_iterator() noexcept :
			cur_node(head) { }

		const_iterator(const DoublyLinkedListNode<T>* pNode) noexcept :
			cur_node(pNode) { }

		const_iterator& operator=(DoublyLinkedListNode<T>* pNode)
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