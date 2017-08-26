//Write a C program to read data from a file and copy all the contents to a new file.

#include <stdio.h>

int main(void){
    FILE *file1,*file2;
    char store,fname1[50],fname2[50];
    printf("Enter Source File: ");
    scanf("%s",fname1);
    printf("Enter Destination File: ");
    scanf("%s",fname2);
    file1= fopen(fname1,"r");
    file2 = fopen(fname2,"w");
    if(!file1  || !file2 ){
        printf("Read Error\n");
        return 1;
    }
    while((store = fgetc(file1)) != EOF){
        //printf("%c",store);
        fputc(store,file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;

}
