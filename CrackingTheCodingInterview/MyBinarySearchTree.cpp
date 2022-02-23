#include "MyBinarySearchTree.h"

void MyBinarySearchTree::Add(int val)
{
	MyBSTNode* newNode = new MyBSTNode(val);
	queue<MyBSTNode*> nodesToVisit;

	if (!root)
	{
		root = newNode;
		return;
	}

	nodesToVisit.push(root);

	while (!nodesToVisit.empty())
	{
		MyBSTNode* curr = nodesToVisit.front();
		nodesToVisit.pop();
		
		if (curr->left == nullptr)
		{
			curr->left = newNode;
			return;
		}
		else
		{
			nodesToVisit.push(curr->left);
		}

		if (curr->right == nullptr)
		{
			curr->right = newNode;
			return;
		}
		else
		{
			nodesToVisit.push(curr->right);
		}
		
	}
}

void MyBinarySearchTree::Print_InOrder(MyBSTNode* curr)
{
	if (!curr)
		return;

	if (curr->left != nullptr)
		Print_InOrder(curr->left);

	Visit(curr);
	
	if (curr->right != nullptr)
		Print_InOrder(curr->right);
}

void MyBinarySearchTree::Print_PreOrder(MyBSTNode* curr)
{
	if (!curr)
		return;

	Visit(curr);

	if (curr->left != nullptr)
		Print_PreOrder(curr->left);

	if (curr->right != nullptr)
		Print_PreOrder(curr->right);
}

void MyBinarySearchTree::Print_PostOrder(MyBSTNode* curr)
{
	if (!curr)
		return;

	if (curr->left != nullptr)
		Print_PostOrder(curr->left);

	if (curr->right != nullptr)
		Print_PostOrder(curr->right);

	Visit(curr);
}

void MyBinarySearchTree::Visit(MyBSTNode* curr)
{
	int leftVal = curr->left ? curr->left->val : -1;
	int rightVal = curr->right ? curr->right->val : -1;

	cout << "val: " << curr->val << ", left: " << leftVal << ", right: " << rightVal << endl;
}
