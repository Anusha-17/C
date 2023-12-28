#include<stdio.h>
int main()
{
	int a,b,sum;
	printf("Enter two numbers : ");
	scanf("%d%d",&a,&b);
	sum=a+b;
	printf("Sum = %d\n",sum);
	int sub=a-b;
	printf("Sub = %d\n",sub);
	int mul=a*b;
	printf("Mul = %d\n",mul);
	int div=a/b;
	printf("Div = %d\n",div);
}

