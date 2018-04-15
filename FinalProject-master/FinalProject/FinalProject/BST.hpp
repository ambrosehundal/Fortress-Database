#pragma once
#ifndef BST_hpp
#define BST_hpp
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************

#include "BSTNode.hpp"
#include "LLNode.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class BST : protected BSTNode
{
private:
	int count;
	BSTNode *root;

public:
	unsigned int operationsTotal = 0;
	unsigned int operationsInsert = 0;
	unsigned int operationsFind = 0;
	unsigned int operationsDelete = 0;
	//defautl ructor
	BST() { root = nullptr; count = 0; operationsTotal += 2; }

	
	// getters and setters for root
	BSTNode *getRoot() { return root; operationsTotal += 1; }

	// returns count of nodes in BST
	int getCount() { return count; operationsTotal += 1; }

	// check if BST is empty
	bool isEmpty();

	void operationsAdd(int x) { operationsTotal += x; }
	// add new data to BST
	void appendByName(string n, int m, int w, int l, int wp);
	void appendByWins(string n, int m, int w, int l, int wp);

	void PreOrder(BSTNode *nodePtr, int level = 0) ;

	// display a post order traversal of BST
	void displayPostOrder()
	{
		PostOrder(root);
		operationsTotal += 1;
	}

	void PostOrder(BSTNode *nodePtr);
	void displayPreOrder()
	{
		PreOrder(root);
		operationsTotal += 1;
	}
	void displayInOrder()
	{
		inOrder(root);
		operationsTotal += 1;
	}
	void inOrder(BSTNode *nodePtr);


	// for breadth traversals
	void breadth();

	// search for data
	bool SearchByName(string n);

	// deletion in BST
	bool remove(string n);
	bool deleteNode(string n, BSTNode *nodePtr);
	void deletion(BSTNode *nodePtr);

	//destructor
	// deletes BST
	~BST()
	{
		BSTNode *nodePtr;
		nodePtr = root;


		if (!isEmpty())
		{
			destroyRec(nodePtr);
		}
		operationsTotal += 4;
	}

	void destroyRec(BSTNode *nodeptr)
	{
		if (nodeptr)
		{
			destroyRec(nodeptr->getLeft());
			destroyRec(nodeptr->getRight());
			delete nodeptr;
			nodeptr = nullptr;
			operationsTotal += 3;
		}
		operationsTotal += 1;
	}
};

//*****************************************************
// this function checks if the entire BST is empty
//*****************************************************
bool BST::isEmpty()
{
	// if root is pnting to nullptr
	// return true
	if (!root)
		return true;

	// if not 
	// return false
	else
		return false;
	operationsTotal += 2;
}


//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
// according to ascii values of names
//********************************************************************
void BST::appendByName(string n, int m, int w, int l, int wp)
{
	if (!root)
	{
		root = new BSTNode(n, m, w, l, wp);
		count++;
		return;
		operationsTotal += 3;
	}
	operationsTotal += 1;
	BSTNode *temp = root;
	BSTNode *parent = nullptr;
	operationsTotal += 2;
	while (temp)
	{
		parent = temp;
		if (n < temp->getName())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
		operationsTotal += 4;
	}

	if (n < parent->getName())
	{
		parent->setLeft(new BSTNode( n,  m,  w, l,  wp));
		count++;
	}
	else
	{
		parent->setRight(new BSTNode( n,  m,  w,  l,  wp));
		count++;
	}
	operationsTotal += 3;
}


//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
// according to value of wins
//********************************************************************
void BST::appendByWins(string n, int m, int w, int l, int wp)
{
	if (!root)
	{
		root = new BSTNode(n, m, w, l, wp);
		count++;
		return;
		operationsTotal += 3;
	}
	operationsTotal += 1;
	BSTNode *temp = root;
	BSTNode *parent = nullptr;
	operationsTotal += 2;
	while (temp)
	{
		parent = temp;
		if (w < temp->getWins())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
		operationsTotal += 4;
	}

	if (w < parent->getWins())
	{
		parent->setLeft(new BSTNode(n, m, w, l, wp));
		count++;
	}
	else
	{
		parent->setRight(new BSTNode(n, m, w, l, wp));
		count++;
	}
	operationsTotal += 3;

}


//*****************************************
// to display a post order traversal
//*****************************************
void BST::PostOrder(BSTNode *nodePtr) 
{

	if (nodePtr)
	{
		PostOrder(nodePtr->getLeft());
		PostOrder(nodePtr->getRight());

		// write to commad scrn
		cout << nodePtr->getName() << endl;
		cout << nodePtr->getMatches() << endl;
		cout << nodePtr->getWins() << endl;
		cout << nodePtr->getLosses() << endl;
		cout << nodePtr->getWinPercent() << endl;
		operationsTotal += 7;
	}
	operationsTotal += 1;
}

