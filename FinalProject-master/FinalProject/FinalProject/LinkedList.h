#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/*
Stephen Lee
CIS 22C
Winter 2017
Lab 2

Used Microsoft Visual Studio 2017

List
A Singly Linked List ADT which will be composed of one or more nodes.
Implement the most common linked-list behaviors as explained in class -
new list, add anywhere, delete anywhere, find anywhere,
count of items in the list, empty the list, etc.
*/

#include "LinkedListNode.h"

/*
To make an array have linked lists
DynamicArray<LinkedList<int>> dynamicList
That is a declaration, not a class!!!
*/
template <class T>
class List
{
private:
	Node<T> *head;
	Node<T> *tail;
	int itemCount;
public:
	unsigned int operationsTotal = 0;
	unsigned int operationsInsert = 0;
	unsigned int operationsFind = 0;
	unsigned int operationsDelete = 0;
	bool empty();
	int size() const;
	bool push_back(T newEntry);
	bool insert(int position, T val);
	bool erase(int indexRemove);
	bool remove(T anEntry);
	bool find(T anEntry);
	T getValue(int indexGet);
	void clear();
	Node<T>* getTail();
	// Default Constructor        
	List();
	// Destructor          
	virtual ~List();

	//******************************************************
	// operator<<        
	//******************************************************
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr);
};
//******************************************************
// empty        
//
// Returns whether the list container is empty
//******************************************************
template<class T>
bool List<T>::empty()
{
	operationsTotal += 2;
	if (itemCount == 0) 
		return true;
	return false;
}

//******************************************************
// size         
//
// Returns the number of elements in the list container.
//******************************************************
template<class T>
int List<T>::size() const
{
	operationsTotal += 1;
	return itemCount;
}

