//Write a program to swap two variables using function to show the difference between call-by-value and
//call-by- reference.

#include <stdio.h>

void noswap(int a,int b){
  int temp;
  printf("\t\tnoswap function called\n");
  printf("\t\tvalues of a,b:%d,%d\n",a,b);
  printf("\t\t\tswapping started\n");
  temp = a;
  a = b;
  b = temp;
  printf("\t\t\tswapping ended\n");
  printf("\t\treturning\n");
}
void swap(int *a,int *b){
  int temp;
  printf("\t\tswap function called\n");
  printf("\t\tvalues of a,b:%d,%d\n",*a,*b);
  printf("\t\t\tswapping started\n");
  temp = *a;
  *a = *b;
  *b = temp;
  printf("\t\t\tswapping ended\n");
  printf("\t\treturning\n");

}

int main(void){
  int a = 5,b = 10;
  printf("\tCalling noswap with values of a,b:%d,%d\n",a,b);
  noswap(a,b);
  printf("\tvalues of a,b:%d,%d [after swap()]\n\n",a,b);
  printf("\tCalling swap with values of a,b:%d,%d\n",a,b);
  swap(&a,&b);
  printf("\tvalues of a,b:%d,%d [after swap()]\n",a,b);
}
