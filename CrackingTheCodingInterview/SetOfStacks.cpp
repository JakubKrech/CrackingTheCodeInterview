#include "SetOfStacks.h"

void SetOfStacks::Push(int val)
{
	if (stacks.empty())
		stacks.push_back(MyStack());

	size_t topStackIndex = stacks.size() - 1;

	if (stacks[topStackIndex].Size() < threshold)
	{
		stacks[topStackIndex].Push(val);
	}
	else
	{
		stacks.push_back(MyStack());
		stacks[topStackIndex + 1].Push(val);
	}
}

MyStackNode* SetOfStacks::Pop()
{
	if (stacks.empty())
		return nullptr;

	size_t topStackIndex = stacks.size() - 1;

	MyStackNode* popped = stacks[topStackIndex].Pop();

	if (popped && stacks[topStackIndex].Size() == 0)
	{
		stacks.erase(stacks.end() - 1);
	}

	return popped;
}

MyStackNode* SetOfStacks::PopAt(int i)
{
	size_t topStackIndex = stacks.size() - 1;

	if (i > topStackIndex || i < 0)
		return nullptr;

	MyStackNode* popped = stacks[i].Pop();

	if (stacks[i].Size() == 0)
	{
		stacks.erase(stacks.begin() + i);
	}

	return popped;
}

MyStackNode* SetOfStacks::Peek()
{
	if (IsEmpty())
		return nullptr;

	size_t topStackIndex = stacks.size() - 1;
	return stacks[topStackIndex].Peek();
}

bool SetOfStacks::IsEmpty()
{
	return stacks.empty();
}

void SetOfStacks::Print()
{
	cout << ">>>> Set of stacks: <<<<" << endl;
	cout << "FIRST ";
	for (auto& stack : stacks)
	{
		stack.Print();
	}
}
