#include "BST.h"
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#pragma region BST Constructor
	
	/// <summary>
	/// Initializes a new instance of the BST class.
	/// </summary>
	BST::BST()
	{
		root = NULL;
	}

#pragma endregion

#pragma region BST Destructor
	
	/// <summary>
	/// Finalizes an instance of the BST class.
	/// </summary>
	BST::~BST() {
		freeNode(root);
	}

#pragma endregion

#pragma region FreeNode
	
	/// <summary>
	/// Frees the node.
	/// </summary>
	/// <param name="leaf">The leaf.</param>
	void BST::freeNode(Node* leaf)
	{
		if (leaf != NULL)
		{
			freeNode(leaf->left);
			freeNode(leaf->right);
			delete leaf;
		}
	}

#pragma endregion
 
#pragma region AddNode to BST 1
	
	/// <summary>
	/// Adds the node [O(height of tree) on average]
	/// </summary>
	/// <param name="key">The key</param>
	void BST::addNode(int key)
	{
		// No elements. Add the root
		if (root == NULL) {
			cout << "add root node ... " << key << endl;
			Node* n = new Node();
			n->setKey(key);
			root = n;
		}
		else {
			cout << "add other node ... " << key << endl;
			addNode(key, root);
		}
	}

#pragma endregion

#pragma region AddNode to BST 2

	// Add a node (private)
	/// <summary>
	/// Adds the node
	/// </summary>
	/// <param name="key">The key.</param>
	/// <param name="leaf">The leaf Node</param>
	void BST::addNode(int key, Node* leaf) {
		if (key <= leaf->key)
		{
			if (leaf->left != NULL)
				addNode(key, leaf->left);
			else
			{
				Node* n = new Node();
				n->setKey(key);
				n->setParent(leaf);
				leaf->setLeft(n);
			}
		}
		else
		{
			if (leaf->right != NULL)
				addNode(key, leaf->right);
			else
			{
				Node* n = new Node();
				n->setKey(key);
				n->setParent(leaf);
				leaf->setRight(n);
			}
		}
	}

#pragma endregion

#pragma region Find Node in BST
	
	/// <summary>
	/// Finds the node [O(height of tree) on average]
	/// </summary>
	/// <param name="key">The key.</param>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* BST::findNode(int key, Node* node)
	{
		if (node == NULL)
			return NULL;
		else if (key == node->key)
			return node;
		else if (key <= node->key)
			findNode(key, node->left);
		else if (key > node->key)
			findNode(key, node->right);
		else
			return NULL;
	}

#pragma endregion

#pragma region Walk/Print Tree
	/// <summary>
	/// Walks the specified node/ Prints the tree node (Left - key - Right)
	/// from left to right
	/// </summary>
	/// <param name="node">The node.</param>
	void BST::walk(Node* node)
	{
		if (node)
		{

			walk(node->left);
			cout << node->key << " ";
			walk(node->right);
		}
	}

#pragma endregion

#pragma region Count No Of Nodes in BST

	/// <summary>
	/// counts number of nodes in BST
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	int BST::nodeCount(Node* node)
	{
		if (node == NULL)
			return 0;
		else
			return 1 + nodeCount(node->left) + nodeCount(node->right);
	}

#pragma endregion

#pragma region Mirror image of BST

	/// <summary>
	/// Mirrors the specified tree.
	/// </summary>
	/// <param name="parent">Root node of tree to be mirrored</param>
	void BST::mirror(Node* parent)
	{
		Node* temp = new Node();
		Node* head = new Node();

		head = parent;

		if (head == NULL)
		{
			return;
		}
		else
		{
			mirror(head->left);
			mirror(head->right);
			temp = head->left;
			head->setLeft(head->right);
			head->setRight(temp);

		}
	}

#pragma endregion

