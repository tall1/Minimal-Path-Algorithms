#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	class LinkedListNode;

	LinkedListNode* head;
	LinkedListNode* tail;
	LinkedListNode* search(T);

public:
	LinkedList();
	~LinkedList();

	bool isEmpty();
	void insertBegin(T);
	void insertEnd(T);
	void deleteNode(T);
	bool doesExists(T);
	void print();
};

// LinkedListNode methods
template <class T>
class LinkedList<T>::LinkedListNode { //nodes to be contained with a LinkedList
private:
	T data; //templatized data stored in node
	LinkedListNode* next; //pointer to the next node in LinkedList

public:
	friend class LinkedList;
	LinkedListNode() :next(nullptr) {}
	LinkedListNode(T dataIn) :data(dataIn), next(nullptr) {}
};


template <typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	if (!isEmpty()) // LinkedList is not empty
	{
		LinkedList<T>::LinkedListNode* currentPtr = head;
		LinkedList<T>::LinkedListNode* tempPtr;

		while (currentPtr != 0) // delete remaining nodes
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() {
	if (head == nullptr && tail == nullptr) //if the start pointer and end pointer are nullptr then the LinkedList is empty
		return true;
	else
		return false;
}

template <typename T>
void LinkedList<T>::insertBegin(T dataIn)
{
	LinkedList<T>::LinkedListNode* newPtr = new LinkedList<T>::LinkedListNode(dataIn);

	if (isEmpty())
	{
		head = newPtr;
		tail = newPtr;
	}
	else
	{
		newPtr->next = head;
		head = newPtr;
	}
}

template <typename T>
void LinkedList<T>::insertEnd(T dataIn)
{
	LinkedList<T>::LinkedListNode* newPtr = new LinkedList<T>::LinkedListNode(dataIn);
	if (isEmpty()) {
		head = newPtr;
		tail = newPtr;
	}
	else {
		tail->next = newPtr;
		tail = newPtr;
	}
}

template <typename T>
typename LinkedList<T>::LinkedListNode* LinkedList<T>::search(T key) //search functions that searches for node that contains data equal to the key
{
	LinkedList<T>::LinkedListNode* nodePtr = nullptr;
	bool found = false;

	nodePtr = head;

	while ((!found) && (nodePtr != nullptr)) //runs through LinkedList until data is found within a node or end of LinkedList is reached
	{
		if (nodePtr->data == key) //if the node's data equals the key then the node has been found
			found = true;
		else
			nodePtr = nodePtr->next;
	}
	return nodePtr;
}

template <typename T>
void LinkedList<T>::deleteNode(T key) {
	LinkedList<T>::LinkedListNode* prev, * cur;
	if (isEmpty()) {
		return;
	}
	else if (this->head->data == key) {
		if (this->tail == this->head) {
			delete head;
			this->head = this->tail = nullptr;
		}
		else {
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

template <typename T>
bool LinkedList<T>::doesExists(T key) {
	if (search(key) != nullptr)
		return true;
	return false;
}

template <typename T>
void LinkedList<T>::print()
{
	LinkedList<T>::LinkedListNode* cur = this->head;

	if (isEmpty()) {
		cout << "The list is empty" << endl;
	}
	else {
		cout << "The contents of the list is: ";
		while (cur != nullptr) //prints until the end of the list is reached
		{
			cout << cur->data << ' ';
			cur = cur->next; //moves to next node in list
		}
		cout << endl;
	}
}