//******************************************************
// push_back             
//
// posts to the end of the list. If successful, newEntry 
// is stored in the list and the count of items in the 
// list has increased by 1.
// param newEntry The object to be added as a new entry.
// return True if addition was successful, or false if not.    
//******************************************************
template<class T>
bool List<T>::push_back(T newEntry)
{
	Node<T> *newNode;
	Node<T> *currentNode;
	bool returnStatus = true;

	newNode = new Node<T>(newEntry);

	if (empty())
	{
		tail = newNode;
		head = tail;
		itemCount++;
		operationsTotal += 3;
	}
	else
	{
		currentNode = tail;

		while (currentNode->next)
			currentNode = currentNode->next;

		currentNode->next = newNode;
		head = currentNode->next;
		itemCount++;
		operationsTotal += 6;
	}
	operationsTotal += 5;
	operationsTotal += newNode->operationsTotal;
	return returnStatus;
}
//******************************************************
// insert       
//
// The container is extended by inserting new elements 
// before the element at the specified position.
// This effectively increases the list size by the
// amount of elements inserted.
//******************************************************
template<class T>
bool List<T>::insert(int position, T val)
{
	Node<T> *newNode;
	Node<T> *currentNode;
	Node<T> *prevNode;
	bool returnStatus = false;
	unsigned int i;

	newNode = new Node<T>(newEntry);
	currentNode = tail;

	if (position <= 0 && position <= itemCount - 1)
	{
		for (i = 0; i <= position; i++)
		{
			if (i == position)
			{
				returnStatus = true;
				if (i != 0) prevNode->next = newNode;
				else tail = newNode;
				if (i != itemCount - 1) newNode->next = currentNode;
				else head = newNode;
				operationsTotal += 6;
			}
			else
			{
				prevNode = currentNode;
				currentNode = currentNode->next;
				operationsTotal += 3;
			}
			operationsTotal += 2;
		}
	}
	operationsTotal += newNode->operationsTotal;
	operationsTotal += currentNode->operationsTotal;
	return returnStatus;
}
//******************************************************
// erase          
//
// removes an entry at the defined index
// index 0=tail, SIZE-1=head 
// list count decremented by 1 if successful.
// returns true if addition was successful, or false if not.    
//******************************************************
template<class T>
bool List<T>::erase(int indexRemove)
{
	Node<T> *currentNode;
	Node<T> *prevNode;
	Node<T> *deletedNode;
	bool returnStatus = false;

	currentNode = tail;
	prevNode = nullptr;
	deletedNode = nullptr;
	operationsTotal += 7;
	if (indexRemove >= 0 && indexRemove < itemCount)
	{
		// loop starts from tail and moves towards head.
		for (int i = 0; i <= indexRemove; i++)
		{
			// found the index. lets remove it
			if (i == indexRemove)
			{
				returnStatus = true;
				deletedNode = currentNode;
				if (i == 0)
				{
					// deleted the tail
					if (itemCount > 0)
					{
						currentNode = currentNode->next;
					}
					tail = currentNode;
				}
				else if (i == itemCount - 1)
				{
					// deleted the head
					prevNode->next = nullptr;
					head = prevNode;
				}
				if (i > 0 && i < itemCount - 1)
				{
					// there is a previous and a next
					prevNode->next = currentNode->next;
				}
				delete deletedNode;
				itemCount--;
			}
			// next
			prevNode = currentNode;
			if (i < itemCount - 1)
			{
				currentNode = currentNode->next;
			}
		}
	}
	return returnStatus;
}
//******************************************************
// remove         
//
// removes all entries with the same value
// list count decremented by entries removed if successful.
// returns true if removal was successful, or false if not.    
//******************************************************
template<class T>
bool List<T>::remove(T anEntry)
{
	Node<T> *currentNode;
	Node<T> *prevNode;

	currentNode = tail;
	prevNode = currentNode;
	bool returnStatus = true;

	if (currentNode->value == anEntry)
	{
		currentNode = currentNode->next;
		delete tail;
		tail = currentNode;
		operationsTotal += 4;
	}
	else
	{

		while (currentNode != nullptr && currentNode->value != anEntry)
		{
			prevNode = currentNode;
			currentNode = currentNode->next;
			operationsTotal += 4;
		}

		if (currentNode->value == anEntry && head->value == anEntry)
		{
			prevNode->next = currentNode->next;
			//delete currentNode;
			//delete head;
			head = prevNode;
			operationsTotal += 4;

		}
		else if (currentNode->value == anEntry)
		{
			prevNode->next = currentNode->next;
			delete currentNode;
			operationsTotal += 3;
		}
	}
	if (itemCount != 0)
	{
		itemCount--;
		operationsTotal += 2;
	}
	return returnStatus;
}
//******************************************************
// find         
//
// Tests whether this list contains a given entry.
// param anEntry  The entry to locate.
// return  True if list contains anEntry, or false otherwise.
//******************************************************
template<class T>
bool List<T>::find(T anEntry)
{
	Node<T> *currentNode;
	currentNode = tail;
	while (currentNode)
	{
		operationsTotal += 2;
		if (currentNode->value == anEntry) 
			return true;
		else currentNode = currentNode->next;
	}
	return false;
}
//******************************************************
// getValue           
//
// returns the value of the list node index.
//******************************************************
template<class T>
T List<T>::getValue(int indexGet)
{
	Node<T> *currentNode;
	T returnValue;

	currentNode = tail;
	operationsTotal += 3;
	if (indexGet >= 0 && indexGet < itemCount)
	{
		operationsTotal += 2;
		// loop starts from tail and moves towards head.
		for (int i = 0; i <= indexGet; i++)
		{
			// found the index. lets get it.
			if (i == indexGet)
			{
				returnValue = currentNode->value;
			}
			// next
			if (i < itemCount - 1)
			{
				currentNode = currentNode->next;
			}
			operationsTotal += 4;
		}
	}
	return returnValue;
}
//******************************************************
// clear          
//
// Removes all elements from the list container
// and leaving the container with a size of 0.
//******************************************************
template<class T>
void List<T>::clear()
{
	Node<T> *currentNode;
	Node<T> *deletedNode;
	Node<T> *nextNode;
	operationsTotal += 4;
	if (!empty())
	{
		currentNode = tail;
		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			deletedNode = currentNode;
			currentNode = nextNode;
			delete deletedNode;
			operationsTotal += 5;
		}
		operationsTotal += 2;
	}
	itemCount = 0;
}
//******************************************************
// getTail        
//
// returns tail node
//******************************************************
template<class T>
Node<T>* List<T>::getTail()
{
	return tail;
}

//******************************************************
// Default Constructor        
//******************************************************
template<class T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	itemCount = 0;
	operationsTotal += 3;
}
//******************************************************
// Destructor          
//******************************************************
template<class T>
List<T>::~List()
{
	clear();
}

#endif // !LINKEDLIST_H
