#include<stdio.h>
#include<stdlib.h>

struct stack_element{
	int data;
	struct stack_element *next;
};

void show();
void push(int);
int pop();

struct stack_element *top;

void push(int val){
	struct stack_element *temp;
	temp=(struct stack_element *)malloc(sizeof(struct stack_element));
	temp->data=val;
	temp->next=top;
	top=temp;
}

void show(){
	if(top==NULL){
		printf("list is empty");
	}
	struct stack_element *t1=top;
	while(t1!=NULL){
	printf("%d ",t1->data);
	t1=t1->next;}
}

int pop(){
	if(top==NULL){
		printf("list is empty");
	}
	int val=top->data;
	top=top->next;
	return val;
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	show();
	printf("Pop:%d\n",pop());
	show();
}
