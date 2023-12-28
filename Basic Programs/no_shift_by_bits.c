// Program to shift inputed data by two bits to the left.

#include<stdio.h>
int main()
{
	int x,y;
	printf("Enter the number to shift : ");
	scanf("%d",&x); //x is position
	x=x<<2;
	y=x;
	printf("The left shift number is : %d \n",y);
}
	
