/* Write a program to print the digit at unit position of a number*/

#include <stdio.h>

int main(void){
	
	int n = 0;
	fflush(stdin);
	scanf("%d",&n);
	printf("%d",n%10);
	return 0;
	
}


