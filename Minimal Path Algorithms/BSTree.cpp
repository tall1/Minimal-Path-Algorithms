#include "BSTree.h"
using namespace std;
TreeNode* BSTree::Find(const char& character) {
	TreeNode* temp = root;
	while (temp) {
		if (temp->pair.character == character)
			return temp;
		else if (temp->pair.character > character)
			temp = temp->left;
		else if (temp->pair.character < character)
			temp = temp->right;
	}
	return nullptr;
}
void BSTree::Delete(const char& character) {
	TreeNode* cur = Find(character);
	TreeNode* left, * right, * max;
	if (cur) {
		left = cur->left;
		right = cur->right;
		if (left && right) {
			max = cur->left;
			while (max->right)
				max = max->right;
			cur->pair = max->pair;// Swap values
			cur = max;
			left = max->left;
			right = max->right;
		}
		if (!left || !right) {//one or less children
			if (cur == root) {// if cur is root and there is one or less children
				root = left != nullptr ? left : right;
			}
			else if (left) {// if cur is not root (he has a parent) and he has a left node
				if (cur->parent->left == cur)// connect curs parent to curs left child
					cur->parent->left = left;
				else
					cur->parent->right = left;
			}
			else {// if cur is not root(he has a parent) and maybe he has a right child.
				if (cur->parent->left == cur)// connect curs parent to curs right child
					cur->parent->left = right;
				else
					cur->parent->right = right;
			}
		}
		delete cur;
		size--;
	}
}
void BSTree::Insert(const char& character) {
	TreeNode* temp = root, * parent = nullptr, * temp2;
	if (temp2 = Find(character))
		temp2->pair.freq++;
	else {
		while (temp) {
			parent = temp;
			if (character > temp->pair.character)
				temp = temp->right;
			else
				temp = temp->left;
		}
		if (!parent)
			root = new TreeNode(Pair(character, 1), nullptr);
		else if (character < parent->getCharacter())
			parent->left = new TreeNode(Pair(character, 1), parent);
		else
			parent->right = new TreeNode(Pair(character, 1), parent);
		size++;
	}
}
void BSTree::makeEmptyHelper(TreeNode* root) {
	if (!root)
		return;
	if (root->left)
		makeEmptyHelper(root->left);
	if (root->right)
		makeEmptyHelper(root->right);
	delete root;
}


DynamicArray<Pair>& BSTree::toVector()const {
	DynamicArray<Pair>* vec = new DynamicArray<Pair>;

	toVectorHelper(*vec, root);

	return *vec;
}
void BSTree::toVectorHelper(DynamicArray<Pair>& vec, TreeNode* root) const {
	if (!root)
		return;
	if (root->left)
		toVectorHelper(vec, root->left);
	vec.push_back(root->pair);
	if (root->right)
		toVectorHelper(vec, root->right);
}

void BSTree::inOrder(TreeNode* root)const {
	if (!root)
		return;
	if (root->left)
		inOrder(root->left);
	cout << root->pair << endl;
	if (root->right)
		inOrder(root->right);
}