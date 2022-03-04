#pragma once

#include "CommonIncludes.h"

#include "MyGraph.h"
#include "MyBinarySearchTree.h"
#include "MyLinkedList.h"

enum class PROJECT_STATE
{
	NOT_BUILD,
	PENDING,
	BUILT
};

class Ex7_Project
{
public:
	char name;
	vector<Ex7_Project*> dependencies;
	PROJECT_STATE built = PROJECT_STATE::NOT_BUILD;

	Ex7_Project(char n) : name(n) {};
};

class Chapter_4_TreesAndGraphs
{
public:
	// EXERCISE 1
	bool Exercise_1_RouteBetweenNodes_BFS(MyGraphNode* graph, MyGraphNode* searchedElem);
	bool Exercise_1_RouteBetweenNodes_DFS(MyGraphNode* graph, MyGraphNode* searchedElem);
	bool BFS(MyGraphNode* current, MyGraphNode* searchedElem); // Breadth
	bool DFS(MyGraphNode* current, MyGraphNode* searchedElem); // Depth
	void ResetVisitedBool(MyGraphNode* graph);

	// EXERCISE 2
	MyBSTNode* Exercise_2_MinimalTree(int sortedIncreasingArray[], int startIndex, int endIndex);

	// EXERCISE 3
	vector<vector<MyBSTNode*>> Exercise_3_ListOfDepths(MyBSTNode* binaryTree);
	void CheckDepth(vector<vector<MyBSTNode*>>& listOfDepths, MyBSTNode* node, size_t depth);

	// EXERCISE 4

	bool Exercise_4_CheckBalanced_A(MyBSTNode* tree);
	int CheckSubtreeHeight_A(MyBSTNode* node, int depth = 0);
	
	bool Exercise_4_CheckBalanced_B(MyBSTNode* tree);
	int CheckSubtreeHeight_B(MyBSTNode* node);

	// EXERCISE 5

	bool Exercise_5_ValidateBST(MyBSTNode* tree);
	bool ComputeMinMaxSubtreeValues(MyBSTNode* node);

	// EXERCISE 6

	MyBSTNode* Exercise_6_Successor(MyBSTNode* tree);

	// EXERCISE 7

	string Exercise_7_BuildOrder(vector<Ex7_Project*> projects);
	bool BuildProject(Ex7_Project* project, string& buildHistory);

	// EXERCISE 8

	MyBSTNode* Exercise_8_FirstCommonAncestor(MyBSTNode* tree, MyBSTNode* node1, MyBSTNode* node2);
	void DFS_SearchForNodes(MyBSTNode* tree, MyBSTNode* node1, MyBSTNode* node2, bool& n1, bool& n2);

	// EXERCISE 9 - needs to be fixed, not totally correct

	vector<string> Exercise_9_BSTSequences(MyBSTNode* tree);

	// EXERCISE 10

	bool Exercise_10_CheckSubtree(MyBSTNode* tree1, MyBSTNode* tree2);
	bool CompareTwoSubtrees(MyBSTNode* tree1, MyBSTNode* tree2);

	// EXERCISE 11

	// class RandomNode;         // defined below
	// class RandomBinaryTree;   // defined below

	// EXERCISE 12

	int Exercise_12_PathsWithSum(MyBSTNode* tree, int targetSum);
	void DFSTreeAndCountPathSums(MyBSTNode* tree, vector<int> sums, int targetSum, int& pathsWithSum);
};

// EXERCISE 11

class RandomNode
{
public:
	int val;
	RandomNode* left = nullptr;
	RandomNode* right = nullptr;

	RandomNode(int v) : val(v) {};
};

class RandomBinaryTree
{
public:
	RandomNode* root = nullptr;
	int size = 0;

	RandomBinaryTree() {};

	void Insert(int v)
	{
		size += 1;
		if (!root)
		{
			root = new RandomNode(v);
			return;
		}

		Insert(root, v);
	}

	void Insert(RandomNode* curr, int v)
	{
		if (v <= curr->val)
		{
			if (curr->left)
				Insert(curr->left, v);
			else
				curr->left = new RandomNode(v);
		}
		else
		{
			if (curr->right)
				Insert(curr->right, v);
			else
				curr->right = new RandomNode(v);
		}
	}

	RandomNode* Find(int v)
	{
		RandomNode* curr = root;

		while (curr->val != v)
		{
			cout << curr->val << " ";

			if (v <= curr->val)
			{
				if (curr->left)
					curr = curr->left;
				else
				{
					cout << "NOT FOUND" << endl;
					return nullptr;
				}
			}
			else
			{
				if (curr->right)
					curr = curr->right;
				else
				{
					cout << "NOT FOUND" << endl;
					return nullptr;
				}
			}
		}

		cout << "FOUND " << curr->val << endl;
		return curr;
	}

	static RandomNode* Delete(RandomNode* root, int val)
	{
		if (root == nullptr)
			return nullptr;

		if (val < root->val)
			root->left = Delete(root->left, val);
		else if(val > root->val)
			root->right = Delete(root->right, val);
		else
		{
			if (!root->left && !root->right)
			{
				return nullptr;
			}
			else if (!root->left)
			{
				RandomNode* temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right)
			{
				RandomNode* temp = root->left;
				delete root;
				return temp;
			}

			cout << (root == nullptr) << " " << (root->right == nullptr) << " " << (root->left == nullptr) << endl;
			
			// node with two children
			RandomNode* smallestSuccessor = root->right;
			while (smallestSuccessor && smallestSuccessor->left)
			{
				smallestSuccessor = smallestSuccessor->left;
			}

			root->val = smallestSuccessor->val;
			root->right = RandomBinaryTree::Delete(root->right, smallestSuccessor->val);
		}
		
		return root;
	}

	RandomNode* GetRandomNode(int n = -1 /*only for test purposes*/)
	{
		int nodeNumber = n == -1 ? GetRandomValue(1, size) : n;
		int currentCounter = 0;

		cout << "GETTING RANDOM NODE OF COUNTER = " << nodeNumber << endl;

		return DFSRandom(root, currentCounter, nodeNumber);
	}

	RandomNode* DFSRandom(RandomNode* curr, int& currentCounter, int expectedCounter)
	{
		if (!curr)
			return nullptr;

		RandomNode* leftResult = DFSRandom(curr->left, currentCounter, expectedCounter);
		if (leftResult != nullptr)
			return leftResult;

		currentCounter += 1;
		if (currentCounter == expectedCounter)
			return curr;

		RandomNode* rightResult = DFSRandom(curr->right, currentCounter, expectedCounter);
		if (rightResult != nullptr)
			return rightResult;

		return nullptr;
	}

	int GetRandomValue(int startValue, int endValue)
	{
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());  // to seed mersenne twister.
		uniform_int_distribution<> dist(startValue, endValue); // distribute results between 1 and 6 inclusive.

		return dist(gen);
	}

	void InOrderPrint()
	{
		InOrderPrint(root);
		cout << endl;
	}

	void InOrderPrint(RandomNode* curr)
	{
		if (!curr)
			return;

		InOrderPrint(curr->left);

		cout << curr->val << " ";

		InOrderPrint(curr->right);
	}
};