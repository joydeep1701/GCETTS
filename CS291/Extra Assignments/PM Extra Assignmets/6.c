/* Write a program to check whether a given year is leap year or not*/

#include <stdio.h>

int main(void){
	
	int year;
	printf("Enter the Year ");
	scanf("%d",&year);
	
	if(((year%4 == 0) && (year % 100 != 0)) || (year%400 == 0)){
		printf("The year is a leap year");
	}
	else{
		printf("Not a leap year");
	}

}
