#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

struct RBTNode
{
	RBTNode * parent;
	RBTNode * left;
	RBTNode * right;
	int key;
	char color;
};

class TRBTree
{
private:
	RBTNode guard;          
	RBTNode * root;        
	string cr, cl, cp;       

	void PrintRBT(string sp, string sn, RBTNode * p); 

public:
	TRBTree(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\trbtree.txt");
	void Show();          
	RBTNode * Find(int value); 
	RBTNode * FindSuccessor(RBTNode * node);
	void RotateL(RBTNode * node); 
	void RotateR(RBTNode * node); 
	void Add(int k);   
	void Delete(RBTNode * node); 
};

