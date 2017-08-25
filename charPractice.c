#include <stdio.h>
#include "header_file.h"

#define MAXLINE 1000  /*MAXIMUM length for input */
#define IN 1  /*inside a word*/
#define OUT 0 /*outside a word*/

void countWordLength();

int getLine(char line[]);
void copy(char to[], char from[]);

extern int limit;

int main(){


  int len; /*length of current line */
  int max;
  char line[MAXLINE]; /* current line of input */
  char longest[MAXLINE]; /* the longest line */


  max = 0;

  while((len = getLine(line)) > 0)
    if(len > max){
      max = len;
      copy(longest, line);

      printf("%s", longest);
    }

  return 0;
}



void copy(char to[], char from[]){
  int i;
  i = 0;

  while((to[i] = from[i]) != '\0')
    i++;
}

int getLine(char s[]){

  int c, i;

  for(i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0 && c == '\n')
    printf("Empty line!\n");

  if(c == '\n' && s[i-1] == '\t'){
    s[i-1] = c;
  }
  else if(c == '\n' && s[i-1] == ' '){
    s[i-1] = c;
  }
  else if(c == '\n'){
    s[i] = c;
    ++i;
  }


  s[i] = '\0';
  return i;
}



void countWordLength(){
  int c, state, words = 0, length = 0;

  int wordsLength[1000];

  state = IN;

  while((c = getchar()) != EOF){

    if(c == ' ' || c == '\t' || c == '\n'){
      wordsLength[words] = length;
      words++;
      length = 0;
      state = IN;
      printf("\n");
    }
    else if(state == IN){
      putchar(c);
      length++;
    }

    if(c == '~'){
      break;
    }

  }

  int i;
  for(i = 0; i < words; i ++){
    printf("Word %d: %d\n", i, wordsLength[i]);
  }
}
