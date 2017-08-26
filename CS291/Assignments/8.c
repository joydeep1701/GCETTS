//Write a program to print some patterns

#include <stdio.h>

int main(void){
    printf("Enter Height: ");
    int n = 1;
    scanf("%d",&n);
    int i = 1;
    for(;i <= n; i++){
        int j = 1;
        for(;j<=i;j++)
            printf("*");
        printf("\n");
    }
    i = 1;
    for(;i <=n;i++){
        int j = 1;
        for(;j <= n - i;j++)
            printf("-");
        for(j=1;j <= i;j++)
            printf("*");
        printf("\n");
    }
    i = 1;
    for(;i <=n;i++){
        int j = 1;
        for(;j <= n - i;j++)
            printf("-");
        for(j=1;j <= 2*i-1;j++)
            j & 1 ?printf("%d",j):printf("*");
        printf("\n");
    }

}
