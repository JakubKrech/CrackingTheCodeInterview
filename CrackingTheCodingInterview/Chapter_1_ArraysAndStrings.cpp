#include "Chapter_1_ArraysAndStrings.h"

// EXERCISE 1

bool Chapter_1_ArraysAndStrings::Exercise_1_IsUnique_A(string text)
{
	// Implement and algorithm to determine if a string has all unique characters.
	// What if you cannot use additional data structures?

	// TIP: Instead of hash map, vector of bools can be used. Mark elements that
	// correspond to characters number in f.e. ASCII set as true.

	// Approach that uses data structures:

	map<char, int> characters;
	bool isUnique = true;

	for (auto& c : text)
	{
		if (characters.find(c) != characters.end())
		{
			isUnique = false;
			break;
		}

		characters[c] = 1;
	}

	return isUnique;
}

bool Chapter_1_ArraysAndStrings::Exercise_1_IsUnique_B(string text)
{
	// Implement and algorithm to determine if a string has all unique characters.
	// What if you cannot use additional data structures?

	// TIP: Instead of hash map, vector of bools can be used. Mark elements that
	// correspond to characters number in f.e. ASCII set as true.

	// Approach that does not use data structures:

	bool isUnique = true;

	for (auto current = 0; current + 1 < text.length(); ++current)
	{
		for (auto compared = current + 1; compared < text.length(); ++compared)
		{
			if (text[current] == text[compared])
			{
				return false;
			}
		}
	}

	return isUnique;
}

// EXERCISE 2

bool Chapter_1_ArraysAndStrings::Exercise_2_CheckPermutation(string one, string two)
{
	// Given two strings, write a method to decide if one is permutation of the other
	// permutation - rearrangement of all elements
	//
	// Time complexity: O(n + n + n) = O(n), where n is strings length

	if (one.length() != two.length())
		return false;

	map<char, int> counter;

	for (const auto& character : one)
	{
		counter[character] += 1;
	}

	for (const auto& character : two)
	{
		counter[character] -= 1;
	}

	for (const auto& elem : counter)
	{
		if (elem.second != 0)
			return false;
	}

	return true;
}

// EXERCISE 3

string Chapter_1_ArraysAndStrings::Exercise_3_URLify_A(string str, int trueLength)
{
	// Replace all spaces in a string with '%20'. Assume that the string
	// has sufficient space at the end to hold the additional characters
	// and you are given true length of the string

	// Approach that uses additional string

	char* charArr = new char[str.length() + 1]{}; // leave one more slot for '\0'
	int arrIndex = 0;

	for (size_t strIndex = 0; strIndex < trueLength; ++strIndex)
	{
		cout << ">" << str[strIndex] << "<" << endl;
		if (str[strIndex] != ' ')
		{
			charArr[arrIndex] = str[strIndex];
			arrIndex += 1;
		}
		else
		{
			charArr[arrIndex] = '%';
			charArr[arrIndex + 1] = '2';
			charArr[arrIndex + 2] = '0';
			arrIndex += 3;
		}
	}

	return string(charArr);
}

string Chapter_1_ArraysAndStrings::Exercise_3_URLify_B(string& str, int trueLength)
{
	// Replace all spaces in a string with '%20'. Assume that the string
	// has sufficient space at the end to hold the additional characters
	// and you are given true length of the string

	// Approach that does not use additional string, instead modifies from the back!

	int backCounter = str.length() - 1;
	int trueCounter = trueLength - 1;

	for (; trueCounter >= 0; --trueCounter)
	{
		cout << str[trueCounter] << endl;
		if (str[trueCounter] != ' ')
		{
			str[backCounter] = str[trueCounter];
			backCounter -= 1;
		}
		else
		{
			str[backCounter] = '0';
			str[backCounter - 1] = '2';
			str[backCounter - 2] = '%';
			backCounter -= 3;
		}
	}

	return str;
}