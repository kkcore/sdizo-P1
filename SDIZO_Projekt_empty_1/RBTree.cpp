#include "RBTree.h"


RBTNode* RBTree::guard;
RBTNode* RBTree::root;
RBTree* RBTree::instance;

RBTree::RBTree(std::string data)
{
	InitializeStart();
	std::ifstream rtbtreetnodet(data);
	int i = 0;
	for (std::string line; getline(rtbtreetnodet, line);) {
		if (i >= 1)
			Add(stoi(line));
		i++;
	}
}

void RBTree::InitializeStart() {
	guard = new RBTNode();
	guard->color = 'B';
	guard->left = guard;
	guard->right = guard;
	guard->parent = guard;
	root = guard;
}

void RBTree::RotateL(RBTNode* node)
{
	RBTNode* son, *parent;
	son = node->right;
	if (node != guard)
	{
		parent = node->parent;
		node->right = son->left;
		if (node->right != guard)
			node->right->parent = node;
		son->left = node;
		son->parent = parent;
		node->parent = son;
		if (parent != guard) {
			if (parent->left == node)
				parent->left = son;
			else
				parent->right = son;
		}
		else
			root = son;
	}
}

void RBTree::RotateR(RBTNode* node)
{
	RBTNode* son, *parent;
	son = node->left;
	if (node != guard)
	{
		parent = node->parent;
		node->left = son->right;
		if (node->left != guard)
			node->left->parent = node;
		son->right = node;
		son->parent = parent;
		node->parent = son;
		if (parent != guard) {
			if (parent->right == node)
				parent->right = son;
			else
				parent->left = son;
		}
		else
			root = son;
	}
}

RBTNode * RBTree::GetSuccessor(RBTNode * node)
{
	RBTNode * helper;

	if (node != guard)
	{
		if (node->right != guard) {
			RBTNode* x = node->right;
			if (x != guard) {
				while (x->left != guard)
					x = x->left;
				return x;
			}
		}
		else
		{
			helper = node->parent;
			while ((helper != guard) && (node == helper->right))
			{
				node = helper;
				helper = helper->parent;
			}
			return helper;
		}
	}
	return guard;
}

