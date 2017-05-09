#include <stdio.h>
#include <ctype.h>

int main(void){
	char c;
	scanf("%c",&c);
	if(isalpha(c)){
		printf("Character");
	}
	else{
		printf("Number");
	}
	
}

