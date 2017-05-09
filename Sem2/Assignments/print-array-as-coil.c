#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

void wait(unsigned int ms){
  //clock_t end = ms + clock();
  //while(end > clock());
  usleep(500000);
}

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
}
void clear(void)
{
    //wait(250000);
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    wait(250000);

}
int main(void){
  int dim,i,j,x,y,count=1;
  int **board;
  do{
    printf("Enter Dimension of array: ");
    scanf("%d",&dim);
  }while(!dim%2);
  board = malloc(sizeof(int*)*dim);
  for(i=0;i < dim;i++){
    *(board + i) = malloc(sizeof(int)*dim);
  }
  x = (dim - 1)/2;
  y = (dim - 1)/2;
  *(*(board + y) + x) = count++;
  clear();
  y--;

  for(i = 1;i < dim;){
    i += 2;

    for(j = 0;j < (i -1 -1);j++){
      *(*(board + y) + x) = count++;
      prnt_board(board,dim);
      x--;
      clear();
    }

    for(j = 0;j < i-1;j++){
      *(*(board + y) + x) = count++;
      prnt_board(board,dim);
      y++;
      clear();
    }

    for(j = 0;j < i-1;j++){
      *(*(board + y) + x) = count++;
      prnt_board(board,dim);
      x++;
      clear();
    }
    for(j = 0;j < i;j++){
      *(*(board + y) + x) = count++;
      prnt_board(board,dim);
      y--;
      clear();
    }
  }
}
