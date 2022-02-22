#pragma once

#include "CommonIncludes.h"
#include "../CrackingTheCodingInterview/MyStack.h"

class SetOfStacks
{
	vector<MyStack> stacks;
	int threshold = 5;

	MyStackNode* top = nullptr;
	MyStackNode* min = nullptr;

public:
	SetOfStacks() {};
	SetOfStacks(int stackCapacity) 
	{
		threshold = stackCapacity;
	};

	void Push(int val);
	MyStackNode* Pop();
	MyStackNode* PopAt(int i);
	MyStackNode* Peek();
	bool IsEmpty();
	void Print();
};
