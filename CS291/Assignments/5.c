//Write a program to find if a number is odd or even

#include <stdio.h>
int main(void) {
    int number = 0;
    printf("Input a Number: ");
    fflush(stdin);
    scanf("%d",&number);

    number%2?printf("The Number is Odd\n"):printf("The Number is Even\n");
    return 0;
}
