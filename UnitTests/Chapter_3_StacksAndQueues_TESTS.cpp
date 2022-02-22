#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/Chapter_3_StacksAndQueues.h"
#include "../CrackingTheCodingInterview/Chapter_3_StacksAndQueues.cpp"

#include "../CrackingTheCodingInterview/MyStack.h"
//#include "../CrackingTheCodingInterview/MyStack.cpp"
#include "../CrackingTheCodingInterview/SetOfStacks.h"
#include "../CrackingTheCodingInterview/SetOfStacks.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter_3_StacksAndQueues_TESTS
{
	Chapter_3_StacksAndQueues chapter_3;

	TEST_CLASS(Exercise_2_StackMin_TESTS)
	{
		TEST_METHOD(Exercise_2_StackMin_)
		{
			MyStack s;

			Assert::IsNull(s.Min());

			s.Push(5);
			Assert::AreEqual(5, s.Min()->val);
				
			s.Push(7);
			Assert::AreEqual(5, s.Min()->val);

			s.Push(4);
			Assert::AreEqual(4, s.Min()->val);

			s.Pop();
			Assert::AreEqual(5, s.Min()->val);

			s.Pop();
			s.Pop();

			Assert::IsNull(s.Min());
		}
	};

	TEST_CLASS(Exercise_3_StackOfPlates_TESTS)
	{
		TEST_METHOD(Exercise_3_StackOfPlates_IsEmpty)
		{
			SetOfStacks sos;
			Assert::IsTrue(sos.IsEmpty());

			sos.Push(2);
			Assert::IsFalse(sos.IsEmpty());
		}

		TEST_METHOD(Exercise_3_StackOfPlates_Peek_Empty)
		{
			SetOfStacks sos;
			Assert::IsNull(sos.Peek());
		}

		TEST_METHOD(Exercise_3_StackOfPlates_Peek_LowAmount)
		{
			SetOfStacks sos;

			sos.Push(2);
			sos.Push(3);
			sos.Push(4);

			Assert::IsNotNull(sos.Peek());
			Assert::AreEqual(4, sos.Peek()->val);
		}

		TEST_METHOD(Exercise_3_StackOfPlates_Peek_HighAmount)
		{
			int stackCapacity = 5;
			SetOfStacks sos(stackCapacity);

			sos.Push(2);
			sos.Push(3);
			sos.Push(4);
			sos.Push(5);
			sos.Push(6);

			sos.Push(7);
			sos.Push(8);

			Assert::IsNotNull(sos.Peek());
			Assert::AreEqual(8, sos.Peek()->val);
		}

		TEST_METHOD(Exercise_3_StackOfPlates_Push)
		{
			SetOfStacks sos(3);

			Assert::IsTrue(sos.IsEmpty());

			sos.Push(4);

			Assert::AreEqual(4, sos.Peek()->val);

			sos.Push(5);
			sos.Push(6);
			sos.Push(7);

			Assert::AreEqual(7, sos.Peek()->val);
		}

		TEST_METHOD(Exercise_3_StackOfPlates_Pop)
		{
			SetOfStacks sos(5);

			sos.Push(1);
			sos.Push(2);
			sos.Push(3);
			sos.Push(4);
			sos.Push(5);
			sos.Push(6);

			Assert::AreEqual(6, sos.Pop()->val);
			Assert::AreEqual(5, sos.Pop()->val);
			Assert::AreEqual(4, sos.Pop()->val);
			Assert::AreEqual(3, sos.Pop()->val);
			Assert::AreEqual(2, sos.Pop()->val);
			Assert::AreEqual(1, sos.Pop()->val);
			Assert::IsNull(sos.Pop());
		}

		TEST_METHOD(Exercise_3_StackOfPlates_PopAt)
		{
			SetOfStacks sos(5);

			sos.Push(1);
			sos.Push(2);
			sos.Push(3);
			sos.Push(4);
			sos.Push(5);

			sos.Push(6);
			sos.Push(7);

			Assert::AreEqual(5, sos.PopAt(0)->val);
			Assert::AreEqual(7, sos.PopAt(1)->val);
			Assert::AreEqual(4, sos.PopAt(0)->val);

			Assert::AreEqual(6, sos.Pop()->val);
			Assert::AreEqual(3, sos.Pop()->val);
		}
	};

	TEST_CLASS(Exercise_4_QueueViaStacks_TESTS)
	{
		TEST_METHOD(Exercise_4_QueueViaStacks_IsEmpty)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;
			Assert::IsTrue(qvs.IsEmpty());

			qvs.Add(2);
			Assert::IsFalse(qvs.IsEmpty());
		}

		TEST_METHOD(Exercise_4_QueueViaStacks_Peek_Empty)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;
			Assert::IsNull(qvs.Peek());
		}

		TEST_METHOD(Exercise_4_QueueViaStacks_Peek)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;
			qvs.Add(2);
			qvs.Add(3);
			qvs.Add(4);
			Assert::AreEqual(4, qvs.Peek()->val);
		}

		TEST_METHOD(Exercise_4_QueueViaStacks_Peek_AfterPop)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;
			qvs.Add(2);
			qvs.Add(3);
			qvs.Add(4);

			MyStackNode* popped = qvs.Remove();

			// mainStack: 2 <- 3 <- 4 TOP, transfer to helper
			// helperStack: 4 <- 3 <- 2 TOP, pop top element to simulate how queue works
			// mainStack: 3 <- 4 TOP

			Assert::AreEqual(2, popped->val);
			Assert::AreEqual(4, qvs.Peek()->val);
		}

		TEST_METHOD(Exercise_4_QueueViaStacks_PopOnEmpty)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;

			Assert::IsNull(qvs.Remove());
		}

		TEST_METHOD(Exercise_4_QueueViaStacks_PushAfterPop)
		{
			Chapter_3_StacksAndQueues::MyQueueViaStacks qvs;
			qvs.Add(2);
			qvs.Add(3);
			qvs.Add(4);
			qvs.Remove();
			qvs.Add(5);

			Assert::AreEqual(5, qvs.Peek()->val);
		}
	};

	TEST_CLASS(Exercise_5_SortStack_TESTS)
	{
		TEST_METHOD(Exercise_5_SortStack_)
		{
			MyStack s;
			s.Push(4);
			s.Push(1);
			s.Push(3);
			s.Push(2);
			s.Push(5);

			chapter_3.Exercise_5_SortStack(s);

			// before sort stack: 4 <- 1 <- 3 <- 2 <- 5 TOP
			// after sort stack:  5 <- 4 <- 3 <- 2 <- 1 TOP

			Assert::AreEqual(1, s.Peek()->val);
			s.Pop();
			Assert::AreEqual(2, s.Peek()->val);
			s.Pop();
			Assert::AreEqual(3, s.Peek()->val);
			s.Pop();
			Assert::AreEqual(4, s.Peek()->val);
			s.Pop();
			Assert::AreEqual(5, s.Peek()->val);
		}
	};

	TEST_CLASS(Exercise_6_AnimalShelter_TESTS)
	{
		TEST_METHOD(Exercise_6_AnimalShelter_IsEmpty)
		{
			AnimalShelter shelter;

			Assert::IsTrue(shelter.IsEmpty());

			shelter.Enqueue(AnimalType::Cat);

			Assert::IsFalse(shelter.IsEmpty());
		}

		TEST_METHOD(Exercise_6_AnimalShelter_DequeueAny)
		{
			AnimalShelter shelter;

			shelter.Enqueue(AnimalType::Cat); // id 0
			shelter.Enqueue(AnimalType::Dog); // id 1
			shelter.Enqueue(AnimalType::Cat); // id 2
			shelter.Enqueue(AnimalType::Dog); // id 3

			Assert::AreEqual(0, shelter.DequeueAny()->val);
			Assert::AreEqual(1, shelter.DequeueAny()->val);
			Assert::AreEqual(2, shelter.DequeueAny()->val);
			Assert::AreEqual(3, shelter.DequeueAny()->val);
		}

		TEST_METHOD(Exercise_6_AnimalShelter_DequeueDog)
		{
			AnimalShelter shelter;

			shelter.Enqueue(AnimalType::Cat); // id 0
			shelter.Enqueue(AnimalType::Dog); // id 1
			shelter.Enqueue(AnimalType::Cat); // id 2
			shelter.Enqueue(AnimalType::Dog); // id 3

			Assert::AreEqual(1, shelter.DequeueDog()->val);
			Assert::AreEqual(3, shelter.DequeueDog()->val);

			Assert::IsFalse(shelter.IsEmpty());
		}

		TEST_METHOD(Exercise_6_AnimalShelter_DequeueCat)
		{
			AnimalShelter shelter;

			shelter.Enqueue(AnimalType::Cat); // id 0
			shelter.Enqueue(AnimalType::Dog); // id 1
			shelter.Enqueue(AnimalType::Cat); // id 2
			shelter.Enqueue(AnimalType::Dog); // id 3

			Assert::AreEqual(0, shelter.DequeueCat()->val);
			Assert::AreEqual(2, shelter.DequeueCat()->val);

			Assert::IsFalse(shelter.IsEmpty());
		}

		TEST_METHOD(Exercise_6_AnimalShelter_DequeuesMixed)
		{
			AnimalShelter shelter;

			shelter.Enqueue(AnimalType::Cat); // id 0
			shelter.Enqueue(AnimalType::Dog); // id 1
			shelter.Enqueue(AnimalType::Cat); // id 2
			shelter.Enqueue(AnimalType::Dog); // id 3

			Assert::AreEqual(1, shelter.DequeueDog()->val);
			Assert::AreEqual(0, shelter.DequeueAny()->val);
			Assert::AreEqual(2, shelter.DequeueCat()->val);
			Assert::AreEqual(3, shelter.DequeueAny()->val);

			Assert::IsTrue(shelter.IsEmpty());
		}

		TEST_METHOD(Exercise_6_AnimalShelter_EnqDeqEnqDeq)
		{
			AnimalShelter shelter;

			shelter.Enqueue(AnimalType::Cat); // id 0
			shelter.Enqueue(AnimalType::Dog); // id 1
			shelter.Enqueue(AnimalType::Cat); // id 2
			shelter.Enqueue(AnimalType::Dog); // id 3

			Assert::AreEqual(0, shelter.DequeueAny()->val);
			Assert::AreEqual(1, shelter.DequeueAny()->val);

			shelter.Enqueue(AnimalType::Cat); // id 4
			shelter.Enqueue(AnimalType::Dog); // id 5

			Assert::AreEqual(2, shelter.DequeueAny()->val);
			Assert::AreEqual(3, shelter.DequeueAny()->val);
			Assert::AreEqual(4, shelter.DequeueAny()->val);
			Assert::AreEqual(5, shelter.DequeueAny()->val);

			Assert::IsTrue(shelter.IsEmpty());
		}
	};
}