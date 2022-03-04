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

	TEST_CLASS(Exercise_4_CheckBalanced_TESTS)
	{
		TEST_METHOD(Exercise_4_CheckBalanced_True)
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

			Assert::IsTrue(chapter_4.Exercise_4_CheckBalanced_A(tree));
			Assert::IsTrue(chapter_4.Exercise_4_CheckBalanced_B(tree));
		}

		TEST_METHOD(Exercise_4_CheckBalanced_False)
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

			Assert::IsFalse(chapter_4.Exercise_4_CheckBalanced_A(tree));
			Assert::IsFalse(chapter_4.Exercise_4_CheckBalanced_B(tree));
		}
	};

	TEST_CLASS(Exercise_5_ValidateBST_TESTS)
	{
		TEST_METHOD(Exercise_5_ValidateBST_TrueMinimal)
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

			Assert::IsTrue(chapter_4.Exercise_5_ValidateBST(tree));
		}

		TEST_METHOD(Exercise_5_ValidateBST_FalseMinimal)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   6     4   8    ->   Depth 2: 2, 6, 4, 8
			//   1                         Depth 3: 1

			Assert::IsFalse(chapter_4.Exercise_5_ValidateBST(tree));
		}

		TEST_METHOD(Exercise_5_ValidateBST_TrueSuboptimal)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			MyBSTNode* d1_1 = new MyBSTNode(7);
			MyBSTNode* d1_2 = new MyBSTNode(9);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(6);
			d1_1->left = d2_1;

			MyBSTNode* d3_1 = new MyBSTNode(5);
			d2_1->left = d3_1;

			MyBSTNode* d4_1 = new MyBSTNode(3);
			d3_1->left = d4_1;

			MyBSTNode* d5_1 = new MyBSTNode(2);
			MyBSTNode* d5_2 = new MyBSTNode(4);
			d4_1->left = d5_1;
			d4_1->right = d5_2;

			//            8           Depth 0: 8
			//          7   9         Depth 1: 7, 9
			//        6           ->  Depth 2: 6
			//      5                 Depth 3: 5
			//    3                   Depth 4: 3
			//   2 4                  Depth 5: 2, 4

			Assert::IsTrue(chapter_4.Exercise_5_ValidateBST(tree));
		}

		TEST_METHOD(Exercise_5_ValidateBST_FalseSuboptimal)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			MyBSTNode* d1_1 = new MyBSTNode(7);
			MyBSTNode* d1_2 = new MyBSTNode(9);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(6);
			d1_1->left = d2_1;

			MyBSTNode* d3_1 = new MyBSTNode(5);
			d2_1->left = d3_1;

			MyBSTNode* d4_1 = new MyBSTNode(3);
			d3_1->left = d4_1;

			MyBSTNode* d5_1 = new MyBSTNode(2);
			MyBSTNode* d5_2 = new MyBSTNode(1);
			d4_1->left = d5_1;
			d4_1->right = d5_2;

			//            8           Depth 0: 8
			//          7   9         Depth 1: 7, 9
			//        6           ->  Depth 2: 6
			//      5                 Depth 3: 5
			//    3                   Depth 4: 3
			//   2 1(!)               Depth 5: 2, 1 (!!!!!!!!)

			Assert::IsFalse(chapter_4.Exercise_5_ValidateBST(tree));
		}
	};

	TEST_CLASS(Exercise_6_Successor_TESTS)
	{
		TEST_METHOD(Exercise_6_Successor_NoSuccessor)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;
			d1_1->parent = tree;
			d1_2->parent = tree;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(4);
			d1_1->left = d2_1;
			d1_1->right = d2_2;
			d2_1->parent = d1_1;
			d2_2->parent = d1_1;

			MyBSTNode* d2_3 = new MyBSTNode(6);
			MyBSTNode* d2_4 = new MyBSTNode(8);
			d1_2->left = d2_3;
			d1_2->right = d2_4;
			d2_3->parent = d1_2;
			d2_4->parent = d1_2;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   4     6   8         Depth 2: 2, 4, 6, 8

			Assert::IsNull(chapter_4.Exercise_6_Successor(d2_4));
		}

		TEST_METHOD(Exercise_6_Successor_SingleNode)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			Assert::IsNull(chapter_4.Exercise_6_Successor(tree));
		}

		TEST_METHOD(Exercise_6_Successor_SuccessorIsRightChild)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			MyBSTNode* d1_1 = new MyBSTNode(7);
			MyBSTNode* d1_2 = new MyBSTNode(9);
			tree->left = d1_1;
			tree->right = d1_2;
			d1_1->parent = tree;
			d1_2->parent = tree;

			//            8           Depth 0: 8
			//          7   9         Depth 1: 7, 9

			Assert::AreEqual(d1_2->val, chapter_4.Exercise_6_Successor(tree)->val);
		}

		TEST_METHOD(Exercise_6_Successor_SuccessorIsParent)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			MyBSTNode* d1_1 = new MyBSTNode(7);
			MyBSTNode* d1_2 = new MyBSTNode(9);
			tree->left = d1_1;
			tree->right = d1_2;
			d1_1->parent = tree;
			d1_2->parent = tree;

			//            8           Depth 0: 8
			//          7   9         Depth 1: 7, 9

			Assert::AreEqual(tree->val, chapter_4.Exercise_6_Successor(d1_1)->val);
		}

		TEST_METHOD(Exercise_6_Successor_SuccessorIsRoot)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(6);
			tree->left = d1_1;
			tree->right = d1_2;
			d1_1->parent = tree;
			d1_2->parent = tree;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(4);
			d1_1->left = d2_1;
			d1_1->right = d2_2;
			d2_1->parent = d1_1;
			d2_2->parent = d1_1;

			//            5                Depth 0: 5
			//       3         6           Depth 1: 3, 6
			//     2   4                   Depth 2: 2, 4
			//
			// successor of node 4 is node 5, which is root of the tree

			Assert::AreEqual(tree->val, chapter_4.Exercise_6_Successor(d2_2)->val);
		}

		TEST_METHOD(Exercise_6_Successor_SuccessorIsLeftmostOfRightSubtree)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;
			d1_1->parent = tree;
			d1_2->parent = tree;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(4);
			d1_1->left = d2_1;
			d1_1->right = d2_2;
			d2_1->parent = d1_1;
			d2_2->parent = d1_1;

			MyBSTNode* d2_3 = new MyBSTNode(6);
			MyBSTNode* d2_4 = new MyBSTNode(8);
			d1_2->left = d2_3;
			d1_2->right = d2_4;
			d2_3->parent = d1_2;
			d2_4->parent = d1_2;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   4     6   8         Depth 2: 2, 4, 6, 8
			//
			// successor of node 5 is node 6, which is leftmost of right subtree

			Assert::AreEqual(d2_3->val, chapter_4.Exercise_6_Successor(tree)->val);
		}
	};

	TEST_CLASS(Exercise_7_BuildOrder_TESTS)
	{
		TEST_METHOD(Exercise_7_BuildOrder_Simple)
		{
			Ex7_Project* a = new Ex7_Project('a');
			Ex7_Project* b = new Ex7_Project('b');
			Ex7_Project* c = new Ex7_Project('c');
			Ex7_Project* d = new Ex7_Project('d');
			Ex7_Project* e = new Ex7_Project('e');
			Ex7_Project* f = new Ex7_Project('f');

			d->dependencies.push_back(a);
			b->dependencies.push_back(f);
			d->dependencies.push_back(b);
			a->dependencies.push_back(f);
			c->dependencies.push_back(d);

			vector<Ex7_Project*> projects{ a, b, c, d, e, f };

			Assert::AreEqual((string)"fabdce", chapter_4.Exercise_7_BuildOrder(projects));
		}

		TEST_METHOD(Exercise_7_BuildOrder_False)
		{
			Ex7_Project* a = new Ex7_Project('a');
			Ex7_Project* b = new Ex7_Project('b');
			Ex7_Project* c = new Ex7_Project('c');
			Ex7_Project* d = new Ex7_Project('d');
			Ex7_Project* e = new Ex7_Project('e');
			Ex7_Project* f = new Ex7_Project('f');

			d->dependencies.push_back(a);
			b->dependencies.push_back(f);
			d->dependencies.push_back(b);
			a->dependencies.push_back(f);
			f->dependencies.push_back(b);
			c->dependencies.push_back(d);

			vector<Ex7_Project*> projects{ a, b, c, d, e, f };

			Assert::AreEqual((string)"!!ERROR!!", chapter_4.Exercise_7_BuildOrder(projects));
		}

		TEST_METHOD(Exercise_7_BuildOrder_NoDependencies)
		{
			Ex7_Project* a = new Ex7_Project('a');
			Ex7_Project* b = new Ex7_Project('b');
			Ex7_Project* c = new Ex7_Project('c');
			Ex7_Project* d = new Ex7_Project('d');
			Ex7_Project* e = new Ex7_Project('e');
			Ex7_Project* f = new Ex7_Project('f');

			vector<Ex7_Project*> projects{ a, b, c, d, e, f };

			Assert::AreEqual((string)"abcdef", chapter_4.Exercise_7_BuildOrder(projects));
		}

		TEST_METHOD(Exercise_7_BuildOrder_NoImmediateFollowNode)
		{
			Ex7_Project* a = new Ex7_Project('a');
			Ex7_Project* b = new Ex7_Project('b');
			Ex7_Project* c = new Ex7_Project('c');
			Ex7_Project* d = new Ex7_Project('d');
			Ex7_Project* e = new Ex7_Project('e');
			Ex7_Project* f = new Ex7_Project('f');

			d->dependencies.push_back(a);
			d->dependencies.push_back(b);
			a->dependencies.push_back(f);
			f->dependencies.push_back(b);
			c->dependencies.push_back(d);

			// in this case, to build a we need f, and to build f we need b

			vector<Ex7_Project*> projects{ a, b, c, d, e, f };

			Assert::AreEqual((string)"bfadce", chapter_4.Exercise_7_BuildOrder(projects));
		}
	};

	TEST_CLASS(Exercise_8_FirstCommonAncestor_TESTS)
	{
		TEST_METHOD(Exercise_8_FirstCommonAncestor_Simple)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2  (6)    4   8    ->   Depth 2: 2, 6, 4, 8
			//  (1)                        Depth 3: 1

			MyBSTNode* result = chapter_4.Exercise_8_FirstCommonAncestor(tree, d3_1, d2_2);
			
			Assert::IsNotNull(result);
			Assert::AreEqual(d1_1->val, result->val);
		}

		TEST_METHOD(Exercise_8_FirstCommonAncestor_NoCommonAncestor)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//           (5)               Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2  (6)    4   8    ->   Depth 2: 2, 6, 4, 8
			//   1                         Depth 3: 1

			MyBSTNode* result = chapter_4.Exercise_8_FirstCommonAncestor(tree, tree, d2_2);

			Assert::IsNull(result);
		}

		TEST_METHOD(Exercise_8_FirstCommonAncestor_NodesInSameSubtree)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3        (7)          Depth 1: 3, 7
			//     2   6    (4)  8    ->   Depth 2: 2, 6, 4, 8
			//   1                         Depth 3: 1

			MyBSTNode* result = chapter_4.Exercise_8_FirstCommonAncestor(tree, d1_2, d2_3);

			Assert::IsNotNull(result);
			Assert::AreEqual(tree->val, result->val);
		}

		TEST_METHOD(Exercise_8_FirstCommonAncestor_UnbalancedTree)
		{
			MyBSTNode* tree = new MyBSTNode(8);

			MyBSTNode* d1_1 = new MyBSTNode(7);
			MyBSTNode* d1_2 = new MyBSTNode(9);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(6);
			d1_1->left = d2_1;

			MyBSTNode* d3_1 = new MyBSTNode(5);
			d2_1->left = d3_1;

			MyBSTNode* d4_1 = new MyBSTNode(3);
			d3_1->left = d4_1;

			MyBSTNode* d5_1 = new MyBSTNode(2);
			MyBSTNode* d5_2 = new MyBSTNode(1);
			d4_1->left = d5_1;
			d4_1->right = d5_2;

			//            8           Depth 0: 8
			//          7   9         Depth 1: 7, 9
			//        6           ->  Depth 2: 6
			//     (5)                Depth 3: 5
			//   (3)                  Depth 4: 3
			//   2 1                  Depth 5: 2, 1

			MyBSTNode* result = chapter_4.Exercise_8_FirstCommonAncestor(tree, d3_1, d4_1);

			Assert::IsNotNull(result);
			Assert::AreEqual(d2_1->val, result->val);
		}
	};

	TEST_CLASS(Exercise_9_BSTSequences_TESTS)
	{
		TEST_METHOD(Exercise_9_BSTSequences_Simple) // not fully correct, weaving required
		{
			MyBSTNode* tree = new MyBSTNode(2);

			MyBSTNode* d1_1 = new MyBSTNode(1);
			MyBSTNode* d1_2 = new MyBSTNode(3);
			tree->left = d1_1;
			tree->right = d1_2;

			vector<string> results = chapter_4.Exercise_9_BSTSequences(tree);

			Assert::AreEqual((size_t)2, results.size());
			Assert::AreEqual((string)"2 1 3", results[0]);
			Assert::AreEqual((string)"2 3 1", results[1]);
		}

		TEST_METHOD(Exercise_9_BSTSequences_Medium) // not fully correct, weaving required
		{
			MyBSTNode* tree = new MyBSTNode(4);

			MyBSTNode* d1_1 = new MyBSTNode(2);
			MyBSTNode* d1_2 = new MyBSTNode(6);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(1);
			MyBSTNode* d2_2 = new MyBSTNode(3);
			MyBSTNode* d2_3 = new MyBSTNode(5);
			MyBSTNode* d2_4 = new MyBSTNode(7);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			vector<string> results = chapter_4.Exercise_9_BSTSequences(tree);

			Assert::AreEqual((size_t)8, results.size());
			Assert::AreEqual((string)"4 2 1 3 6 5 7", results[0]);
			Assert::AreEqual((string)"4 6 7 5 2 3 1", results[7]);
		}

		/*TEST_METHOD(Exercise_9_BSTSequences_ExampleFromBook)
		{
			MyBSTNode* tree = new MyBSTNode(50);

			MyBSTNode* d20 = new MyBSTNode(20);
			MyBSTNode* d60 = new MyBSTNode(60);
			tree->left = d20;
			tree->right = d60;

			MyBSTNode* d10 = new MyBSTNode(10);
			MyBSTNode* d25 = new MyBSTNode(25);

			MyBSTNode* d70 = new MyBSTNode(70);

			d20->left = d10;
			d20->right = d25;

			d60->right = d70;

			MyBSTNode* d5 = new MyBSTNode(5);
			MyBSTNode* d15 = new MyBSTNode(15);

			d10->left = d5;
			d10->right = d15;

			MyBSTNode* d65 = new MyBSTNode(65);
			MyBSTNode* d80 = new MyBSTNode(80);

			d70->left = d65;
			d70->right = d80;
		}*/
	};

	TEST_CLASS(Exercise_10_CheckSubtree_TESTS)
	{
		TEST_METHOD(Exercise_10_CheckSubtree_True)
		{
			MyBSTNode* tree1 = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree1->left = d1_1;
			tree1->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   6     4   8    ->   Depth 2: 2, 6, 4, 8
			//   1                         Depth 3: 1

			MyBSTNode* tree2 = new MyBSTNode(3);

			MyBSTNode* dd1_1 = new MyBSTNode(2);
			MyBSTNode* dd1_2 = new MyBSTNode(6);
			tree2->left = dd1_1;
			tree2->right = dd1_2;

			MyBSTNode* dd2_1 = new MyBSTNode(1);
			dd1_1->left = dd2_1;

			//      3
			//   2     6
			// 1

			Assert::IsTrue(chapter_4.Exercise_10_CheckSubtree(tree1, tree2));
		}

		TEST_METHOD(Exercise_10_CheckSubtree_False)
		{
			MyBSTNode* tree1 = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree1->left = d1_1;
			tree1->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(6);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(8);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(1);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   6     4   8    ->   Depth 2: 2, 6, 4, 8
			//   1                         Depth 3: 1

			MyBSTNode* tree2 = new MyBSTNode(3);

			MyBSTNode* dd1_1 = new MyBSTNode(2);
			MyBSTNode* dd1_2 = new MyBSTNode(6);
			tree2->left = dd1_1;
			tree2->right = dd1_2;

			//       3
			//   2       6
			//     1

			MyBSTNode* dd2_1 = new MyBSTNode(1);
			dd1_1->right = dd2_1;

			Assert::IsFalse(chapter_4.Exercise_10_CheckSubtree(tree1, tree2));
		}
	};

	TEST_CLASS(Exercise_11_RandomBinaryTree_TESTS)
	{
		TEST_METHOD(Exercise_11_RandomBinaryTree_)
		{
			RandomBinaryTree rbt;
			rbt.Insert(3);
			rbt.Insert(1);
			rbt.Insert(2);
			rbt.Insert(5);
			rbt.Insert(7);
			rbt.Insert(15);
			rbt.Insert(-2);
			rbt.Insert(6);
			rbt.Insert(4);

			Assert::AreEqual(2, rbt.GetRandomNode(3)->val);
			Assert::AreEqual(4, rbt.GetRandomNode(5)->val);
			Assert::AreEqual(7, rbt.GetRandomNode(8)->val);
		}
	};

	TEST_CLASS(Exercise_12_PathsWithSum_TESTS)
	{
		TEST_METHOD(Exercise_12_PathsWithSum_onlyTwoElemPaths)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(5);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(1);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(6);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   5     4   1    ->   Depth 2: 2, 6, 4, 8
			//   6                         Depth 3: 1

			// Looking for paths of sum 8
			// 
			//            5
			//	        /(1)
			//        3        7
			//          \(2)     \(3)
			//     2     5   4     1
			//    /(4)
			//   6

			Assert::AreEqual(4, chapter_4.Exercise_12_PathsWithSum(tree, 8));
		}

		TEST_METHOD(Exercise_12_PathsWithSum_threeElemPath)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(3);
			MyBSTNode* d1_2 = new MyBSTNode(7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(5);
			MyBSTNode* d2_3 = new MyBSTNode(4);
			MyBSTNode* d2_4 = new MyBSTNode(1);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(6);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//       3         7           Depth 1: 3, 7
			//     2   5     4   1    ->   Depth 2: 2, 6, 4, 8
			//   6                         Depth 3: 1

			// Looking for paths of sum 11
			// 
			//            5
			//        3        7
			//      /(1)      /(2)
			//     2     5   4     1
			//    /(1)
			//   6

			Assert::AreEqual(2, chapter_4.Exercise_12_PathsWithSum(tree, 11));
		}

		TEST_METHOD(Exercise_12_PathsWithSum_negativeValues)
		{
			MyBSTNode* tree = new MyBSTNode(5);

			MyBSTNode* d1_1 = new MyBSTNode(-3);
			MyBSTNode* d1_2 = new MyBSTNode(-7);
			tree->left = d1_1;
			tree->right = d1_2;

			MyBSTNode* d2_1 = new MyBSTNode(2);
			MyBSTNode* d2_2 = new MyBSTNode(-1);
			MyBSTNode* d2_3 = new MyBSTNode(3);
			MyBSTNode* d2_4 = new MyBSTNode(1);

			d1_1->left = d2_1;
			d1_1->right = d2_2;

			d1_2->left = d2_3;
			d1_2->right = d2_4;

			MyBSTNode* d3_1 = new MyBSTNode(-3);
			d2_1->left = d3_1;

			//            5                Depth 0: 5
			//      -3        -7           Depth 1: 3, 7
			//     2  -1    3   1    ->   Depth 2: 2, 6, 4, 8
			//  -3                         Depth 3: 1

			// Looking for paths of sum 1
			// 
			//            5
			//         /(1)  \(2)
			//       -3       -7
			//         \(1)  /(2)
			//     2    -1   3     1
			//    /(3)
			//  -3

			Assert::AreEqual(3, chapter_4.Exercise_12_PathsWithSum(tree, 1));
		}
	};
}