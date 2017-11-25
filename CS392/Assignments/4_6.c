/**
* Data Structures Assignment - 4
* CS 392
* Problem 6:
*       Write a C program to sort the given array element using Radix Sort Algorithm
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

#include <stdio.h>
#include <stdlib.h>

int* array;
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

int getMax(int n) {
  int mx = array[0];
  for(int i=0; i < n; i++) {
    if (array[i] > mx)
      mx = array[i];
  }
  return mx;
}
void countSort(int n, int ex) {
  int* output = malloc(sizeof(int)*n);
  int i,count[10] = {0};

  for (i = 0; i < n; i++)
    count[ (array[i]/ex)%10 ]++;

  for (i = 1; i < n; i++)
    count[i] += count[i-1];

  for (i = n - 1; i>= 0; i-- ) {
    output[count[ (array[i]/ex)%10 ] - 1] = array[i];
    count[ (array[i]/ex)%10 ]--;
  }

  for (i = 0; i < n; i++)
    array[i] = output[i];
}

void radixsort(int n) {
  int m = getMax(n);

  for (int ex = 1;m/ex > 0; ex *= 10)
    countSort(n,ex);
}

int main(int argc, char* argv[]) {
  // For testing puposes no prefix text will be given for input
  init();

  radixsort(len);
  if(argc < 2)
    show();

  return 0;
}
