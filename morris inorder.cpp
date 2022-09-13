#include<stdio.h>
#include<malloc.h>
struct node{
	struct node *lc;
	int data;
	struct node *rc;
};
struct node *create(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->lc=temp->rc=NULL;
	return temp;
}
void inorder(struct node *t1)
{
	if(t1==NULL)
	return;
	while(t1!=NULL){
		if(t1->lc==NULL){
			printf("%d ",t1->data);
			t1=t1->rc;
		}
		else{
			struct node *p1;
			p1=t1->lc;
			while(p1->rc!=NULL && p1->rc!=t1)
			p1=p1->rc;
			if(p1->rc==NULL){
				p1->rc=t1;
				t1=t1->lc;
			}
			else{
				p1->rc=NULL;
				printf("%d ",t1->data);
				t1=t1->rc;
			}
		}
	}
}

int main()
{
	struct node *root;
	root=create(25);
	root->lc=create(35);
	root->rc=create(45);
	root->lc->rc=create(55);
	printf("Inorder traversal:\n");
	inorder(root);
}
