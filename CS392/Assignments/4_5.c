/**
* Data Structures Assignment - 4
* CS 392
* Problem 5:
*       Write a C program to sort the given array element using Quick Sort Algorithm
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

void QuickSort(int low, int high) {
  int pos_pivot = low;
  int pivot = array[low];
  int left = low;
  int right = high;
  int temp = 0;
  // Base case for recursion
  if(high > low) {
    while (right > left) {
      while(array[left] <= pivot)
        left++;
      while(array[right] > pivot)
        right--;

      if(left < right) {
        temp = array[right];
        array[right] = array[left];
        array[left] = temp;
      }
    }

    array[pos_pivot] = array[right];
    array[right] = pivot;
    pos_pivot = right;

    
    QuickSort(low, pos_pivot-1);
    QuickSort(pos_pivot+1, high);
  }
  return;
}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  QuickSort(0,len-1);
  if(argc < 2)
    show();

  return 0;
}