#pragma region Display BST Level Wise

	/// <summary>
	/// Displays the leaf nodes in BST / level wise printing
	/// </summary>
	/// <param name="head">The head</param>
	void BST::displayLeafNodes(Node* head)
	{
		std::queue<Node*> node_q;

		Node* temp;
		Node* root;
		Node* level_node = new Node();
		int level_counter = 0;

		level_node->setKey(-1);
		root = head;

		node_q.push(root);
		node_q.push(level_node);
		//node_q.push()

		temp = node_q.front();

		if (head != NULL)
		{
			cout << "Head Not Null you can display nodes" << endl;

			/*temp = node_q.front();
			node_q.pop();*/


			while (!node_q.empty())
			{
				cout << endl;
				temp = node_q.front();

				node_q.pop();

				if (temp->key == -1)
				{
					if (!node_q.empty())
					{
						cout << " ------ level " << level_counter++ << " ------" << endl;
						node_q.push(level_node);
					}

				}
				else
				{
					cout << temp->key;

					if (temp->left != NULL)
					{
						node_q.push(temp->left);
					}

					if (temp->right != NULL)
					{
						node_q.push(temp->right);
					}
				}

			}
		}
		else
		{
			cout << "Tree is empty" << endl;
		}
	}

#pragma endregion

#pragma region Get Min Node

	/// <summary>
	/// Find the node with min key
	/// Traverse the left sub-BST recursively
	/// till left sub-tree is empty to get min
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns>Minimum node</returns>
    Node* BST::min(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->left)
			min(node->left);
		else
			return node;
	}

#pragma endregion

#pragma region Get Max Node

	/// <summary>
	/// Find the node with max key
	/// Traverse the right sub-tree recursively
	/// till right sub-tree is empty to get max
	/// </summary>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* BST::max(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->right)
			max(node->right);
		else
			return node;
	}

#pragma endregion

#pragma region Get Successor of Node

	/// <summary>
	/// Find successor to a node
	/// Find the node, get the node with max value
	/// for the right sub-BST to get the successor
	/// </summary>
	/// <param name="key">The key.</param>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* BST::successor(int key, Node *node)
	{
		Node* thisKey = findNode(key, node);
		if (thisKey)
			return max(thisKey->right);
		else
			return NULL;
	}

#pragma endregion

#pragma region Get Predecessor of Node

	/// <summary>
	/// Find predecessor to a node
	/// Find the node, get the node with max value
	/// for the left sub-tree to get the predecessor
	/// </summary>
	/// <param name="key">The key.</param>
	/// <param name="node">The node.</param>
	/// <returns></returns>
	Node* BST::predecessor(int key, Node *node)
	{
		Node* thisKey = findNode(key, node);
		if (thisKey)
			return max(thisKey->left);
	}

#pragma endregion

#pragma region Delete Node from BST

	/// <summary>
	///		Delete a node
	///		(1) If leaf just delete
	///		(2) If only one child delete this node and replace
	///		with the child
	///		(3) If 2 children. Find the predecessor (or successor).
	///		Delete the predecessor (or successor). Replace the
	///		node to be deleted with the predecessor (or successor).
	/// </summary>
	/// <param name="key">The key.</param>
	void BST::deleteNode(int key)
	{
		// Find the node.
		Node* thisKey = findNode(key, root);

		// (1)

		if (thisKey->left == NULL && thisKey->right == NULL)
		{
			if (thisKey->key > thisKey->parent->key)
				thisKey->parent->setRight(NULL);
			else
				thisKey->parent->setLeft(NULL);

			delete thisKey;
		}

		// (2)
		if (thisKey->left == NULL && thisKey->right != NULL)
		{
			if (thisKey->key > thisKey->parent->key)
				thisKey->parent->setRight(thisKey->right);
			else
				thisKey->parent->setLeft(thisKey->right);

			delete thisKey;
		}
		if (thisKey->left != NULL && thisKey->right == NULL)
		{
			if (thisKey->key > thisKey->parent->key)
				thisKey->parent->setRight(thisKey->left);
			else
				thisKey->parent->setLeft(thisKey->left);

			delete thisKey;
		}

		// (3)
		if (thisKey->left != NULL && thisKey->right != NULL)
		{
			Node* sub = predecessor(thisKey->key, thisKey);
			if (sub == NULL)
				sub = successor(thisKey->key, thisKey);

			if (sub->parent->key <= sub->key)
				sub->parent->setRight(sub->right);
			else
				sub->parent->setLeft(sub->left);

			thisKey->setKey(sub->key);
			delete sub;
		}
	}

