/**
* Data Structures Assignment - 4
* CS 392
* Problem 3:
*       Write a C program to sort the given array element using Insertion Sort Algorithm
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/


#include <stdio.h>
#include <stdlib.h>

int *array;
int len;

void init() {
  scanf("%d",&len);
  array = malloc(sizeof(int)*len);
  for (int i=0; i<len; i++) {
    scanf("%d",(array+i));
  }
}

void show() {
  for(int i=0; i < len; i++)
      printf("%d ",*(array + i));
  printf("\n");
}

void InsertionSort() {
  int temp;
  int j;
  for (int i=0; i < len; i++) {
    temp = array[i];
    for (j = i;j>0 && array[j-1] > temp;j--) {
      array[j] = array[j-1];
    }
    array[j] = temp;
  }
}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  InsertionSort();
  if(argc < 2)
    show();

  return 0;
}
