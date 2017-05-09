/* Write a program to enter a number from 1 to 7 and display the corresponding day of the week*/

#include <stdio.h>

int main(void){
	
	int a;
	printf("Enter the value of a: ");
	scanf("%d",&a);
	switch(a){
		case 1:printf("Sunday");break;
		case 2:printf("Monday");break;
		case 3:printf("Tuesday");break;
		case 4:printf("Wednesday");break;
		case 5:printf("Thursday");break;
		case 6:printf("Friday");break;
		case 7:printf("Saturday");break;
		default:printf("Error");break;
	}

}
