#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Hash::Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new player;
		hashTable[i]->name = "empty";
		hashTable[i]->matches = 0;
		hashTable[i]->wins = 0;
		hashTable[i]->losses = 0;
		hashTable[i]->winPercent = 0;
		hashTable[i]->next = NULL;
		operationsTotal += 7;
	}
}

int Hash::numberOfCollisions()
{
	int num;
	int count = 0;
	for (int i = 0; i < tableSize; i++)
	{
		num = numberOfItemsInIndex(i);
		if (num == 1)
		{
			continue;
		}
		count += num;
		operationsTotal += 3;
	}
	return count;
}
int Hash::hash(string key)
{
	int hash = 0;
	int index;

	for (int i = 0; i < 3; i++)
	{
		hash = (hash+(int)key[i])*17;
		operationsTotal += 3;
	}
	index = hash % tableSize;
	operationsTotal += 2;
	return index;
}

void Hash::addItem(string name, int matches, int wins, int losses, int winPercent)
{
	int index = hash(name);

	if (hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->matches = matches;
		hashTable[index]->wins = wins;
		hashTable[index]->losses = losses;
		hashTable[index]->winPercent = winPercent;
		operationsTotal += 7;
	}
	else
	{
		player* Ptr = hashTable[index];
		player* n = new player;
		n->name = name;
		n->matches = matches;
		n->wins = wins;
		n->losses = losses;
		n->winPercent = winPercent;
		n->next = NULL;
		// to keey track of # of colliosions
		 // for load factor + collisions
		int i = 0;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
			i++;
			operationsTotal += 3;
		}

		Ptr->next = n;
		operationsTotal += 9;
	}
}

int Hash::numberOfItemsInIndex(int index)
{
	int count = 0;
	if (hashTable[index]->name == "empty")
	{
		operationsTotal += 2;
		return count;
	}
	else
	{
		operationsTotal += 3;
		count++;
		player* ptr = hashTable[index];
		while (ptr->next != NULL)
		{
			operationsTotal += 2;
			count++;
			ptr = ptr->next;
		}
	}
	return count;

}

void Hash::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		player* y = hashTable[i];
		number = numberOfItemsInIndex(i);
		operationsTotal += 4;
		for (int x = 0; x < number; x++)
		{
			cout << "*********************" << endl;
			cout << "index = " << i << endl;
			cout << y->name << endl;
			cout << "Number of matches played: " <<y->matches << endl;
			cout << "Number of wins: " << y->wins << endl;
			cout << "Number of losses: " << y->losses << endl;
			cout << "Win Percentage: " << y->winPercent << "%" << endl;
			cout << "# of items = " << number << endl;
			cout << "*********************" << endl;
			y = y->next;
			operationsTotal += 15;
		}
	}
}

void Hash::PrintItemsInIndex(int index)
{
	player* Ptr = hashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << " is empty.";
	}
	else
	{
		cout << "index = " << index << " contains the following players" << endl;
		while (Ptr != NULL)
		{
			cout << "*********************" << endl;
			cout << Ptr->name << endl;
			cout << "Number of matches played: " << Ptr->matches << endl;
			cout << "Number of wins: " << Ptr->wins << endl;
			cout << "Number of losses: " << Ptr->losses << endl;
			cout << "Win Percentage: " << Ptr->winPercent << "%" << endl;
			cout << "*********************" << endl;
			Ptr = Ptr->next;
		}
	}
	operationsTotal += 15;
}

Hash::player* Hash::FindPlayer(string name)
{
	int index = hash(name);
	bool foundName = false;
	int matches, wins, losses, winPercent;
	player* Ptr = hashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			matches = Ptr->matches;
			wins = Ptr->wins;
			losses = Ptr->losses;
			winPercent = Ptr->winPercent;
			operationsTotal += 5;
			break;
		}
		Ptr = Ptr->next;
		operationsTotal += 3;
	}

	return Ptr;
}

void Hash::FindPlayer(int index, string name)
{
	player* Ptr = hashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << " is empty. Player not found";
		operationsTotal += 2;
	}
	else
	{
		while (Ptr != NULL)
		{
			if (Ptr->name == name)
			{
				cout << "*********************" << endl;
				cout << Ptr->name << endl;
				cout << "Number of matches played: " << Ptr->matches << endl;
				cout << "Number of wins: " << Ptr->wins << endl;
				cout << "Number of losses: " << Ptr->losses << endl;
				cout << "Win Percentage: " << Ptr->winPercent << "%" << endl;
				cout << "*********************" << endl;
			}
			Ptr = Ptr->next;
			operationsTotal += 7;
		}
		operationsTotal += 1;
	}
}
Hash::player* Hash::returnPlayerPointer(string name)
{
	int index = hash(name);
	bool foundName = false;
	player* Ptr = hashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			break;
			operationsTotal += 1;
		}
		Ptr = Ptr->next;
		operationsTotal += 3;
	}
	return Ptr;
}

void Hash::removePlayer(string name)
{
	int index = hash(name);
	
	player* delPtr;
	player* P1;
	player* P2;

	if (hashTable[index]->name == "empty")
	{
		cout << name << " was not found in the Hash table" << endl;
		operationsTotal += 1;
	}
	else if (hashTable[index]->name == name && hashTable[index]->next == NULL)
	{
		hashTable[index]->name = "empty";
		hashTable[index]->losses = 0;
		hashTable[index]->matches = 0;
		hashTable[index]->winPercent = 0;
		hashTable[index]->wins = 0;
		cout << name << " was removed from Hash Table" << endl;
		operationsTotal += 7;
	}
	
	else if (hashTable[index]->name == name)
	{
		delPtr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delPtr;
		cout << name << " was removed from Hash Table" << endl;
		operationsTotal += 7;
	}
	else
	{
		P1 = hashTable[index]->next;
		P2 = hashTable[index];
		operationsTotal += 5;
		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
			operationsTotal += 4;
		}
		if (P1 == NULL)
		{
			cout << name << " was not found in the Hash table" << endl;
			operationsTotal += 1;
		}
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			cout << name << " was removed from Hash Table" << endl;
			operationsTotal += 4;
		}
	}
	

}

void Hash::printEachName()
{
	int index = 0;
	int i = 0;
	player* Ptr;
	operationsTotal += 3;
	while (index < tableSize)
	{
		Ptr = hashTable[index];
		if (Ptr->name == "empty")
		{
			index++;
			operationsTotal += 2;
			continue;
		}
		else
		{
			operationsTotal += 1;
			while (Ptr != NULL)
			{
				cout << i << ") " <<Ptr->name << endl;
				i++;
				Ptr = Ptr->next;
				operationsTotal += 3;
			}
		}
		index++;
		operationsTotal += 2;
	}
}
