/**
* Data Structures Assignment - 1
* CS 392
* Problem 2:
*  - Write a C program to add two polynomial using arrays
*
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int power;
  int mult;
} elem;

int main(int argc, char const *argv[]) {
  elem *pa,*pb,*pc;
  int len,i,j,k;
  printf("Enter order of polynomial:");
  scanf("%d",&len);
  pa = (elem*) malloc(sizeof(elem)*len);
  pb = (elem*) malloc(sizeof(elem)*len);
  pc = (elem*) malloc(sizeof(elem)*2*len);

  printf("For polynomial:1 enter the multiplier, power in descending order\n");
  printf("Enter '0 0' to quit\n");
  printf("Format:[mult][pow]\n");
  for (i = 0; i < len; i++) {
    scanf("%d %d",&(pa + i)->mult,&(pa + i)->power);
    if(!(pa + i)->mult && !(pa + i)->power)
      break;
  }
  printf("For polynomial:2 enter the multiplier, power in descending order\n");
  for (i = 0; i < len; i++) {
    scanf("%d %d",&(pb + i)->mult,&(pb + i)->power);
    if(!(pb + i)->mult && !(pb + i)->power)
      break;
  }

  for ( i = 0; i < len*2; i++) {
    if((pa + j)->power == (pb + k)->power) {
      (pc + i)->power = (pa + j)->power;
      (pc + i)->mult = (pa + j++)->mult + (pb + k++)->mult;
    }
    else if((pa + j)->power > (pb + k)->power) {
      (pc + i)->power = (pa + j)->power;
      (pc + i)->mult = (pa + j++)->mult;
    }
    else {
      (pc + i)->power = (pb + k)->power;
      (pc + i)->mult = (pb + k++)->mult;
    }
  }
  printf("polynomial 1: ");
  for( i = 0; ((pa + i)->mult && (pa + i)->power) && i < len ; i++)
    printf("%dx^%d + ",(pa + i)->mult,(pa + i)->power);
  printf("0\n");
  printf("polynomial 2: ");
  for( i = 0; ((pb + i)->mult && (pb + i)->power) && i < len ; i++)
    printf("%dx^%d + ",(pb + i)->mult,(pb + i)->power);
  printf("0\n");
  printf("Result: ");
  for( i = 0; ((pc + i)->mult && (pc + i)->power) && i < len*2 ; i++)
    printf("%dx^%d + ",(pc + i)->mult,(pc + i)->power);
  printf("0\n");

  return 0;
}
