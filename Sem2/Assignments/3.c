//Write a program to print value & address & sizeof char int float

#include <stdio.h>

int main(void){

    char x;
    int y;
    float z;

    printf("Enter Char X:");
    fflush(stdin);
    scanf("%c",&x);

    printf("Enter Int Y:");
    fflush(stdin);
    scanf("%d",&y);

    printf("Enter Float Z:");
    fflush(stdin);
    scanf("%f",&z);

    printf("X:value->%c,address->%d,size->%d",x,&x,sizeof(x));
    printf("Y:value->%d,address->%d,size->%d",y,&y,sizeof(y));
    printf("Z:value->%f,address->%d,size->%d",z,&z,sizeof(z));


}
