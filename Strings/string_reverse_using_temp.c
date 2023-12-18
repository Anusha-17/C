#include<stdio.h>
#include<string.h>

void reverse(char str[])
{
	/*int len=strlen(str);
	int temp[len];
	int start=0;
	int end=len-1;
	while(start<end)
	{
		char temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}*/
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		char temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
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


		
