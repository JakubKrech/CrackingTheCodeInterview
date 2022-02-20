#include "MyHashTable.h"

MyHashTable::MyHashTable()
{
	cout << "HashTable created" << endl;

	for (auto i = 0; i < arraySize; ++i)
	{
		tab[i] = new MyLinkedList();
	}
}

int MyHashTable::Hash(string s)
{
	return int(s[0]);
}

int MyHashTable::Map(int hash)
{
	return hash % arraySize;
}

void MyHashTable::Add(string key, int value)
{
	int hash = Hash(key);
	int index = Map(hash);

	tab[index]->PushBack(key, value);
}

void MyHashTable::Print()
{
	for (auto i = 0; i < arraySize; ++i)
	{
		cout << i;
		tab[i]->Print();
	}
}

void MyHashTable::Increment(string key, int incrementValue)
{
	int hash = Hash(key);
	int index = Map(hash);

	MyNode* target = tab[index]->GetNode(key);

	if (target)
	{
		target->m_value += incrementValue;
	}
	else
	{
		tab[index]->PushBack(key, incrementValue);
	}
}
