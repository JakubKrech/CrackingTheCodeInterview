#include "CommonIncludes.h"

#include "MyHashTable.h"
#include "MyLinkedList.h"
#include "MyArrayList.h"

#include "Chapter_1_ArraysAndStrings.h"
#include "Chapter_2_LinkedLists.h"

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

	Chapter_2_LinkedLists chapter_2;

	Node* first = new Node(9);
	first->AppendToTail(7);
	first->AppendToTail(8);

	Node* second = new Node(6);
	second->AppendToTail(8);
	second->AppendToTail(5);

	/*first->Print();
	second->Print();*/

	// 617 + 295 = 912

	Node* result = chapter_2.Exercise_5_SumLists_ReverseOrder(first, second);
	result->Print();
}