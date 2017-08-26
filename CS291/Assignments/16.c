//Write a program to print array in accending order

#include <stdio.h>
#include <stdlib.h>

#define MAX 200

void SelectionSort(int *array,int n){
  int i,j,pos,max,temp;
  for(i = 0; i < n; i++){
    pos = i;
    for(j = i;j < n;j++){
      if(*(array + pos) > *(array + j)){
        pos = j;
      }
    }
    temp = *(array + i);
    *(array + i) = *(array + pos);
    *(array + pos) = temp;
  }
}

int main(void){
  int *array = NULL;
  int n,i;
  printf("Enter Size of Array: ");
  scanf("%d",&n);
  array = malloc(sizeof(int)*n);
  printf("Enter Array: ");
  for(i=0;i<n;i++){
    scanf("%d",(array+i));
  }

  SelectionSort(array,n);

  for(i=0;i < n;i++)
    printf("%d ",*(array + i) );

}
