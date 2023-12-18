#include<stdio.h>
#define SIZE 100
void palindrome(char[],int);
int main()
{
	char s[SIZE];
	int n,len=0,i;
	printf("Enter the size of the string :\n");
	scanf("%d",&n);
	printf("Enter the string :\n");
	scanf(" %[^\n]s",s);
	fgets(s,sizeof(s),stdin);
	for(i=0;s[i]!='\0';i++)
	{
		len++;
	}
	printf("Length of the string : %d\n",len);
	palindrome(s,len);
}
void palindrome(char s[],int len)
{
	int i,flag;
	for(i=0;i<len/2;i++)
	{
		if(s[i]==s[len-i-1])
			flag=0;
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Given string is palindrome\n");
	else
		printf("Given string is not a palindrome\n");
	}
