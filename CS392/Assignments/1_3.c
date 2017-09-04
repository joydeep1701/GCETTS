#include <stdio.h>

int main(int argc, char const *argv[]) {

  int r,c,i,j,size;
  int arr[100][100];

  printf("Enter Row Size: ");
  scanf("%d",&r);
  printf("Enter Column Size: ");
  scanf("%d",&c);

  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      scanf("%d",(*(arr + i) + j) );

  printf("Sparse matrix of %dx%d is:\n",r,c);
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      printf("%d ",*(*(arr + i) + j) );
    }
    printf("\n");
  }

  for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (arr[i][j] != 0)
				size++;
  printf("Size of matrix:%d\n",size);
  int compactMatrix[3][size];

	// Making of new matrix
	int k;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 5; j++)
			if (arr[i][j] != 0)
			{
				compactMatrix[0][k] = i;
				compactMatrix[1][k] = j;
				compactMatrix[2][k] = arr[i][j];
				k++;
			}

  printf("Sparse matrix:\n");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<size; j++)
			printf("%d ", compactMatrix[i][j]);

		printf("\n");
	}

	return 0;




  return 0;
}
