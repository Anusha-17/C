#include<stdio.h>
#include<string.h>
int stringconcat(char *s1,char *s2)
{
	int i;
	int j=strlen(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		s1[i+j]=s2[i];
	}
	s1[i+j]='\0';
}
int main()
{
	char s1[20],s2[20];
	printf("Enter string1 :");
	gets(s1);
	printf("Enter string2 : ");
	gets(s2);
	stringconcat(s1,s2);
	printf("Concatinated string = %s\n",s1);
}
