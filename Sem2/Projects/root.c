#include <stdio.h>
float raisetopower(float number,int power){
    float temp = 1;
    for(;power>0;power--)
        temp *= number;
    return temp;
}
int check(float guess,float number,int power){    
    int a;
    a = (int) (raisetopower(guess,power)*100);
    int b = number*100;   
    if(a == b)        
        return 1;    
    return 0;
}
float root(float lower,float upper,float number,int power){    
    float middle = (lower + upper)/2;
    if(check(middle,number,power))
            return middle;
    else if(raisetopower(middle,power) < number)
        return root(middle,upper,number,power);
    else
        return root(lower,middle,number,power);
}
int main(void){
    float numb;int upper = 1;int lower = 1;
    printf("Format: (number)^(a/b)\n");
    INPUT:    
      printf("Input Number: ");scanf("%f",&numb);fflush(stdin);
      printf("Input a:");scanf("%d",&upper);fflush(stdin);
      printf("Input b:");scanf("%d",&lower);
      numb = root(0,numb,numb,lower);
      numb = raisetopower(numb,upper);
      printf("Value-> %0.2f\n",numb);   
    goto INPUT;
}
