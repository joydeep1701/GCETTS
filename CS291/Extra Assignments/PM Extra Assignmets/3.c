/* Write a program to swap two numbers without using a temporary variable*/

#include <stdio.h>

int main(void){
	
	int a,b;
	printf("Enter the values of a,b: ");
	scanf("%d %d",&a,&b);
	a = a + b;
	b = a - b;
	a = a - b;
	
	printf("The values of a,b is %d %d",a,b);
}
