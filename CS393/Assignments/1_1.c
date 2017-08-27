/**
* Data Structures Assignment - 1
* CS 392
* Problem 1:
*  - Write a C program to perform the following operations using an array:
*      - Insert element into array
*      - Delete element from array
*      - Search a given element using linear search technique
*      - Search a given element using binary search technique
*
* Joydeep Mukherjee
* CSE,3rd Sem, 11000116030
* GCETTS 2017
*
**/
#include <stdio.h>
#include <stdlib.h>

// Input array from user & return the size of array
int input(int **arr);
// Show the array
void show(int *arr,int len);
// menu
void menu(int **arr,int len);
// Insert element
int insert(int **arr,int len);
//Delete element
int delete(int **arr,int len);
// linear search
void linSearch(int *arr,int len);
// binary search
void binSearch(int *arr,int len);
// Selection Sort
int SelectionSort(int **arr,int len);



int main(int argc, char const *argv[]) {
  /* Lets define the program parameters
    - An array of int
    - An int containing length of array
  */
  int *array = NULL;
  int len = 0;

  // Lets input our array from stdin
  len = input(&array);
  // Show our array
  menu(&array,len);

  return 0;
}

int input(int **arr) {
  /*  Prompts user to enter the array
      Arguments: a pointer to a pointer
      Returns: the number of items in array
      Summary: Updates the pointer to point to a memory location on
               created on heap, containing the array of elements
  */
  int* temp_array = NULL;
  int i,len = 0;
  printf("Create a new array\n");
  // Input the length of array
  printf("Number of array elements: ");
  scanf("%d",&len);
  // Create the array
  temp_array = (int*) malloc(sizeof(int)*len);
  // Input the array
  printf("Enter the elements: ");
  for (i = 0; i < len; i++) {
    scanf("%d",(temp_array + i));
  }
  // Set the main pointer address
  *arr = temp_array;
  fflush(stdin);
  // Return
  return len;
}
void show(int *arr,int len) {
  /* Shows the array
  Arguments: the array,length
  Returns: None
  */
  int i;
  printf("\nThe array is:\n");
  for (i = 0; i < len-1; i++) {
    printf("%d, ",*(arr + i));
  }
  printf("%d\n",*(arr + i));
}
void menu(int **arr,int len) {
  /*
    Prompts user to input a choice according to the list
    Arguments: a pointer to a pointer
    Returns: Nothing
  */
  int sel = -1;
  fflush(stdin);
  printf("Choose an option:\n");
  printf("\t1> Show the array \n");
  printf("\t2> Insert element \n");
  printf("\t3> Delete element \n");
  printf("\t4> Search element with linear search\n");
  printf("\t5> Search element with binary search\n");
  printf("\t6> Sort the array with Selection Sort\n");
  printf("\t7> Re-enter array\n");
  printf("\t0> Exit\n");
  do {
    /* menu options */
    printf("\nYour choice:");
    fflush(stdin);
    scanf("%d",&sel);
    // Call Functons accordingly
    switch (sel) {
      case 1:
        show(*arr,len);
        break;
      case 2:
        len = insert(arr,len);
        break;
      case 3:
        len = delete(arr,len);
        break;
      case 4:
        linSearch(*arr,len);
        break;
      case 5:
        binSearch(*arr,len);
        break;
      case 6:
        SelectionSort(arr,len);
        break;
      case 7:
        len = input(arr);
        break;
    }
  } while(sel);

  return;
}
int insert(int **arr,int len) {
  /* Inserts an element at a specific position
     Arguments: A pointer to a pointer, initial lenght
     Returns: Updated lenght
     Summary: Reads index & value from stdin
              Creates a new array & copies values from old to new
              frees the old, changes the pointer
  */
  int i,index,val;
  int *temp_array = (int*) malloc(sizeof(int)*(len+1));

  printf("\nInsert an element in the zero-indexed array\n");
  printf("\tEnter Index: ");
  scanf("%d",&index);
  printf("\tEnter Value: ");
  scanf("%d",&val);

  for( i = 0; i < index; i++)
    *(temp_array + i) = *(*(arr) + i);

  *(temp_array + i) = val;

  for(; i < len; i++)
    *(temp_array + i + 1) = *(*(arr) + i);

  free(*arr);
  *arr = temp_array;
  return len+1;
}

int delete(int **arr,int len) {
  
}
// linear search
void linSearch(int *arr,int len) {

}
// binary search
void binSearch(int *arr,int len) {

}
// Selection Sort
int SelectionSort(int **arr,int len) {

}
