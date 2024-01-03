/*
#include<stdio.h>
static char c;
static int a;
static float b;
static char s[10];
void main()
{
	printf("%d %d %f\n",c,a,b);
}
*/

#include<stdio.h>
int sum()
{
	static int a; //static variable can be declared many times but can be assigned at only one time.
	static int b;
	a = 5;
	a++;
	b++;
	printf("%d %d\n",a,b);	
}
int main()
{
	int i;
	for(i=0;i<3;i++)
	{
		sum();
	}
}
