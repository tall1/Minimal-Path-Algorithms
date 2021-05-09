#include "Dijkstra.h"

void Dijkstra::run() {
	int i, u, w;
	LinkedList<Graph::Edge> adjList;
	PriorityQueue* queue = buildQueue();
	// Search
	while (!queue->isEmpty()) {
		u = queue->pop().data;
		adjList = G.GetAdjList(u);
		for (const Graph::Edge& v : adjList) {
			w = v.weight;
			//Relax:
			if (d[v.to - 1] > d[u - 1] + w) {
				d[v.to - 1] = d[u - 1] + w;
				p[v.to - 1] = u;
				queue->update(PriorityQueue::Pair(v.to, d[v.to - 1]));
			}
		}
	}
	delete queue;
}
PriorityQueue* Dijkstra::buildQueue()const {
	PriorityQueue* queue;

	// Initialize queue
	// queue = min heap
	if (qt == queue_type::HEAP) {
		queue = new MinHeap(G.getN());
	}
	else {// queue = unsorted min array
		queue = new UnsortedMinArray(G.getN());
	}

	// Build priority queue
	for (int i = 0; i < G.getN(); i++) {
		queue->push(i + 1, d[i]);
	}
	return queue;
}