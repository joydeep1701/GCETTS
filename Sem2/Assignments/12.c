
//Write a program to compute the following series using function
// 1 + (1+ 2) + (1+2+3) + ... + (1 + 2 + ... + n)
#include <stdio.h>
int calc_series(int n){
  if(n < 2)
    return 1;
  return n*(n+1)/2 + calc_series(--n);
}

int main(void){
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Calculated Series Sum: %d\n",calc_series(n));
}
