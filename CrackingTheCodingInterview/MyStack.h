#pragma once

#include "CommonIncludes.h"

class MyStackNode
{
public:
	int val;
	MyStackNode* next = nullptr;
	MyStackNode* minOfSubstack = nullptr; // substack = all of elements below, including self

	MyStackNode(int v)
	{
		val = v;
	}
};

class MyStack
{
	MyStackNode* top = nullptr;
	MyStackNode* min = nullptr;

	int stackSize = 0;

public:
	MyStack() {};

	void Push(int val);
	MyStackNode* Pop();
	MyStackNode* Peek();
	MyStackNode* Min();
	bool IsEmpty();
	void Print();
	int Size();
};

