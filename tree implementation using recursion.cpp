#include<stdio.h>
#include<stdlib.h>

struct bnode{
	struct bnode *lc;
	int data;
	struct bnode *rc;
};

struct bnode *create(int val)
{
	struct bnode *temp;
	temp=(struct bnode*)malloc(sizeof(struct bnode));
	temp->data=val;
	temp->lc=temp->rc=NULL;
	return temp;
}

void inorder(struct bnode* temp)
{
	if(temp==NULL)
	return;
	inorder(temp->lc);
	printf("%d ",temp->data);
	inorder(temp->rc);
}

void preorder(struct bnode* temp)
{
	if(temp==NULL)
	return;
	printf("%d ",temp->data);
	preorder(temp->lc);
	preorder(temp->rc);
}

void postorder(struct bnode* temp)
{
	if(temp==NULL)
	return;
	postorder(temp->lc);
	postorder(temp->rc);
	printf("%d ",temp->data);
}

int height(struct bnode *temp)
{
	if(temp==NULL)
		return 0;
	int t1=height(temp->lc);
	int t2=height(temp->rc);
	if(t1>t2)
		return t1+1;
	else
		return t2+1;
}

int main()
{
	struct bnode *root;
	root=create(25);
	root->lc=create(35);
	root->rc=create(45);
	root->lc->rc=create(55);
	printf("Inorder traversal:\n");
	inorder(root);
//	printf("\nPreorder traversal:\n");
//	preorder(root);
//	printf("\nPostorder traversal:\n");
//	postorder(root);
	printf("\nHeight:%d\n",height(root));

}
