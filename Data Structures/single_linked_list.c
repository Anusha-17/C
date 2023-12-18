#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
int main()
{
	/******Creating node*******/
	struct node *head=NULL;
	head=(struct node *)malloc(sizeof(struct node));
	head->data=24;
	head->link=NULL;
	printf("%d\n",head->data);
	
	struct node *current=malloc(sizeof(struct node));
	current->data=45;
	current->link=NULL;
	head->link=current;
	printf("%d\n",current->data);
	
	current=malloc(sizeof(struct node));
	current->data=4;
	current->link=NULL;
	head->link->link=NULL;
	printf("%d\n",current->data);
	
	return 0;
}
