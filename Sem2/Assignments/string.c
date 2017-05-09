#include <stdio.h>
#include <stdlib.h>

#define LIMIT 200

char *str_cpy(char *string1,char *string2,int n,int start){
  /* Usage: strcpy(source,destination,n,start)
    where n is the number of bytes to be copied to destination from source,
    begining from start'th byte from left of destination
  */
  while((*(string2 + start++) = *string1++) && --n);

  return string2;
}
void str_cpy_main(void){
  int start,len;
  char *string1 = malloc(sizeof(char)*LIMIT);
  char *string2 = malloc(sizeof(char)*LIMIT);

  printf("Enter String to be copied: ");
  fflush(stdin);
  scanf("%s",string1);
  printf("Enter Destination String: ");
  fflush(stdin);
  scanf("%s",string2);
  //printf("%s %s\n",string1,string2);
  printf("Enter number of bytes to be copied: ");
  fflush(stdin);
  scanf("%d",&len);
  printf("Enter number of escape bytes: ");
  fflush(stdin);
  scanf("%d",&start);
  str_cpy(string1,string2,len,start);
  /*
  int i;
  for(i=0;i<LIMIT;i++)
    printf("%c",*(string2 + i));
  */
  printf("Output: %s\n",string2);
}
void str_set_main(void){
  int start,len,i;
  //char oc = 65;
  char *string1 = malloc(sizeof(char)*LIMIT);
  char *string2 = malloc(sizeof(char)*LIMIT);
  char *oc = malloc(sizeof(char));

  printf("Enter over-write character: ");
  fflush(stdin);
  scanf("%s",oc);
  //char ovrwrt = getc(stdin);

  printf("Enter number of bytes to be copied: ");
  fflush(stdin);
  scanf("%d",&len);
  printf("Enter number of escape bytes: ");
  fflush(stdin);
  scanf("%d",&start);

  printf("Enter Base String: ");
  fflush(stdin);
  scanf("%s",string2);

  for(i=0;i<len;i++)
    *(string1 + i) = *oc;
  str_cpy(string1,string2,len,start);
  printf("Output: %s\n",string2);
}
int main(int argc, char const *argv[]) {
  int option = 0;
  printf("Choose function:\n 1> strcpy()\n 2> strset()\n");fflush(stdin);
  scanf("%d",&option);fflush(stdin);
  switch (option) {
    case 1:str_cpy_main();break;
    case 2:str_set_main();break;
  }
  return 0;
}
