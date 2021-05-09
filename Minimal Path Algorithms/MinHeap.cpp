#include "DynamicArray.h"
#include "MinHeap.h"
using namespace std;

void MinHeap::fixHeap(const int& node) {
	int min, lft = left(node), rht = right(node);

	if (lft < logSize && (arr[node].key > arr[lft].key)) {
		min = lft;
	}
	else {
		min = node;
	}
	if (rht < logSize && arr[min].key > arr[rht].key) {
		min = rht;
	}
	if (min != node) {
		swap(node, min);
		fixHeap(min);
	}
}
PriorityQueue::Pair MinHeap::pop() {
	if (logSize < 1) {
		throw exception("Heap is empty");
	}
	Pair min = arr[0];
	logSize--;
	arr[0] = arr[logSize];
	fixHeap(0);
	return min;
}
void MinHeap::push(const int& data, const Distance& ds) {
	if (logSize == n) {
		throw exception("Heap is full");
	}
	int i = logSize;
	logSize++;
	while ((i > 0) && (arr[parent(i)].key > ds)) {
		arr[i] = arr[parent(i)];
		i = parent(i);
	}
	arr[i] = Pair(data, ds);
}
void MinHeap::swap(const int& a, const  int& b) {
	PriorityQueue::Pair temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void MinHeap::update(const Pair& p) {
	int i;
	for (i = 0; i < logSize; i++) {
		if (arr[i].data == p.data) {
			arr[i] = p;
			while (parent(i) >= 0 && arr[parent(i)].key > arr[i].key) {
				swap(i, parent(i));
				i = parent(i);
			}
			break;
		}
	}
}
void MinHeap::printPriorityQueue()const {
	for (int i = 0; i < logSize; i++) {
		cout << arr[i] << endl;
	}
}
