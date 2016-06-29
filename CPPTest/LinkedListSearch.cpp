#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int i)
	{
		data = i;
		next = NULL;
	}
};

int nodeAtM(int m, node *root)
{
	int i = 2;
	node *n1 = root;
	node *n2 = root->next;
	while (n2->next != NULL)
	{
		i += 1;
		n2 = n2->next;
		if (i > m)
		{
			n1 = n1->next;
		}
	}
	return n1->data;
}

int mainLinkedListSearch()
{
	node* n = new node(1);
	n->next = new node(2);
	n->next->next = new node(3);
	n->next->next->next = new node(4);
	n->next->next->next->next = new node(5);
	cout << nodeAtM(3, n) << endl;
	cout << nodeAtM(4, n) << endl;
	getchar();
	return 0;
}