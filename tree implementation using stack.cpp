#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *lc;
	int data;
	struct node *rc;
};

struct node *stack[20];
int top=-1;

void push(struct node *t1)
{
	stack[++top]=t1;
}

struct node *pop()
{
	return stack[top--];
}

struct node *create(int val)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->lc=temp->rc=NULL;
	return temp;
}

void inorder(struct node *temp)
{
	if(temp==NULL)
	return;
	while(1){
	while((temp->lc)!=NULL)
	{
		push(temp);
		temp=temp->lc;
	}
	while((temp->rc)==NULL)
	{
		printf("%d ",temp->data);
		if(top==-1)
		return;
		temp=pop();
	}
	while((temp->rc)!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->rc;
	}}
}

void root_leaf(struct node *tp,int out[],int index)
{
    if(tp==NULL)
    {
        return;
    }
    out[index]=tp->data;
    index++;
    if(tp->lc==NULL && tp->rc==NULL)
    {
        int i=0;
        for(i=0;i<index;i++)
        {
            printf(" %d",out[i]);
        }
        printf("\n");
    }
    root_leaf(tp->lc,out,index);
    root_leaf(tp->rc,out,index);
}

void preorder(struct node *temp)
{
	if(temp==NULL)
	return;
	push(temp);
	while(top!=-1)
	{
		temp=pop();
		printf("%d ",temp->data);
		if((temp->rc)!=NULL)
		push(temp->rc);
		if((temp->lc)!=NULL)
		push(temp->lc);
	}
}
void postorder(struct node *temp)
{
	if(temp=NULL)
	return;
	while(1){
	while((temp->lc)!=NULL)
	{
		push(temp);
		temp=temp->lc;
	}
	while((temp->rc)==NULL)
	{
		printf("%d ",temp->data);
		if(top==-1)
		return;
		temp=pop();
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
//	printf("Inorder traversal:\n");
//	inorder(root);
//	printf("\nPreorder traversal:\n");
//	preorder(root);
	printf("\nPostorder traversal:\n");
	postorder(root);
//	root_leaf(root,stack[],)
}

