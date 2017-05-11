#include <stdio.h>

int main(void){

    float temp;
    printf("Input Temperature: ");
    fflush(stdin);
    scanf("%f",&temp);

    char type;
    printf("Input C to convert to Celcius of F to convert to Farhenheit: ");
    fflush(stdin);
    scanf("%c",&type);

    if(type == 'C'){
        printf("Temp in Celcius is:%0.2f C\n",(5.0/9.0*(temp-32)));
    }
    else if(type == 'F'){
        printf("Temp in Farhenheit is:%0.2f F\n",(9.0/5.0*temp+32));
    }
    else{
        printf("Invalid Symbol");
    }
}
