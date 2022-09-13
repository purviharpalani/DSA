#include<stdio.h>
#include<malloc.h>
struct queue{
	int size;
	int front;
	int rear;
	int *Q;
};

void enqueue(struct queue *q,int val)
{
	if(q->rear==q->size-1){
		printf("queue is full");
	}
	else
	{
		q->rear++;
		q->Q[q->rear]=val;
	}
}

int dequeue(struct queue *q)
{
	int temp=-1;
	if(q->front==q->rear){
		printf("queue is empty");
	}
	else{
	q->front++;
	temp=q->Q[q->front];
//	q->Q[q->front]=NULL;
	return temp;}
}

void display(struct queue q)
{
	for(int i=q.front+1;i<=q.rear;i++)
	printf("%d\n",q.Q[i]);
	
}

void create(struct queue *q,int size){
	q->size=size;
	q->front=q->rear=-1;
	q->Q=(int *)malloc(q->size*sizeof(int));	
}


int main()
{
	struct queue q;
//	printf("enter size:");
//	scanf("%d",&q.size);
	create(&q,5);
	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,40);
	enqueue(&q,50);
	display(q);
	printf("Deleted value:%d\n",dequeue(&q));
	display(q);
	printf("Deleted value:%d\n",dequeue(&q));
	display(q);
	
}
