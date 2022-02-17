#pragma once

#include "CommonIncludes.h"

class Node
{
public:
	string _key;
	int _value;
	Node* _prev = nullptr;
	Node* _next = nullptr;

	Node(string key, int value)
	{
		_key = key;
		_value = value;
	}

	~Node()
	{
		//cout << "Deleting node: " << _key << ": " << _value << endl;
	}
};

class MyLinkedList
{
private:
	Node* _head = nullptr;
public:
	MyLinkedList() {};
	~MyLinkedList()
	{
		if (_head == nullptr)
		{
			return;
		}

		Node* curr = _head;

		while (curr != nullptr)
		{
			_head = curr->_next;
			delete(curr);
			curr = _head;
		}
	};

	void Print();
	
	void PushBack(string key, int val);
	void PushFront(string key, int val);

	Node* GetNode(string key);

	Node* PopBack();
	Node* PopFront();
};

