#include<stdio.h>
int main()
{
	int n,r=0,a;
	printf("Enter the number : ");
	scanf("%d",&n);
	while(n>=1)
	{
		a=n%10;
		r=r*10+a;
		n=n/10;
	}
	printf("Reversed number = %d \n",r);
}
