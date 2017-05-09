#include <stdio.h>

int main(void){
	printf("Input a Character");	
	char c;
	scanf("%c",&c);
	switch(c){
		case 97:
		case 101:
		case 105:
		case 111:
		case 117:
		case 65:
		case 69:
		case 73:
		case 79:
		case 85:
			printf("Is Vowel");
			break;
		default: 
			printf("Is not Vowel");
	}
	
}
