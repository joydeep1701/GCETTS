#include <stdio.h>

int main(void){
	printf("Input a Character ");	
	char c;
	scanf("%c",&c);
	
	if( (c == 97 ) ||(c == 65 ) ||(c == 101 ) ||(c == 69 ) ||(c == 73 ) ||(c == 105 ) ||(c == 111 ) ||(c == 79 ) ||(c == 117 ) ||(c == 85 ))
		printf("Is Vowel");
	else
		printf("Is not Vowel");
	return 0;
}
