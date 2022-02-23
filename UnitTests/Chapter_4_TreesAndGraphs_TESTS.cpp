#include "pch.h"
#include "CppUnitTest.h"

#include "../CrackingTheCodingInterview/CommonIncludes.h"

#include "../CrackingTheCodingInterview/Chapter_4_TreesAndGraphs.h"
#include "../CrackingTheCodingInterview/Chapter_4_TreesAndGraphs.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Chapter_4_TreesAndGraphs_TESTS
{
	Chapter_4_TreesAndGraphs chapter_4;

	TEST_CLASS(Exercise_1_RouteBetweenNodes_TESTS)
	{
		TEST_METHOD(Exercise_1_RouteBetweenNodes_BFS_)
		{
			MyGraphNode* n1 = new MyGraphNode(1);
			MyGraphNode* n2 = new MyGraphNode(2);
			MyGraphNode* n3 = new MyGraphNode(3);
			MyGraphNode* n4 = new MyGraphNode(4);
			MyGraphNode* n5 = new MyGraphNode(5);

			n1->children.push_back(n2);
			n2->children.push_back(n3);
			n2->children.push_back(n4);
			n4->children.push_back(n3);
			n4->children.push_back(n5);

			//           |---> n3
			// n1 -> n2 -      ^
			//           |     |
			//           |---> n4 -> n5

			Assert::IsTrue(chapter_4.Exercise_1_RouteBetweenNodes_BFS(n1, n5));
			Assert::IsTrue(chapter_4.Exercise_1_RouteBetweenNodes_BFS(n5, n1));

			Assert::IsFalse(chapter_4.Exercise_1_RouteBetweenNodes_BFS(n3, n5));
		}

		TEST_METHOD(Exercise_1_RouteBetweenNodes_DFS_)
		{
			MyGraphNode* n1 = new MyGraphNode(1);
			MyGraphNode* n2 = new MyGraphNode(2);
			MyGraphNode* n3 = new MyGraphNode(3);
			MyGraphNode* n4 = new MyGraphNode(4);
			MyGraphNode* n5 = new MyGraphNode(5);

			n1->children.push_back(n2);
			n2->children.push_back(n3);
			n2->children.push_back(n4);
			n4->children.push_back(n3);
			n4->children.push_back(n5);

			//           |---> n3
			// n1 -> n2 -      ^
			//           |     |
			//           |---> n4 -> n5

			Assert::IsTrue(chapter_4.Exercise_1_RouteBetweenNodes_DFS(n1, n5));
			Assert::IsTrue(chapter_4.Exercise_1_RouteBetweenNodes_DFS(n5, n1));

			Assert::IsFalse(chapter_4.Exercise_1_RouteBetweenNodes_DFS(n3, n5));
		}
	};

	TEST_CLASS(Exercise_2_MinimalTree_TESTS)
	{
		TEST_METHOD(Exercise_2_MinimalTree_OddNoOfElements)
		{
			int data[] = { 1, 2, 3, 4, 5, 6, 7 };
			int size = (int)sizeof(data) / sizeof(data[0]);
			MyBSTNode* graph = chapter_4.Exercise_2_MinimalTree(data, 0, size - 1);

			//         4
			//     2       6     Expected result
			//   1   3   5   7

			Assert::IsNotNull(graph);

			Assert::AreEqual(4, graph->val);
			Assert::AreEqual(2, graph->left->val);
			Assert::AreEqual(6, graph->right->val);

			Assert::AreEqual(1, graph->left->left->val);
			Assert::AreEqual(3, graph->left->right->val);

			Assert::AreEqual(5, graph->right->left->val);
			Assert::AreEqual(7, graph->right->right->val);
		}

		TEST_METHOD(Exercise_2_MinimalTree_EvenNoOfElements)
		{
			int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
			int size = (int)sizeof(data) / sizeof(data[0]);
			MyBSTNode* graph = chapter_4.Exercise_2_MinimalTree(data, 0, size - 1);

			//          5
			//      3       7     Expected result
			//    2   4   6   8
			//  1

			Assert::IsNotNull(graph);

			Assert::AreEqual(5, graph->val);
			Assert::AreEqual(3, graph->left->val);
			Assert::AreEqual(7, graph->right->val);

			Assert::AreEqual(2, graph->left->left->val);
			Assert::AreEqual(4, graph->left->right->val);

			Assert::AreEqual(6, graph->right->left->val);
			Assert::AreEqual(8, graph->right->right->val);

			Assert::AreEqual(1, graph->left->left->left->val);
		}
	};

	TEST_CLASS(Exercise_3_ListOfDepths_TESTS)
	{
		TEST_METHOD(Exercise_3_ListOfDepths_OptimalTree)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(4);
			MyBSTNode* d2_3 = new MyBSTNode(6);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;
			
			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   4     6   8    ->   Depth 2: 2, 4, 6, 8
			//   1                         Depth 3: 1

			vector<int> depth_0{ 5 };
			vector<int> depth_1{ 3, 7 };
			vector<int> depth_2{ 2, 4, 6, 8 };
			vector<int> depth_3{ 1 };

			vector<vector<MyBSTNode*>> results = chapter_4.Exercise_3_ListOfDepths(tree);

			Assert::AreEqual(5, results[0][0]->val);

			Assert::AreEqual(3, results[1][0]->val);
			Assert::AreEqual(7, results[1][1]->val);

			Assert::AreEqual(2, results[2][0]->val);
			Assert::AreEqual(4, results[2][1]->val);
			Assert::AreEqual(6, results[2][2]->val);
			Assert::AreEqual(8, results[2][3]->val);

			Assert::AreEqual(1, results[3][0]->val);
		}

		TEST_METHOD(Exercise_3_ListOfDepths_SuboptimalTree)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			d1_1->left = d2_1;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			MyBSTNode* d4_1 = new MyBSTNode(7);
			d3_1->left = d4_1;

			MyBSTNode* d5_1 = new MyBSTNode(9);
			MyBSTNode* d5_2 = new MyBSTNode(8);
			d4_1->left = d5_1;
			d4_1->right = d5_2;

			MyBSTNode* d6_1 = new MyBSTNode(4);
			d5_2->right = d6_1;

			//            5           Depth 0: 5
			//          3   7         Depth 1: 3, 7
			//        2           ->  Depth 2: 2
			//      1                 Depth 3: 1
			//    7                   Depth 4: 7
			//   9 8                  Depth 5: 9, 8
			//      4                 Depth 6: 4

			vector<vector<MyBSTNode*>> results = chapter_4.Exercise_3_ListOfDepths(tree);

			Assert::AreEqual(5, results[0][0]->val);

			Assert::AreEqual(3, results[1][0]->val);
			Assert::AreEqual(7, results[1][1]->val);

			Assert::AreEqual(2, results[2][0]->val);

			Assert::AreEqual(1, results[3][0]->val);

			Assert::AreEqual(7, results[4][0]->val);
			
			Assert::AreEqual(9, results[5][0]->val);
			Assert::AreEqual(8, results[5][1]->val);

			Assert::AreEqual(4, results[6][0]->val);
		}
	};
}