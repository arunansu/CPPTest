#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int data)
{
	//struct node* node = (struct node*) malloc(sizeof(struct node));
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool identicalTrees(struct node* a, struct node* b)
{
	if (a == NULL && b == NULL)
		return true;

	if (a != NULL && b != NULL)
	{
		return
			(
				a->data == b->data &&
				identicalTrees(a->left, b->left) &&
				identicalTrees(a->right, b->right)
				);
	}

	return false;
}

int mainBSTSearch()
{
	struct node *root1 = newNode(1);
	struct node *root2 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);

	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	if (identicalTrees(root1, root2))
		cout << "Both trees are identical";
	else
		cout << "Trees are not identical";
	getchar();
	return 0;
}