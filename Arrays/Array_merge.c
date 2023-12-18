#include<stdio.h>
int main()
{
	int a[10],b[10],i,m,n;
	printf("Enter no of first elements in the array: \n");
	scanf("%d",&m);
	printf("Enter the first array elements:\n");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	printf("Enter no of second elements in the array: \n");
	scanf("%d",&n);
	printf("Enter the second array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
	for(i=0;i<n;i++)
	{
		a[m+i]=b[i];
	}
	printf("Merged elements are : \n");
	for(i=0;i<m+n;i++)
		printf("%d ",a[i]);
		printf("\n");
}
