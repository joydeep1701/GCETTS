/**
* Data Structures Assignment - 2
* CS 392
* Problem 1:
* - Write a C program to create a doubly linked list to perform the following operations:
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
  struct node_t* prev;
} node;

void show(node* head,int count) {

  int i;
  node* next = head;
  printf("\tLinked List\n" );
  printf("\t\tHEAD->");
  for (i = 0; i < count; i++){
    printf("[%d,%d]",i,next->val);
    fflush(stdout);
    next = next->next;
    if(next == NULL)
      break;
    else
      printf("<->");
  }
  printf("->NULL\n");

}


int insert(node** head, int count) {
  int val, pos, i;
  node* next = *head;

  printf("\tInsert Element in Linked List\n");
  printf("\t\tEnter Value: ");
  scanf("%d",&val);

  node* newNode = (node*) malloc(sizeof(node));

  if(!newNode) {
    printf("\t[ERROR] Memory Error\n");
    return count;
  }

  newNode->val = val;
  newNode->next = NULL;
  newNode->prev = NULL;

  if(*head == NULL) {
    *head = newNode;
    return count+1;
  }
  else{
    printf("\t\tEnter Position: ");
    scanf("%d",&pos);

    if(!pos) {
      newNode->next = (*head);
      *head = newNode;
      return count + 1;
    }

    for (i = 0; i < pos -1; i++) {
      if(next->next ==  NULL) {
        printf("\t[WARN] Value: %d will be inserted at end\n",val);
        break;
      }

      next = next->next;
    }

    if(next != NULL) {
      newNode->next = next->next;
      newNode->prev = next;
    }
    else {
      newNode->next = NULL;
      newNode->prev = next;
    }

    next->next = newNode;

    return count+1;
  }

}

int delete(node** head,int count) {
  int pos, i;
  node *next = *head;
  node *tmp = NULL;

  if(next == NULL) {
    printf("\t[ERROR] List is Empty\n");
    return 0;
  }

  printf("\tDelete Element in Linked List\n");
  show(*head,count);
  printf("\t\tEnter Index: ");
  scanf("%d",&pos);

  if(!pos) {
    tmp = (*head);
    if((*head)->next != NULL)
      (*head) = (*head)->next;
    else
      (*head) = NULL;

    return count -1;
  }
  else {
    tmp = next;
    for ( i = 0; i < pos; i++) {

      if(next->next == NULL) {
        printf("\t[ERROR] Index out of range\n");
        return count;
      }
      tmp = next;
      next = next->next;
    }
    // next is at index to be removed
    // tmp is at previous index

    if(next->next == NULL)
      tmp->next = NULL;
    else {
        tmp->next = next->next;
        next->next->prev = tmp;
    }

    free(next);

    return count -1;
  }
}

void search(node *head, int count) {
  int i,val;
  node* next = head;

  printf("\tSearch Element in List:\n");

  if(next == NULL) {
    printf("\t[ERROR] List is Empty\n");
    return;
  }

  printf("\t\tElememt: ");
  scanf("%d",&val);

  for( i = 0; i < count; i++) {

    if(next == NULL) {
      printf("\tEnd Of List, No Results\n");
      return;
    }

    if(next->val == val) {
      printf("\tFound %d at index %d\n",val,i);
      return;
    }

    next = next->next;

  }

  if(next == NULL) {
    printf("\tEnd Of List, No Results\n");
    return;
  }

}

int main(int argc, char const *argv[]) {
  /* */
  int menu_option = -1,count = 0;
  node* head = NULL;
  printf("Your options are:\n");
  printf("\t1. Insert Element\n");
  printf("\t2. Delete Element\n");
  printf("\t3. Search Element by Value\n");
  printf("\t4. Show List\n");
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
        count = delete(&head,count);
        break;
      case 3:
        search(head,count);
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
  }
  return 0;
}
