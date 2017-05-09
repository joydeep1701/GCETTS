#include <stdio.h>
#include <string.h>
int isvowel(char c){
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
			return 1;
			break;
		default: 
			return 0;
	}
	
}

int main(void){
	printf("Input Sentence: ");	
	char s[50];
	gets(s);
	int i,count = 0;
	for(i = 0;s[i] != '\0';i++){
		if(isvowel(s[i]))//{
			//printf("%c %d\n",s[i],count);
			count++;
			//printf("%c %d\n",s[i],count);
		//}
			
	}
	printf("%d",count);
	
	
}
