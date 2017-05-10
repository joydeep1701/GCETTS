/* Write  a program to to calculate average of n numbers entered by user */

#include <stdio.h>

int main(void){
	int i,n = 0;
	float total=0;
	printf("Enter number of digits: ");
	scanf("%d",&n);
	for(i = 0; i < n;i++){
		float input = 0;
		scanf("%f",&input);
		total += input;
	}

	printf("%0.2f",(total/n));


}
