//Write a program using pointers to read an array of integers and display them

#include <stdio.h>
#define LIMIT 10
int main(){
  int i,array[LIMIT];
  for(i = 0;i < LIMIT;i++){
    scanf("%d",&array[i]);
  }
  for(i = 0;i < LIMIT;i++){
    printf("%d\n",*(array + i) );
  }

}
