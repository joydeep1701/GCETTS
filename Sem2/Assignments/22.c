//Declare a structure with the following members:
// -Name, Stream, Age. Read these data for 4 student and print the names of all those students whose Age > 20.
#include <stdio.h>

#define MAX 4

typedef struct Student{
  char name[20];
  char stream[20];
  int age;
}student;

int main(void){
  int i;
  student database[MAX];
  for(i=0;i<MAX;i++){
    printf("Student #%d\n",i+1);
    printf("Enter Name:");
    scanf("%s",database[i].name);
    printf("Enter Stream:");
    scanf("%s",database[i].stream);
    printf("Enter Age:");
    scanf("%d",&database[i].age);
  }
  printf("Students with age > 20\n");
  for(i=0;i<MAX;i++){
    if(database[i].age > 20){
      printf("Name: %s\n",database[i].name);
    }
  }
}
