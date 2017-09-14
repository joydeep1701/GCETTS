/**
* Data Structures Assignment - 2
* CS 392
* Problem 1:
* - Write a C program to create a singly linked list to perform the following operations:
*    - Insert element
*    - Delete element
*    - Search a given element
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  /* basic node data type */
  int val;
  struct node_t* next;
} node;

void show(node* head,int count) {

  int i;
  node* next = head;

  printf("HEAD->");
  for (i = 0; i < count; i++){
    printf("[%d,%d]->",i,next->val);
    fflush(stdout);
    next = next->next;
    if(next == NULL)
      break;
  }
  printf("NULL\n");

}


int insert(node** head, int count) {
  int val, pos, i;
  node* next = *head;

  printf("\tInsert Element in Linked List\n");
  printf("\t\tEnter Value: ");
  scanf("%d",&val);

  node* newNode = (node*) malloc(sizeof(node));

  if(!newNode) {
    printf("[ERROR] Memory Error\n");
    return count;
  }

  newNode->val = val;
  newNode->next = NULL;

  if(*head == NULL) {
    *head = newNode;
    return count+1;
  }
  else{
    printf("\t\tEnter Position: ");
    scanf("%d",&pos);

    if(!pos) {
      //printf("current head val:%d\n",(*head)->val);
      newNode->next = (*head);
      //printf("newNode->next->val->%d\n",newNode->next->val);
      *head = newNode;
      //printf("current head val:%d\n",(*head)->val);
      //printf("head->next->val:%d\n",(*head)->next->val);
      return count + 1;

    }

    //printf("%d",(*head));
    for (i = 0; i < pos -1; i++) {
      //printf("Next elem:%d\n",next->val);
      if(next->next ==  NULL) {
        printf("Value: %d will be inserted at the end pos:%d\n",val,i);
        break;
      }

      //printf("[%d|%d]->",i,next->val);
      fflush(stdout);
      next = next->next;
    }
    //printf("Out of Loop");
    if(next != NULL) {
      newNode->next = next->next;
      //printf("Next is not NULL\n");
      //fflush(stdout);
    }
    else{
      newNode->next = NULL;
    }
    next->next = newNode;

    return count+1;
  }

  return count;
}

int main(int argc, char const *argv[]) {
  /* */
  int menu_option = -1,count = 0;
  node* head = NULL;
  printf("Your options are:\n");
  printf("\t1. Insert Element\n");
  printf("\t2. Delete Element\n");
  printf("\t3. Search Element by Value\n");
  printf("\t0. Exit\n");
  while (menu_option) {
    printf("Enter option: ");
    fflush(stdin);
    scanf("%d",&menu_option);
    switch (menu_option) {
      case 1:
        count = insert(&head,count);
        break;
      case 2:
        //delete();
        break;
      case 3:
        //search();
        break;
      case 4:
        show(head,count);
        break;
      case 0:
        return 0;
        break;
      default:
        printf("Invalid option\n");
    }
    /* code */
  }
  return 0;
}
