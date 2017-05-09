
/*
  --------------------
  | 1 | 2 | 4 | 7
  | 3 | 5 | 8 | 11
  | 6 | 9 | 12| 14
  | 10| 13| 15| 16
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prnt_board(int **board,int dim){
  int i,j;
  for(i=0;i < dim;i++){
      for(j=0;j < dim;j++){
        if(*(*(board + i) + j))
          printf("%02d ",*(*(board + i) + j));
        else
          printf(" %c ",' ');
      }
      printf("\n");
  }
  fflush(stdout);
  usleep(500000);
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
}

int main(void){
  int dim,i,j,count = 1,x,y;
  int **board = NULL;
  printf("Enter Dimension: ");
  scanf("%d",&dim);
  board = malloc(sizeof(int*)*dim);
  for(i=0;i<dim;i++)
    *(board + i) = malloc(sizeof(int)*dim);

  x = 0;
  y = 0;
  prnt_board(board,dim);

  //Print The upper left triangle (0,0),(dim-1,0),(0,dim-1)
  /*
    (0,0). . . . . (0,dim-1)
    .             .
    .           .
    .         .
    .       .
    .     .
    (dim-1,0)
  */
  for(i=0;i < dim;i++){
    x = 0;
    y = i;
    for(j=0;j<=i;j++){
      //printf("(%d,%d) ",x,y);
      //*(*(board + y--) + x++) = count++;
      *(*(board + x++) + y-- ) = count++;
      prnt_board(board,dim);

    }
    //printf("\n");
  }
  //Print the lower right triangle
  /*
                      (1,dim-1)
                  .       .
                .         .
              .           .
            .             .
          .               .
    (dim-1,1) . . . . (dim-1,dim-1)
  */
  for(i=1;i < dim ;i++){
    x = i;
    y = dim - 1;
    for(j=0;j<dim-i;j++){
      //printf("(%d,%d) ",x,y);
      //*(*(board + y--) + x++) = count++;
      *(*(board + x++) + y--) = count++;
      prnt_board(board,dim);

    }
    //printf("\n");
  }
}
