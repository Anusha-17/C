#include<stdio.h>
#define n 10
int main()
{
	int a[n];
	printf("Enter the elements of an array:  \n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The Array elements are : " );
	for(int i=0;i<n;i++)
		printf("%d ", a[i]);
}

	

