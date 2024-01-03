#include<stdio.h>
int main()
{
	int age;
	printf("Enter the age : \n");
	scanf("%d",&age);
	(age >=18) ? printf("Can vote\n") : printf("Can't vote\n");
	return 0;
}

#include<stdio.h>
int main()
{
	char op='+';
	int a,b;
	printf("Enter two numbers :\n");
	scanf("%d %d",&a,&b);
	int res =(op == '+') ? (a+b) : (a-b);
	printf("Result = %d",res);
}
