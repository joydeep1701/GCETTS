//Write a program to print the fibonacci series using recursion

#include <stdio.h>

void fibonacci(int a,int b,int n){
  if(n < 1)
    return;
    printf("%d ",a);
    fibonacci(a+b,a,--n);
}

int main(void){
  int n;
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  fibonacci(0,1,n);
  printf("\n");
}
