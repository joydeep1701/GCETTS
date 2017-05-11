#include <stdio.h>
#include <math.h>
int len(int n){
	int i = 1,s = 0;
	for(;i <= n;){
		i *=10;
		s++;
	}
	return s;
}
int raisetopower(float number,int power){
    float temp = 1;
    for(;power>0;power--)
        temp *= number;
    return temp;
}
int main(void){
	int n,l,i,total=0,temp;
	printf("Enter Number:");
	scanf("%d",&n);
	temp = n;
	l = len(n);
	for(i = 0;i < l;i++){
		//printf("%d->",n%10);
		total += raisetopower(n%10,l);
		//printf("%d ",total);
		n = n/10;
	}

	if(temp != total){
		printf("Not");
	}
	else{
		printf("Yes");
	}

}
