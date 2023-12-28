#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers to swap : ");
	scanf("%d %d",&a,&b);
	printf("Numbers before swapping : %d %d \n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("Numbers after swapping : %d %d \n",a,b);
}
