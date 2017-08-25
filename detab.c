#include <stdio.h>
#include <string.h>

#define MAX 100 /* Maximum characters to detab for a given line of input */

void getInput(char input[]);

void main(){

char input[MAX];

getInput(input);

int i;
for(i = 0; i < strlen(input); i++){
  printf("%c", plinput[i]);
}

}

void getInput(char input[]){
  int c;
  int i;

  printf("Enter a line of input.\n");

  for(i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; i++){
    if(c == '\t'){
      input[i] = ' ';
      input[++i] = ' ';
      input[++i] = ' ';
    }
    else{
      input[i] = c;
    }

    if(c == '\n'){
      input[i] = '\0';
    }
  }
}
