#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/Chapter_1_ArraysAndStrings.h"
#include "../CrackingTheCodingInterview/Chapter_1_ArraysAndStrings.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter_1_ArraysAndStrings_TESTS
{
	Chapter_1_ArraysAndStrings chapter_1;

	TEST_CLASS(Exercise_1_IsUnique_TESTS)
	{
		TEST_METHOD(Exercise_1_IsUnique_A_)
		{
			Assert::IsTrue(chapter_1.Exercise_1_IsUnique_A("Unique str"));
			Assert::IsFalse(chapter_1.Exercise_1_IsUnique_A("Not unique string"));
		}

		TEST_METHOD(Exercise_1_IsUnique_B_)
		{
			Assert::IsTrue(chapter_1.Exercise_1_IsUnique_B("Unique str"));
			Assert::IsFalse(chapter_1.Exercise_1_IsUnique_B("Not unique string"));
		}
	};

	TEST_CLASS(Exercise_2_CheckPermutation_TESTS)
	{
		TEST_METHOD(Exercise_2_CheckPermutation_)
		{
			Assert::IsTrue(chapter_1.Exercise_2_CheckPermutation("string! .,213", "string! .,213"));
			Assert::IsFalse(chapter_1.Exercise_2_CheckPermutation("string! .,213", "gggggg! .,213"));
			Assert::IsFalse(chapter_1.Exercise_2_CheckPermutation("string! .,213", "short"));
		}
	};

	TEST_CLASS(Exercise_3_URLify_TESTS)
	{
		TEST_METHOD(Exercise_3_URLify_A_)
		{
			string str = "Mr John Smith    ";
			Assert::AreEqual(string("Mr%20John%20Smith"), chapter_1.Exercise_3_URLify_A(str, 13));

			/*string str2 = "Mr John Smith      ";
			Assert::AreEqual(string("Mr%20John%20Smith  "), chapter_1.Exercise_3_URLify_A(str2, 13));*/
		}

		TEST_METHOD(Exercise_3_URLify_B_)
		{
			string str = "Mr John Smith    ";
			Assert::AreEqual(string("Mr%20John%20Smith"), chapter_1.Exercise_3_URLify_B(str, 13));

			string str2 = "Mr John Smith      ";
			Assert::AreEqual(string("Mr%20John%20Smith  "), chapter_1.Exercise_3_URLify_B(str2, 13));
		}
	};

	TEST_CLASS(Exercise_4_PalindromePermutation_TESTS)
	{
		TEST_METHOD(Exercise_4_PalindromePermutation_)
		{
			Assert::IsTrue(chapter_1.Exercise_4_PalindromePermutation("tact coa"));
			Assert::IsTrue(chapter_1.Exercise_4_PalindromePermutation("tact coao"));
			Assert::IsFalse(chapter_1.Exercise_4_PalindromePermutation("tact coaoxyz"));
		}
	};

	TEST_CLASS(Exercise_5_OneAway_TESTS)
	{
		TEST_METHOD(Exercise_5_OneAway_RemoveCharacter)
		{
			Assert::IsTrue(chapter_1.Exercise_5_OneAway("pale", "ple"));
		}

		TEST_METHOD(Exercise_5_OneAway_InsertCharacter)
		{
			Assert::IsTrue(chapter_1.Exercise_5_OneAway("pales", "pale"));
			Assert::IsTrue(chapter_1.Exercise_5_OneAway("pale", "prale"));
		}

		TEST_METHOD(Exercise_5_OneAway_ReplaceCharacter)
		{
			Assert::IsTrue(chapter_1.Exercise_5_OneAway("pale", "bale"));
		}

		TEST_METHOD(Exercise_5_OneAway_TwoCharactersReplaced)
		{
			Assert::IsFalse(chapter_1.Exercise_5_OneAway("pale", "bake"));
		}

		TEST_METHOD(Exercise_5_OneAway_ManyCharactersSwappedPlaces)
		{
			Assert::IsFalse(chapter_1.Exercise_5_OneAway("pale", "alep"));
		}

		TEST_METHOD(Exercise_5_OneAway_ReplaceCharacterAndSwap)
		{
			Assert::IsFalse(chapter_1.Exercise_5_OneAway("pale", "lade"));
		}

		TEST_METHOD(Exercise_5_OneAway_BigLengthDifference)
		{
			Assert::IsFalse(chapter_1.Exercise_5_OneAway("pale", "palepalepalepale"));
		}
	};

	TEST_CLASS(Exercise_6_StringCompression_TESTS)
	{
		TEST_METHOD(Exercise_6_StringCompression_normalCase)
		{
			Assert::AreEqual(string("a2b1c5a3"), chapter_1.Exercise_6_StringCompression("aabcccccaaa"));
		}

		TEST_METHOD(Exercise_6_StringCompression_compressedStringLonger)
		{
			Assert::AreEqual(string("abcdefg"), chapter_1.Exercise_6_StringCompression("abcdefg"));
		}

		TEST_METHOD(Exercise_6_StringCompression_multiDigitsCounter)
		{
			Assert::AreEqual(string("a1b13c2"), chapter_1.Exercise_6_StringCompression("abbbbbbbbbbbbbcc"));
		}

		TEST_METHOD(Exercise_6_StringCompression_shortCase)
		{
			Assert::AreEqual(string("a"), chapter_1.Exercise_6_StringCompression("a"));
		}

		TEST_METHOD(Exercise_6_StringCompression_shortLengthEqualToResult)
		{
			Assert::AreEqual(string("aa"), chapter_1.Exercise_6_StringCompression("aa"));
		}
	};

	TEST_CLASS(Exercise_7_RotateMatrix_TESTS)
	{
		TEST_METHOD(Exercise_7_RotateMatrix_3x3)
		{
			int n = 3;

			int** tab = new int* [n];
			for (int i = 0; i < n; ++i)
			{
				tab[i] = new int[n];
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					tab[i][j] = j + n * i;
				}
			}

			int** rotatedMatrix = chapter_1.Exercise_7_RotateMatrix(tab, n);

			Assert::AreEqual(7, rotatedMatrix[0][0]);
			Assert::AreEqual(4, rotatedMatrix[0][1]);
			Assert::AreEqual(1, rotatedMatrix[0][2]);
		}

		TEST_METHOD(Exercise_7_RotateMatrix_4x4)
		{
			int n = 4;

			int** tab = new int* [n];
			for (int i = 0; i < n; ++i)
			{
				tab[i] = new int[n];
			}

			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					tab[i][j] = j + n * i;
				}
			}

			int** rotatedMatrix = chapter_1.Exercise_7_RotateMatrix(tab, n);

			Assert::AreEqual(13, rotatedMatrix[0][0]);
			Assert::AreEqual(9, rotatedMatrix[0][1]);
			Assert::AreEqual(5, rotatedMatrix[0][2]);
			Assert::AreEqual(1, rotatedMatrix[0][3]);
		}
	};

	TEST_CLASS(Exercise_8_ZeroMatrix_TESTS)
	{
		TEST_METHOD(Exercise_8_ZeroMatrix_3x4)
		{
			int m = 3;
			int n = 4;

			int** tab = new int* [m];
			for (int i = 0; i < m; ++i)
			{
				tab[i] = new int[n];
			}

			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					tab[i][j] = 1;
				}
			}

			// 1 0 1 1       0 0 0 0
			// 1 1 0 1  ->   0 0 0 0
			// 1 1 1 1       1 0 0 1

			tab[0][1] = 0;
			tab[1][2] = 0;

			int** rotatedMatrix = chapter_1.Exercise_8_ZeroMatrix(tab, m, n);

			Assert::AreEqual(0, rotatedMatrix[0][0]);
			Assert::AreEqual(0, rotatedMatrix[0][1]);
			Assert::AreEqual(0, rotatedMatrix[0][2]);
			Assert::AreEqual(0, rotatedMatrix[0][3]);

			Assert::AreEqual(0, rotatedMatrix[1][0]);
			Assert::AreEqual(0, rotatedMatrix[1][1]);
			Assert::AreEqual(0, rotatedMatrix[1][2]);
			Assert::AreEqual(0, rotatedMatrix[1][3]);

			Assert::AreEqual(1, rotatedMatrix[2][0]);
			Assert::AreEqual(0, rotatedMatrix[2][1]);
			Assert::AreEqual(0, rotatedMatrix[2][2]);
			Assert::AreEqual(1, rotatedMatrix[2][3]);
		}
	};

	TEST_CLASS(Exercise_9_StringRotation_TESTS)
	{
		TEST_METHOD(Exercise_9_StringRotation_)
		{
			Assert::IsTrue(chapter_1.Exercise_9_StringRotation("waterbottle", "erbottlewat"));
			Assert::IsFalse(chapter_1.Exercise_9_StringRotation("waterbottle", "erbottlewatx"));
		}
	};
}