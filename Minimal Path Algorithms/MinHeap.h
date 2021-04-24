#pragma once
#include "BSTree.h"
class MinHeap
{
private:
	TreeNode** heapArr;
	int heapSize, capacity;
	bool allocated;
	static int Parent(const int& node) { return (node - 1) / 2; }
	static int Left(const int& node) { return (2 * node + 1); }
	static int Right(const int& node) { return (2 * node + 2); }
	void FixHeap(const int& node);
	void Swap(const int& a, const int& b);
public:
	MinHeap(const int& maxCapacity);
	MinHeap(const BSTree& tree);
	~MinHeap();

	const int& getSize()const { return heapSize; }

	TreeNode* Min()const { return heapArr[0]; }
	TreeNode* DeleteMin();
	void Insert(TreeNode* node);
	bool isEmpty()const { return heapSize == 0; }
	void makeEmpty();
};

