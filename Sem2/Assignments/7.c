#include <stdio.h>

int main(void){
    int a,b;
    printf("Enter First Number: ");
    scanf("%d",&a);
    printf("Enter Second Number: ");
    fflush(stdin);
    scanf("%d",&b);
    char op;
    printf("Enter operation ");
    fflush(stdin);
    scanf("%c",&op);
    float result = 0;
    switch(op){
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '*':
            result = a*b;
            break;
        case '/':
            result = a/b;
            break;
        default:
            printf("Invalid Operation");
            return -1;
    }
    printf("Result-> %0.2f",result);
    return 0;
}
