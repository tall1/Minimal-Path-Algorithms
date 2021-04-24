#include "IO.h"
using namespace std;

BSTree* IO::readFromFile(const string& fname) {
	ifstream infile;
	char c;
	BSTree* tree = new BSTree();
	infile.open(fname, ios::in);
	if (!infile) {
		cout << "Error with infile" << endl;
		exit(-1);
	}
	infile.get(c);
	while (!infile.eof()) {
		if (!infile.good()) {
			cout << "Error reading" << endl;
			exit(-1);
		}
		tree->Insert(c);
		infile.get(c);
	}
	infile.close();
	return tree;
}

TreeNode* IO::Huffman(BSTree* tree) {
	if (tree->isEmpty())
		return nullptr;
	MinHeap min_heap(*tree);
	int n = min_heap.getSize();
	TreeNode* node, * right, * left;

	if (n == 1) {// if n==1 create 1 left child for node.
		node = new TreeNode();
		node->setLeft(min_heap.DeleteMin());
		node->setPair(Pair('*', node->getLeft()->getFreq()));
		min_heap.Insert(node);
	}

	for (auto i = 1; i < n; i++) {
		node = new TreeNode();
		left = min_heap.DeleteMin();
		right = min_heap.DeleteMin();

		node->setLeft(left);
		node->setRight(right);

		node->setPair(Pair('*', left->getFreq() + right->getFreq()));
		min_heap.Insert(node);
	}
	return min_heap.DeleteMin();
}

int IO::printHuffman(const TreeNode* node, const string& str) {
	if (!node)
		return -1;
	int weight = 0;
	if (node->isLeaf()) {
		if (node->getCharacter() == '\n')
			cout << "'\\n' - " << str << endl;
		else
			cout << "'" << node->getCharacter() << "' - " << str << endl;
		weight = node->getFreq() * str.length();
	}
	else {
		if (node->getRight())
			weight += printHuffman(node->getRight(), str + "1");
		if (node->getLeft())
			weight += printHuffman(node->getLeft(), str + "0");
	}
	if (str.length() == 0)
		cout << "Encode file weight: " << weight << " bits" << endl;
	return weight;
}
void IO::deleteTree(TreeNode* root) {
	if (!root)
		return;
	if (root->getLeft())
		deleteTree(root->getLeft());
	if (root->getRight())
		deleteTree(root->getRight());
	delete root;
}
