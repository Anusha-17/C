#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	for(int i=0;i<5;i++)
		printf("%p\n",&a[i]);
	
	printf("%d\n",*a);
	printf("%d\n",*(a+1));
	printf("%d\n\n",*(a+2));
	
	int *p=a;
	for(int i=0;i<5;i++)
		printf("%d\n",*(p+i));
}
