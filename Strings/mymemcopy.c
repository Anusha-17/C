#include<stdio.h>
#include<string.h>
void *mymemcopy(char*,char*,int);
void main()
{
	char str1[20]="Memory copying",str2[20];
        mymemcopy(str2,str1,strlen(str1));
        printf("Copied string is : %s\n",str2);
}
void *mymemcopy(char *dest,char *src,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		dest[i]=src[i];
	}
}
