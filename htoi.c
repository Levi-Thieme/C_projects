#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLENGTH 16 /* maximum length for hexadecimal string */

int tolower(int c);

// 0x or 0X denotes hexadecimal.
int main(){


int i, c;
int hexValue = 0;

double total;
total = 0;

for(i = 0; (c = getchar()) != EOF && c != '\n' && i < MAXLENGTH; i++){
  if(c < 10 && c > -1)
    total = total + pow(c, i);
  else{
    switch (tolower(c)) {
      case 'a':
        hexValue = 10; break;

      case 'b':
        hexValue = 11; break;

      case 'c':
        hexValue = 12; break;

      case 'd':
        hexValue = 13; break;

      case 'e':
        hexValue = 14; break;

      case 'f':
        hexValue = 15; break;
    }
    total = total + pow(hexValue, i);
  }
  printf("Value %f\n", total);
}

printf("Total value %f\n", total);

return 1;
}
