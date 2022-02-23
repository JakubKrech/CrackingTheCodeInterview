#pragma once

#include "CommonIncludes.h"

class MyGraphNode
{
public:
	int val;
	bool visited = false;
	vector<MyGraphNode*> children;

	MyGraphNode(int v) : val(v) {};
};

class MyGraph
{
public:
	MyGraphNode* root;
};

