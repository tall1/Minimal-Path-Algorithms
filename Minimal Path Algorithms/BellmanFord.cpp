#include "BellmanFord.h"
void BellmanFord::run() {
	int j, size = G.getN(), u, v, w;
	const DoublyLinkedList<Graph::Edge*>& edge_list = G.getEdgeList();
	for (j = 1; j < size; j++) {// MAIN LOOP
		for (Graph::Edge* i : edge_list) {
			u = i->from;
			v = i->to;
			w = i->weight;
			//Relax:
			if (d[v - 1] > d[u - 1] + w) {
				d[v - 1] = d[u - 1] + w;
				p[v - 1] = u;
			}
		}
	}

	for (Graph::Edge* i : edge_list) {
		u = i->from;
		v = i->to;
		w = i->weight;
		if (d[v - 1] > d[u - 1] + w) {
			throw exception("Negative-Cycle");
		}
	}
}

