#include<stdio.h>
#include "ex1.h"
#include "ex12.h"

//int a=10;
//extern int a;
int main()
{
	//extern int a; // variable a is defined globally, the memory will not be allocated to a 
	
	//extern int a = 0; // this will show a compiler error since we can not use extern and initializer at same time    
	printf("%d\n",a);
}



/*
In file included from extern.c:3:
ex1.h:1:12: error: static declaration of ‘a’ follows non-static declaration
    1 | static int a=10;
      |            ^
In file included from extern.c:2:
ex12.h:1:12: note: previous declaration of ‘a’ was here
    1 | extern int a;
      |  
*/
