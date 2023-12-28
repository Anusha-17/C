#include<stdio.h>
int main()
{
	int n;
	printf("Enter number:");
	scanf("%d",&n);
	if(n%4 == 0)
		printf("Leap year\n");
	else
		printf("Not a leap year\n");
}

