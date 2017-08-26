/* Write a program using for loop to calculate factorial of a number using for loop*/

#include <stdio.h>

int main(void){
	int n = 0;
	printf("Enter Digit: ");
	scanf("%d",&n);
	int facto=1,i = 1;
	for(;i <= n;i++)
		facto *= i;
	printf("%d",facto);

}
