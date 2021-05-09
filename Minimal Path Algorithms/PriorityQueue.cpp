#include "PriorityQueue.h"
PriorityQueue::PriorityQueue(const int& m) {
	arr = new Pair[m];
	logSize = 0;
	n = m;
}

PriorityQueue::~PriorityQueue() {
	delete[] arr;
}

std::ostream& operator<<(std::ostream& out, const PriorityQueue::Pair& pair) {
	out << "(" << pair.data << ",";
	if (pair.key.infinity) {
		out << "infinit";
	}
	else {
		out << pair.key.value;
	}
	out << ")";
	return out;
}