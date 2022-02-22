#include "Chapter_3_StacksAndQueues.h"

// EXERCISE 2, 3, 4
// Can be found in Chapter_3_StacksAndQueues.h

// EXERCISE 5

void Chapter_3_StacksAndQueues::Exercise_5_SortStack(MyStack& s)
{
	if (s.IsEmpty())
		return;

	MyStack helper1;
	MyStack helper2;
	bool isSorted = false;

	while (!isSorted)
	{
		helper2.Push(s.Pop()->val);

		while (!s.IsEmpty())
		{
			MyStackNode* popped = s.Pop();

			if (popped->val > helper2.Peek()->val)
			{
				helper2.Push(popped->val);
			}
			else
			{
				helper1.Push(popped->val);
			}
			delete(popped);
		}

		isSorted = helper1.IsEmpty();

		while (!helper2.IsEmpty())
		{
			MyStackNode* popped = helper2.Pop();
			s.Push(popped->val);
			delete(popped);
		}

		while (!helper1.IsEmpty())
		{
			MyStackNode* popped = helper1.Pop();
			s.Push(popped->val);
			delete(popped);
		}
	}
}

// EXERCISE 6

enum class AnimalType
{
	Dog,
	Cat
};

class AnimalShelter
{
public:
	MyQueue cats;
	MyQueue dogs;
	int global_id = 0;

	void Enqueue(AnimalType t);
	MyQueueNode* DequeueAny();
	MyQueueNode* DequeueDog();
	MyQueueNode* DequeueCat();
	bool IsEmpty();
};

void AnimalShelter::Enqueue(AnimalType type)
{
	switch (type)
	{
	case AnimalType::Dog:
		dogs.Add(global_id++);
		break;
	case AnimalType::Cat:
		cats.Add(global_id++);
		break;
	}
}

MyQueueNode* AnimalShelter::DequeueAny()
{
	if (IsEmpty())
		return nullptr;
	else if (cats.IsEmpty())
		return dogs.Remove();
	else if (dogs.IsEmpty())
		return cats.Remove();
	else
	{
		return cats.Peek()->val < dogs.Peek()->val ? cats.Remove() : dogs.Remove();
	}
}

MyQueueNode* AnimalShelter::DequeueDog()
{
	if (IsEmpty())
		return nullptr;
	else
		return dogs.Remove();
}

MyQueueNode* AnimalShelter::DequeueCat()
{
	if (IsEmpty())
		return nullptr;
	else
		return cats.Remove();
}

bool AnimalShelter::IsEmpty()
{
	return cats.IsEmpty() && dogs.IsEmpty();
}
