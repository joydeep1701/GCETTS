/* Write a program to swap two numbers using a temporary variable*/

#include <stdio.h>

int main(void){
	
	int a,b;
	printf("Enter the values of a,b: ");
	scanf("%d %d",&a,&b);
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
	printf("The values of a,b is %d %d",a,b);
}
