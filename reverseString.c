#include <stdio.h>
#include <string.h>
#define MAXLENGTH 25 /* Maximum length for an input string */

void getString(char string[]);
void clearStrings(char string1[], char string2[]);


int main(){

char inputString[MAXLENGTH];
char reversedString[MAXLENGTH];
int length; /* length of the string */


getString(inputString);
length = strlen(inputString);

while(length > 0){

  int i;
  for(i = 0; i <= strlen(inputString); i++){
    reversedString[i] = inputString[length-1-i];
  }

  reversedString[length] = '\0';

  printf("\nLength: %d\nInput %s\nReversed %s\n",length, inputString, reversedString);

  clearStrings(inputString, reversedString);

  getString(inputString);
  length = strlen(inputString);

}

return 0;
}


void getString(char string[]){

  int i, c;

  for(i = 0; i < MAXLENGTH && (c = getchar()) != '\n' && c != '\t' && c != ' '; i++)
    string[i] = c;
}
