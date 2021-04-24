#include "DynamicArray.h"
#include "MinHeap.h"
using namespace std;
MinHeap::MinHeap(const int& maxCapacity) {
	heapArr = new TreeNode * [maxCapacity];
	capacity = maxCapacity;
	heapSize = 0;
	allocated = true;
}
MinHeap::MinHeap(const BSTree& tree) {
	int i;
	DynamicArray<Pair>& vec = tree.toVector();
	capacity = heapSize = vec.getLogSize();
	heapArr = new TreeNode * [heapSize];
	for (i = 0; i < heapSize; i++)
		heapArr[i] = new TreeNode(vec[i]);

	allocated = true;

	for (i = heapSize / 2 - 1; i >= 0; i--)
		FixHeap(i);
}

MinHeap::~MinHeap() {
	if (allocated)
		makeEmpty();
	delete[] heapArr;
}
void MinHeap::FixHeap(const int& node) {
	int min, left = Left(node), right = Right(node);
	if (left < heapSize && (heapArr[left]->pair.freq < heapArr[node]->pair.freq))
		min = left;
	else
		min = node;
	if (right < heapSize && heapArr[right]->pair.freq < heapArr[min]->pair.freq)
		min = right;

	if (min != node) {
		Swap(node, min);
		FixHeap(min);
	}
}

TreeNode* MinHeap::DeleteMin() {
	if (heapSize < 1)
		throw "Heap is empty.";
	TreeNode* min = heapArr[0];
	heapSize--;
	heapArr[0] = heapArr[heapSize];
	FixHeap(0);
	return min;
}
void MinHeap::Insert(TreeNode* node) {
	if (heapSize == capacity)
		throw "Heap is full.";
	int i = heapSize;
	heapSize++;
	while ((i > 0) && (heapArr[Parent(i)]->pair.freq > node->getFreq())) {
		heapArr[i] = heapArr[Parent(i)];
		i = Parent(i);
	}
	heapArr[i] = node;
}

void MinHeap::makeEmpty() {
	for (int i = 0; i < heapSize; i++) {
		if (allocated)
			delete heapArr[i];
		heapArr[i] = nullptr;
	}
	heapSize = 0;
}

void MinHeap::Swap(const int& a, const  int& b) {
	TreeNode* temp = heapArr[a];
	heapArr[a] = heapArr[b];
	heapArr[b] = temp;
}
