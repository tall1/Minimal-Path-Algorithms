#pragma once
#include "AdjacencyListNode.h"
class AdjacencyList
{
private:
	AdjacencyListNode* head,*tail;
	int size;
public:
	AdjacencyList():head(nullptr),tail(nullptr),size(0){}
	~AdjacencyList(){
		AdjacencyListNode* keep;
		while (this->head != nullptr) {
			keep = this->head->next;
			delete head;
			this->head = keep;
		}
	}
	const int& getSize()const { return this->size; }


	void push_back(const int& v) {
		AdjacencyListNode* new_node = new AdjacencyListNode(v);
		this->tail->next = new_node;
		this->tail = new_node;
		this->size++;
	}
};

