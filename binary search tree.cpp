#include<stdio.h>
#include<malloc.h>
struct node{
	struct node *lc;
	int data;
	struct node *rc;
};
struct node *root;

node * insert(node *p,int key)
{
	node *t;
	if(p==NULL)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=key;
		t->lc=t->rc=NULL;
		return t;
	}
	if(key<p->data)
		p->lc=insert(p->lc,key);
	else if(key>p->data)
		p->rc=insert(p->rc,key);
	return p;
}

void inorder(node *temp)
{
	if(temp==NULL)
	return;
	inorder(temp->lc);
	printf("%d ",temp->data);
	inorder(temp->rc);
}

void preorder(struct node* temp)
{
	if(temp==NULL)
	return;
	printf("%d ",temp->data);
	preorder(temp->lc);
	preorder(temp->rc);
}

void postorder(struct node* temp)
{
	if(temp==NULL)
	return;
	postorder(temp->lc);
	postorder(temp->rc);
	printf("%d ",temp->data);
}
//struct node *minvaluenode(struct node *Node){
//	struct node *curr=Node;
//	while(curr->lc!=NULL)
//		curr=curr->lc;
//	return curr;
//}

node * delete_n(struct node *root,int val)
{
	if(root==NULL)
	{
		return root;
	}
	if(val<root->data){
		root->lc=delete_n(root->lc,val);
	}
	else if(val>root->data){
		root->rc=delete_n(root->rc,val);
	}
	else{
		if(root->lc==NULL){
			struct node *temp=root->rc;
			free(root);
			return temp;
		}
		else if(root->rc==NULL){
			struct node *temp=root->lc;
			free(root);
			return temp;
		}
		else
        {
            struct node *p1=root->rc;
            while(p1->lc!=NULL)
            {
                p1=p1->lc;
            }
            root->data=p1->data;
            root->rc=delete_n(root->rc,p1->data);
        }
	}
	return root;
}

int main()
{
	root=NULL;
	root=insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,50);
	insert(root,60);
	insert(root,10);
	printf("Inorder traversal:");
	inorder(root);
	printf("\nPreorder traversal:");
	preorder(root);
	printf("\nPostorder traversal:");
	postorder(root);
	printf("\nafter deletion,inorder traversal:\n");
	delete_n(root,30);
	inorder(root);
}
