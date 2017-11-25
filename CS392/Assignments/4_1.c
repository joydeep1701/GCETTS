/**
* Data Structures Assignment - 4
* CS 392
* Problem 5:
*       Write a C program to sort the given array element using Bubble Sort Algorithm
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

/**
*   Algorithm:
*       begin BubbleSort(list)
*
*        for all elements of list
*            if list[i] > list[i+1]
*              swap(list[i], list[i+1])
*            end if
*          end for
*
*          return list
*
*        end BubbleSort
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

void BubbleSort() {
  int temp;

  for (int pass = len-1; pass > 0; pass--) {
    for (int i=0; i < pass; i++) {
      if(array[i] > array[i+1]) {
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  BubbleSort();
  if(argc < 2)
    show();

  return 0;
}
