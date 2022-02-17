#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/MyLinkedList.cpp"
#include "../CrackingTheCodingInterview/MyHashTable.cpp"
#include "../CrackingTheCodingInterview/MyArrayList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MyArrayList_TESTS)
	{
	public:

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
}
