#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;           
    struct node *next; 
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtPosition(int data,int position);
void deleteNodeAtBeginning();
void deleteNodeAtEnd();
void displayList();
void sortlist();
void reverselist();
void searchNode(int data);


/*int main()
{
    int n, data;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in the list \n");
    displayList();
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);
    printf("\nData in the list \n");
    displayList();
    printf("\nSoring the list \n");
    sortlist();
    displayList();
    
    printf("\nReversing the list \n");
    reverselist();
    displayList();
    
    return 0;
}*/

int main()
{
	int choice,data,n,position;
	printf("Enter the total number of nodes: ");
	scanf("%d",&n);
	
	createList(n);
	
	do
	{
		printf("\n1.Display List \n");
		printf("2.Insert Node at Beginning\n");
		printf("3.Insert Node at End\n");
		printf("4.Delete Node at Beginning\n");
		printf("5.Delete Node at End\n");
		printf("6.Search for a Node\n");
		printf("7.Sort the list\n");
		printf("8.Reverse the list\n");
		printf("9.Insert Node at position\n");
		printf("0.Exit\n");
		
		printf("Enter your choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0: printf("Exiting the program\n");
				break;
			case 1: printf("\nData in the list\n");
				displayList();
				break;
			case 2: printf("Enter the data to insert at the beginning:");
				scanf("%d",&data);
				insertNodeAtBeginning(data);
				break;
			case 3: printf("Enter the data to insert at the end:");
				scanf("%d",&data);
				insertNodeAtEnd(data);
				break;
			case 4: deleteNodeAtBeginning();
				break;
			case 5: deleteNodeAtEnd();
				break;
			case 6: printf("Enter the data to search:");
				scanf("%d",&data);
				searchNode(data);
				break;
			case 7: printf("\nSoring the list \n");
    				sortlist();
    				displayList();
    				break;
    			case 8: printf("\nReversing the list \n");
    				reverselist();
    				displayList();
    				break;
    			case 9: printf("\nEnter data to insert:");
    				scanf("%d",&data);
    				printf("Enter the position to insert:");
    				scanf("%d",&position);
    				insertNodeAtPosition(data,position);
    				break;
    			default : printf("Invalid choice. Please enter a valid option.\n");
    		}
    	}while(choice!=0);
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data; 
        head->next = NULL; 
        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertNodeAtBeginning(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 
        head = newNode;          
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertNodeAtEnd(int data)
{
	struct node *newNode,*temp;
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("Unable to allocate memory.");
		return;
	}
	newNode->data=data;
	newNode->next=NULL;
	
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
	printf("Data inserted at the end successfully.\n");
}

void insertNodeAtPosition(int data,int position)
{
	struct node *temp,*newNode;
	int i;
	
	newNode=(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL)
	{
		printf("Unable to allocate memory.");
		return;
	}
	newNode->data=data;
	newNode->next=NULL;
	
	if(position==1)
	{
		newNode->next=head;
		head=newNode;
		printf("Data inserted at position %d successfully.\n",position);
	}
	else
	{
		temp=head;
		for(i=1;i<position-1 && temp!=NULL; i++)
		{
			temp=temp->next;
		}
		
		if(temp==NULL)
		{
			printf("Invalid position.\n");
		}
		else
		{
			newNode->next = temp->next;
			temp->next=newNode;
			printf("Data inserted at position %d successfully.\n",position);
		}
	}
}
void deleteNodeAtBeginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty, cannot delete.\n");
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
	
	printf("Node deleted from the beginning successfully.\n");
}

void deleteNodeAtEnd()
{
	struct node *temp,*prev;
	if(head==NULL)
	{
		printf("List is empty, cannot delete.\n");
		return;
	}
	temp=head;
	prev=NULL;
	
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(prev==NULL)
	{
		free(head); // only one node in the list
		head=NULL;
	}
	else
	{
		prev->next=NULL;
		free(temp);
	}
	printf("Node deleted from the end successfully.\n");
}

void searchNode(int key)
{
	struct node *temp;
	int position=1;
	temp=head;
	while(temp!=NULL && temp->data != key)
	{
		temp=temp->next;
		position++;
	}
	if(temp==NULL)
	{
		printf("Data not found in the list.\n");
	}
	else
	{
		printf("Data found at position %d.\n",position);
	}
}
	
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                 
        }
    }
}

void sortlist()
{
	struct node *current, *index;
	int temp;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	else
	{
		for(current = head; current !=NULL; current=current->next)
		{
			for(index=current->next; index!=NULL; index=index->next)
			{
				if(current->data > index->data)
				{
					temp=current->data;
					current->data=index->data;
					index->data=temp;
				}
			}
		}
		printf("List sorted successfully.\n");
	}
}

void reverselist()
{
	struct node *prev,*current,*next;
	prev=NULL;
	current=head;
	if(head==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head = prev;
	printf("List reversed successfully.\n");
}



		
			
