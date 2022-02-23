#pragma once

#include "CommonIncludes.h"

#include "MyGraph.h"
#include "MyBinarySearchTree.h"
#include "MyLinkedList.h"

class Chapter_4_TreesAndGraphs
{
public:
	// EXERCISE 1
	bool Exercise_1_RouteBetweenNodes_BFS(MyGraphNode* graph, MyGraphNode* searchedElem);
	bool Exercise_1_RouteBetweenNodes_DFS(MyGraphNode* graph, MyGraphNode* searchedElem);

	// EXERCISE 2
	MyBSTNode* Exercise_2_MinimalTree(int sortedIncreasingArray[], int startIndex, int endIndex);

	// EXERCISE 3
	vector<vector<MyBSTNode*>> Exercise_3_ListOfDepths(MyBSTNode* binaryTree);

	// EXERCISE 4

	// EXERCISE 5

	// EXERCISE 6

	// EXERCISE 7

	// EXERCISE 8

	// EXERCISE 9

	// EXERCISE 10

	// EXERCISE 11

	// EXERCISE 12

	// Helper functions
private:
	bool BFS(MyGraphNode* current, MyGraphNode* searchedElem); // Breadth
	bool DFS(MyGraphNode* current, MyGraphNode* searchedElem); // Depth

	void ResetVisitedBool(MyGraphNode* graph);

	void CheckDepth(vector<vector<MyBSTNode*>>& listOfDepths, MyBSTNode* node, size_t depth);
	

	//bool FixBSTOrdering(MyBSTNode* curr, MyBSTNode* parent);
};

