/*
  WHEN USING POINTER IN LARGE DATA STRUCTURE USE POINTER AS FOLLOWS
  1) Lets say we have class or structure called Node and 
     we are going to use pointer of type Node
  2) Use Node to create new nodes
  3) Use NodePtr as Node pointer
  4) Using above concepts
     i)  NodePtr can used in program as follows
	      using NodePtr = Node*;
	 ii) To istantiate a node or to allocate memory use Node
	      
		 NodePtr n; // create reference of type Node (equivalent to Node* n)
		            // It can point to object of type Node if assigned address of object
					// if allocated memory can act as object (it creates object and get address of 
				    //   its location)
		n = new Node;  // Memory allocation

*/

#include <iostream>

using namespace std;
#pragma once

class Node {
	
public:
	int key;
	Node* left;
	Node* right;
	Node* parent;

	Node() { key = -1; left = NULL; right = NULL; parent = NULL; };
	Node(int myKey) { key = myKey; left = NULL; right = NULL; parent = NULL; };
	void setKey(int aKey) { key = aKey; };
	void setLeft(Node* aLeft) { left = aLeft; };
	void setRight(Node* aRight) { right = aRight; };
	void setParent(Node* aParent) { parent = aParent; };
	int Key() { if (this == NULL) return 0;  return key; };
	Node* Left() { return left; };
	Node* Right() { return right; };
	Node* Parent() { return parent; };

	Node * NewNode(int data)
	{
		Node* n = new Node();
		n->key = data;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	/*struct TNode* newNode(int data)
	{
		struct TNode* node = (struct TNode*)
			malloc(sizeof(struct TNode));
		node->data = data;
		node->left = NULL;
		node->right = NULL;

		return node;
	}*/
};

