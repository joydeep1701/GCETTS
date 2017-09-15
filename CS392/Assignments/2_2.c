/**
* Data Structures Assignment - 3
* CS 392
* Problem 2:
* - Write a C program to create a singly circular linked list to perform the following operations:
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
  printf("\tLinked List\n" );
  printf("\t\tHEAD->");
  for (i = 0; i < count; i++){
    printf("[%d,%d]->",i,next->val);
    fflush(stdout);
    next = next->next;
    if(next == head)
      break;
  }
  printf("HEAD\n");

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
  newNode->next = (*head);

  if(*head == NULL) {
    *head = newNode;
    newNode->next = (*head);
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
      if(next->next ==  (*head)) {
        printf("\t[WARN] Value: %d will be inserted at end\n",val);
        break;
      }
      next = next->next;
    }

    newNode->next = next->next;

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
    //printf("%d\n",(*head)->next->val );
    if((*head)->next != (*head))
      (*head) = (*head)->next;
    else
      (*head) = NULL;

    free(tmp);
    return count -1;
  }
  else {
    tmp = next;
    for ( i = 0; i < pos; i++) {

      if(next->next == (*head)) {
        printf("\t[ERROR] Index out of range\n");
        return count;
      }
      tmp = next;
      next = next->next;
    }
    // next is at index to be removed
    // tmp is at previous index

    if(next->next == (*head))
      tmp->next = (*head);
    else
      tmp->next = next->next;

    free(next);

    return count -1;
  }
}

void search(node *head, int count) {
  int i,val;
  node* next = head;

  printf("\tSearch Element in List:\n");

  if(next->next == head) {
    printf("\t[ERROR] List is Empty\n");
    return;
  }

  printf("\t\tElememt: ");
  scanf("%d",&val);

  for( i = 0; i < count; i++) {

    if(next->next == head) {
      printf("\tEnd Of List, No Results\n");
      return;
    }

    if(next->val == val) {
      printf("\tFound %d at index %d\n",val,i);
      return;
    }

    next = next->next;

  }

  if(next == head) {
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
