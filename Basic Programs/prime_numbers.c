/*
#include<stdio.h>
int main()
{
	int n,i,count,range;
	printf("Enter the range: \n");
	scanf("%d",&range);
	for(n=1;n<=range;n++)
	{
		count=0;
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				count++;
				break;
			}
		}
		if(count==0 && n!=1)
			printf("%d ",n);
	}
}
*/			

#include<stdio.h>
int main()
{
	int n,i,m=0,flag=0;
	printf("Enter the number : \n");
	scanf("%d",&n);
	m=n/2;
	for(i=2;i<=m;i++)
	{
		if(n%i==0)
		{
			printf("Not a prime number\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Number is prime\n");
	return 0;
}