void BST::inOrder(BSTNode *nodePtr) 
{
	if (nodePtr)
	{
		inOrder(nodePtr->getLeft());

		cout << std::left
			<< setw(20) << nodePtr->getName() << " Matches: "
			<< setw(4) << nodePtr->getMatches() << " Wins: "
			<< setw(4) << nodePtr->getWins() << " Losses: "
			<< setw(4) << nodePtr->getLosses() << " Win Percentage: "
			<< setw(4) << nodePtr->getWinPercent() << "%";
		cout << endl;
		inOrder(nodePtr->getRight());
		operationsTotal += 18;
		
	}
	operationsTotal += 1;
}

//*****************************************
// to display a pre order traversal
//*****************************************
void BST::PreOrder(BSTNode *nodePtr, int level) 
{
	level++;
	if (nodePtr)
	{
		for (int x = 0; x < level; x++)
		{
			cout << " ";
			operationsTotal += 1;
		}
		cout << nodePtr->getName();
		cout << " Wins: ";
		cout << nodePtr->getWins() << endl;

		PreOrder(nodePtr->getLeft(), level);
		PreOrder(nodePtr->getRight(), level);
		operationsTotal += 6;
	}
	operationsTotal += 2;
}

//*****************************************
// to search if a value/data exists within
// the BST. returns true/false.
//*****************************************

bool BST::SearchByName(string n)
{
	BSTNode *nodePtr = root;
	operationsTotal += 1;
	while (nodePtr)
	{
		if (nodePtr->getName() == n)
		{
			operationsTotal += 1;
			return true;
		}
		else
		{
			if (n < nodePtr->getName())
			{
				operationsTotal += 1;
				nodePtr->getLeft();
			}
			else
			{
				operationsTotal += 1;
				nodePtr->getRight();
			}
			operationsTotal += 1;
		}// end if
	}// end while
	operationsTotal += 1;
	return false;
}
//*****************************************
// removes node from tree
// by calling deleting node.
//*****************************************
bool BST::remove(string n)
{
	bool x = deleteNode(n, root);
	return x;
	operationsTotal += 2;
}
//**********************************************
// find the node in the binary tree
// and when found, calls the deletion function
// that will delete the node and redefine the 
// tree appropiately.
//*****************************************
bool BST::deleteNode(string n, BSTNode *nodePtr)
{
	bool x = false;
	if (n < nodePtr->getName() )//&& nodePtr != NULL)
	{
		x = deleteNode(n, nodePtr->getLeft());

	}
	else if (n > nodePtr->getName())// && nodePtr != NULL)
	{
		x = deleteNode(n, nodePtr->getRight());
	}
	else
	{
		deletion(nodePtr);
		x = true;
		operationsTotal += 1;
	}
	operationsTotal += 4;
	return x;
}
//******************************************
// deletes node in BST and reattaches nodes
// in tree to fit appropiately
// by finding he smallest in the left tree
//******************************************
void BST::deletion(BSTNode *nodePtr)
{
	BSTNode *temp = nullptr;
	operationsTotal += 1;
	if (nodePtr == nullptr)
	{
		cout << "Cannot delete empty node....." << endl;
		operationsTotal += 2;
		return;
	}
	// if only left child
	else if (nodePtr->getRight() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getLeft();
		delete temp;
		temp = nullptr;
		operationsTotal += 4;
	}
	// if only right child
	else if (nodePtr->getLeft() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getRight();
		delete temp;
		temp = nullptr;
		operationsTotal += 4;
	}
	// if rooot has both left and right children
	else
	{
		// get right node
		temp = nodePtr->getRight();

		// get to end of left
		while (temp->getLeft() !=nullptr)
		{
			temp = nodePtr->getLeft();
			operationsTotal += 2;
		}
		// reattach left subtree
		temp->setLeft(nodePtr->getLeft());
		//temp->left = nodePtr->left;
		temp = nodePtr;
		// reattach right subtre
		temp->setRight(nodePtr->getRight());
		//temp->getRight() = nodePtr->getRight();
		delete temp;
		temp = nullptr;
		operationsTotal += 8;


	}

}
//**********************************************
// to traverse tree breadth/level method
//**********************************************
void BST::breadth()
{
	//ofs << "this is breadth traversal of your data" << endl;

	// Base Case
	if (root == nullptr)
	{
		operationsTotal += 2;
		return;
	}

	// Create an empty queue for level order tarversal
	Queue<BSTNode *> q;

	BSTNode *temp = root;
	// Enqueue Root and initialize height
	q.enqueue(temp);
	operationsTotal += 3;
	while (q.getNum() != 0)
	{
		// Print front of queue and remove it from queue
		temp = q.front();
		cout << "*************************************************" << endl;
		cout << "Player name: "<< temp->getName() << endl;
		cout << "Wins: " << temp->getWins() << endl;
		cout << "Losses: " << temp->getLosses() << endl;
		cout << "Matches played: " << temp->getMatches() << endl;
		cout << "Win Percent: " << temp->getWinPercent() << endl;
		operationsTotal += 20;
		//ofs << temp->getData() << " ";
		q.dequeue();

		/* Enqueue left child */
		if (temp->getLeft() != nullptr)
			q.enqueue(temp->getLeft());

		/*Enqueue right child */
		if (temp->getRight() != nullptr)
			q.enqueue(temp->getRight());
		operationsTotal += 2;
	}
}





#endif