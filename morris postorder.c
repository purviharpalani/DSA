// CPP program for postorder traversal
//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>
#include<malloc.h>
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
	int visited;
};

void postorder(struct Node* head)
{
	struct Node* temp = head;
	while (temp && temp->visited == 1) {

		// Visited left subtree
		if (temp->left && temp->left->visited == 1)
			temp = temp->left;

		// Visited right subtree
		else if (temp->right && temp->right->visited == 1)
			temp = temp->right;

		// Print node
		else {
			printf("%d ", temp->data);
			temp->visited = 0;
			temp = head;
		}
	}
}

struct Node* newNode(int data)
{
	struct Node* node =malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->visited = 1;
	return (node);
}

/* Driver program to test above functions*/
int main()
{
	struct Node* root = newNode(8);
	root->left = newNode(3);
	root->right = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
//	root->right->right = newNode(14);
//	root->right->right->left = newNode(13);
	postorder(root);
	return 0;
}

