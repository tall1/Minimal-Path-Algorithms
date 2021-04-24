#pragma once
#include <iostream>
struct Pair {
	char character;//key
	int freq;//data
	Pair() :character(0), freq(0) {}
	Pair(const char& character, const int& freq) :character(character), freq(freq) {}
	friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
};

class TreeNode
{
private:
	Pair pair;
	TreeNode* left, * right, * parent;
public:
	TreeNode() :left(nullptr), right(nullptr), parent(nullptr) {}
	TreeNode(const Pair& pair, TreeNode* parent = nullptr) :pair(pair), left(nullptr), right(nullptr), parent(parent) {}
	TreeNode(const Pair& pair, TreeNode* left, TreeNode* right, TreeNode* parent) :pair(pair), left(left), right(right), parent(parent) {}

	const char& getCharacter()const { return pair.character; }
	const int& getFreq()const { return pair.freq; }
	TreeNode* getLeft()const { return left; }
	TreeNode* getRight()const { return right; }
	const Pair& getPair()const { return pair; }

	void setLeft(TreeNode* node) {
		left = node;
		node->parent = this;
	}
	void setRight(TreeNode* node) {
		right = node;
		node->parent = this;
	}
	void setParent(TreeNode* node) { parent = node; }
	void setPair(const Pair& pair) { this->pair = pair; }

	bool isLeaf() const { return !left && !right; }

	friend class BSTree;
	friend class MinHeap;

};

