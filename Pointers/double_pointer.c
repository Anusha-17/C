#include<stdio.h>
void main()
{
	int a=17;
	int *p=&a;
	int **q=&p;
	int ***r=&q;
	//int **q=&a;  //warning: initialization of ‘int **’ from incompatible pointer type ‘int *’
	printf("Value of a = %d %d %d\n",a,*p,**q);
	printf("Value of a = %d\n",***r);
	printf("Address of a= %x %x %x %x\n",&a, p, q, r);
	//printf("Address of p=%x\n",&p);
	//printf("Value of *q=%d\n",*q);
}