#pragma endregion

#pragma region InOrder Traversal of BST (Recursive)
	
	/// <summary>
	/// InOrder traversal of tree
	/// </summary>
	/// <param name="head">The head.</param>
	void BST::InOrderRec(Node* head)
	{
		if (head == NULL)
		{
			return;
		}

		InOrderRec(head->left);
		cout << " " << head->key;
		InOrderRec(head->right);

	}

#pragma endregion

#pragma region PreOrder Traversal of BST (Recursive)
	
	/// <summary>
	/// PreOrder traversal of tree, recursively
	/// </summary>
	/// <param name="head">The head.</param>
	void BST::PreOrderRec(Node* head)
	{
		if (head == NULL)
		{
			return;
		}

		cout << " " << head->key;
		PreOrderRec(head->left);

		PreOrderRec(head->right);

	}

#pragma endregion

#pragma region PostOrder Traversal of BST (Recursive)

	/// <summary>
	/// Postorder traversal of tree, recursively
	/// </summary>
	/// <param name="head">The head.</param>
	void BST::PostOrderRec(Node* head)
	{
		if (head == NULL)
		{
			return;
		}

		PostOrderRec(head->left);
		PostOrderRec(head->right);
		cout << " " << head->key;
	}

#pragma endregion

#pragma region Least Common Ancestor of 2 Nodes

	/// <summary>
	/// Return the Least Common Ancestor (LCA) of Nodes with values a and b
	/// </summary>
	/// <param name="root">The root.</param>
	/// <param name="a">a</param>
	/// <param name="b">b</param>
	/// <returns></returns>
	Node* BST::LCA(Node* root, int a, int b)
	{
		// if one of the noede is not in tree 
		if (findNode(a, root) == NULL || findNode(a, root) == NULL)
			return NULL;
		// case when LCA doesn't exist
		if (root == NULL || root->key == a || root->key == b)
			return root;

		if ((root->key > a && root->key < b) || (root->key > b && root->key < a))
			return root;

		// LCA will be on the LEFT sub-tree
		if (root->key > a && root->key > b)
			return LCA(root->left, a, b);

		// LCA will be on the RIGHT sub-tree
		if (root->key < a && root->key < b)
			return LCA(root->right, a, b);
	}

#pragma endregion

#pragma region Calculate Min Depth of BST

	/// <summary>
	///  To Calculate minimum depth in BST
	/// </summary>
	/// <param name="parent">The parent.</param>
	/// <returns></returns>
	int BST::MinDepth(Node* parent)
	{
		if (parent == NULL)
		{
			return 0;
		}
		
		return 1 + (std::min(MinDepth(parent->left), MinDepth(parent->right)));
	}

#pragma endregion

#pragma region Calculate Max Depth of BST

	/// <summary>
	/// Calculates max depth of tree
	/// </summary>
	/// <param name="parent">The parent.</param>
	/// <returns></returns>
	int BST::MaxDepth(Node* parent)
	{
		if (parent == NULL)
		{
			return 0;
		}

		
		return 1 + (std::max(MaxDepth(parent->left), MaxDepth(parent->right)));
	}
#pragma endregion

#pragma region To Check if Given BST is balanced or not
	/// <summary>
	/// Determines whether the specified BST is balanced.
	/// </summary>
	/// <param name="parent">Root of tree</param>
	/// <returns> 1: Success 0: Failure</returns>
	bool BST::isBalanced(Node* parent)
	{
		return (MaxDepth(parent) - MinDepth(parent) <= 1);
	}

	int TestMin(Node* parent)
	{

		int res = std::min(parent->left->key, parent->right->key);
		if (res == parent->left->key)
			return 1;
		else return 0;

		//return (std::min(parent->left->key, parent->right->key));
		//return ((std::min(parent->, MinDepth(parent->right))) ? 0 : 1);
	}
#pragma endregion

