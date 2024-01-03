#include<stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define max_three(a,b,c) max(max(a,b),c)
int main()
{
	int n1,n2,n3;
	printf("Enter the numbers:\n");
	scanf("%d %d %d",&n1,&n2,&n3);
	int maxnum=max_three(n1,n2,n3);
	printf("The biggest number is : %d\n",maxnum);
}
