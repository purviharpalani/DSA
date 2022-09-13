#include<stdio.h>
#include<conio.h>
#include<inttypes.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *npx;
};
struct node *header,*last;
struct node *XOR(struct node *prev,struct node *next)
{
	return (struct node *)((uintptr_t)(prev)^(uintptr_t)(next));
}
void create(int val)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=val;
	temp->npx=NULL;
	if(header==NULL)
	{
		header=last=temp;
		return;
	}
	else{
		last->npx=XOR(last->npx,temp);
		temp->npx=last;
		last=temp;
		return;
	}
}
void display()
{
	struct node *t1=header;
	struct node *prev=NULL,*curr=NULL;
	printf("In forward direction:\n");
	while(t1!=NULL)
	{
		printf("%d ",t1->data);
		curr=t1;
		t1=XOR(prev,t1->npx);
		prev=curr;
	}
	printf("\nIn backward direction:\n");
	t1=last;
	prev=NULL;
	while(t1!=NULL)
	{
		printf("%d ",t1->data);
		curr=t1;
		t1=XOR(prev,t1->npx);
		prev=curr;
	}
}

int main()
{
	create(5);
	create(10);
	create(15);
	create(20);
	display();
}
