/************Array is not full****************
#include<stdio.h>
int add_at_end(int a[],int freepos,int data)
{
	a[freepos]=data;
	freepos++;
	return freepos;
}
	
int main()
{
	int a[10],i,n,freepos;
	printf("Enter the no of elements: \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	freepos=n;
	freepos=add_at_end(a,freepos,65);
	
	for(i=0;i<freepos;i++)
		printf("%d ",a[i]);
	return 0;
}
*/

/************Array is full****************/
#include<stdio.h>
int add_at_end(int a[],int b[],int n,int freepos,int data)
{
	int i;
	for(i=0;i<n;i++)
		b[i]=a[i]; //copying all elements for a into b
	b[freepos]=data;
	freepos++;
	return freepos;
}
	
int main()
{
	int a[3],i,n,freepos;
	printf("Enter the no of elements: \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int size=sizeof(a)/sizeof(a[0]);
	freepos=n;
	if(n==size)
	{
		int b[size+2];
		freepos=add_at_end(a,b,size,freepos,65);
		for(i=0;i<freepos;i++)
			printf("%d ",b[i]);
	}
	return 0;
}	
