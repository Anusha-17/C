#include<stdio.h>
int add_at_beg(int a[],int n,int data)
{
	int i;
	for(i=n-1;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	a[0]=data;
	return n+1;
}
	
int main()
{
	int a[10],i,n,data=10;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	n=add_at_beg(a,n,data);
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
