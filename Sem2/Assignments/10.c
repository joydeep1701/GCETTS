#include <stdio.h>
#include <math.h>
int main(void){
	int i,n,end;
	printf("Enter number: ");
	scanf("%d",&n);
	end = (int) sqrt(n);

	for(i=2;i <= end;i++){
		//printf("%d",i);
		if(n%i == 0){
			printf("Not Prime");
			return 0;
		}
	}
	printf("Prime");
}
