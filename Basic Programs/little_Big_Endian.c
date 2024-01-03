/*
#include<stdio.h>
int main()
{
	unsigned int i=1;
	char *c=(char*)&i;
	if(*c)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
	return 0;
}
*/


#include<stdio.h>
int main()
{
	unsigned int num=0x12345678;
	unsigned char *ptr=(unsigned char*)&num;
	printf("Original integer: 0x%X\n",num);
	if(*ptr == 0x78)
		printf("The system is little endian\n");
	else if(*ptr == 0x12)
		printf("The system is big endian\n");
	else
		printf("Unable to determine endianness\n");
	
	printf("Displaying indivudual bytes:\n");	
	for(int i=0;i<sizeof(num);i++)
	{
		printf("%X\n",*ptr);
		ptr++;
	}
		
}

