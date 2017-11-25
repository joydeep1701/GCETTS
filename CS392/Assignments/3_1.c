/**
* Data Structures Assignment - 3
* CS 392
* Problem 1:
*       Write a C program to perform push and pop operation on a stack array
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

#include <stdio.h>
#include <stdlib.h>

int *stack;
int pos;
int size;


void init() {
  // Prompt the user to enter the size of stack
  printf("Enter Size of stack: ");
  scanf("%d",&size);
  stack = malloc(sizeof(int)*size);
  pos = 0;
}
void push(int elem) {
  if(size == pos) {
    printf("Stack Overflow, %d not added\n",elem);
    return;
  }
  stack[pos++] = elem;

}
int pop() {
  if(pos == 0) {
    printf("Stack is Empty\n");
    return 0;
  }
  return stack[--pos];
}


int main(void ){
  int temp;

  init();

  printf("Enter 0 to pop, -1 to exit\n");
  do{
    printf(">>> ");
    scanf("%d", &temp);

    if(temp)
      push(temp);
    else
      if(temp=pop())
        printf("Popped: %d\n",temp);

  } while(temp != -1);

  return 0;
}
