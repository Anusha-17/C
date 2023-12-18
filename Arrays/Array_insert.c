#include<stdio.h>
int main()
{
	int a[10],i,n,pos,val;
	printf("Enter no of elements in the array: \n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the location where u want to insert\n" );
	scanf("%d",&pos);
	printf("Enter the value \n");
	scanf("%d",&val);
	for(i=n-1;i>=pos-1;i--)
		a[i+1]=a[i];
	a[pos-1]=val;
	printf("New array after inserting element: \n");
	for(i=0;i<=n;i++)
		printf("%d ",a[i]);
}
	
	
