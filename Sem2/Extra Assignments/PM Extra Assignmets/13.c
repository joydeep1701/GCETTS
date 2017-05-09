#include <stdio.h>

int main(void){
	
	int input = 0;
	int negative = 0;
	int positive = 0;
	int zero = 0;
	do{
		printf("Enter Number: ");
		scanf("%d",&input);		
		if(input != -1){
			if(input < 0)
				negative++;
			else if(input > 0)
				positive++;
			else
				zero++;
		}
	}
	while(input != -1);
	
	printf("Number of positive number = %d\n",positive);
	printf("Number of negative number = %d\n",negative);
	printf("Number of Zero = %d\n",zero);
	
}
