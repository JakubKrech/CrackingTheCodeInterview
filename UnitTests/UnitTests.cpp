#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/MyLinkedList.h"
#include "../CrackingTheCodingInterview/MyLinkedList.cpp"
#include "../CrackingTheCodingInterview/MyHashTable.h"
#include "../CrackingTheCodingInterview/MyHashTable.cpp"
#include "../CrackingTheCodingInterview/MyArrayList.h"
#include "../CrackingTheCodingInterview/MyArrayList.cpp"
#include "../CrackingTheCodingInterview/Chapter_1_ArraysAndStrings.h"
#include "../CrackingTheCodingInterview/Chapter_1_ArraysAndStrings.cpp"

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

	TEST_CLASS(Chapter_1_ArraysAndStrings_TESTS)
	{
	public:

		Chapter_1_ArraysAndStrings chapter_1;

		TEST_METHOD(Exercise_1_IsUnique_A)
		{
			Assert::AreEqual(true, chapter_1.Exercise_1_IsUnique_A("Unique str"));
			Assert::AreEqual(false, chapter_1.Exercise_1_IsUnique_A("Not unique string"));
		}

		TEST_METHOD(Exercise_1_IsUnique_B)
		{
			Assert::AreEqual(true, chapter_1.Exercise_1_IsUnique_B("Unique str"));
			Assert::AreEqual(false, chapter_1.Exercise_1_IsUnique_B("Not unique string"));
		}

		TEST_METHOD(Exercise_2_CheckPermutation)
		{
			Assert::AreEqual(true, chapter_1.Exercise_2_CheckPermutation("string! .,213", "string! .,213"));
			Assert::AreEqual(false, chapter_1.Exercise_2_CheckPermutation("string! .,213", "gggggg! .,213"));
			Assert::AreEqual(false, chapter_1.Exercise_2_CheckPermutation("string! .,213", "short"));
		}

		TEST_METHOD(Exercise_3_URLify_A)
		{
			string str = "Mr John Smith    ";
			Assert::AreEqual(string("Mr%20John%20Smith"), chapter_1.Exercise_3_URLify_A(str, 13));
		}

		TEST_METHOD(Exercise_3_URLify_B)
		{
			string str = "Mr John Smith    ";
			Assert::AreEqual(string("Mr%20John%20Smith"), chapter_1.Exercise_3_URLify_B(str, 13));
		}
	};
}
