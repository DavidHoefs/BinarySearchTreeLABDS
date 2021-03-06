// main.cpp : Defines the entry point for the console application.
//

//
#include "stdafx.h"
#include "bst.h"
#include <process.h>
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
int main()
{
	int deleteValue = 0;
	// Declaring BST
	BST testBST = BST();
	// prompting user function 
	//testBST.promptUser();
	srand(5);
// added to fill BST with rand values to test speed with multiple inputs
	for (int i = 0; i <250; i++) {
		testBST.insert(rand());
	}
	
	// Tell user the number of leaves in BST
	 int numOfLeaves = testBST.leavesCount(testBST.getRoot());
	 cout <<"Number of Leaves: "<< numOfLeaves << endl;
	 cout << "Inorder Traversal" << endl;
	 // Tests inorderTraversal() function
	 testBST.inorderTraversal(testBST.getRoot());
	 // tests search function, calls prompt for search function which will call the search funtion according to user input
	  testBST.promptForSearch();
	  cout << "Enter value to delete from BST: " << endl;
	  cin >> deleteValue;
	  testBST.deleteNode(deleteValue,testBST.getRoot());
	  cout << "inOrder Traversal after removal " << endl;
	  cout << "-------------------------" << endl;
	  testBST.inorderTraversal(testBST.getRoot());
	  cout << "Pre Order Traversal Test:" << endl;
	  testBST.preOrderTraversal(testBST.getRoot());
	  cout << "Post Order Traversal Test: " << endl;
	  testBST.postOrderTraversal(testBST.getRoot());
	
	
	
	
	system("pause");
	return 0;
}

