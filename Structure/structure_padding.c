#include<stdio.h>
struct test
{
	int a;
	float b;
	char c;
	double d;
	
	struct test2
	{
		int a;
		char b;
	}s2;
};
int main()
{
	struct test s1;
	printf("Size of structure is = %ld\n",sizeof(s1));
	//printf("Size of double is = %d\n",sizeof(s1.d));
	//printf("Size of int is = %d\n",sizeof(s1.a));
	//printf("Size of float is = %d\n",sizeof(s1.b));
	//printf("Size of char is = %d\n",sizeof(s1.c));
}
