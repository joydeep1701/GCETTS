//Multiplying two 2-d array

#include <stdio.h>
#define MAX 3

int main(void){
    int i,j;
    int array1[MAX][MAX];
    int array2[MAX][MAX];
    
    printf("Enter Array 1:\n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++)
            scanf("%d",&array1[i][j]);
    }
    
    printf("Enter Array2:\n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++)
            scanf("%d",&array2[i][j]);
    }
    printf("Product of two arrays:\n");
    for(i=0;i<MAX;i++){
        for(j = 0;j< MAX;j++){
            printf("%d ",array1[i][j]*array2[i][j]);
        }
        printf("\n");
    }    
    
    

}
