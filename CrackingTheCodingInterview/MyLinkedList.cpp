#include "MyLinkedList.h"

void MyLinkedList::Print()
{
	if (m_head == nullptr)
	{
		cout << "Linked list empty" << endl;
		return;
	}

	MyNode* curr = m_head;
	int index = 0;

	cout << " LIST:";

	while (curr != nullptr)
	{
		// string prevVal = curr->_prev == nullptr ? "nullptr" : curr->_prev->_value;
		// string nextVal = curr->_next == nullptr ? "nullptr" : curr->_next->_value;

		// cout << "[" << index << "] " << curr->_value << "   p: " << prevVal << " n: " << nextVal << endl;

		cout << " -> " << curr->m_key << "(" << curr->m_value << ")";

		curr = curr->m_next;
	}

	cout << endl;
}

void MyLinkedList::PushBack(string key, int val)
{
	MyNode* newNode = new MyNode(key, val);

	if (m_head == nullptr)
	{
		m_head = newNode;
	}
	else
	{
		MyNode* curr = m_head;

		while (curr->m_next != nullptr)
		{
			curr = curr->m_next;
		}

		curr->m_next = newNode;
		newNode->m_prev = curr;
	}
}

void MyLinkedList::PushFront(string key, int val)
{
	MyNode* newNode = new MyNode(key, val);

	MyNode* temp = m_head;

	m_head = newNode;
	m_head->m_next = temp;
	temp->m_prev = m_head;
}

MyNode* MyLinkedList::GetNode(string key)
{
	MyNode* curr = m_head;

	while (curr != nullptr)
	{
		if (curr->m_key == key)
		{
			return curr;
		}
		else
		{
			curr = curr->m_next;
		}
	}

	return nullptr;
}

MyNode* MyLinkedList::PopBack()
{
	if (m_head == nullptr)
	{
		return nullptr;
	}

	MyNode* curr = m_head;

	while (curr->m_next != nullptr)
	{
		curr = curr->m_next;
	}

	curr->m_prev->m_next = nullptr;

	return curr;
}

MyNode* MyLinkedList::PopFront()
{
	if (m_head == nullptr)
	{
		return nullptr;
	}

	MyNode* curr = m_head;

	m_head = curr->m_next;
	m_head->m_prev = nullptr;

	return curr;
}
