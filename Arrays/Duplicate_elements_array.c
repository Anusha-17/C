#include<stdio.h>
void duparr(int a[],int n);
int main()
{
	int a[20],n,i;
	printf("Enter no of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	duparr(a,n);
}

void duparr(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				printf("Duplicate elements are : %d\n",a[i]);
			}
		}
	}
}
