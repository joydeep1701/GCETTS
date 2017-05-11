#include <stdio.h>
int main(void){
        float a=0,b=0,c=0;
        printf("Enter the values of a,b,c: ");
        scanf("%f %f %f",&a,&b,&c);
        a>b?
            a<c?
                printf("a")
            :b>c?
                printf("b")
            :printf("c")
        :b<c?
            printf("b")
        :c>a?
            printf("c")
            :printf("a");
}
