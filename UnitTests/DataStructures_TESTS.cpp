#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/MyLinkedList.h"
#include "../CrackingTheCodingInterview/MyLinkedList.cpp"
#include "../CrackingTheCodingInterview/MyHashTable.h"
#include "../CrackingTheCodingInterview/MyHashTable.cpp"
#include "../CrackingTheCodingInterview/MyArrayList.h"
#include "../CrackingTheCodingInterview/MyArrayList.cpp"
#include "../CrackingTheCodingInterview/MyStack.h"
#include "../CrackingTheCodingInterview/MyStack.cpp"
#include "../CrackingTheCodingInterview/MyQueue.h"
#include "../CrackingTheCodingInterview/MyQueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructures_TESTS
{
	TEST_CLASS(MyArrayList_TESTS)
	{
		TEST_METHOD(Constructor_OneArg)
		{
			MyArrayList<double> al(10);
			Assert::AreEqual((size_t)10, al.GetSize());
		}

		TEST_METHOD(Constructor_TwoArg)
		{
			MyArrayList<double> al(3, 12.0);
			Assert::AreEqual((size_t)3, al.GetSize());
			Assert::AreEqual(12.0, al[0]);
			Assert::AreEqual(12.0, al[1]);
			Assert::AreEqual(12.0, al[2]);
		}

		TEST_METHOD(Append)
		{
			MyArrayList<double> al;
			al.Append(123.0);
			Assert::AreEqual(123.0, al[0]);
		}
	};

	TEST_CLASS(MyStack_TESTS)
	{
		TEST_METHOD(Peek_)
		{
			MyStack s;

			Assert::IsNull(s.Peek());

			s.Push(5);

			Assert::AreEqual(5, s.Peek()->val);
		}

		TEST_METHOD(Push_)
		{
			MyStack s;
			s.Push(5);
			Assert::AreEqual(5, s.Peek()->val);
		}

		TEST_METHOD(Pop_existingNode)
		{
			MyStack s;
			s.Push(5);
			s.Push(4);
			s.Push(2);

			MyStackNode* popped = s.Pop();

			Assert::AreEqual(4, s.Peek()->val);
			Assert::AreEqual(2, popped->val);
		}

		TEST_METHOD(Pop_onEmptyStack)
		{
			MyStack s;

			s.Pop();
			s.Pop();
			s.Pop();
			s.Pop();
			s.Pop();
			s.Pop();

			Assert::IsNull(s.Pop());
		}

		TEST_METHOD(IsEmpty_)
		{
			MyStack s;

			Assert::IsTrue(s.IsEmpty());

			s.Push(3);

			Assert::IsFalse(s.IsEmpty());

			s.Pop();

			Assert::IsTrue(s.IsEmpty());
		}
	};

	TEST_CLASS(MyQueue_TESTS)
	{
		TEST_METHOD(Peek_)
		{
			MyQueue q;

			Assert::IsNull(q.Peek());

			q.Add(5);

			Assert::AreEqual(5, q.Peek()->val);
		}

		TEST_METHOD(Add_)
		{
			MyQueue q;
			q.Add(5);
			Assert::AreEqual(5, q.Peek()->val);
		}

		TEST_METHOD(Remove_)
		{
			MyQueue q;
			q.Add(5);
			q.Add(4);
			q.Add(2);

			MyQueueNode* popped = q.Remove();

			Assert::AreEqual(4, q.Peek()->val);
			Assert::AreEqual(5, popped->val);
		}

		TEST_METHOD(IsEmpty_)
		{
			MyStack s;

			Assert::IsTrue(s.IsEmpty());

			s.Push(3);

			Assert::IsFalse(s.IsEmpty());

			s.Pop();

			Assert::IsTrue(s.IsEmpty());
		}
	};
}
