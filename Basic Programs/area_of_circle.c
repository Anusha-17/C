#include<stdio.h>
#define pi 3.14
int main()
{
	int r;
	float area,circumference;
	printf("Enter the radius : ");
	scanf("%d",&r);
	area=pi*r*r;
	printf("Area of circle = %f\n",area);
	circumference=2*pi*r;
	printf("Circumference of circle = %f\n",circumference);
}
	
