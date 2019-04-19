#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 30;           // Liczba wêz³ów
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
	RBTNode S;             // Wêze³ stra¿nika
	RBTNode * root;        // Korzeñ drzewa czerwono-czarnego
	string cr, cl, cp;       // £añcuchy do znaków ramek

	void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

public:
	TRBTree();             // Konstruktor klasy
	~TRBTree();            // Destruktor klasy
	void DFSRelease(RBTNode * p); // Usuwa rekurencyjnie drzewo
	void print();          // Wypisuje drzewo
	RBTNode * findRBT(int k); // Wyszukuje wêze³ o kluczu k
	RBTNode * minRBT(RBTNode * p); // Wyszukuje najmniejszy wêze³ w p
	RBTNode * succRBT(RBTNode * p);// Wyszukuje nastêpnik p
	void rot_L(RBTNode * A); // Rotacja w lewo wzglêdem A
	void rot_R(RBTNode * A); // Rotacja w prawo wzglêdem A
	void insertRBT(int k);   // Wstawia wêze³ o kluczu k
	void removeRBT(RBTNode * X); // Usuwa wêze³ X
};

