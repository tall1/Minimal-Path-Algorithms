#include "Graph.h"
bool Graph::Edge::operator==(const Graph::Edge& other) {
	return this->exists == other.exists &&
		this->from == other.from &&
		this->to == other.to;
}

ostream& operator<<(ostream& output, const Graph::Edge& e) {
	if (e.exists) {
		output << e.to << "(" << e.weight << ")";
		//output << "{ " << e.from << " -> " << e.to << " (" << e.weight << ") }";
	}
	return output;
}

void Graph::printEdgeList()const {
	for (Graph::Edge* i : edge_list) {
		cout << i->from << " " << i->to << "(" << i->weight << ")" << endl;
	}
}
