#include "Chapter_4_TreesAndGraphs.h"

/////////////////// EXERCISE 1 ///////////////////
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

/////////////////// EXERCISE 2 ///////////////////
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

/////////////////// EXERCISE 3 ///////////////////

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

/////////////////// EXERCISE 4 ///////////////////

bool Chapter_4_TreesAndGraphs::Exercise_4_CheckBalanced_A(MyBSTNode* tree)
{
	if (!tree)
		return false;

	queue<MyBSTNode*> nodes;
	nodes.push(tree);

	while (!nodes.empty())
	{
		MyBSTNode* curr = nodes.front();
		nodes.pop();

		int leftSubtreeHeight = curr->subtreeHeight;
		int rightSubtreeHeight = curr->subtreeHeight;

		if (curr->left)
		{
			nodes.push(curr->left);

			if (curr->left->subtreeHeight == -1)
			{
				curr->left->subtreeHeight = CheckSubtreeHeight_A(curr->left, 1);
			}
			leftSubtreeHeight = curr->left->subtreeHeight;
		}

		if (curr->right)
		{
			nodes.push(curr->right);

			if (curr->right->subtreeHeight == -1)
			{
				curr->right->subtreeHeight = CheckSubtreeHeight_A(curr->right, 1);
			}
			rightSubtreeHeight = curr->right->subtreeHeight;
		}
			
		if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
			return false;
	}

	return true;
}

int Chapter_4_TreesAndGraphs::CheckSubtreeHeight_A(MyBSTNode* node, int depth)
{
	if (!node)
		return depth;

	int leftSubtreeHeight = depth;
	int rightSubtreeHeight = depth;

	if (node->left)
		leftSubtreeHeight = CheckSubtreeHeight_A(node->left, depth + 1);

	if (node->right)
		rightSubtreeHeight = CheckSubtreeHeight_A(node->right, depth + 1);

	node->subtreeHeight = max(leftSubtreeHeight, rightSubtreeHeight);

	return node->subtreeHeight;
}


bool Chapter_4_TreesAndGraphs::Exercise_4_CheckBalanced_B(MyBSTNode* tree)
{
	if (!tree)
		return false;

	return CheckSubtreeHeight_B(tree) != INT_MIN;
}

