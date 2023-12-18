#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void count_of_nodes(struct node *head)
{
	int count=0;
	if(head==NULL)
		printf("List is empty\n");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("Count of nodes = %d\n",count);
}
void print_data(struct node *head)
{
	if(head==NULL)
		printf("List is empty\n");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("Data = %d \n",ptr->data);
		ptr=ptr->link;
	}
}
void add_at_end(struct node *head, int data)
{
	struct node *ptr,*temp;
	ptr=head;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=temp;
	printf("%d\n",temp->data);
}
int main()
{
	/*******Creating node*******/
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
	head->link->link=current;
	printf("%d\n",current->data);
	
	add_at_end(head,34);
	
	count_of_nodes(head);
	
	print_data(head);
	
	return 0;
}

