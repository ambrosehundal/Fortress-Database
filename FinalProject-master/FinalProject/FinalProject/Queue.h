
#ifndef QUEUE_H
#define QUEUE_H 
#include "LinkedList.h"


/*
UML notation
*/




template <class T>
class Queue : protected List<T>
{
public:
	unsigned int operationsTotal = 0;
	unsigned int operationsInsert = 0;
	unsigned int operationsFind = 0;
	unsigned int operationsDelete = 0;
	Queue();
	~Queue();
	bool enqueue(newEntry);
	bool dequeue();
	bool empty();
	void clear();
	int size();
	T front();
	T rear();


	//operator<<        
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr);
};


// Default Constructor        
template <class T>
Queue<T>::Queue()
{
	operationsTotal += 1;
	List();

}

// Destructor          
template <class T>
Queue<T>::~Queue()
{
	operationsTotal += 1;
	clear();
}

// enqueue
// insert an entry onto the queue
template <class T>
bool Queue<T>::enqueue(newEntry)
{
	operationsTotal += 1;
	return push_back(newEntry);
}

//dequeue
//remove an entry from the queue
template <class T>
bool Queue<T>::dequeue()
{
	operationsTotal += 1;
	return remove(1);
}

// empty        
// checks whether the queue is empty or not     
template <class T>
bool Queue<T>::empty()
{
	operationsTotal += 1;
	return List::empty();
}



// size         
template <class T>
int Queue<T>::size()
{
	operationsTotal += 1;
	return List::size();
}


// clear          
template <class T>
void Queue<T>::clear()
{
	operationsTotal += 1;
	List::clear();
}


//front
// returns the first element
template <class T>
T Queue<T>::front()
{
	operationsTotal += 1;
	return getValue(1);
}

//rear
//returns the last value in the queue
template <class T>
T Queue<T>::rear()
{
	operationsTotal += 1;
	return getValue(size() - 1);
}

#endif