#include <stdio.h>

int main(void){
	int n = 10;
	printf("Summation-> %d\n",(n/2)*(n+1));
	int i = 0;
	int total = 0;
	for(;i <= n;i++)
		total += i;

	printf("%d",total);
}
