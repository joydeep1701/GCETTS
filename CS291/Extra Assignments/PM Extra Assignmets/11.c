/* Write a program to calculate sum of numbers from m to n */

#include <stdio.h>

int main(void){
	int m;
	int n;
	printf("Input m,n: ");
	scanf("%d %d",&m,&n);
	int i = m;
	int total = 0;
	for(;i <= n;i++)
		total += i;

	printf("%d",total);
}
