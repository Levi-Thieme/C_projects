#include <stdio.h>


void print(const char* c);

void main(){

char chars[20] = {'H', 'e','l','l','o'};

print(chars);


}

void print(const char* c){

  while(*c != '\0'){
    printf("%c", *c);
    c++;
  }
  printf("\n");
}
