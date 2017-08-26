/* Write a program to calculate average of two numbers */


#include <stdio.h>

int main(void){
	
	float a,b;
	printf("Enter the values of a,b: ");
	scanf("%f %f",&a,&b);
	float avg = (a+b)/2;
	printf("The average value of a,b is %0.2f\n",avg);
	printf("Deviation of a:%0.2f, Deviation of b:%0.2f",avg-a,avg-b);
	return 0;
}
