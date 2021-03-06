#include "CommonIncludes.h"

#include "MyHashTable.h"
#include "MyLinkedList.h"
#include "MyArrayList.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "SetOfStacks.h"
#include "MyBinarySearchTree.h"
#include "MyGraph.h"

#include "Chapter_1_ArraysAndStrings.h"
#include "Chapter_2_LinkedLists.h"
#include "Chapter_3_StacksAndQueues.h"
#include "Chapter_4_TreesAndGraphs.h"

// TODO:
// - Implement HashTable, ArrayList, StringBuilder
// - Additional Reading: HashTable Collision Resolution, Rabin-Karp Substring Search
// - Interview Questions 1.1 - 1.9
//

void Test_MyLinkedList()
{
	MyLinkedList ll;

	ll.Print();
	ll.PushBack("Zenon", 0);
	ll.PushBack("Kazimierz", 0);
	ll.PushBack("Jaroslaw", 0);
	ll.PushBack("Agnieszka", 0);
	ll.PushFront("Borys", 0);
	ll.Print();

	MyNode* poppedBack = ll.PopBack();
	cout << "Popped node: " << poppedBack->m_value << endl;

	ll.Print();

	MyNode* poppedFront = ll.PopFront();
	cout << "Popped node: " << poppedFront->m_value << endl;

	ll.Print();
}

void Test_MyHashTable()
{
	MyHashTable ht;

	ht.Add("Katarzyna", 0);
	ht.Add("Antoni", 0);
	ht.Add("Piotr", 0);
	ht.Add("Adam", 0);
	ht.Add("Pawel", 0);
	ht.Add("Arkadiusz", 0);
	ht.Add("Kuba", 0);
	ht.Add("Zbigniew", 0);

	ht.Increment("Kuba", 5);
	ht.Increment("Fifonz", 1);

	ht.Print();
}

void Test_MyArrayList()
{
	MyArrayList<string> al;

	cout << al.GetSize() << endl;
	al.Append("Katarina");
	al.Append("Darius");
	al.Append("Amumu");
	al.Append("Victor");
	al.Append("Garen");

	for (auto i = 0; i < 500000; i++)
	{
		al.Append("GG");
	}

	// al.Print();
}

void TestMyStack()
{
	MyStack s;

	s.Push(12);
	
	s.Print();
	
	s.Push(8);
	s.Push(1);
	s.Push(534);
	s.Push(874);

	s.Print();

	cout << "POP: " << s.Pop()->val << endl;

	s.Print();
}

void Test_Chapter_1()
{
	Chapter_1_ArraysAndStrings chapter1;

	string str = "Mr John Smith      ";
	cout << "[" << chapter1.Exercise_3_URLify_B(str, 13) << "]" << endl;
}


int main()
{
	//Test_MyLinkedList();
	//Test_MyLinkedList();
	//Test_MyArrayList();

	//TestMyStack();
	Chapter_4_TreesAndGraphs chapter_4;

	RandomBinaryTree rbt;
	rbt.Insert(3);
	rbt.Insert(1);
	rbt.Insert(2);
	rbt.Insert(5);
	rbt.Insert(7);
	rbt.Insert(15);
	rbt.Insert(-2);
	rbt.Insert(6);
	rbt.Insert(4);

	rbt.InOrderPrint();
	cout << "SIZE: " << rbt.size << endl;

	/*rbt.Find(6);
	rbt.Find(123);*/

	//RandomBinaryTree::Delete(rbt.root, 1);

	//rbt.InOrderPrint();

	cout << rbt.GetRandomNode()->val << endl;
	cout << rbt.GetRandomNode(5)->val << endl;
}