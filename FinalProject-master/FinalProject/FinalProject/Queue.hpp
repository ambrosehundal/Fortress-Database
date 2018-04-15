#pragma once
#pragma once

#ifndef Queue_hpp
#define Queue_hpp
#include "LinkedList.hpp"
#include <iostream>
//#include <stdio.h>

using namespace std;

template<class T>
class Queue : protected LinkedList<T>
{
public:
	//contructor
	Queue() {}

	// push function 
	void enqueue(T newV);
	//pop function
	T dequeue() { return this->deleteLast(); }
	// return front of Queue (first in)
	T front() { return this->findLast(); }
	// returns rear of Queue (last in = first of queue)
	T rear() { return this->getFirst(); }
	int getNum() { return this->getCount(); }
	void displayQue() { this->display(); }
	//destructor
	~Queue() {}
};



#endif /* queue_hpp */

//************************************
// this to to new item onto the Queue
//*************************************
template<class T>
void Queue<T>::enqueue(T newV)
{
	return  this->append(newV);
}
