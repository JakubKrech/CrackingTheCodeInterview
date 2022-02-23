#include "Chapter_4_TreesAndGraphs.h"

// EXERCISE 1
// BFS is better for finding shortest path, as it checks every closest possibility before going further away
// DFS is better in situations, when visiting every node will be required anyway, since it is a bit simpler

bool Chapter_4_TreesAndGraphs::Exercise_1_RouteBetweenNodes_BFS(MyGraphNode* node1, MyGraphNode* node2)
{
	ResetVisitedBool(node1);
	bool result = BFS(node1, node2);
	ResetVisitedBool(node1);
	result |= BFS(node2, node1);

	return result;
}

bool Chapter_4_TreesAndGraphs::Exercise_1_RouteBetweenNodes_DFS(MyGraphNode* node1, MyGraphNode* node2)
{
	ResetVisitedBool(node1);
	bool result = DFS(node1, node2);
	ResetVisitedBool(node1);
	result |= DFS(node2, node1);

	return result;
}

// EXERCISE 2
// Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a BST with minimal height

MyBSTNode* Chapter_4_TreesAndGraphs::Exercise_2_MinimalTree(int sortedIncreasingArray[], int startIndex, int endIndex)
{
	int middleIndex = (int)(ceil((double)(endIndex - startIndex) / 2)) + startIndex;

	MyBSTNode* node = new MyBSTNode(sortedIncreasingArray[middleIndex]);

	if (startIndex < middleIndex)
		node->left = Exercise_2_MinimalTree(sortedIncreasingArray, startIndex, middleIndex - 1);

	if (endIndex > middleIndex)
		node->right = Exercise_2_MinimalTree(sortedIncreasingArray, middleIndex + 1, endIndex);

	return node;
}

// EXERCISE 3

vector<vector<MyBSTNode*>> Chapter_4_TreesAndGraphs::Exercise_3_ListOfDepths(MyBSTNode* binaryTree)
{
	vector<vector<MyBSTNode*>> listOfDepths;

	if (!binaryTree)
		return listOfDepths;

	CheckDepth(listOfDepths, binaryTree, 0);

	return listOfDepths;
}

void Chapter_4_TreesAndGraphs::CheckDepth(vector<vector<MyBSTNode*>>& listOfDepths, MyBSTNode* node, size_t depth)
{
	if (!node)
		return;

	if (listOfDepths.size() <= depth)
	{
		listOfDepths.push_back(vector<MyBSTNode*>());
	}
		
	listOfDepths[depth].push_back(node);

	if (node->left != nullptr)
		CheckDepth(listOfDepths, node->left, depth + 1);

	if (node->right != nullptr)
		CheckDepth(listOfDepths, node->right, depth + 1);
}

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

bool Chapter_4_TreesAndGraphs::BFS(MyGraphNode* current, MyGraphNode* searchedElem)
{
	if (!current || !searchedElem)
		return false;

	queue<MyGraphNode*> nodesQueue;
	nodesQueue.push(current);

	while (!nodesQueue.empty())
	{
		MyGraphNode* curr = nodesQueue.front();
		nodesQueue.pop();
		curr->visited = true;

		if (curr == searchedElem)
		{
			return true;
		}
		else
		{
			for (auto& child : curr->children)
			{
				if (!child->visited)
					nodesQueue.push(child);
			}
		}
	}

	return false;
}

bool Chapter_4_TreesAndGraphs::DFS(MyGraphNode* current, MyGraphNode* searchedElem)
{
	if (!current || !searchedElem)
		return false;

	if (current == searchedElem)
		return true;
	else
	{
		current->visited = true;

		for (MyGraphNode* child : current->children)
		{
			if (!child->visited)
			{
				bool found = DFS(child, searchedElem);
				if (found)
					return true;
			}
		}
	}

	return false;
}

void Chapter_4_TreesAndGraphs::ResetVisitedBool(MyGraphNode* graph)
{
	graph->visited = false;

	for (MyGraphNode* child : graph->children)
	{
		if (child->visited == true)
		{
			ResetVisitedBool(child);
		}
	}
}

