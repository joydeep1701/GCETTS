#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

float parseFloat(char* string,int end){
  /**
  * This Function takes in two in inputs,
  * string:-> a pointer to the first element of the float [basically arrray] 
  * end:->  a counter which donates the end of float calculated previously
  */
    int s = 0; // A counter to check the digit number
    float number = 0; // The total float number
    float multiplier = 10; // Before the floating point the multiplier should be 10
    int decimal = 0; // Checks if it is decimal part of fractional part
    for(s = 0;s < end;s++){ // Loop until the end
        if(*(string+s) != '.'){ // Checks  if cuurent one is a point
            //printf("%u",*(string+i)-48); // Prints the current for debugging purposes
            //printf("%d ",s);  //Prints the counter value
            if(decimal==0){ // If it is a decimal portion
                number = number*multiplier + (*(string+s)-48); // Appends the values , -48 -> As the values are stored in ascii
            }
            else{
                number = number + (*(string+s)-48)*multiplier; // Appends the values after the point
                multiplier *= 0.1; // multiplier should be decreased
            }
        }
        else{
            multiplier = 0.1; //sets the multiplier to 0.1          
            decimal = 1;  // Sets decimal to 1
        }
    }    //printf("number->%0.3f   End-> %u  i-> %d\n",number,end,i);
    return number;
}
float parseNumb(char* string,int *index){
  /*
    This Fuction is used to extract number begining from a pointer
    Input: string-> a pointer to the begining of the number
           index->  a pointer to an integer index which stores the current location from the begining
    Output: returns the float value    
  */
    int j =0; // Sets up a initial counter
    while(isdigit(*(string+ j))) // Loops & increases while there is a number
        j++;                                                                            //printf("%c",(*(input+ i + j)));
    if((*(string+ j)) == '.' ){ // if its a point 
        j++;    //its counted                                                        //printf("true");
        while(isdigit(*(string+ j))) // Loops & increases while there is a number
            j++;                                                     // printf("%d  ",j);
    }
    float current = parseFloat((string),j); // calls the parseFloat function to generate the float from the 
    *index += j;
    return current;
}
float multiply(char *string,int *index,int *max_len,char *this_action,char *next_action,float *total){
    if(isdigit(*(string+*index) )){
        float current = parseNumb((string+*index),index);
        *next_action = *(string + (*index));
        (*index)++;
        //printf("----Multiply: this->%0.2f this_action->%c next_action->%c next->%c total->%0.2f\n",current,*this_action,*next_action,*(string + (*index)),*total);
        if(*next_action == '*'){
            return current * multiply(string,index,max_len,this_action,next_action,total);
        }
        else{
            *this_action=*next_action;
            return current;
        }
    }
    return 0;
}
float divide(char *string,int *index,int *max_len,char *this_action,char *next_action,float *total){
    if(isdigit(*(string+*index) )){
        float current = parseNumb((string+*index),index);
        *next_action = *(string + (*index));
        (*index)++;
        //printf("----Divide: this->%0.2f this_action->%c next_action->%c next->%c\n",current,*this_action,*next_action,*(string + (*index)));
        if(*next_action == '/'){
            return current / divide(string,index,max_len,this_action,next_action,total);
        }
        else{
            *this_action=*next_action;
            return current;
        }
    }
    return 0;
}

float check(char *string,int *index,int *max_len,char *this_action,char *next_action,float *total){
   // printf("%c\n",(*(string) ));
    if((*index) > *max_len){
        return 0;
    }
   if(isdigit(*(string+*index) )){
        float current = parseNumb((string+*index),index);
        *next_action = *(string + (*index));
        //printf("current->%0.2f index->%d this_action->%c next_action->%c next->%c total->%0.2f\n",current,*index,*this_action,*next_action,*(string+*index),*total);
        (*index)++;
        switch(*this_action){
            case '+':
                if(*next_action == '*'){
                    *this_action=*next_action;
                    *total += current * multiply(string,index,max_len,this_action,next_action,total);
                    check(string,index,max_len,this_action,next_action,total);
                }
                else if(*next_action == '/'){
                    *this_action=*next_action;
                    *total += current / divide(string,index,max_len,this_action,next_action,total);
                    check(string,index,max_len,this_action,next_action,total);
                }
                else{
                    *total += current;
                    *this_action = *next_action;
                    check(string,index,max_len,this_action,next_action,total);
                }
                break;
            case '-':
                if(*next_action == '*'){
                    *this_action=*next_action;
                    *total -= current * multiply(string,index,max_len,this_action,next_action,total);
                    check(string,index,max_len,this_action,next_action,total);
                }
                else if(*next_action == '/'){
                    *this_action=*next_action;
                    *total -= current / divide(string,index,max_len,this_action,next_action,total);
                    check(string,index,max_len,this_action,next_action,total);
                }
                else{
                    *total -= current;
                    *this_action = *next_action;
                    check(string,index,max_len,this_action,next_action,total);
                }
                break;
            case 0:
                return current;
        }

    }
    return 0;
}
int main(void){
    printf("\n-------------------------Calculator--------------------Joydeep Mukherjee------\n\n");
    printf("Enter expression: ");
    char *input =NULL;
    input = malloc(sizeof(int)*50);
    scanf("%s",input);
    int index = 0;
    int max_len = strlen(input);//printf("max len: %d\n",max_len);
    float total = 0;
    char this_action = '+';
    char next_action = '+';
    /*
    printf("\n---------------------------index--------------------------------\n");
    int ss = 0;
    for(;ss<max_len;ss++)
        printf("%0d ",ss);
   printf("\n---------------------------value--------------------------------\n");
   for(ss=0;ss<max_len;ss++)
        printf("%c ",*(input+ss));
    printf("\n-----------------------------------------------------------\n\n");
    */
    check(input,&index,&max_len,&this_action,&next_action,&total);
    printf("Total: %0.2f\n\n",total);

    return max_len;
}
