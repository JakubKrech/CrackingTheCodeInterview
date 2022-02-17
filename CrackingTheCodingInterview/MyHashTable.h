#pragma once

#include "CommonIncludes.h"
#include "MyLinkedList.h"

using namespace std;

class MyHashTable
{
private:
	static constexpr int arraySize = 26;

	int Hash(string s);
	int Map(int hash);
public:
	MyLinkedList* tab[arraySize]{};

	MyHashTable();
	~MyHashTable()
	{
		for (auto i = 0; i < arraySize; ++i)
		{
			delete(tab[i]);
		}
	};
	
	void Add(string key, int value);
	void Print();
	void Increment(string key, int incrementValue = 1);
};
