#include <stdio.h>
#include <math.h>

int main(void) {
  float a=0,b=0,c=0;
  printf("Enter the values of a,b,c: ");
  scanf("%f %f %f",&a,&b,&c);
  float d = b*b - 4*a*c;

  if(d <0){
    printf("The Q.E has Imaginary roots\n");
    printf("First root:%0.2f+%0.2fi\n",(-b/(2*a)),((sqrt(-d))/(2*a)));
    printf("Second root:%0.2f-%0.2fi\n",(-b/(2*a)),((sqrt(-d))/(2*a)));
  }
  else{
   printf("The Q.E has Real roots\n");
   printf("First root:%0.2f\n",(-b/(2*a)+(sqrt(d))/(2*a)));
   printf("Second root:%0.2f\n",(-b/(2*a)-(sqrt(d))/(2*a)));
  }
  return 0;
}
