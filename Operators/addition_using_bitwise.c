#include<stdio.h>
int bitwise_add(int a,int b)
{
	while(b!=0)
	{
		int carry=a&b;
		a=a^b;
		b=carry<<1;
	}
	return a;
}
int main()
{
	int a,b;
	printf("Enter two numbers: \n");
	scanf("%d %d",&a,&b);
	int sum=bitwise_add(a,b);
	printf("Sum = %d\n",sum);
}
