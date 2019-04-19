#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 30;           // Liczba w�z��w
struct RBTNode
{
	RBTNode * up;
	RBTNode * left;
	RBTNode * right;
	int key;
	char color;
};

class TRBTree
{
private:
	RBTNode S;             // W�ze� stra�nika
	RBTNode * root;        // Korze� drzewa czerwono-czarnego
	string cr, cl, cp;       // �a�cuchy do znak�w ramek

	void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

public:
	TRBTree();             // Konstruktor klasy
	~TRBTree();            // Destruktor klasy
	void DFSRelease(RBTNode * p); // Usuwa rekurencyjnie drzewo
	void print();          // Wypisuje drzewo
	RBTNode * findRBT(int k); // Wyszukuje w�ze� o kluczu k
	RBTNode * minRBT(RBTNode * p); // Wyszukuje najmniejszy w�ze� w p
	RBTNode * succRBT(RBTNode * p);// Wyszukuje nast�pnik p
	void rot_L(RBTNode * A); // Rotacja w lewo wzgl�dem A
	void rot_R(RBTNode * A); // Rotacja w prawo wzgl�dem A
	void insertRBT(int k);   // Wstawia w�ze� o kluczu k
	void removeRBT(RBTNode * X); // Usuwa w�ze� X
};

