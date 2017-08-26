//Reversing a String using function

#include <stdio.h>

#define MAX 20

char *str_rev(char *string){
  int i=0,j=0;
  char temp;
  while(*(string + ++i));
  while(j < i){
    temp = *(string + j);
    *(string + j++) = *(string + --i);
    *(string + i) = temp;
  }
  return string;
}
int main(void){
  char s[]= "Hello World";
  ;


  printf("%s\n",str_rev(s));
}
