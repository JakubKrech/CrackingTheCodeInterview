#include "MyQueue.h"

void MyQueue::Add(int v)
{
	MyQueueNode* newNode = new MyQueueNode(v);

	if (!front && !back)
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;
	}
}

MyQueueNode* MyQueue::Remove()
{
	if (!front)
	{
		return nullptr;
	}

	MyQueueNode* popped = front;

	if (back == front) // only one element in queue
	{
		back = nullptr;
		front = nullptr;
	}
	else
	{
		front = front->next;
	}

	return popped;
}

MyQueueNode* MyQueue::Peek()
{
	return front;
}

bool MyQueue::IsEmpty()
{
	return front == nullptr;
}

void MyQueue::Print()
{
}
