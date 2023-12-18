#include<stdio.h>
int fact(int n)
{
	if(n<=0)
		return 1;
	else
		return (n*fact(n-1));
}
int main()
{
	int x,i;
	printf("Enter the value : \n");
	scanf("%d",&x);
	i=fact(x);
	printf("Factorial of %d is %d \n",x,i);
}
