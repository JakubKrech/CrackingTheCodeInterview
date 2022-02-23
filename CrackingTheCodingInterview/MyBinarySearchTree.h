#pragma once

#include "CommonIncludes.h"

class MyBSTNode // Binary Search Tree Node
{
public:
	int val;
	MyBSTNode* left = nullptr;
	MyBSTNode* right = nullptr;

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

