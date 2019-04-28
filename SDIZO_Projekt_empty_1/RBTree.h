#pragma once
#include <fstream>
#include <iostream>
#include <string>

struct RBTNode
{
	RBTNode* parent;
	RBTNode* left;
	RBTNode* right;
	int value;
	char color;
};
class RBTree
{
private:
	RBTree(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt");
	static RBTree* instance;
	static RBTNode* root;
	static RBTNode* guard;
	static void InitializeStart();
	static void RotateL(RBTNode* node);
	static void RotateR(RBTNode* node);
	static RBTNode* GetSuccessor(RBTNode* node);

public:
	static RBTree* GetInstance();
	static void Show(std::string sp = "", std::string sn = "", RBTNode* v = root);
	static void Delete(int value);
	static void Add(int value);
	static RBTNode* Find(int value);
};

