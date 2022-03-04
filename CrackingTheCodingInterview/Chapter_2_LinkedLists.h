#pragma once

#include "CommonIncludes.h"
#include "Node.h"

class Chapter_2_LinkedLists
{
public:

	// EXERCISE 1
	int Exercise_1_RemoveDups_A(Node* n);
	int Exercise_1_RemoveDups_B(Node* n);

	// EXERCISE 2 - Also two pointers can be used, one moved at the beggining
	//              by k elements, and then moving them at the same pace.
	int Exercise_2_ReturnKthToLast(Node* n, int k);

	// EXERCISE 3
	void Exercise_3_DeleteMiddleNode(Node* toBeDeleted);

	// EXERCISE 4
	Node* Exercise_4_Partition(Node* n, int partitionElemValue);

	// EXERCISE 5
	Node* Exercise_5_SumLists_ReverseOrder(Node* first, Node* second);
	Node* Exercise_5_SumLists_ForwardOrder(Node* first, Node* second);

	// EXERCISE 6
	bool Exercise_6_Palindrome(Node* n);

	// EXERCISE 7
	Node* Exercise_7_Intersection(Node* first, Node* second);

	// EXERCISE 8 todo: doczytac rozwiazanie nr 4
	Node* Exercise_8_LoopDetection_A(Node* n);
	Node* Exercise_8_LoopDetection_B(Node* n);


	// Helper functions
	Node* Ex5_ReverseLinkedList(Node* n);
	int Ex7_CalculateLinkedListLength(Node* n);
};

