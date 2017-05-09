#include <stdio.h>

int main(void){
	int total = 0;
	int number = 0;
	printf("Input a number: ");
	scanf("%d",&number);
	int i =0;
	int n = number;
	
	for(i = 10; i < number;i*=10){
		
		printf("%d",(n % 10));		
		n = n / 10;		 
		
	} 
	
	printf("%d\n",(n % 10));
	
}
