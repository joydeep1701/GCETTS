/* Write a program to calculate the sum of the series 1 + 1/2^2 + 1/3^2 + .... + 1/n^2 */


#include <stdio.h>

int main(void){
	int n = 0;

	printf("Input a number: ");
	scanf("%d",&n);

	float total = 0;
	int i = 1;
	for(i = 1;i<=n;i++){
		float s = i;
		total = total + 1/(s*s);

	}
	printf("%0.2f",total);


}
