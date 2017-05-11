//Write a program to show whether a string is a palindrome, or not without using string library function.

#include <stdio.h>

int main(){
  char string[20];
  int i=0,j=0;
  char pal = 1;
  printf("Enter String: ");
  scanf("%s",string);

  while(*(string + ++i));
  i--;
  while( i >= j){
    //printf("[%d]%c == [%d]%c\n",i,*(string +i),j,*(string + j));
    if(*(string + i) != *(string + j))
      pal *= 0;
    i--;
    j++;
  }
  printf("%s\n",pal?"Palindrome":"Not Palindrome");



}
