#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;
#pragma once
class BST
{
	Node* root;
public:
	BST();
	~BST();
	// To get root of tree
	Node* Root() { return root; };  //1
	// Add node to current tree. provide key
	void addNode(int key);  //2
	// Findnode in a tree
	Node* findNode(int key, Node* parent); //3
	// Print nodes in a tree
	void walk(Node* node); //4
	// Count no of nodes in a tree
	int nodeCount(Node* node); //5
	// Delete a node in a tree
	void deleteNode(int key); //6
	// Find min node in tree
	static Node* min(Node* node); //7
	// Find max node in tree
	Node* max(Node* node); //8
	// Find successor of node
	Node* successor(int key, Node* parent); //9
	// Find Predecessor of node
	Node* predecessor(int key, Node* parent); //10
	// Mirror image of a tree
	void mirror(Node* parent); //11
	// Display node level wise
	void displayLeafNodes(Node* parent); //12
	// In order traversal recursive
	void InOrderRec(Node* parent); //13
	// Preorder traversal recursive
	void PreOrderRec(Node* parent); //14
	// Postorder traversal recursive
	void PostOrderRec(Node* parent); //15
	// Lease common ancestor
	Node* LCA(Node* parent, int n1, int n2);  //16 Lowest Common Ancestor
	// To Calculate MinDepth of BST
	int MinDepth(Node* parent); // 
	// Calculate max depth of BST
	int MaxDepth(Node* parent);
	// To check if BST is balanced or not
	bool isBalanced(Node* root);
	// List of levels
	void Traverse(Node* node, int &level);
	// Create BST from sorted array
	Node* orderedArrayToTree(Node*, int*, int, int);
	// Inorder Successor of BST node
	Node* inOrderSuccessor(Node *root, Node *n);
	// To Check if T2 is subtree of T1
	static bool isSubTree(Node* T1, Node* T2);
	// To Find path whos sum is equal to given number
	static void FindSum(Node * root, int sum, vector<int> path, int level);

private:
	void addNode(int key, Node* leaf); //
	void freeNode(Node* leaf); //
};

