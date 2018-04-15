#pragma once
#pragma once
//
//  LinkedList.hpp
//  lab2
//
//*****************************************************************************************************************************************
//This class is used to manipulate the nodes in the list, by adding, deleting, to display, and get the count for number of nodes in list.
//*****************************************************************************************************************************************
#include "LLNode.hpp"
#ifndef LinkedList_hpp
#define LinkedList_hpp

//#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
protected:
	int count; // count of nodes in linkedList at all times
	LLNode<T> *head;


public:
	// constructor
	LinkedList() : head(nullptr) {}


	int getCount() { return count; }
	void setCount() { count = 0; } const
		void setHead() { head = nullptr; }
	LLNode<T>* getHead() { return head; }
	virtual void append(T newVal);
	void addAnywhere(T newVal);
	virtual void display() const;
	void deleteNode(T val);
	virtual T deleteFirst();
	int findAnywhere(T item);
	// specific for Queue ADT
	T findLast();
	// specific for Queue ADT
	// used to find the first item in the Queue
	// or "Last In" item in Queue
	T getFirst() {
		if (!head)
		{
			throw "nothing in the queue";
		}
		T temp = head->getData();
		return temp;
	}
	// specific for the Queue class
	T deleteLast();




	// destructor
	// also doubles as an empty function
	~LinkedList();
};


// add function adds a node to a user specified place in the linked list
// options to add include first, last and somewhere in the middle
//**************************************************************************************************
// this function adds a node to the beginning of the list only.
//and takes and templated parameter for data
//***************************************************************************************************
template<class T>
void LinkedList<T>::append(T newVal)
{
	LLNode<T> *newNode; // node to be added


						// allocate new node
	newNode = new LLNode<T>(newVal);

	// if linkedlist is empty, then newNode = first node
	if (!head)
	{
		head = newNode;
	}
	else // insert node
	{
		newNode->setNext(head);
		head = newNode;

	}
	count++;
}
//*******************************************************************
//this function displays the contenst of the list
//********************************************************************

// to display contents in linked list
template <class T>
void LinkedList<T>::display() const
{

	LLNode<T>* nodePtr; // to move through list

						// position pntr
	nodePtr = head;

	// while there is a node
	while (nodePtr)
	{
		std::cout << nodePtr->getData() << endl;

		// move to next
		nodePtr = nodePtr->getNext();
	}

}



//*****************************************************************************
//this function allows user to add a node anywhee in the list,
// taking a templated parameter for the value of data defined in the Node
// class.
//******************************************************************************
// inserting a node anywhere in program
template<class T>
void LinkedList<T>::addAnywhere(T newVal)
{
	LLNode<T> *newNode;
	LLNode<T> *nodePtr;
	LLNode<T> *prev = nullptr;

	// allocate a new node
	newNode = new LLNode<T>;
	newNode->data = newVal;

	// if listis empty, make newnode the first
	if (!head)
	{
		head = newNode;
		newNode->pNext = nullptr;
	}
	else // insert at a diff. location
	{
		// pos. at head of list
		nodePtr = head;

		//initialize prev node to null
		prev = nullptr;

		// skip all node until is less than newVal
		while (nodePtr != nullptr && nodePtr < newVal)
		{
			prev = newNode;
			nodePtr = nodePtr->pNext;
		}
		// if new node is to be first
		if (prev == nullptr)
		{
			head = newNode;
			nodePtr->pNext = nodePtr;
		}
		else
		{
			prev->pNext = newNode;
			newNode->pNext = nodePtr;
		}
	}
	count++;
}
//*********************************************************************************
// this functioins deletes a node anywhere in the list and return nothing
//*********************************************************************************

// to delete node
template<class T>
void LinkedList<T>::deleteNode(T val)
{

	LLNode<T> *nodePtr;
	LLNode<T> * prev;

	//check if list is empty
	if (!head)
	{
		cout << "list is empty." << endl;
		return;
	}
	if (head->data == val)
	{
		nodePtr = head->pNext;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->data != val)
		{
			prev = nodePtr;
			nodePtr = nodePtr->pNext;
		}
		// if node pntr is not at end of list
		// then link prev to node after
		// and delete node pntr
		if (nodePtr)
		{
			prev->pNext = nodePtr->pNext;
			delete nodePtr;
		}
	}
	count--;
}

// deconstructor
//*********************************************************
//the destructor for linked list deletes 
// all alocated memory, destroying the list completely
// doubling as an empty function as well.
//*********************************************************
template<class T>
LinkedList<T>::~LinkedList()
{
	LLNode<T> *nodePtr;
	LLNode<T> *next;

	nodePtr = head;
	while (nodePtr != nullptr)
	{
		next = nodePtr->getNext();
		delete nodePtr;

		nodePtr = next;

	}
}

//**************************************************************
//this function deletes only the first node in the list
// and return the nodes contents
//************************************************************
template<class T>
T LinkedList<T>::deleteFirst()
{
	LLNode<T> *nodePtr;
	T temp;

	if (!head)
	{
		throw "stack is empty, try another option";
	}
	else {
		nodePtr = head->getNext();
		temp = head->getData();
		delete head;
		head = nodePtr;
		count--;
		return temp;
	}

}
//*************************************************************************
// this is specific for the Queue ADT. The way our findAnywhere function
// was defined, was only compatible by passing in the Data the user wanted 
// to find and not with the  integer pos. of where the item was located
//*************************************************************************
template<class T>
T LinkedList<T>::findLast()
{
	LLNode<T> *nodePtr = head;
	T temp;

	if (head->getNext() == nullptr)
	{
		temp = head->getData();
		return temp;
	}
	while (nodePtr->getNext() != nullptr)
	{
		nodePtr = nodePtr->getNext();

	}
	temp = nodePtr->getData();
	return temp;
}


//***********************************************************************
//This class is specific for the Queue ADT
// beforehand our LL ADT did not have anything compatible with returning
// the "First in" Item
//***********************************************************************
template<class T>
T LinkedList<T>::deleteLast()
{
	LLNode<T> *nodePtr = head;
	LLNode<T> *prevPtr = nodePtr;
	T temp;

	if (head->getNext() == nullptr)
	{
		temp = head->getData();
		delete head;
		head = nullptr;
		count--;
		return temp;
	}
	while (nodePtr->getNext() != nullptr)
	{
		prevPtr = nodePtr;
		nodePtr = nodePtr->getNext();

	}
	prevPtr->setNext(nullptr);
	temp = nodePtr->getData();
	delete nodePtr;
	count--;
	return temp;
}




//***********************************************
//find the nth node and return the data
//*********************************************
template<class T>
int LinkedList<T>::findAnywhere(T item)
{
	LLNode<T> *next->setNext(head);
	int count = 0;
	if (item == head->getData())
	{
		return count;
	}
	else
	{
		while (item != next->getData())
		{
			next = next->getNext();
			count++;
		}
		return count;
	}
	else
	{
		cout << "Item was not found." << endl;
		return -1;
	}
}
#endif /* LinkedList_hpp */

