#include<stdio.h>
#include<malloc.h>

struct queue_element{
	int data;
	struct queue_element *next;
};

struct queue_element *rear, *front;

void enqueue(int val)
{
	struct queue_element *temp;
	temp=(struct queue_element *)malloc(sizeof(struct queue_element));
	temp->data=val;
	temp->next=NULL;
	if(front==NULL)
	{
		front=rear=temp;
		return;
	}
	else
	{
		rear->next=temp;
		rear=temp;
		return;
	}
}

int dequeue()
{
	int t;
	if(front==NULL){
		printf("queue is empty");
	}
	if(front==rear){
		t=front->data;
		front=rear=NULL;
		return t;
	}
	t=front->data;
	front=front->next;
	return t;
}

void display()
{
	if(front==NULL){
		return;
	}
	struct queue_element *t;
	t=front;
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	display();
	printf("\nAfter dequeue:%d\n",dequeue());
	display();
}
