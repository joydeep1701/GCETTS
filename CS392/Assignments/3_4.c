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
  int a,b;
  init();
  printf("Enter Postfix Expression:\n>>>");
  while((c = getchar()) != '\n') {
    if(c >= 48 && c < 58) {
        //printf("Pushed: %d\n",c-48);
        push(c-48);
    }
    else if (c != ' '){
      b = pop();
      a = pop();
      //printf("Popped: %d %d\n",a,b);
      switch (c) {
        case '+':
          push(a+b);
          break;
        case '-':
          push(a-b);
          break;
        case '*':
          push(a*b);
          break;
        case '/':
          push(a/b);
          break;
        default:
          break;
      }
    }
  }
  printf("Result of Expression: %d\n",pop());

  return 0;
}
