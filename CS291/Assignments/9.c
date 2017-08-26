//Write a program to print fibonacci series using while loop

#include <stdio.h>

int main(void){
	int n = 0;
	int i = 0;
	int a = 0,b = 1,c;
	printf("Enter n: ");
	scanf("%d",&n);

	while(i <= n){
		i++;
		printf("%d ",a);
		c = a;
		a += b;
		b = c;

	}

}
