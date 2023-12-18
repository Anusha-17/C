#include<stdio.h>
void mul(int a,int b)
{
	int product=0;
	while(b!=0)
	{
		product=product+a;
		b--;
	}
	printf("Product is : %d\n",product);
}
void product(int a,int b)
{
	int p=0;
	while(b>0)
	{
		if((b&1)!=0)
			p=p+a;
		a=a<<1;
		b=b>>1;
	}
	printf("P = %d\n",p);
}
int main()
{
	int a,b;
	printf("Enter two numbers:\n");
	scanf("%d %d",&a,&b);
	void (*fp)(int,int)=product;
	fp(a,b);
}
