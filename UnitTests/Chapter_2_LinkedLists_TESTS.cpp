#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/Chapter_2_LinkedLists.h"
#include "../CrackingTheCodingInterview/Chapter_2_LinkedLists.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter_2_LinkedLists_TESTS
{
	Chapter_2_LinkedLists chapter_2;

	TEST_CLASS(Exercise_1_RemoveDups_TESTS)
	{
		TEST_METHOD(Exercise_1_RemoveDups_A_normalCase)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);
			n->AppendToTail(2); // <- remove
			n->AppendToTail(2); // <- remove
			n->AppendToTail(4);
			n->AppendToTail(1); // <- remove

			Assert::AreEqual(3, chapter_2.Exercise_1_RemoveDups_A(n));
		}

		TEST_METHOD(Exercise_1_RemoveDups_A_nullptr)
		{
			Node* n = nullptr;
			Assert::AreEqual(0, chapter_2.Exercise_1_RemoveDups_A(n));
		}

		TEST_METHOD(Exercise_1_RemoveDups_B_normalCase)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);
			n->AppendToTail(2); // <- remove
			n->AppendToTail(2); // <- remove
			n->AppendToTail(4);
			n->AppendToTail(1); // <- remove

			Assert::AreEqual(3, chapter_2.Exercise_1_RemoveDups_B(n));
		}

		TEST_METHOD(Exercise_1_RemoveDups_B_nullptr)
		{
			Node* n = nullptr;
			Assert::AreEqual(0, chapter_2.Exercise_1_RemoveDups_B(n));
		}
	};

	TEST_CLASS(Exercise_2_ReturnKthToLast_TESTS)
	{
		TEST_METHOD(Exercise_2_ReturnKthToLast_normalCase)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);
			n->AppendToTail(4);
			n->AppendToTail(9);
			n->AppendToTail(8);
			n->AppendToTail(7);

			Assert::AreEqual(4, chapter_2.Exercise_2_ReturnKthToLast(n, 4));
			Assert::AreEqual(8, chapter_2.Exercise_2_ReturnKthToLast(n, 2));
			Assert::AreEqual(7, chapter_2.Exercise_2_ReturnKthToLast(n, 1));
		}

		TEST_METHOD(Exercise_2_ReturnKthToLast_nullptr)
		{
			Node* n = nullptr;
			Assert::AreEqual(-1, chapter_2.Exercise_2_ReturnKthToLast(n, 5));
		}

		TEST_METHOD(Exercise_2_ReturnKthToLast_kBiggerThanLength)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);

			Assert::AreEqual(-1, chapter_2.Exercise_2_ReturnKthToLast(n, 4));
		}

		TEST_METHOD(Exercise_2_ReturnKthToLast_kSameAsLength)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);

			Assert::AreEqual(1, chapter_2.Exercise_2_ReturnKthToLast(n, 3));
		}
	};

	TEST_CLASS(Exercise_3_DeleteMiddleNode_TESTS)
	{
		TEST_METHOD(Exercise_3_DeleteMiddleNode_normalCase)
		{
			Node* n = new Node(1);
			n->AppendToTail(2);
			n->AppendToTail(3);
			n->AppendToTail(4);

			Node* toBeDeleted = n->next;

			chapter_2.Exercise_3_DeleteMiddleNode(toBeDeleted);

			Assert::AreEqual(1, n->val);
			Assert::AreEqual(3, n->next->val);
			Assert::AreEqual(4, n->next->next->val);

			toBeDeleted = n->next;

			chapter_2.Exercise_3_DeleteMiddleNode(toBeDeleted);

			Assert::AreEqual(1, n->val);
			Assert::AreEqual(4, n->next->val);
		}

		TEST_METHOD(Exercise_3_DeleteMiddleNode_nullptr)
		{
			Node* toBeDeleted = nullptr;
			chapter_2.Exercise_3_DeleteMiddleNode(toBeDeleted);
		}
	};

	TEST_CLASS(Exercise_4_Partition_TESTS)
	{
		TEST_METHOD(Exercise_4_Partition_normalCase)
		{
			Node* n = new Node(3);
			n->AppendToTail(5);
			n->AppendToTail(8);
			n->AppendToTail(5);
			n->AppendToTail(10);
			n->AppendToTail(2);
			n->AppendToTail(1);

			int partitionElemValue = 5;

			n = chapter_2.Exercise_4_Partition(n, partitionElemValue);

			while (n != nullptr && n->val != partitionElemValue)
			{
				Assert::IsTrue(n->val < partitionElemValue);
				n = n->next;
			}

			while (n != nullptr && n->val == partitionElemValue)
			{
				n = n->next;
			}

			while (n != nullptr)
			{
				Assert::IsTrue(n->val > partitionElemValue);
				n = n->next;
			}
		}
	};

	TEST_CLASS(Exercise_5_SumLists_TESTS)
	{
		TEST_METHOD(Exercise_5_SumLists_ReverseOrder_smallNumbers)
		{
			Node* first = new Node(7);
			first->AppendToTail(1);
			first->AppendToTail(6);

			Node* second = new Node(5);
			second->AppendToTail(9);
			second->AppendToTail(2);

			// 617 + 295 = 912

			Node* result = chapter_2.Exercise_5_SumLists_ReverseOrder(first, second);
			result->Print();
			Assert::AreEqual(2, result->val);
			Assert::AreEqual(1, result->next->val);
			Assert::AreEqual(9, result->next->next->val);
		}

		TEST_METHOD(Exercise_5_SumLists_ReverseOrder_biggerNumbers)
		{
			Node* first = new Node(7);
			first->AppendToTail(1);
			first->AppendToTail(6);

			Node* second = new Node(5);
			second->AppendToTail(9);
			second->AppendToTail(8);

			// 617 + 895 = 1512

			Node* result = chapter_2.Exercise_5_SumLists_ReverseOrder(first, second);
			result->Print();
			Assert::AreEqual(2, result->val);
			Assert::AreEqual(1, result->next->val);
			Assert::AreEqual(5, result->next->next->val);
			Assert::AreEqual(1, result->next->next->next->val);
		}

		TEST_METHOD(Exercise_5_SumLists_ReverseOrder_differentLength)
		{
			Node* first = new Node(7);
			first->AppendToTail(1);
			first->AppendToTail(6);

			Node* second = new Node(5);
			second->AppendToTail(9);
			second->AppendToTail(9);
			second->AppendToTail(1);
			second->AppendToTail(2);

			// 617 + 21995 = 22612

			Node* result = chapter_2.Exercise_5_SumLists_ReverseOrder(first, second);
			result->Print();
			Assert::AreEqual(2, result->val);
			Assert::AreEqual(1, result->next->val);
			Assert::AreEqual(6, result->next->next->val);
			Assert::AreEqual(2, result->next->next->next->val);
			Assert::AreEqual(2, result->next->next->next->next->val);
		}

		TEST_METHOD(Exercise_5_SumLists_ForwardOrder_smallNumbers)
		{
			Node* first = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* second = new Node(2);
			second->AppendToTail(9);
			second->AppendToTail(5);

			// 617 + 295 = 912

			Node* result = chapter_2.Exercise_5_SumLists_ForwardOrder(first, second);
			result->Print();
			Assert::AreEqual(9, result->val);
			Assert::AreEqual(1, result->next->val);
			Assert::AreEqual(2, result->next->next->val);
		}

		TEST_METHOD(Exercise_5_SumLists_ForwardOrder_biggerNumbers)
		{
			Node* first = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* second = new Node(8);
			second->AppendToTail(9);
			second->AppendToTail(5);

			// 617 + 895 = 1512

			Node* result = chapter_2.Exercise_5_SumLists_ForwardOrder(first, second);
			result->Print();
			Assert::AreEqual(1, result->val);
			Assert::AreEqual(5, result->next->val);
			Assert::AreEqual(1, result->next->next->val);
			Assert::AreEqual(2, result->next->next->next->val);
		}

		TEST_METHOD(Exercise_5_SumLists_ForwardOrder_differentLength)
		{
			Node* first = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* second = new Node(2);
			second->AppendToTail(1);
			second->AppendToTail(9);
			second->AppendToTail(9);
			second->AppendToTail(5);

			// 617 + 21995 = 22612

			Node* result = chapter_2.Exercise_5_SumLists_ForwardOrder(first, second);
			result->Print();
			Assert::AreEqual(2, result->val);
			Assert::AreEqual(2, result->next->val);
			Assert::AreEqual(6, result->next->next->val);
			Assert::AreEqual(1, result->next->next->next->val);
			Assert::AreEqual(2, result->next->next->next->next->val);
		}
	};

	TEST_CLASS(Exercise_6_Palindrome_TESTS)
	{
		TEST_METHOD(Exercise_6_Palindrome_EvenLength_isPalindrome)
		{
			Node* n = new Node(6);
			n->AppendToTail(1);
			n->AppendToTail(7);
			n->AppendToTail(7);
			n->AppendToTail(1);
			n->AppendToTail(6);

			Assert::IsTrue(chapter_2.Exercise_6_Palindrome(n));
		}

		TEST_METHOD(Exercise_6_Palindrome_EvenLength_isNotPalindrome)
		{
			Node* n = new Node(6);
			n->AppendToTail(1);
			n->AppendToTail(7);
			n->AppendToTail(7);
			n->AppendToTail(9);
			n->AppendToTail(6);

			Assert::IsFalse(chapter_2.Exercise_6_Palindrome(n));
		}

		TEST_METHOD(Exercise_6_Palindrome_OddLength_isPalindrome)
		{
			Node* n = new Node(6);
			n->AppendToTail(1);
			n->AppendToTail(7);
			n->AppendToTail(1);
			n->AppendToTail(6);

			Assert::IsTrue(chapter_2.Exercise_6_Palindrome(n));
		}

		TEST_METHOD(Exercise_6_Palindrome_OddLength_isNotPalindrome)
		{
			Node* n = new Node(6);
			n->AppendToTail(1);
			n->AppendToTail(7);
			n->AppendToTail(7);
			n->AppendToTail(8);

			Assert::IsFalse(chapter_2.Exercise_6_Palindrome(n));
		}

		TEST_METHOD(Exercise_6_Palindrome_OddLength_nullptr)
		{
			Node* n = nullptr;

			Assert::IsFalse(chapter_2.Exercise_6_Palindrome(n));
		}
	};

	TEST_CLASS(Exercise_7_Intersection_TESTS)
	{
		TEST_METHOD(Exercise_7_Intersection_oneIsPartOfOther)
		{
			Node* n = new Node(6);
			n->AppendToTail(1);
			n->AppendToTail(7);
			n->AppendToTail(5); // <- intersection
			n->AppendToTail(8);
			n->AppendToTail(9);
			n->AppendToTail(2);

			Node* intersectionPoint = n->next->next->next;

			Node* result = chapter_2.Exercise_7_Intersection(n, intersectionPoint);

			Assert::IsNotNull(result);
			Assert::IsTrue(intersectionPoint == result);
		}

		TEST_METHOD(Exercise_7_Intersection_twoDifferentLists)
		{
			Node* first = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* second = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* result = chapter_2.Exercise_7_Intersection(first, second);

			Assert::IsTrue(result == nullptr);
		}

		TEST_METHOD(Exercise_7_Intersection_twoListsSharingEndingWhichIsThirdList)
		{
			Node* first = new Node(6);
			first->AppendToTail(1);
			first->AppendToTail(7);

			Node* second = new Node(7);
			first->AppendToTail(6);
			first->AppendToTail(5);
			first->AppendToTail(4);
			first->AppendToTail(9);

			Node* sharedEnding = new Node(12);
			first->AppendToTail(1);
			first->AppendToTail(6);
			first->AppendToTail(8);

			Node* endPtr = first;
			while (endPtr->next != nullptr) endPtr = endPtr->next;
			endPtr->next = sharedEnding;

			endPtr = second;
			while (endPtr->next != nullptr) endPtr = endPtr->next;
			endPtr->next = sharedEnding;

			//           6 -> 1 -> 7 \ 
			//                        -> 12 -> 1 -> 6 -> 8
			// 7 -> 6 -> 5 -> 4 -> 9 / 

			// TEST APPROACH A
			Node* result = chapter_2.Exercise_7_Intersection(first, second);
			Assert::IsNotNull(result);
			Assert::IsTrue(sharedEnding == result);

			// TEST APPROACH B
		}
	};

	TEST_CLASS(Exercise_8_LoopDetection_TESTS)
	{
		TEST_METHOD(Exercise_8_LoopDetection_LoopExists)
		{
			Node* first = new Node(6);
			Node* second = new Node(6);
			Node* third = new Node(6);
			Node* fourth = new Node(6);
			Node* fifth = new Node(6);

			first->next = second;
			second->next = third;
			third->next = fourth;
			fourth->next = fifth;
			fifth->next = third;

			//                  __________________
			//                  |                |
			//                  V                |
			// Node -> Node -> Node -> Node -> Node

			// TEST APPROACH A
			Node* result_A = chapter_2.Exercise_8_LoopDetection_A(first);
			Assert::IsNotNull(result_A);
			Assert::IsTrue(result_A == third);

			// TEST APPROACH B
			Node* result_B = chapter_2.Exercise_8_LoopDetection_B(first);
			Assert::IsNotNull(result_B);
			Assert::IsTrue(result_B == third);
		}

		TEST_METHOD(Exercise_8_LoopDetection_NoLoop)
		{
			Node* n = new Node(6);
			n->AppendToTail(6);
			n->AppendToTail(6);
			n->AppendToTail(6);
			n->AppendToTail(6);

			// Node -> Node -> Node -> Node -> Node

			// TEST APPROACH A
			Node* result_A = chapter_2.Exercise_8_LoopDetection_A(n);
			Assert::IsTrue(result_A == nullptr);

			// TEST APPROACH B
			Node* result_B = chapter_2.Exercise_8_LoopDetection_B(n);
			Assert::IsTrue(result_B == nullptr);
		}

		TEST_METHOD(Exercise_8_LoopDetection_LoopsToBeggining)
		{
			Node* first = new Node(6);
			Node* second = new Node(6);
			Node* third = new Node(6);
			Node* fourth = new Node(6);
			Node* fifth = new Node(6);

			first->next = second;
			second->next = third;
			third->next = fourth;
			fourth->next = fifth;
			fifth->next = first;

			//  __________________________________
			//  |                                |
			//  V                                |
			// Node -> Node -> Node -> Node -> Node

			// TEST APPROACH A
			Node* result_A = chapter_2.Exercise_8_LoopDetection_A(first);
			Assert::IsNotNull(result_A);
			Assert::IsTrue(result_A == first);

			// TEST APPROACH B
			Node* result_B = chapter_2.Exercise_8_LoopDetection_B(first);
			Assert::IsNotNull(result_B);
			Assert::IsTrue(result_B == first);
		}
	};
}