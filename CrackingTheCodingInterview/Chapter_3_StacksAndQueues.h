#pragma once

#include "CommonIncludes.h"

#include "MyStack.h"
#include "MyQueue.h"

class Chapter_3_StacksAndQueues
{
public:

	// EXERCISE 2
	// Implemented in MyStack.cpp and MyStack.h
	// Another solution is to create additional stack to keep track of min elements, then
	// we add to it values <= than current min.

	// EXERCISE 3
	// Implemented in SetOfStacks.cpp and SetOfStacks.h
	// Solution to follow up question omits shifting elements, and leaves stacks
	// at not maxed out capacity. While it is acceptable, in some situations it would
	// be better to shift elements to avoid incorrect assumptions that all the stacks
	// are at their full capacity, which could lead to bugs and problems in the future.

	// EXERCISE 4
	// It is also possible to move elements from mainStack to helperStack only when we want
	// to remove an element, AND there are no more elements in helperStack. Otherwise just remove
	// top element from helper. When adding, we can just add on top of mainStack.

	class MyQueueViaStacks
	{
	private:
		MyStack mainStack;
		MyStack helperStack;

		bool inPopState = false;
	public:
		
		void TransferBetweenStacks()
		{
			if (!inPopState)
			{
				cout << "into pop state" << endl;
				mainStack.Print();
				
				while (!mainStack.IsEmpty())
				{
					MyStackNode* popped = mainStack.Pop();
					cout << "moving: " << popped->val << endl;
					helperStack.Push(popped->val);
					delete(popped);
				}

				helperStack.Print();
				inPopState = true;
			}
			else
			{
				cout << "into push state" << endl;
				helperStack.Print();

				while (!helperStack.IsEmpty())
				{
					MyStackNode* popped = helperStack.Pop();
					mainStack.Push(popped->val);
					delete(popped);
				}
				inPopState = false;
			}
		};

		void Add(int val)
		{
			if (inPopState)
			{
				TransferBetweenStacks();
			}

			mainStack.Push(val);
		};

		MyStackNode* Remove()
		{
			if (!inPopState)
			{
				TransferBetweenStacks();
			}

			return helperStack.Pop();
		};

		MyStackNode* Peek()
		{
			if (inPopState)
			{
				TransferBetweenStacks();
			}

			return mainStack.Peek();
		};

		bool IsEmpty()
		{
			return mainStack.IsEmpty() && helperStack.IsEmpty();
		};

		void Print()
		{
			if (inPopState)
			{
				TransferBetweenStacks();
			}

			mainStack.Print();
		};
	};

	// EXERCISE 5
	// Sort stack such that smallest items are on top. Using another temporary stack is allowed,
	// copying elements into any other data structure is not allowed.
	// The stack supports operations: push, pop, peek, isEmpty

	void Exercise_5_SortStack(MyStack& s);

	// EXERCISE 6

	enum class AnimalType;
	class AnimalShelter;
};