void RBTree::Delete(int value)
{
	RBTNode* node = Find(value);
	if (node) {
		RBTNode * W, *Y, *Z;

		if ((node->left == guard) || (node->right == guard))
			Y = node;
		else
			Y = GetSuccessor(node);

		if (Y->left != guard) Z = Y->left;
		else              Z = Y->right;

		Z->parent = Y->parent;

		if (Y->parent == guard) root = Z;
		else if (Y == Y->parent->left) Y->parent->left = Z;
		else                      Y->parent->right = Z;

		if (Y != node) node->value = Y->value;

		if (Y->color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
			while ((Z != root) && (Z->color == 'B'))
				if (Z == Z->parent->left)
				{
					W = Z->parent->right;

					if (W->color == 'R')
					{              // Przypadek 1
						W->color = 'B';
						Z->parent->color = 'R';
						RotateL(Z->parent);
						W = Z->parent->right;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{              // Przypadek 2
						W->color = 'R';
						Z = Z->parent;
						continue;
					}

					if (W->right->color == 'B')
					{              // Przypadek 3
						W->left->color = 'B';
						W->color = 'R';
						RotateR(W);
						W = Z->parent->right;
					}

					W->color = Z->parent->color; // Przypadek 4
					Z->parent->color = 'B';
					W->right->color = 'B';
					RotateL(Z->parent);
					Z = root;         // To spowoduje zakoñczenie pêtli
				}
				else
				{                // Przypadki lustrzane
					W = Z->parent->left;

					if (W->color == 'R')
					{              // Przypadek 1
						W->color = 'B';
						Z->parent->color = 'R';
						RotateR(Z->parent);
						W = Z->parent->left;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{              // Przypadek 2
						W->color = 'R';
						Z = Z->parent;
						continue;
					}

					if (W->left->color == 'B')
					{              // Przypadek 3
						W->right->color = 'B';
						W->color = 'R';
						RotateL(W);
						W = Z->parent->left;
					}

					W->color = Z->parent->color;  // Przypadek 4
					Z->parent->color = 'B';
					W->left->color = 'B';
					RotateR(Z->parent);
					Z = root;         // To spowoduje zakoñczenie pêtli
				}

		Z->color = 'B';

		delete Y;
		std::cout << "Element zosta³ usuniêty" << std::endl;
	}
	else
	std::cout << "Taki element nie znajduje siê w drzewie" << std::endl;
}

void RBTree::Add(int value) {
	RBTNode* newnode;
	newnode = new RBTNode();
	newnode->left = guard;
	newnode->right = guard;
	newnode->parent = root;
	newnode->value = value;
	//Sprawdzanie, czy drzewo nie jest puste
	if (newnode->parent == guard) {
		root = newnode;
		newnode->color = 'B';
		return;
	}
	else {
		while (true) { //Je¿eli nie jest puste to wstawianie jak w drzewach BST (ró¿nica jest taka, ¿e porównujemy z adresem stra¿nika a nie NULLEM
			if (value < newnode->parent->value) {
				if (newnode->parent->left == guard) {
					newnode->parent->left = newnode;
					break;
				}
				newnode->parent = newnode->parent->left;
			}
			else
			{
				if (newnode->parent->right == guard) {
					newnode->parent->right = newnode;
					break;
				}
				newnode->parent = newnode->parent->right;
			}
		}
	}
	//Zmiana koloru na czerwony wstawianego liœcia i sprawdzanie warunków drzewa czerwono-czarnego
	newnode->color = 'R';
	if (newnode->parent->color == 'B')
		return;
	//Je¿eli ojciec jest czarny to warunki zostan¹ zachowane, je¿eli nie to musimy sprawdziæ odpowiednie przypadki
	//Przypadek, w którym wujek wstawianego wêz³a jest czerwony
	RBTNode* grandparent = newnode->parent->parent;
	while (newnode != root && newnode->parent->color == 'R')
	{
		//Przypadek dla lewej czesci drzewa
		if (grandparent->left == newnode->parent) {

			RBTNode* uncle = grandparent->right;
			if (uncle->color == 'R')
			{
				uncle->color = 'B';
				newnode->parent->color = 'B';
				grandparent->color = 'R';
				if (grandparent == root)
					grandparent->color = 'B';
				newnode = grandparent;
				continue;

			}
			else {
				//Przypadek 2 (Wujek jest czarny, a wstawiany wêzê³ jest prawym dzieckiem rodzica)
				if (newnode->parent->right == newnode) {
					newnode = newnode->parent;
					RotateL(newnode);
				}
				//Przypadek 3 
				newnode->parent->color = 'B';
				grandparent->color = 'R';
				RotateR(grandparent);
				break;
			}
		}
		//Przypadki lustrzane (lewa czesc drzewa)
		else {
			RBTNode* uncle = grandparent->left;
			if (uncle->color == 'R') 
			{
				uncle->color = 'B';
				newnode->parent->color = 'B';
				grandparent->color = 'R';
				if (grandparent == root)
					grandparent->color = 'B';
				newnode = grandparent;
				continue;
			}
			else {
				if (newnode->parent->left == newnode) {
					newnode = newnode->parent;
					RotateR(newnode);
				}
				newnode->parent->color = 'B';
				grandparent->color = 'R';
				RotateL(grandparent);
				break;
			}
		}
		root->color = 'B';
	}
	std::cout << "Element zosta³ wstawiony" << std::endl;
}

RBTNode * RBTree::Find(int value)
{
	RBTNode* helper = root;
	while (helper != guard) {
		if (value == helper->value)
			return helper;
		if (value > helper->value) {
			helper = helper->right;
		}
		if (value < helper->value)
			helper = helper->left;
	}
	return nullptr;
}

RBTree * RBTree::GetInstance()
{
	if (instance == NULL)
		instance = new RBTree();
	return instance;
}

void RBTree::Show(std::string sp, std::string sn, RBTNode* v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218;
	cr[1] = 196;
	cl[0] = 192;
	cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v != guard)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		Show(s + cp, cr, v->right);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << v->value << v->color << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		Show(s + cp, cl, v->left);
	}
}

static RBTNode* GetUncle(RBTNode* node)
{
	if (node->parent->parent->right != node->parent)
		return node->parent->parent->right;
	else
		return node->parent->parent->left;
}
