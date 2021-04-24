#pragma once
#include "TreeNode.h"
#include "DynamicArray.h"
#include <iostream>
class BSTree
{
private:
	TreeNode* root;
	int size;
	void toVectorHelper(DynamicArray<Pair>& vec, TreeNode* root)const;
	void inOrder(TreeNode* root)const;
	void makeEmptyHelper(TreeNode* root);
public:
	BSTree() :root(nullptr), size(0) {}
	~BSTree() { makeEmpty(); }
	TreeNode* Find(const char& character);
	void Delete(const char& character);
	void Insert(const char& character);
	bool isEmpty()const { return !root; }
	void makeEmpty() {
		makeEmptyHelper(root);
		root = nullptr;
	}
	DynamicArray<Pair>& toVector()const;
};

