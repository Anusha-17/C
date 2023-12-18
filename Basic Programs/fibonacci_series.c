#include<stdio.h>
int main()
{
	int i,n;
	int f1=0,f2=1;
	int f3=f1+f2;
	printf("Enter the number : \n");
	scanf("%d",&n);
	printf("Fibonacci series : %d, %d ,",f1,f2);
	for(i=3;i<=n;i++)
	{
		printf("%d, ",f3);
		f1=f2;
		f2=f3;
		f3=f1+f2;
	}
}
