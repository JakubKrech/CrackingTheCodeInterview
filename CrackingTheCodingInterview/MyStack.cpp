#include "MyStack.h"

void MyStack::Push(int val)
{
	MyStackNode* newNode = new MyStackNode(val);
	newNode->next = top;
	top = newNode;

	// Update min value
	if (min == nullptr || newNode->val < min->val)
	{
		newNode->minOfSubstack = newNode;
		min = newNode;
	}
	else
	{
		newNode->minOfSubstack = min;
	}

	++stackSize;
}

MyStackNode* MyStack::Pop()
{
	if (!top)
		return nullptr;

	MyStackNode* popped = top;
	top = top->next;

	// Update min value
	if (popped == min)
	{
		if (top)
			min = top->minOfSubstack;
		else
			min = nullptr;
	}

	--stackSize;

	return popped;
}

MyStackNode* MyStack::Peek()
{
	return top;
}

MyStackNode* MyStack::Min()
{
	return min;
}

bool MyStack::IsEmpty()
{
	return top == nullptr;
}

void MyStack::Print()
{
	cout << "TOP -> ";

	MyStackNode* curr = top;

	while (curr)
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}

int MyStack::Size()
{
	return stackSize;
}
