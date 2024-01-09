/*
#include<stdio.h>
int main()
{
    char str[30];
    printf("Enter your String:");
    scanf("%[^\n]",str);
    int i,j;
     for (i = 0; str[i] != '\0'; ++i) 
     {
     while (str[i] >= '0' && str[i] <= '9') 
     {
         for (j = i; str[j] != '\0'; ++j) 
         {
            str[j] = str[j + 1];
         }
         str[j] = '\0';
      }
   }
       printf("After removing all numbers string is: %s\n",str);
}
*/

#include <stdio.h>
#include <string.h>

void removeNumbers(char *inputString, char *removedNumbers) 
{
    int i, j = 0;

    for (i = 0; inputString[i] != '\0'; i++) {
        if (!(inputString[i] >= '0' && inputString[i] <= '9')) {
            removedNumbers[j] = inputString[i];
            j++;
        }
    }

    removedNumbers[j] = '\0';  // Null-terminate the removedNumbers string
}

int main() {
    char inputString[100], removedNumbers[100];

    // Input string from the user
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove numbers and store them in removedNumbers
    removeNumbers(inputString, removedNumbers);

    // Display the removed numbers
    printf("Removed numbers: %s\n", removedNumbers);

    return 0;
}



