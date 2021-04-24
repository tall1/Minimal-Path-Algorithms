#pragma once
class AdjacencyListNode
{
private:
	int vertex_no;
	AdjacencyListNode* next;
public:
	AdjacencyListNode(const int& v_no):vertex_no(v_no),next(nullptr){}
	~AdjacencyListNode(){}
	friend class AdjacencyList;
};

