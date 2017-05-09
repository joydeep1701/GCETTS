//Write a program to impliment GCD using recursion

#include <stdio.h>
int gcd(int a,int b){
  if(!b)
    return a;
  return gcd(b,a%b);
}

int main(void){
  int a,b;
  printf("Enter a: ");
  fflush(stdin);
  scanf("%d",&a);
  printf("Enter b: ");
  fflush(stdin);
  scanf("%d",&b);
  printf("GCD: %d\n",gcd(a,b));
}
