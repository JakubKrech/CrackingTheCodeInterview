#pragma once

#include "CommonIncludes.h"

class Chapter_1_ArraysAndStrings
{
public:

	// EXERCISE 1 - Sometimes instead of hash map, vector of bools can be used. Mark elements that
    //              correspond to characters number in f.e. ASCII to check if they already occured.
	bool Exercise_1_IsUnique_A(string text);
	bool Exercise_1_IsUnique_B(string text);

	// EXERCISE 2 - Permutation is a rearrangement of all elements.
	bool Exercise_2_CheckPermutation(string one, string two);

	// EXERCISE 3 - Its often usefull to modify string from the back, this way it can be done in place!
	string Exercise_3_URLify_A(string str, int trueLength);
	string Exercise_3_URLify_B(string& str, int trueLength);

	// EXERCISE 4
    bool Exercise_4_PalindromePermutation(string str);

	// EXERCISE 5
	bool Exercise_5_OneAway(string s1, string s2);

	// EXERCISE 6
	string Exercise_6_StringCompression(string str);

	// EXERCISE 7 - TODO
	int** Exercise_7_RotateMatrix(int** tab, int n);

	// EXERCISE 8 - first row and column can be used to store info about zero's locations,
	//              this adds up some coding, but reduces Space complexity to O(1).
	int** Exercise_8_ZeroMatrix(int** tab, int m, int n);

	// EXERCISE 9 - to check if one string is rotation of another, we can check if s2 is substring of s1 + s1
	bool Exercise_9_StringRotation(string s1, string s2);



	// Helper functions
	bool Ex6_AppendCharCountToResult(char* result, int strLength, size_t& resultIndex, char c, int counter);
	bool Ex9_IsSubstring(string s1, string s2);
};

