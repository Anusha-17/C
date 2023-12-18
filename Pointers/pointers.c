#include<stdio.h>
void main()
{
	int a=10,b=20,c;
	int *p=&a;
	int *q=&b;
	c=*q;
	*p=12;
	printf("Value of a=%d\n",a);
	printf("Value of *p=%d\n",*p);
	printf("Address of a=%x\n",&a);
	printf("Address of a=%x\n",p);
	printf("Address of p=%x\n",&p);
	printf("Value of b=%d\n",b);
	printf("Value of *q=%d\n",*q);
	printf("Value of c=%d\n",c);
	printf("Address of b=%x\n",&b);
	printf("Address of b=%x\n",q);
	printf("Address of c=%x\n",q);
}
