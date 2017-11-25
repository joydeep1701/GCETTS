/**
* Data Structures Assignment - 3
* CS 392
* Problem 2:
*       Write a C program to perform push and pop operation on a linked stack
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
  int val;
  struct node_t *next;
}node;

node *stack;

void init() {
  // Create Stack
  stack = NULL;
}
void push(int elem) {
  // Allocate New node
  node *new = malloc(sizeof(node));
  // Check for memory fault
  if(!new) {
    printf("Memory Fault\n");
    return;
  }
  new->val = elem;
  new->next = stack;

  stack = new;
}
int pop() {
  int temp;
  // Check for empty stack
  if(!stack) {
    //printf("Stack is Empty\n");
    return 0;
  }
  temp = stack->val;
  stack = stack->next;

  return temp;
}


int main(void ){
  char c;

  init();
  printf("Enter String:\n>>>");
  while((c = getchar()) != '\n') {
    push(c);
  }
  printf("Reversed String: ");
  while(c = pop())
    printf("%c",c);
  printf("\n");


  return 0;
}
