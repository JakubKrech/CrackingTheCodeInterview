#pragma once

#include "CommonIncludes.h"

class MyQueueNode
{
public:
	int val;
	MyQueueNode* next = nullptr;
	
	MyQueueNode(int v)
	{
		val = v;
	}
};

class MyQueue
{
	MyQueueNode* front = nullptr; // first to be removed
	MyQueueNode* back = nullptr;  // last to be removed

public:
	void Add(int v);
	MyQueueNode* Remove();
	MyQueueNode* Peek();
	bool IsEmpty();
	void Print();
};

