#include "MyLinkedList.h"

void MyLinkedList::Print()
{
	if (_head == nullptr)
	{
		cout << "Linked list empty" << endl;
		return;
	}

	Node* curr = _head;
	int index = 0;

	cout << " LIST:";

	while (curr != nullptr)
	{
		// string prevVal = curr->_prev == nullptr ? "nullptr" : curr->_prev->_value;
		// string nextVal = curr->_next == nullptr ? "nullptr" : curr->_next->_value;

		// cout << "[" << index << "] " << curr->_value << "   p: " << prevVal << " n: " << nextVal << endl;

		cout << " -> " << curr->_key << "(" << curr->_value << ")";

		curr = curr->_next;
	}

	cout << endl;
}

void MyLinkedList::PushBack(string key, int val)
{
	Node* newNode = new Node(key, val);

	if (_head == nullptr)
	{
		_head = newNode;
	}
	else
	{
		Node* curr = _head;

		while (curr->_next != nullptr)
		{
			curr = curr->_next;
		}

		curr->_next = newNode;
		newNode->_prev = curr;
	}
}

void MyLinkedList::PushFront(string key, int val)
{
	Node* newNode = new Node(key, val);

	Node* temp = _head;

	_head = newNode;
	_head->_next = temp;
	temp->_prev = _head;
}

Node* MyLinkedList::GetNode(string key)
{
	Node* curr = _head;

	while (curr != nullptr)
	{
		if (curr->_key == key)
		{
			return curr;
		}
		else
		{
			curr = curr->_next;
		}
	}

	return nullptr;
}

Node* MyLinkedList::PopBack()
{
	if (_head == nullptr)
	{
		return nullptr;
	}

	Node* curr = _head;

	while (curr->_next != nullptr)
	{
		curr = curr->_next;
	}

	curr->_prev->_next = nullptr;

	return curr;
}

Node* MyLinkedList::PopFront()
{
	if (_head == nullptr)
	{
		return nullptr;
	}

	Node* curr = _head;

	_head = curr->_next;
	_head->_prev = nullptr;

	return curr;
}
