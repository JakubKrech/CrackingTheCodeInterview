#pragma once

#include "CommonIncludes.h"

class Node
{
public:
	int val;
	Node* next = nullptr;

	Node(int v)
	{
		val = v;
	}

	void AppendToTail(int v)
	{
		Node* curr = this;
		while (curr->next != nullptr)
		{
			curr = curr->next;
		}

		Node* newNode = new Node(v);
		curr->next = newNode;
	}

	void Print()
	{
		Node* curr = this;

		while (curr != nullptr)
		{
			cout << curr->val << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

