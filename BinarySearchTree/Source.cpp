/*
  BST ALL FUNCTION TEST CASES
  1) Regula BST (balanced or unbalanced)
  2) Skewed Right BST
  3) Skewed Left BST

*/

#include <iostream>
#include <vector>
#include <list>
#include "BST.h"
#include "Node.h"

using namespace std;

/// <summary>
/// Function to test all operations on binary search tree
/// </summary>
void DoTest()
{
	vector<int> binV = { 100, 200, 300, 400, 500, 600, 50 };
	// = { 100, 200,300,400,500,600,50};
	// = { 600, 300, 900, 150, 450, 120, 320, 750, 1050, 800 };

	// Create BST
	BST* tree = new BST();
	
	
	// Add Nodes in BST
	for (int i = 0; i < binV.size(); i++)
	{
		tree->addNode(binV[i]);
	}

	cout << "Min of left and right" << tree->TestMin(tree->Root()) << endl;
	cout << "Mindepth: " << tree->MinDepth(tree->Root()) << endl;
	cout << "Maxdepth: " << tree->MaxDepth(tree->Root()) << endl;
	if (tree->isBalanced(tree->Root()))
	{
		cout << "The Current BST is Balanced" << endl;
	}
	else
	{
		cout << "The Current BST is not Balanced" << endl;
	}
	//-------------------

	cout << "---------------------------------------------------------------------" << endl;
	// Traverse the tree
	tree->walk(tree->Root());
	cout << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	// Find nodes
	if (tree->findNode(500, tree->Root()))
		cout << "Node 500 found" << endl;
	else
		cout << "Node 500 not found" << endl;

	if (tree->findNode(600, tree->Root()))
		cout << "Node 600 found" << endl;
	else
		cout << "Node 600 not found" << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	// Min & Max
	cout << "Min=" << tree->min(tree->Root())->Key() << endl;
	cout << "Max=" << tree->max(tree->Root())->Key() << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	// Successor and Predecessor
	Node* PreSuc;

	PreSuc = tree->successor(300, tree->Root());
	if (PreSuc)
	{
		cout << "Successor to 300 = " <<
			PreSuc->Key() << endl;
	}
	else
	{
		cout << "Successor to 300 = NULL" << endl;
	}
	// Predecessor
	PreSuc = tree->predecessor(300, tree->Root());
	if (PreSuc)
	{
		cout << "Predecessor to 300 = " <<
			PreSuc->Key() << endl;
	}
	else
	{
		cout << "Predecessor to 300 = NULL" << endl;
	}
	

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	// Delete a node
	//tree->deleteNode(300);

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	// Traverse the tree
	tree->walk(tree->Root());
	cout << endl;
	//cout << tree->nodeCount(tree->Root());

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	tree->mirror(tree->Root());

	tree->walk(tree->Root());
	tree->mirror(tree->Root());
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "No of nodes in tree: " << tree->nodeCount(tree->Root()) << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;
	tree->displayLeafNodes(tree->Root());

	//vector<list<Node*>> resultV;
	int level = 0;
	tree->Traverse(tree->Root(), level);

	cout << "---------------------> Pre Order Tree Traversal<----------------------" << endl;
	cout << endl;
	tree->PreOrderRec(tree->Root());
	cout << endl;
	cout << endl;

	cout << "---------------------> In Order Tree Traversal<----------------------" << endl;
	cout << endl;
	tree->InOrderRec(tree->Root());
	cout << endl;
	cout << endl;

	cout << "---------------------> Post Order Tree Traversal<----------------------" << endl;
	cout << endl;
	tree->PostOrderRec(tree->Root());
	cout << endl;
	cout << endl;

	cout << "---------------------> Least Common Successor<----------------------" << endl;
	cout << endl;
	Node* tempLCA;

	tempLCA = tree->LCA(tree->Root(), 320, 800);
	cout << " LCA for 320 and 800 is: " << tempLCA->Key() << endl;
	tempLCA = tree->LCA(tree->Root(), 120, 450);
	cout << " LCA for 120 and 450 is: " << tempLCA->Key() << endl;
	tempLCA = tree->LCA(tree->Root(), 750, 800);
	cout << " LCA for 750 and 800 is: " << tempLCA->Key() << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "---------------->> Form Balance Tree from sorted array <<------------" << endl;
	cout << endl;
	int array[10];
	cout << "array: ";
	for (int i = 0; i < 10; i++) {
		array[i] = i;
		cout << i << " ";
	}

	BST* tree1 = new BST();
	
	Node* root = tree1->orderedArrayToTree(tree->Root(), array, 0, 9);
	    
	    
		cout << endl << "after insert (pre-ordered traversal): " << endl << "Binary Tree: ";
		tree1->InOrderRec(root);
		cout << endl;
		cout << "Mindepth: " << tree1->MinDepth(root) << endl;
		cout << "Maxdepth: " << tree1->MaxDepth(root) << endl;
	//	tree->LeftView(tree->Root());

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "---------------->> In-order Successor of BST Node <<------------" << endl;
	cout << endl;

	Node* temp = tree->findNode(200, tree->Root());
	Node * result = tree->inOrderSuccessor(tree->Root(), temp);
	cout << "InOrder Successor of " << temp->key << " is " << result->key << endl;

	cout << "---------------------------------------------------------------------" << endl;
	cout << endl;

	delete tree1;
	
	delete tree;
	
	#pragma region To Test Subtree Function (creates 3 tree) [CareerCup 4.7]
		 
		// Create trees required for testing
		 BST* sT1 = new BST(); // Original Tree
		 BST* sT2 = new BST();
		 BST* sT3 = new BST();

		 // Inputs for BST to be tested
		 vector<int> Vect_T1 = { 1, 2, 3, 4, 5, 6 };   //, 7, 8, 9, 10, 11, 12, 13};
		 vector<int> Vect_T2 = { 3, 4, 5, 6 };
		 vector<int> Vect_T3 = { 1, 2, 3 };

		 cout << endl;
		 // Add Nodes in sT1
		 for (int i = 0; i < Vect_T1.size(); i++)
		 {
			 sT1->addNode(Vect_T1[i]);
		 }
		 cout << endl;

		 // Add Nodes in sT2
		 for (int i = 0; i < Vect_T2.size(); i++)
		 {
			 sT2->addNode(Vect_T2[i]);
		 }
		 cout << endl;

		 // Add Nodes in sT3
		 for (int i = 0; i < Vect_T3.size(); i++)
		 {
			 sT3->addNode(Vect_T3[i]);
		 }
		 cout << endl;

		 // Check if sT2 is subtree of sT1
		 //isSubTree(Node* T1, Node* T2);

		 if (BST::isSubTree(sT1->Root(), sT3->Root()))
			 cout << "Tree3 is subtree of Tree 1" << endl;
		 else
			 cout << "Tree3 is not subtree of Tree 1" << endl;
		 
		 cout << endl;

		 // Check if sT3 is subtree of sT1
		 
		 if (BST::isSubTree(sT1->Root(), sT2->Root()))
			 cout << "Tree2 is subtree of Tree 1" << endl;
		 else
			 cout << "Tree2 is not subtree of Tree 1" << endl;
		 
		 cout << endl;
		 // Delete trees

		 delete sT1;
		 delete sT2;
		 delete sT3;
	#pragma endregion

	#pragma region Find Path For a Given Sum

		 BST* BST_Sum = new BST();
		 vector<int> SumTest = { 10, 8, 12, 6, 9, 11, 3, 15 };

		 // Add Nodes in BST_Sum
		 for (int i = 0; i < SumTest.size(); i++)
		 {
			 BST_Sum->addNode(SumTest[i]);
		 }
		 cout << endl;
		 vector<int> path;
		 BST::FindSum(BST_Sum->Root(), 27, path, 0);
		 BST::FindSum(BST_Sum->Root(), 33, path, 0);
		 BST::FindSum(BST_Sum->Root(), 9, path, 0);
		
#pragma endregion



}



/// <summary>
/// Starting point of program
/// </summary>
/// <returns></returns>
int main()
{
	DoTest();
	
	return 0;
}