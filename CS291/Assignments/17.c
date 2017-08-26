//Write a program to add two 3x3 matrix

#include <stdio.h>
#define DIM 3

int main(void){
  int arr[DIM][DIM],brr[DIM][DIM],crr[DIM][DIM],i,j;
  printf("Enter Matrix 1: \n");

  for(i = 0;i < DIM; i++){
    for(j = 0; j < DIM;j++)
      scanf("%d",&arr[i][j]);
  }

  printf("Enter Matrix 2: \n");
  for(i = 0;i < DIM; i++){
    for(j = 0; j < DIM;j++)
      scanf("%d",&brr[i][j]);
  }
  for(i = 0;i < DIM;i++){
    for(j = 0; j < DIM;j++){
      crr[i][j] = arr[i][j] + brr[i][j];
    }
  }
  for(i = 0;i < DIM; i++){
    for(j = 0; j < DIM;j++)
      printf("%02d ",crr[i][j]);
    printf("\n");
  }
}
