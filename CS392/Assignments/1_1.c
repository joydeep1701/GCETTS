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

void show   (int *arr,int len); // Show the array
void menu   (int **arr,int len); // menu

int  input   (int len);  // Takes input & bound checks

int  create (int **arr); // Input array from user & return the size of array
int  insert (int **arr,int len); // Insert element
int  delete (int **arr,int len); //Delete element

void linSearch     (int *arr,int len); // linear search
void binSearch     (int *arr,int len); // binary search
int  binSearchRun  (int *arr,int s,int l,int h); // Run binary Search
int  SelectionSort (int *arr,int len); // Selection Sort

int main(int argc, char const *argv[]) {
  /* Lets define the program parameters
    - An array of int
    - An int containing length of array
  */

  int *array = NULL;
  int len = 0;

  len = create(&array); // Lets input our array from stdin
  menu(&array,len);     // Show our array

  return 0;
}

int create(int **arr) {
  /*  Prompts user to enter the array
      Arguments: a pointer to a pointer
      Returns: the number of items in array
      Summary: Updates the pointer to point to a memory location on
               created on heap, containing the array of elements
  */

  int* temp_array = NULL;
  int i,len = 0;

  /* Input the length of array */
  printf("Create a new array\n");
  printf("Number of array elements: ");
  scanf("%d",&len);

  temp_array = (int*) malloc(sizeof(int)*len);   // Create the array

  /* Input the array */
  printf("Enter the elements: ");
  for (i = 0; i < len; i++) {
    scanf("%d",(temp_array + i));
  }

  *arr = temp_array;   // Set the main pointer address
  fflush(stdin);       // Sometimes prevents extra input to be passed to menu

  return len;
}

void show(int *arr,int len) {
  /* Shows the array
  Arguments: the array,length
  Returns: None
  */

  int i;

  printf("\nThe array is:\n");

  for (i = 0; i < len-1; i++)
    printf("%d, ",*(arr + i));
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
    sel = input(8);

    /* Call Functons accordingly */
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
        SelectionSort(*arr,len);
        break;
      case 7:
        len = create(arr);
        break;
    }

  } while(sel);

  return;
}

int input(int len) {
  /* Takes input from user in the range [0,len-1]
  Arguments: a limit len
  Returns: a number from user in range
  */

  int temp = -1;
  while (1) {
    fflush(stdin);
    scanf("%d",&temp);

    if (temp < 0 || temp >= len)
      printf("[Out of range] Retry:");
    else
      break;
  }

  return temp;
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
  index = input(len);
  printf("\tEnter Value: ");
  scanf("%d",&val);

  /* Iterate & copy elements before our desired index */
  for( i = 0; i < index; i++)
    *(temp_array + i) = *(*(arr) + i);

  *(temp_array + i) = val; // Insert new element
  /* Copy remaining elements upto end */
  for(; i < len; i++)
    *(temp_array + i + 1) = *(*(arr) + i);

  free(*arr);  // Free the previous block, prevents memory leak
  *arr = temp_array; // Update our pointer

  return len+1;
}

int delete(int **arr,int len) {
  /* Deletes an element from a specific position
    Arguments: The pointer to the array pointer,lenght
    Returns:   The modified length
    Summary:   Reads index & value from stdin
               Creates a new array & copies values from old to new
               frees the old, changes the pointer
   */

   int index,i;
   int *temp_array = (int*) malloc(sizeof(int)*(len-1));

   printf("\nDelete an element from the zero-indexed array\n");
   printf("\tEnter index:");
   index = input(len);

   for( i = index + 1;i < len;i++)
      *(*arr + i -1) = *(*arr + i);

   *arr = realloc(*arr,sizeof(int)*(len - 1)); // Removes extra space
   return len-1;
}

// linear search
void linSearch(int *arr,int len) {
  /* Does a linear search on the array
  Arguments: a pointer to an array, length of array
  Returns: None
  */

  int s,i;
  printf("\nSearch an element in the array using LinearSearch\n");
  printf("\tEnter value:");
  scanf("%d",&s);

  for (i = 0; i < len; i++) {
    if (*(arr + i) == s) {
      printf("\tFound %d at index %d\n",s,i);
      return;
    }
  }

  printf("\tFound %d at NO index\n",s);
}

// binary search
void binSearch(int *arr,int len) {
  /* Does a binary search on the array for a specific value taken from stdin
  Arguments: a pointer to an array
  Returns: None
  Calls: SelectionSort()
  */

  int s,i;

  SelectionSort(arr,len);

  printf("\nSearch an element in the array using BinarySearch\n");
  printf("\tEnter value:");
  scanf("%d",&s);

  i = binSearchRun(arr,s,0,len);

  if (i != -1)
    printf("\tFound %d at index %d\n",s,i);
  else
    printf("\tFound %d at NO index\n",s);
}

// binary search
int binSearchRun(int *arr,int s,int l,int h) {
  /* Searchs an element in the array using binary search
  Arguments: a pointer to an array, target variable,lower end,higher end
  Returns: index of target variable, if none then -1
  */

  int mid = (l + h)/2;

  if(h < l)
    return -1;
  else if (s == *(arr + mid))
    return mid;
  else if (s > *(arr + mid))
    return binSearchRun(arr,s,mid+1,h);
  else if (s < *(arr + mid))
    return binSearchRun(arr,s,l,mid-1);
}

// Selection Sort
int SelectionSort(int *arr,int len) {
  /* Sorts the array using Selection Sort algorithm
  Arguments: pointer to the array,length of array
  Returns: 0
  */

  int i,j,vi,vj;
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {

      vi = *(arr + i);
      vj = *(arr + j);

      if (vi < vj) {
        *(arr + i) = vj;
        *(arr + j) = vi;
      }
    }
  }
  printf("\nArray is sorted using Selection Sort\n");
  return 0;
}
