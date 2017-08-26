//Write a program to implement strlen, strcat and strcmp functions of strings.

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

#define LIMIT 20

int str_len(char *string){
  int len = 0;
  while(*(string + ++len));
  return len;
}
char *strcat(char *a,char *b){
  int i=0,j=0;
  while(*(a + ++i) );
  while(*(a + i++) = *(b + j++));
  return a;
}
int strcmp(char *a,char *b){
  int i=0;
  while(*(a + i ) == *(b + i))
    i++;
  return *(a + i) - *(b + i);
}
int main(void){
  char *a = NULL;
  char *b = NULL;
  a = (char*)malloc(sizeof(char)*LIMIT);
  b = (char*)malloc(sizeof(char)*LIMIT);

  printf("Input String 1: ");
  scanf("%s",a);
  printf("Input String 2: ");
  scanf("%s",b);

  printf("Length of String 1:%d\n",str_len(a));
  printf("Length of String 2:%d\n",str_len(a));
  printf("strcmp of 1,2 is:%d\n",strcmp(a,b));
  printf("strcat of 1,2 is:%s\n",strcat(a,b));


}
