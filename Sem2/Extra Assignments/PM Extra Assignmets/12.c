#include <stdio.h>

int main(void){
	int i,count,n = 200;
	
	for(i=0;i <= n;i++){
		if( (i%2) == 0){
			count += i;
		}
	}	
	printf("%d",count);
	
}
