#include "TRBTree.h"



TRBTree::TRBTree(std::string data)
{

	guard.color = 'B';         
	guard.parent = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;         

	std::ifstream rtbtreetnodet(data);
	int i = 0;
	for (std::string line; getline(rtbtreetnodet, line);) {
		if (i >= 1)
			Add(stoi(line));
		i++;
	}
}



void TRBTree::PrintRBT(string sp, string sn, RBTNode * node)
{
	string t;
	string cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	if (node != &guard)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		PrintRBT(t + cp, cr, node->right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << node->key << node->color << endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		PrintRBT(t + cp, cl, node->left);
	}
}

void TRBTree::Show()
{
	PrintRBT("", "", root);
}

RBTNode * TRBTree::Find(int k)
{
	RBTNode * p;

	p = root;
	while ((p != &guard) && (p->key != k))
		if (k < p->key) p = p->left;
		else           p = p->right;
	if (p == &guard) return NULL;
	return p;
}


RBTNode * TRBTree::FindSuccessor(RBTNode * node)
{
	RBTNode * r;

	if (node != &guard)
	{
		if (node->right != &guard) {
			if (node != &guard)
				while (node->left != &guard) node = node->left;
			return node;
		}
		else
		{
			r = node->parent;
			while ((r != &guard) && (node == r->right))
			{
				node = r;
				r = r->parent;
			}
			return r;
		}
	}
	return &guard;
}

void TRBTree::RotateL(RBTNode * node)
{
	RBTNode * pivot, *parent;

	pivot = node->right;
	if (pivot != &guard)
	{
		parent = node->parent;
		node->right = pivot->left;
		if (node->right != &guard) node->right->parent = node;

		pivot->left = node;
		pivot->parent = parent;
		node->parent = pivot;

		if (parent != &guard)
		{
			if (parent->left == node) parent->left = pivot; else parent->right = pivot;
		}
		else root = pivot;
	}
}

void TRBTree::RotateR(RBTNode * node)
{
	RBTNode * pivot, *parent;

	pivot = node->left;
	if (pivot != &guard)
	{
		parent = node->parent;
		node->left = pivot->right;
		if (node->left != &guard) node->left->parent = node;

		pivot->right = node;
		pivot->parent = parent;
		node->parent = pivot;

		if (parent != &guard)
		{
			if (parent->left == node) parent->left = pivot; else parent->right = pivot;
		}
		else root = pivot;
	}
}

void TRBTree::Add(int k)
{
	RBTNode * child, *uncle;

	child = new RBTNode;        
	child->left = &guard;       
	child->right = &guard;
	child->parent = root;
	child->key = k;
	if (child->parent == &guard) root = child; 
	else
		while (true)             
		{
			if (k < child->parent->key)
			{
				if (child->parent->left == &guard)
				{
					child->parent->left = child;  
					break;
				}
				child->parent = child->parent->left;
			}
			else
			{
				if (child->parent->right == &guard)
				{
					child->parent->right = child; 
					break;
				}
				child->parent = child->parent->right;
			}
		}
	child->color = 'R';        
	while ((child != root) && (child->parent->color == 'R'))
	{
		if (child->parent == child->parent->parent->left)
		{
			uncle = child->parent->parent->right; 

			if (uncle->color == 'R')
			{
				child->parent->color = 'B';
				uncle->color = 'B';
				child->parent->parent->color = 'R';
				child = child->parent->parent;
				continue;
			}

			if (child == child->parent->right) 
			{
				child = child->parent;
				RotateL(child);
			}

			child->parent->color = 'B'; 
			child->parent->parent->color = 'R';
			RotateR(child->parent->parent);
			break;
		}
		else
		{               
			uncle = child->parent->parent->left;

			if (uncle->color == 'R') 
			{
				child->parent->color = 'B';
				uncle->color = 'B';
				child->parent->parent->color = 'R';
				child = child->parent->parent;
				continue;
			}

			if (child == child->parent->left) 
			{
				child = child->parent;
				RotateR(child);
			}

			child->parent->color = 'B'; 
			child->parent->parent->color = 'R';
			RotateL(child->parent->parent);
			break;
		}
	}
	root->color = 'B';
}

void TRBTree::Delete(RBTNode * node)
{
	RBTNode * a, *b, *c;

	if ((node->left == &guard) || (node->right == &guard))
		b = node;
	else                                  
		b = FindSuccessor(node);

	if (b->left != &guard)
		c = b->left;
	else            
		c = b->right;

	c->parent = b->parent;

	if (b->parent == &guard) 
		root = c;
	else if (b == b->parent->left)
		b->parent->left = c;
	else                     
		b->parent->right = c;

	if (b != node)
		node->key = b->key;

	if (b->color == 'B')  
		while ((c != root) && (c->color == 'B'))
			if (c == c->parent->left)
			{
				a = c->parent->right;

				if (a->color == 'R')
				{              
					a->color = 'B';
					c->parent->color = 'R';
					RotateL(c->parent);
					a = c->parent->right;
				}

				if ((a->left->color == 'B') && (a->right->color == 'B'))
				{            
					a->color = 'R';
					c = c->parent;
					continue;
				}

				if (a->right->color == 'B')
				{            
					a->left->color = 'B';
					a->color = 'R';
					RotateR(a);
					a = c->parent->right;
				}

				a->color = c->parent->color;
				c->parent->color = 'B';
				a->right->color = 'B';
				RotateL(c->parent);
				c = root;        
			}
			else
			{                
				a = c->parent->left;

				if (a->color == 'R')
				{             
					a->color = 'B';
					c->parent->color = 'R';
					RotateR(c->parent);
					a = c->parent->left;
				}

				if ((a->left->color == 'B') && (a->right->color == 'B'))
				{           
					a->color = 'R';
					c = c->parent;
					continue;
				}

				if (a->left->color == 'B')
				{             
					a->right->color = 'B';
					a->color = 'R';
					RotateL(a);
					a = c->parent->left;
				}

				a->color = c->parent->color;  
				c->parent->color = 'B';
				a->left->color = 'B';
				RotateR(c->parent);
				c = root;        
			}

	c->color = 'B';

	delete b;
}
