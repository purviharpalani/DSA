#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *header,*last;

void create(int t){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=t;
	temp->next=NULL;
	if(header==NULL){
		header=last=temp;
		return;
	}
	else{
		last->next=temp;
		last=temp;
	}
}

void display(){
	if(header==NULL){
		printf("list is empty");
	}
	else{
		struct node *t=header;
		while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	    }
	}
}

void swap(){
	struct node *p1=header;
	struct node *p2=header->next;
	struct node *p3=p2->next;
	header=p2;
	if(header==NULL || header->next==NULL){
		return; 
	}
	while(1){
		p2->next=p1;
		if(p3==NULL || p3->next==NULL){
			p1->next=p3;
			return;
		}
		else{
			p1->next=p3->next;
			p1=p3;
			p2=p3->next;
			p3=p2->next;
		}
		
	}	
	
}

int main()
{
	create(10);
	create(20);
	create(30);
	create(40);
	display();
	swap();
	printf("\nAfter pairwaise swapping, list becomes:\n");
	display();
}
