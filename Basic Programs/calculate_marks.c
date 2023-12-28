#include<stdio.h>
int main()
{
	int s1,s2,s3,s4,s5,sum,total=500;
	float per;
	printf("Enter marks for subjects : ");
	scanf("%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5);
	sum=s1+s2+s3+s4+s5;
	printf("Sum = %d\n",sum);
	per=(sum*100)/total;
	printf("Percentage = %f\n",per);
}
	
