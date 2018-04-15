#include <iostream>
#include <string>
#include "LinkedList.h"




using namespace std;


void LinkedListNode::printList() {
	Node<T>* curr = head;

	while (curr != NULL) {
		cout << "Player Name: " << curr->name << endl;
		cout << "Total Matches: " << curr->matches << endl;
		cout << "Wins: " << curr->wins << endl;
		cout << "Losses: " << curr->losses << endl;
		cout << "Winning Percentage: " << curr->winPercent << endl;
		cout << "------------------------" << endl;
		curr = curr->next; 

	}
	 
}
