#include "UnsortedMinArray.h"


void UnsortedMinArray::fixMinIndex() {
	min_index = 0;
	for (int i = 1; i < logSize; i++) {
		if (arr[min_index].key > arr[i].key) {
			min_index = i;
		}
	}
}
PriorityQueue::Pair UnsortedMinArray::pop() {
	if (logSize < 1) {
		throw exception("MinArray is empty");
	}
	Pair min = arr[min_index];
	logSize--;
	arr[min_index] = arr[logSize];
	fixMinIndex();
	return min;
}
void UnsortedMinArray::push(const int& data, const Distance& ds) {
	if (logSize == n) {
		throw exception("Heap is full");
	}
	int i = logSize;
	arr[logSize] = Pair(data, ds);
	if (arr[min_index].key > ds) {
		min_index = logSize;
	}
	logSize++;
}
void UnsortedMinArray::update(const Pair& p) {
	for (int i = 0; i < logSize; i++) {
		if (arr[i].data == p.data) {
			arr[i] = p;
			if (arr[min_index].key > arr[i].key) {
				min_index = i;
			}
			break;
		}
	}
}

void UnsortedMinArray::printPriorityQueue()const {
	for (int i = 0; i < logSize; i++) {
		cout << arr[i] << endl;
	}
}
