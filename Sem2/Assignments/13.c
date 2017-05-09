//Write a program to calculate factorial in recursive form

#include <stdio.h>

int factorial(int n){
  if(n < 2)
    return 1;
  return n*factorial(n-1);
}

int main(void){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Factorial: %d\n",factorial(n));
}
