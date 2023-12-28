#include<stdio.h>
int main()
{
	char ch;
	printf("Enter the letter to display week days : \n");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'm':
		case 'M':printf("Monday\n");
		break;
		case 't':
		case 'T':printf("Tuesday\n");
		break;
		case 'w':
		case 'W':printf("Wednesday\n");
		break;
		case 'h':
		case 'H':printf("Thursday\n");
		break;
		case 'f':
		case 'F':printf("Friday\n");
		break;
		case 's':
		case 'S':printf("Saturday\n");
		break;
		case 'u':
		case 'U':printf("Sunday\n");
		break;
		default : printf("Invalid choice\n");
		break;
	}	
}

		
