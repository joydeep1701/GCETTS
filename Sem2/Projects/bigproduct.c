//Due to time constraints this code isn't documneted, I will send another copy with proper documentation soon :)

//Include the header files
#include <stdio.h>
#include <stdlib.h>

//Define the max length of nummber
#define MAXLEN 200

char* multiply(char *numb,int len,int multiplier,int suffix,char *buffer);
void add(char *numb1,char *numb2,char *total);

int main(int argc, char const *argv[]) {
  /* code */
  //printf("%d",'=');
  char *numb1_p = malloc(sizeof(int)*MAXLEN);
  char *numb2_p = malloc(sizeof(int)*MAXLEN);
  char *result_p = malloc(sizeof(int)*MAXLEN*2);
  char *buffer_p = malloc(sizeof(int)*MAXLEN*2);
  char *zero = NULL;
  int len_numb1,len_numb2,i,j;
  /*
  char numb1[] = {1,2,3,4};
  char numb2[] = {4,5,6,7};
  char total[] = {0,0,0,0};
  //add(&numb1[0],&numb2[0],total);
  //for(int i=0;i<4;i++)
    //printf("%d\n",total[i]);
  */
  printf("Input the first number: ");
  scanf("%s",numb1_p);
  fflush(stdin);
  printf("Input the second number: ");
  scanf("%s",numb2_p);
  fflush(stdin);
  for(len_numb1=0;*(numb1_p+len_numb1) != '\0';len_numb1++);
  for(len_numb2=0;*(numb2_p+len_numb2) != '\0';len_numb2++);
  //printf("Length of First %d, Second %d \n",len_numb1,len_numb2);
  for(i=len_numb2-1,j=1; i>=0;i--){
    buffer_p = multiply(numb1_p,len_numb1,(*(numb2_p+i)-48),j++,buffer_p);
    //for(int i=0;i < MAXLEN*2-1;i++)
      //printf("%d",*(buffer_p+i));
      //printf("  ");
    //for(int i=0;i < MAXLEN*2-1;i++)
      //printf("%d",*(result_p+i));
      //printf("\n");

    zero = malloc(sizeof(int)*MAXLEN*2);

    add(buffer_p,result_p,zero);
    //free(result_p);
    result_p = zero;
    //free(zero);
  }
  printf("Result is: ");
  int number_not_started = 1;
  for(i=0;i < MAXLEN*2-1;i++){
    if(number_not_started && !(*(result_p + i))){
      printf("%c",0);
    }
    else{
      printf("%d",*(result_p+i));
      number_not_started = 0;
    }
  }
  printf("\n");

  return 0;
}
char* multiply(char *numb,int len,int multiplier,int suffix,char *buffer){
  *(buffer + MAXLEN*2-1) = '\0';
  char *carry = malloc(sizeof(char)*MAXLEN*2);
  *(carry + MAXLEN*2-1) = '\0';
  int temp = 0,i;
  int index = MAXLEN*2-1;
  *(carry + index) = 0;
  //printf("%d",index);
  for(i = 0;i < suffix;i++){
    *(buffer + index) = 0;
    index--;

  }
  for(i=len-1;i >= 0;i--){
    //printf("%d * %d = %d carry:%d temp:%d\n",(*(numb+i)-48),multiplier,//((*(numb+i)-48)*multiplier)%10,((*(numb+i)-48)*multiplier)/10,((*(numb+i)-48)*multiplier)%10 + carry);
    *(buffer + index) = ((*(numb+i)-48)*multiplier)%10;
    index--;
    *(carry + index) = ((*(numb+i)-48)*multiplier)/10;
  }
  char *total = malloc(sizeof(char)*MAXLEN*2);
  add(buffer,carry,total);
  //for(int i=0;i < MAXLEN*2-1;i++)
    //printf("%d",*(total+i));
  return total;
}
void add(char *numb1,char *numb2,char *total){
  int temp,i;
  for(i= (MAXLEN*2-1); i >= 0; i--){
    //printf(" %d+ %d+ %d = %d ",*(numb1+i),*(numb2+i),*(total+i),(*(total+i) + *(numb1+i)+*(numb2+i)) );

    if((*(total+i) + (*(numb1+i)+*(numb2+i))) < 10){
      *(total+i) = (*(total+i) + *(numb1+i)+*(numb2+i))%10;
      //*(total +i-1) = (*(total+i) + *(numb1+i)+*(numb2+i))/10;
    }
    else{
      temp = (*(total+i) + (*(numb1+i)+*(numb2+i)));
      *(total+i) = temp%10;
      *(total +i-1) = temp/10;
      //printf("> 10,carried->%d ",*(total+i-1));

    }
    //printf(" %d %d %d\n",*(numb1+i),*(numb2+i),*(total+i) );
  }

}
