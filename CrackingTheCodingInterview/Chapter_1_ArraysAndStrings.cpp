#include "Chapter_1_ArraysAndStrings.h"

// EXERCISE 1 - Sometimes instead of hash map, vector of bools can be used. Mark elements that
//              correspond to characters number in f.e. ASCII to check if they already occured.

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

	for (size_t current = 0; current + 1 < text.length(); ++current)
	{
		for (size_t compared = current + 1; compared < text.length(); ++compared)
		{
			if (text[current] == text[compared])
			{
				return false;
			}
		}
	}

	return isUnique;
}

// EXERCISE 2 - Permutation is a rearrangement of all elements.

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

// EXERCISE 3 - Its often usefull to modify string from the back, this way it can be done in place!

string Chapter_1_ArraysAndStrings::Exercise_3_URLify_A(string str, int trueLength)
{
	// Replace all spaces in a string with '%20'. Assume that the string
	// has sufficient space at the end to hold the additional characters
	// and you are given true length of the string.

	// Approach that uses additional string.
	// NOTE: String can have additional spaces at the end, and it has to be accounted for.
	// Solution B solves this problem.

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
#pragma warning( push )
#pragma warning(disable:6386)
			charArr[arrIndex] = '%';
			charArr[arrIndex + 1] = '2';
			charArr[arrIndex + 2] = '0';
			arrIndex += 3;
#pragma warning( pop )
		}
	}

	return string(charArr);
}

string Chapter_1_ArraysAndStrings::Exercise_3_URLify_B(string& str, int trueLength)
{
	// Replace all spaces in a string with '%20'. Assume that the string
	// has sufficient space at the end to hold the additional characters
	// and you are given true length of the string (CAN HAVE MORE!).

	// Approach that does not use additional string, instead modifies from the back!

	int ammountOfSpaces = 0;

	for (int i = 0; i < trueLength; ++i)
	{
		if (str[i] == ' ') ammountOfSpaces += 1;
	}

	int backIndex = trueLength - 1 + 2 * ammountOfSpaces;
	int trueIndex = trueLength - 1;

	cout << "SPACES: " << ammountOfSpaces << endl;

	for (; trueIndex >= 0; --trueIndex)
	{
		cout << str[trueIndex] << endl;
		if (str[trueIndex] != ' ')
		{
			str[backIndex] = str[trueIndex];
			backIndex -= 1;
		}
		else
		{
			str[backIndex] = '0';
			str[backIndex - 1] = '2';
			str[backIndex - 2] = '%';
			backIndex -= 3;
		}
	}

	return str;
}

// EXERCISE 4

bool Chapter_1_ArraysAndStrings::Exercise_4_PalindromePermutation(string str)
{
	// TODO: reduce space usage by using bit vector

	map<char, int> charCount;
	int odd_counts = 0;

	for (auto& c : str)
	{
		if (c != ' ')
			charCount[c] += 1;
	}

	for (const auto& count : charCount)
	{
		cout << "'" << count.first << "' " << count.second << endl;
		if (count.second % 2 == 1)
		{
			odd_counts += 1;
		}
	}

	cout << odd_counts << endl;

	return (odd_counts == 0 || odd_counts == 1);
}

// EXERCISE 5

bool Chapter_1_ArraysAndStrings::Exercise_5_OneAway(string s1, string s2)
{
	// Time complexity: O(n) where n is length of string s1
	// Space complexity: O(1)

	if (abs((int)s1.length() - (int)s2.length()) > 1)
		return false;

	size_t s1_idx = 0;
	size_t s2_idx = 0;

	bool charChanged = false;

	while (s1_idx != s1.length() || s2_idx != s2.length())
	{
		if (s1[s1_idx] == s2[s2_idx])
		{
			s1_idx += 1;
			s2_idx += 1;
		}
		else
		{
			if (charChanged)
				return false;
			else
				charChanged = true;

			if (s1[s1_idx + 1] == s2[s2_idx])
			{
				s1_idx += 1;
			}
			else if (s1[s1_idx] == s2[s2_idx + 1])
			{
				s2_idx += 1;
			}
			else if (s1[s1_idx + 1] == s2[s2_idx + 1])
			{
				s1_idx += 1;
				s2_idx += 1;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

// EXERCISE 6

string Chapter_1_ArraysAndStrings::Exercise_6_StringCompression(string str)
{
	size_t strLength = str.length();
	char* result = new char[strLength + 1] {};
	size_t resultIndex = 0;
	size_t strIndex = 0;
	int currentCounter = 1;

	while (strIndex + 1 < strLength)
	{
		if (str[strIndex] == str[strIndex + 1])
		{
			currentCounter += 1;
		}
		else
		{
			if (!Ex6_AppendCharCountToResult(result, strLength, resultIndex, str[strIndex], currentCounter))
			{
				return str;
			}
			currentCounter = 1;
		}
		strIndex += 1;
	}

	// Append last character count
	if (!Ex6_AppendCharCountToResult(result, strLength, resultIndex, str[strIndex], currentCounter))
	{
		return str;
	}

	return string(result);
}

bool Chapter_1_ArraysAndStrings::Ex6_AppendCharCountToResult(char* result,
	size_t strLength, size_t& resultIndex, char c, int counter)
{
	string number = to_string(counter);

	if (resultIndex + 1 + number.length() < strLength)
	{
		result[resultIndex++] = c;

		for (const auto& digit : number)
		{
			if (resultIndex < strLength)
			{
				result[resultIndex++] = digit;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

// EXERCISE 7

int** Chapter_1_ArraysAndStrings::Exercise_7_RotateMatrix(int** tab, int n)
{
	// Ex7_PrintMatrix(tab, n, n);

	int currentMaxRow = n - 1;

	for (int row = 0; row < currentMaxRow; ++row, --currentMaxRow)
	{
		for (int col = row; col < currentMaxRow; ++col)
		{
			int temp = tab[row][col];

			// first swap
			tab[row][col] = tab[n - 1 - col][row];

			// second swap
			tab[n - 1 - col][row] = tab[n - 1 - row][n - 1 - col];

			// third swap
			tab[n - 1 - row][n - 1 - col] = tab[col][n - 1 - row];

			// fourth swap
			tab[col][n - 1 - row] = temp;
		}
	}

	// Ex7_PrintMatrix(tab, n, n);

	return tab;
}

// EXERCISE 8

int** Chapter_1_ArraysAndStrings::Exercise_8_ZeroMatrix(int** tab, int m, int n)
{
	vector<bool> vertical(m, 1);
	vector<bool> horizontal(n, 1);

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!tab[i][j])
			{
				vertical[i] = 0;
				horizontal[j] = 0;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!vertical[i] || !horizontal[j])
			{
				tab[i][j] = 0;
			}
		}
	}

	return tab;
}

// EXERCISE 9

bool Chapter_1_ArraysAndStrings::Exercise_9_StringRotation(string s1, string s2)
{
	size_t len_1 = s1.length();
	size_t len_2 = s2.length();

	if (len_1 != len_2 || len_1 == 0)
		return false;

	string doubled = s1 + s1;

	return Ex9_IsSubstring(doubled, s2);
}

// Helper functions

void Chapter_1_ArraysAndStrings::Ex7_PrintMatrix(int** tab, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Chapter_1_ArraysAndStrings::Ex9_IsSubstring(string s1, string s2)
{
	return s1.find(s2) != string::npos;
}
