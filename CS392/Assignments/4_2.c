/**
* Data Structures Assignment - 4
* CS 392
* Problem 5:
*       Write a C program to sort the given array element using Selection Sort Algorithm
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

/**
*   Algorithm:
*       begin SelectionSort(list)
*
*        for element e in list:
*            set min = indexof(e)
*            for element f in list starting from index min:
*              if f < e:
*                set min = indexof(f)
*
*            swap elements e and min
*
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

void SelectionSort() {
  int min, temp;

  for (int i=0; i < len - 1; i++) {
    min = i;
    for (int j = i + 1; j < len; j++) {
        if(array[j] < array[min])
          min = j;
    }
    // swap
    temp = array[min];
    array[min] = array[i];
    array[i] = temp;
  }

}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  SelectionSort();

  if(argc < 2)
    show();

  return 0;
}
