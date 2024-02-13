/*
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
*/
/*
#include<stdio.h>
struct test
{
	int a;
	int b;
	char x[15];
	double y;
	int z;
}s1;
int main()
{
	printf("Size  of s1 = %ld \n",sizeof(s1));
	printf("Size of double is = %ld\n",sizeof(s1.y));
	printf("Size of int is = %ld\n",sizeof(s1.a));
	printf("Size of float is = %ld\n",sizeof(s1.b));
	printf("Size of char is = %ld\n",sizeof(s1.x));
}
*/

#include<stdio.h>
struct test
{
	int a : 5;
	int b : 10;
	int c;
}s1;
int main()
{
	printf("Size  of s1 = %ld \n",sizeof(s1));
	//printf("Size  of a = %ld \n",sizeof(s1.a));
	//printf("Size  of b = %ld \n",sizeof(s1.b));
	printf("Size  of c = %ld \n",sizeof(s1.c));
	
	
}
