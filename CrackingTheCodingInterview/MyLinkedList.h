#pragma once

#include "CommonIncludes.h"

class Node
{
public:
	string m_key;
	int m_value;
	Node* m_prev = nullptr;
	Node* m_next = nullptr;

	Node(string key, int value)
	{
		m_key = key;
		m_value = value;
	}

	~Node()
	{
		//cout << "Deleting node: " << _key << ": " << _value << endl;
	}
};

class MyLinkedList
{
private:
	Node* m_head = nullptr;
public:
	MyLinkedList() {};
	~MyLinkedList()
	{
		if (m_head == nullptr)
		{
			return;
		}

		Node* curr = m_head;

		while (curr != nullptr)
		{
			m_head = curr->m_next;
			delete(curr);
			curr = m_head;
		}
	};

	void Print();
	
	void PushBack(string key, int val);
	void PushFront(string key, int val);

	Node* GetNode(string key);

	Node* PopBack();
	Node* PopFront();
};