#pragma region BST Levels to List

	typedef vector< Node* > ListNodes;
	vector< ListNodes > arrNodes;
	/// <summary>
	/// Traverses the specified node.
	/// </summary>
	/// <param name="node">The node.</param>
	/// <param name="level">The level.</param>
	void BST::Traverse(Node* node, int &level)
	{
		if (node == NULL)
		{
			level -= 1;
			return;
		}
		cout << node->key << " " << level << endl;

		if (arrNodes.size() == level) arrNodes.push_back(ListNodes());

		arrNodes[level].push_back(node);

		level++;
		Traverse(node->left, level);
		level++;
		Traverse(node->right, level);
		level--;
	}
#pragma endregion

#pragma region Sorted Array to Binary Search Tree
	
	
	/// <summary>
	/// Creates Binaray Search Tree using given sorted array
	/// </summary>
	/// <param name="parent">The parent.</param>
	/// <param name="arr">The arr.</param>
	/// <param name="from">From.</param>
	/// <param name="to">To.</param>
	/// <returns></returns>
	Node* BST::orderedArrayToTree(Node* parent, int* arr, int from, int to)
	{
		if (from > to)
			return NULL;
		else {
			int mid = from + (to - from) / 2;  // avoid integer overflow
			int temp = arr[mid];
			Node * node = new Node(temp);

			node->parent = parent;
			node->left = orderedArrayToTree(node, arr, from, mid - 1);
			node->right = orderedArrayToTree(node, arr, mid + 1, to);
			return node;
		}
	}

#pragma endregion

#pragma region Function to Find InOrder Successor of Given Node
	
	
	/// <summary>
	/// Retunrn the inorder successor.
	/// </summary>
	/// <param name="root">The root.</param>
	/// <param name="n">The n.</param>
	/// <returns></returns>
	Node * BST::inOrderSuccessor(Node *root, Node *n)
	{
		// step 1 of the above algorithm 
		if (n->right != NULL)
			return min(n->right);

		// step 2 of the above algorithm
		Node *p = n->parent;
		while (p != NULL && n == p->right)
		{
			n = p;
			p = p->parent;
		}
		return p;
	}

#pragma endregion

#pragma region Function to check subtree

	/// <summary>
	/// Matches the two tree, Utility function for isSubTree
	/// </summary>
	/// <param name="T1">The t1.</param>
	/// <param name="T2">The t2.</param>
	/// <returns></returns>
	bool matchTree(Node* T1, Node* T2)
	{		
		if (T1 == NULL && T2 == NULL) // both nothing left
			return true;

		if (T1 == NULL || T2 == NULL) // less nodes
			return false;

		if (T1->key == T2->key)
			return (matchTree(T1->left, T2->left) && matchTree(T1->right, T2->right));
		 // does not match
	}

	// To Check if T2 is subtree of T1
	/// <summary>
	/// Determines whether T2 is sub tree of T1
	/// </summary>
	/// <param name="T1">The root of Tree 1</param>
	/// <param name="T2">The root of Tree 2</param>
	/// <returns></returns>
	bool BST::isSubTree(Node* T1, Node* T2)  //VIMP: dont use static in .cpp use it only in header file
	{
		
		if (!T2)
			return true;
		if (!T1)
			return false;
		if (T1->key == T2->key) {
			if (matchTree(T1, T2))
				return true;
		}

		return isSubTree(T1->left, T2) || isSubTree(T1->right, T2);

	}


#pragma endregion

#pragma region Find Sum [CareerCup 4.8]

	/// <summary>
	/// Finds the sum.
	/// </summary>
	/// <param name="root">The root.</param>
	/// <param name="sum">The sum.</param>
	/// <param name="path">The path.</param>
	/// <param name="level">The level.</param>
	void BST::FindSum(Node * root, int sum, vector<int> path, int level)
	{
		if (!root)
			return;

		int temp = sum;

		path.push_back(root->key);

		for (int i = level; i >= 0; i--) {
			temp -= path[i];
			if (temp == 0) { // find a path: sum = path[i] + .. + path[level]
				cout << "path: ";
				for (int j = i; j< level; j++)
					cout << path[j] << " -> ";
				cout << path[level] << endl;
			}
		}
		FindSum(root->left, sum, path, level + 1);
		FindSum(root->right, sum, path, level + 1);
	}

#pragma endregion

