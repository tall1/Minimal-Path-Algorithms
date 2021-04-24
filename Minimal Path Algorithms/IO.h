#pragma once
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include "MinHeap.h"
class IO
{
public:
	static BSTree* readFromFile(const std::string& fname);
	static TreeNode* Huffman(BSTree* tree);
	static int printHuffman(const TreeNode* node, const std::string& str = "");
	static void deleteTree(TreeNode* root);
};

