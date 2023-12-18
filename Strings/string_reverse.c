#include<stdio.h>
#include<string.h>

void reverse(char str[])
{
	int len=strlen(str);
	int start=0;
	int end=len-1;
	while(start < end)
	{
		str[start]^=str[end];
		str[end]^=str[start];
		str[start]^=str[end];
		start++;
		end--;
	}
	
}

int main()
{
	char input[100];
	printf("Enter the string :\n");
	fgets(input,sizeof(input),stdin);
	printf("Original strign : %s\n", input);
	reverse(input);
	printf("Reversed string is : %s\n",input);
}
	
