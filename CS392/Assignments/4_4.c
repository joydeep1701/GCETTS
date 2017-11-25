/**
* Data Structures Assignment - 4
* CS 392
* Problem 4:
*       Write a C program to sort the given array element using Merge Sort Algorithm
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/



#include <stdio.h>
#include <stdlib.h>

int *array;
int *temp;
int len;

void Merge(int left, int mid, int right);

void init() {
  scanf("%d",&len);
  array = malloc(sizeof(int)*len);
  temp = malloc(sizeof(int)*len);

  for (int i=0; i<len; i++) {
    scanf("%d",(array+i));
  }
}

void show() {
  for(int i=0; i < len; i++)
      printf("%d ",*(array + i));
  printf("\n");
}

void MergeSort(int left, int right) {
  int mid;
  if (right > left) {
    mid = (right + left) / 2;
    MergeSort(left, mid);
    MergeSort(mid + 1, right);
    Merge(left, mid+1, right);
  }
}
void Merge(int left, int mid, int right) {
  int i, left_end, size, temp_pos;

  left_end = mid -1;
  temp_pos = left;

  size = right - left + 1;

  while((left <= left_end) && (mid <= right)) {
    if(array[left] <= array[mid])
      temp[temp_pos++] = array[left++];
    else
      temp[temp_pos++] = array[mid++];
  }
  while( left <= left_end) {
    temp[temp_pos++] = array[left++];
  }
  while( mid <= right) {
    temp[temp_pos++] = array[mid++];
  }
  for(int i=0; i<= size; i++) {
    array[right] = temp[right--];
  }
}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  MergeSort(0,len-1);
  if(argc < 2)
    show();

  return 0;
}