int Chapter_4_TreesAndGraphs::CheckSubtreeHeight_B(MyBSTNode* node)
{
	if (!node)
		return -1;

	int leftSubtreeHeight = CheckSubtreeHeight_B(node->left);
	if (leftSubtreeHeight == INT_MIN) return INT_MIN;  // pass error value

	int rightSubtreeHeight = CheckSubtreeHeight_B(node->right);
	if (rightSubtreeHeight == INT_MIN) return INT_MIN; // pass error value

	if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
		return INT_MIN;

	return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

/////////////////// EXERCISE 5 ///////////////////

bool Chapter_4_TreesAndGraphs::Exercise_5_ValidateBST(MyBSTNode* tree)
{
	return ComputeMinMaxSubtreeValues(tree);
}

bool Chapter_4_TreesAndGraphs::ComputeMinMaxSubtreeValues(MyBSTNode* node)
{
	if (!node)
		return true;

	if (node->left != nullptr)
	{
		if (!ComputeMinMaxSubtreeValues(node->left))
			return false;

		if (node->val < node->left->val || node->val < node->left->maxSubtreeValue)
			return false;

		node->minSubtreeValue = min(node->val, node->left->minSubtreeValue);
	}
	else
	{
		node->minSubtreeValue = node->val;
	}

	if (node->right != nullptr)
	{
		if (!ComputeMinMaxSubtreeValues(node->right))
			return false;

		if (node->val >= node->right->val || node->val >= node->right->minSubtreeValue)
			return false;

		node->maxSubtreeValue = max(node->val, node->right->minSubtreeValue);
	}
	else
	{
		node->maxSubtreeValue = node->val;
	}
	
	return true;
}

/////////////////// EXERCISE 6 ///////////////////

MyBSTNode* Chapter_4_TreesAndGraphs::Exercise_6_Successor(MyBSTNode* node)
{
	if (node->right == nullptr && node->parent == nullptr)
		return nullptr;

	// successor is usually leftmost grandchild of right child

	if (node->right)
	{
		node = node->right;

		while (node->left)
			node = node->left;

		return node;
	}
	else if (node->parent)
	{
		if (node == node->parent->left)
		{
			return node->parent;
		}
		else
		{
			while (node->parent)
			{
				if (node == node->parent->left)
					return node->parent;
				node = node->parent;
			}
		}
	}
	
	return nullptr;
}

/////////////////// EXERCISE 7 ///////////////////

string Chapter_4_TreesAndGraphs::Exercise_7_BuildOrder(vector<Ex7_Project*> projects)
{
	string buildHistory = "";

	for (auto& project : projects)
	{
		if (project->built != PROJECT_STATE::BUILT)
		{
			project->built = PROJECT_STATE::PENDING;
			if (!BuildProject(project, buildHistory))
			{
				return "!!ERROR!!";
			}
		}
	}

	return buildHistory;
}

bool Chapter_4_TreesAndGraphs::BuildProject(Ex7_Project* project, string& buildHistory)
{
	cout << "BUILDING: " << project->name << endl;
	for (auto& dependency : project->dependencies)
	{
		if (dependency->built == PROJECT_STATE::PENDING)
			return false;

		if (dependency->built != PROJECT_STATE::BUILT)
		{
			dependency->built = PROJECT_STATE::PENDING;
			if (!BuildProject(dependency, buildHistory))
			{
				return false;
			}
		}
	}

	buildHistory += project->name;
	project->built = PROJECT_STATE::BUILT;

	return true;
}

/////////////////// EXERCISE 8 ///////////////////

MyBSTNode* Chapter_4_TreesAndGraphs::Exercise_8_FirstCommonAncestor(
	MyBSTNode* tree, MyBSTNode* node1, MyBSTNode* node2)
{
	if (tree == node1 || tree == node2 || node1 == node2 || !node1 || !node2 || !tree)
		return nullptr;

	MyBSTNode* curr = tree;

	while (curr)
	{
		bool n1 = false;
		bool n2 = false;

		DFS_SearchForNodes(curr->left, node1, node2, n1, n2);

		if (n1 != n2)
			return curr;
		else if (n1 && n2)
		{
			if (curr->left == node1 || curr->left == node2)
				return curr;

			curr = curr->left;
		}
		else if (!n1 && !n2)
		{
			if (curr->right == node1 || curr->right == node2)
				return curr;

			curr = curr->right;
		}
	}

	return nullptr;
}

void Chapter_4_TreesAndGraphs::DFS_SearchForNodes(MyBSTNode* tree,
	MyBSTNode* node1, MyBSTNode* node2, bool& n1, bool& n2)
{
	if (!tree)
		return;

	cout << tree->val << endl;

	DFS_SearchForNodes(tree->left, node1, node2, n1, n2);

	if (tree->val == node1->val)
		n1 = true;

	if (tree->val == node2->val)
		n2 = true;

	DFS_SearchForNodes(tree->right, node1, node2, n1, n2);
}

/////////////////// EXERCISE 9 ///////////////////

vector<string> Chapter_4_TreesAndGraphs::Exercise_9_BSTSequences(MyBSTNode* tree)
{
	if (!tree)
		return vector<string>();

	vector<string> results;

	vector<string> leftResult = Exercise_9_BSTSequences(tree->left);
	vector<string> rightResult = Exercise_9_BSTSequences(tree->right);

	if (leftResult.empty() && !rightResult.empty())
		results.push_back(to_string(tree->val) + " " + rightResult[0]);
	else if(!leftResult.empty() && rightResult.empty())
		results.push_back(to_string(tree->val) + " " + leftResult[0]);
	else if(!leftResult.empty() && !rightResult.empty())
	{
		for (auto i = 0; i < leftResult.size(); ++i)
		{
			for (auto j = 0; j < rightResult.size(); ++j)
			{
				results.push_back(to_string(tree->val) + " " + leftResult[i] + " " + rightResult[j]);
				results.push_back(to_string(tree->val) + " " + rightResult[j] + " " + leftResult[i]);
			}
		}
	}
	else
	{
		results.push_back(to_string(tree->val));
	}


	cout << " >>>>>>>>>>> Called for: " << tree->val << endl;

	for (auto& x : results)
	{
		cout << x << endl;
	}

	return results;
}

/////////////////// EXERCISE 10 //////////////////

bool Chapter_4_TreesAndGraphs::Exercise_10_CheckSubtree(MyBSTNode* tree1, MyBSTNode* tree2)
{
	if (!tree1)
		return false;

	cout << "CHECKING: " << tree1->val << endl;

	if (tree1->val == tree2->val)
	{
		cout << "EQUAL TO TREE2 ROOT!" << endl;
		bool result = CompareTwoSubtrees(tree1, tree2);
		if (result)
			return true;
	}

	if(Exercise_10_CheckSubtree(tree1->left, tree2))
		return true;

	if (Exercise_10_CheckSubtree(tree1->right, tree2))
		return true;

	return false;
}

bool Chapter_4_TreesAndGraphs::CompareTwoSubtrees(MyBSTNode* tree1, MyBSTNode* tree2)
{
	if (!tree1 && !tree2)
	{
		return true;
	}

	if (!tree1 && tree2 || tree1 && !tree2)
	{
		return false;
	}

	if (tree1->val != tree2->val)
	{
		return false;
	}

	if(!CompareTwoSubtrees(tree1->left, tree2->left))
	{
		return false;
	}

	if (!CompareTwoSubtrees(tree1->right, tree2->right))
	{
		return false;
	}

	return true;
}

/////////////////// EXERCISE 11 //////////////////

// class RandomNode;
// class RandomBinaryTree;

/////////////////// EXERCISE 12 //////////////////

int Chapter_4_TreesAndGraphs::Exercise_12_PathsWithSum(MyBSTNode* tree, int targetSum)
{
	vector<int> sums;
	int pathsWithSum = 0;

	DFSTreeAndCountPathSums(tree, sums, targetSum, pathsWithSum);

	return pathsWithSum;
}

void Chapter_4_TreesAndGraphs::DFSTreeAndCountPathSums(MyBSTNode* tree, vector<int> prevSums,
	int targetSum, int& pathsWithSum)
{
	if (!tree)
		return;

	// travers pre order style
	vector<int> sums;
	sums.push_back(tree->val);

	for (auto& prevSum : prevSums)
	{
		int newSum = prevSum + tree->val;
		sums.push_back(newSum);
		
		if (newSum == targetSum)
			pathsWithSum += 1;
	}
	
	DFSTreeAndCountPathSums(tree->left, sums, targetSum, pathsWithSum);
	DFSTreeAndCountPathSums(tree->right, sums, targetSum, pathsWithSum);
}

// Helper functions



