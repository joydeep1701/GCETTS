#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int base;
  int power;
  struct node_t* next;
}node;

int insert(node **head) {
  int base,power,i,iszero = 1;
  node *newNode = NULL;
  node *next = *head;

  while(iszero) {
    scanf("%d %d",&base,&power);

    newNode = (node*) malloc(sizeof(node));

    if(!newNode){
      printf("\nMemory Error\n");
      return -1;
    }

    newNode->base = base;
    newNode->power = power;
    newNode->next = NULL;


    if((*head) == NULL) {

      *head = newNode;
      next = *head;
    }
    else{
      next->next = newNode;
      next = next->next;
    }

    (!base && !power)?(iszero = 0):(iszero = 1);

  }
  return 0;
}
void show(node *head) {
  node *this = head;
  while(this != NULL) {
    printf("%dx^%d ",this->base,this->power);
    this = this->next;
    if(this != NULL)
      printf("+ ");
    else
      break;
  }
  printf("\n");
}

void add(node *pa,node *pb,node **pc) {
  node *newNode = NULL;
  node *next = *pc;

  int pc_power = 0;
  int pc_base = 0;

  while(pa != NULL || pa != NULL){
    if(pa->power == pb->power) {

      pc_base = pa->base + pb->base;
      pc_power = pa->power;

      pa = pa->next;
      pb = pb->next;

    }
    else if(pa->power > pb->power){

      pc_base = pa->base;
      pc_power = pa->power;

      pa = pa->next;


    }
    else {

      pc_base =  pb->base;
      pc_power = pb->power;

      pb = pb->next;

    }

    newNode = (node*) malloc(sizeof(node));

    if(!newNode){
      printf("\nMemory Error\n");
      return;
    }

    newNode->base = pc_base;
    newNode->power = pc_power;
    newNode->next = NULL;

    if((*pc) == NULL) {
      *pc = newNode;
      next = *pc;
    }
    else{
      next->next = newNode;
      next = next->next;
    }

  }
  return;
}

int main(int argc, char const *argv[]) {
  /* code */
  node *pa,*pb,*pc;

  printf("For polynomial:1 enter the multiplier, power in descending order\n");
  printf("Enter '0 0' to quit\n");
  printf("Format:[mult][pow]\n");
  pa = NULL;
  insert(&pa);

  printf("For polynomial:2 enter the multiplier, power in descending order\n");
  pb = NULL;
  insert(&pb);

  pc = NULL;
  add(pa,pb,&pc);
  printf("polynomial 1: ");
  show(pa);
  printf("polynomial 2: ");
  show(pb);
  printf("Result: ");
  show(pc);

  return 0;
}
