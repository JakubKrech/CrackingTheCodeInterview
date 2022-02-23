#pragma once

#include "CommonIncludes.h"

class MyNode
{
public:
	string m_key;
	int m_value;
	MyNode* m_prev = nullptr;
	MyNode* m_next = nullptr;

	MyNode(int value)
	{
		m_value = value;
	}

	MyNode(string key, int value)
	{
		m_key = key;
		m_value = value;
	}

	~MyNode()
	{
		//cout << "Deleting node: " << _key << ": " << _value << endl;
	}
};

class MyLinkedList
{
private:
	MyNode* m_head = nullptr;
public:
	MyLinkedList() {};
	~MyLinkedList()
	{
		if (m_head == nullptr)
		{
			return;
		}

		MyNode* curr = m_head;

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

	MyNode* GetNode(string key);

	MyNode* PopBack();
	MyNode* PopFront();
};

