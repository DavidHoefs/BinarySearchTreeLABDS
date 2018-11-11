//bst.cpp 
//	Where header functions are defined
//
//



#include "stdafx.h"
#include "bst.h"


#include <iostream>
using namespace std;
// setter to set the value of object Node
void Node::setInfo(int value) {
	this->info = value;
}

Node::Node(int info) {
	this->info = info;
	right = 0;
	left = 0;
}
// insert function for BST
// input: int value, this is the value you want to add to tree
// output: nothing
// Purpose: adds values to BST
void BST::insert(int value) {
	//creating insertNode with user input value
	Node* insertNode = new Node(value);
	//creating a temp node
	Node* temp = new Node(0);
	// if this is the first value, it is the root of the BST
	if (!this->root) {
		this->root = insertNode;
	}
	// Otherwise, if not the root
	else {
		// temp is now equal to root of BST
		Node* temp = this->root;
		// Endless While loop to traverse BST
		while (true) {
			// if the user input value is less than the root value, check if root ->left has a node already, if not insertNode goes there, otherwise loop until open spot
			if (value < temp->getInfo()) {
				if (temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = insertNode;
					break;
				}
			}
			// if the user input value is greater than the root of BST
			else if (value > temp->getInfo()) {
				if (temp->right != NULL) {
					temp = temp->right;

				}
				else {
					temp->right = insertNode;
					break;
				}
			}
			// if this value is already in the BST, throw exception
			else {
				throw "Duplicates not allowed";
			}
		}
	}
}
Node* BST::getRoot() {
	return this->root;
}
// Search function for BST
// Input: int value, this is the value to search for in the BST
// Output: Nothing
//Purpose: Searches BST for user input value, tells user if it was found or not
void BST::search(int value) {
	// creating searchNode with user input value
	Node* searchNode = new Node(value);
	// if there are no values, throw exception
	if (!this->root) {
		throw "No Values In BST";
	}
	// if the value is the root of the BST, tell user
	if (value == this->root->getInfo()) {
		cout << "Value found, it is the Root" << endl;
	}
	else {
		// creating tempNode
		Node* temp = this->root;
		// infinite while loop to traverse BST
		while (true) {
			// if the value is less than the root, go left
			if (value < temp->getInfo()) {
				searchNode=temp->left;
				temp = temp->left;
				// if we reach the end, we havent found the value, tell user that BST does not contain user input value
				if (searchNode==NULL) {
					cout << "value not found!" << endl;
					
					break;
				}
				// if we found the value, tell user
				if (value == searchNode->getInfo()) {
					cout << "Value Found" << endl;
					
					break;
				}
				
			}
			// if value is greater than root, go right
			// same as previous code, just with searchNode ->right
			else {
				searchNode = temp->right;
				temp = temp->right;
				if (searchNode == NULL) {
					cout << "value not found!" << endl;
					break;
				}
				if (value == searchNode->getInfo()) {
					cout << "Value Found" << endl;
					
					break;
				}
			}
			
			
		}
	}
}
// Function to count number of leaves in BST
// Input: Node* root, this is the pointer that points to the root of the BST
// Output: int value that represents the number of leaves
int BST::leavesCount(Node* root) {
	int numOfLeaves = 0;
	// if there are no values in BST, number of leaves is zero
	if (root == NULL)
		return 0;
	// if the root is the only value, root is only leaf, 
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	// otherwise, recursively call leavesCount function and add together the result of left and right traversals through BST
	else {
		return leavesCount(root->left) + leavesCount(root->right);
	}
}
// Function to print BST in order
// input: Node* orderNode
// output: Nothing
// Purpose: Traverses BST in numeric order
void BST::inorderTraversal(Node* orderNode) {
	// if there are no values, return
	if (orderNode == NULL) {
		return;
	}
	// otherwise, recursively call inorderTraversal() function on left and right sides until you reach the end

	inorderTraversal( orderNode->left);
	cout << orderNode->getInfo() << endl;
	inorderTraversal(orderNode->right);

	
}
// function to prompt user for values to fill BST
void BST::promptUser() {
	cout << "BINARY SEARCH TREE" << endl;
	cout << "ENTER MIN OF 5 NUMBERS" << endl;
	cout << "----------------------" << endl;
	int input = 0;
	int numOfInputs = 0;
	int choice = NULL;
	bool a = true;
	// infinite loop to fill BST until user is done
	while (a == true) {
		// prompts user to enter num
		cout << "Enter num" << endl;
		cin >> input;
		// calling insert function to add user input value to the BST
		insert(input);
		cout << input << " imported into list" << endl;
		numOfInputs++;
		// if statement to ensure atleast 5 values are entered, then user can choose to continue or keep adding
		if (numOfInputs >= 5) {
			cout << "1 to insert more numbers, 0 to stop input" << endl;
			cin >> choice;
			if (choice == 1) {
				continue;
			}
			if (choice == 0) {
				a = false;
			}
		}
	}

	


}
// function to prompt user to enter value for search funtion test
void BST::promptForSearch() {
	int searchNum = 0;
	
	while (true) {
		cout << "Enter number to check if it is in the tree or 0 to continue program : " << endl;
		cin >> searchNum;
		if (searchNum == 0) {
			break;
		}
		BST::search(searchNum);
		
		
	
			
	}
	
}
// Function to delete node with user input value from the BST
// Input: the int value to be deleted, the root of the BST
Node*  BST::deleteNode(int value, Node* deleteRoot) {
	if (i == 0);
		bool checkForValue = true;
	while (checkForValue) {
		search(value);
		i++;
		checkForValue = false;
	}
	
	// if the root of the BST is null, no values in BST to delete
	if (deleteRoot == nullptr) return deleteRoot;
	// first check if the user input value is less than the root of the BST
	else if (value < deleteRoot->getInfo()) {
		// if it is less the the root, recursively call deleteNode function passing in the user input value and the node that is left of the root
		deleteRoot->left = deleteNode(value, deleteRoot->left);
	}
	// checks if user input value is greater than the root of the BST
	else if (value > deleteRoot->getInfo()) {
		// if the value is greater than the root, recursively call deleteNode function passing in the user input value and the node that is right of the root
		deleteRoot->right = deleteNode(value, deleteRoot->right);
	}
	// the two else if statements above run until the node to be delete is found then moves to else statement below
	else {
		// When the node to be deleted has no child, we just delete that node and set it to null
		if (deleteRoot->left == nullptr && deleteRoot->right == nullptr) {
			delete deleteRoot;
			deleteRoot = NULL;
			
		}
		// when the node to be delete has one child node
		else if (deleteRoot->left == nullptr) {
			// create a temp node and set the pointer to the address where the value to be delete is held
			Node* tempNode = deleteRoot;
			// set the delete root to point to the right node 
			deleteRoot = deleteRoot->right;
			// And delete the node containing the value we want to delete
			delete tempNode;
			
		}
		// same as above but when the right node of the the node to be deleted is null rather than the left
		else if (deleteRoot->right == nullptr) {
			Node* tempNode = deleteRoot;
			deleteRoot = deleteRoot->left;
			delete tempNode;
			
		}
		// Node to be deleted has 2 children
		else {
			// create a temp node and set it equal to the minimum value node to the right
			Node* tempNode = findMin(deleteRoot->right);
			deleteRoot->setInfo(tempNode->getInfo()); 
			deleteRoot->right = deleteNode(tempNode ->getInfo(), deleteRoot ->right);
			
		}
	}
	// return the deleted and null node, no longer in BST
	return deleteRoot;


	
}
// Function to determine if node is a leaf
// input: node
// output: TRUE OR FALSE
bool BST::isLeaf(Node* node){
	if (node->left == NULL && node->right == NULL)
		return true;
	else
		return false;
}
// Function that finds the min node to the left of user input node
Node* BST::findMin(Node* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}
// preorder traversal function 
void BST::preOrderTraversal(Node* preOrderNode) {
	if (preOrderNode) {
		// Print root, print left, print right
		cout << preOrderNode->getInfo() << endl;
		preOrderTraversal(preOrderNode->left);
		preOrderTraversal(preOrderNode->right);
	}
}
void BST::postOrderTraversal(Node* postOrderNode) {
	if (postOrderNode) {
		// print left, print right, print root
		postOrderTraversal(postOrderNode->left);
		postOrderTraversal(postOrderNode->right);
		cout << postOrderNode->getInfo() << endl;
	}
}