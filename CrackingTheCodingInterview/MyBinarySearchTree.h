#pragma once

#include "CommonIncludes.h"

class MyBSTNode // Binary Search Tree Node
{
public:
	// universal fields
	int val;
	MyBSTNode* left = nullptr;
	MyBSTNode* right = nullptr;

	// fields used only in some exercises
	int subtreeHeight = -1;
	int minSubtreeValue = INT_MAX;
	int maxSubtreeValue = INT_MIN;
	MyBSTNode* parent = nullptr;
	vector<int> pathsWithSum;

	MyBSTNode(int v) : val(v) { };
};

class MyBinarySearchTree
{
public:
	MyBSTNode* root = nullptr;
	
	void Add(int val);
	static void Print_InOrder(MyBSTNode* curr);
	void Print_PreOrder(MyBSTNode* curr);
	void Print_PostOrder(MyBSTNode* curr);

private:
	static void Visit(MyBSTNode* curr);
};

