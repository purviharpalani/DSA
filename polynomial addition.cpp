#include<stdio.h>
#include<stdlib.h>
struct term
{
	int coef,exp;
	struct term *next;
};
void create(struct term **,int,int);
void show(struct term *);
void add(struct term *p1,struct term *p2,struct term **p3)
{
    struct term *temp;
    if(p1==NULL && p2==NULL)
    {
        printf("\n\nAdding polynomials are empty");
        return;
    }
    while(p1!=NULL && p2!=NULL)
    {
        if(*p3==NULL)
        {
            temp=(struct term *)malloc(sizeof(struct term));
            *p3=temp;
        }
        else
        {
            temp->next=(struct term *)malloc(sizeof(struct term));
            temp=temp->next;
        }
        if(p1->exp>p2->exp)
		{
			temp->coef=p1->coef;
			temp->exp=p1->exp;
			p1=p1->next;
		}
		else
		{
            if(p2->exp>p1->exp)
            {
                temp->coef=p2->coef;
                temp->exp=p2->exp;
                p2=p2->next;
            }
            else
            {
                temp->coef=p2->coef + p1->coef;
                temp->exp=p2->exp;
                p2=p2->next;
                p1=p1->next;
            }
		}
	}
	while(p1!=NULL)
	{
        temp->next=(struct term *)malloc(sizeof(struct term));
        temp=temp->next;
        temp->coef=p1->coef;
        temp->exp=p1->exp;
        p1=p1->next;
	}
    while(p2!=NULL)
	{
        temp->next=(struct term *)malloc(sizeof(struct term));
        temp=temp->next;
        temp->coef=p2->coef;
        temp->exp=p2->exp;
        p2=p2->next;
	}
	temp->next=NULL;
}
int main()
{
    struct term *poly1,*poly2,*poly3;
    poly1=poly2=poly3=NULL;
    create(&poly1,5,3);
    create(&poly1,4,2);
    create(&poly1,5,0);
    printf("\n------------Now First Polynomail is------------\n\n");
    show(poly1);
    create(&poly2,5,2);
    create(&poly2,5,1);
    create(&poly2,8,0);
    printf("\n\n------------Now Second Polynomail is------------\n\n");
    show(poly2);
    add(poly1,poly2,&poly3);
    printf("\n\n------------Now Third Polynomail is------------\n\n");
    show(poly3);
}
void create(struct term **p1,int c,int e)
{
	struct term *temp,*t1;
	temp=(struct term *)malloc(sizeof(struct term));
	temp->coef=c;
	temp->exp=e;
	temp->next=NULL;
	if(*p1==NULL)
	{
		*p1=temp;
		return;
	}
	else
	{
		t1=*p1;
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp;
		return;
	}
}
void show(struct term *t1)
{
	if(t1==NULL)
	{
		printf("Polynomial Empty\n");
		return;
	}
	while(t1!=NULL)
	{
		if(t1->exp==0)
		{
            printf(" %d",t1->coef);
		}
		else
		{
            printf(" %d x%d +",t1->coef,t1->exp);
        }
		t1=t1->next;
	}
}
