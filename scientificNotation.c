#include <stdio.h>

#include <ctype.h>

int getLine(char s[]);
double atof(char s[]);

#define MAXLINE 100

/*
get line from user
check for e or E
get sign value
get num value
adjust decimal occording to sign and num values
pass result to atoi()
return result
 */

int main(){


char line[MAXLINE];

double lineValue;

getLine(line);

lineValue = atof(line);

printf("%f\n", lineValue);

return 1;
}

double atof(char s[]){

  double val, power;
  int i, sign;

  for(i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;

  if(s[i] == '+' || s[i] == '-')
    i++;

  for(val == 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if(s[i] == '.')
    i++;

  for(power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  int exponentSign;
  int exponent;

  if(tolower(s[i]) == 'e')
    i++;

  if(s[i] == '-') {
    exponentSign = -1;
    i++;
  }
  else if(s[i] == '+'){
    exponentSign = 1;
    i++;
  }
  else
    exponentSign = 1;


  exponent = (s[i] - '0');

//  printf("%c  %d\n", s[i-1], exponent);

  //Adjust power based on exponent
  int j;

  if(exponentSign == -1) {
    for(j = 0; j < exponent; j++){
      power *= 10;
    }
  }
  else{
    for(j = 0; j < exponent; j++){
      power /= 10;
    }
  }

//  printf("Exponent Sign: %d\nExponent: %d\n", exponentSign, exponent);

  return sign * val / power;
}

int getLine(char s[]){

  int c, i;

  for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
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
