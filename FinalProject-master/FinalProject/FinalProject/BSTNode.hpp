#pragma once
#ifndef BSTNODE_H
#define BSTNODE_H
//**************************
// Node for BST 
//**************************

#include <string>
#include <iostream>
#include "LinkedList.h"


class BSTNode
{
private:
	// data in node for BST
	std::string name;
	int matches, wins, losses, winPercent;
	BSTNode *left;
	BSTNode *right;

public:
	unsigned int operationsTotal = 0;
	unsigned int operationsInsert = 0;
	unsigned int operationsFind = 0;
	unsigned int operationsDelete = 0;
	//default constructor
	BSTNode() {}
	//constructor
	BSTNode(std::string n, int m, int w, int l, int wp) 
	{
		name = n;
		matches = m;
		wins = w;
		losses = l;
		winPercent = wp;

		left = nullptr;
		right = nullptr; 
		operationsTotal += 7;
	}
	
	// setters
	void setName(std::string n) { name = n; operationsTotal += 1; }
	void setMatches(int m) { matches = m; operationsTotal += 1; }
	void setWins(int w) { wins = w; operationsTotal += 1; }
	void setLosses(int l) { losses = l; operationsTotal += 1; }
	void setWinPercent(int wp) { winPercent = wp; operationsTotal += 1; }

	//getters
	std::string getName() { return name; operationsTotal += 1;}
	int getMatches() { return matches; operationsTotal += 1;}
	int getWins() { return wins; operationsTotal += 1;}
	int getLosses() { return losses; operationsTotal += 1;}
	int getWinPercent() { return winPercent; operationsTotal += 1;}


	//get and setters for left child
	void setLeft(BSTNode *l) { left = l; operationsTotal += 1;}
	BSTNode *getLeft() { return left; operationsTotal += 1;}

	//getters and setters for right child
	void setRight(BSTNode *r) { right = r; operationsTotal += 1;}
	BSTNode *getRight() { return right; operationsTotal += 1;}


	//destructor
	virtual ~BSTNode() {}
};
#endif