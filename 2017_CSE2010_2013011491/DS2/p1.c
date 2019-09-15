#include<stdio.h>

void swap(int**a, int**b)
{ int*temp;
*temp=**a;
**a=**b;
**b=*temp;
}

int main(void){
int a[2];
int*pA=&a[0];
int*pB=&a[1];

printf("Input data: ");
scanf("%d,%d",&a[0],&a[1]);
printf("variable A : %d, B : %d\n",a[0],a[1]);
swap(&pA,&pB);
printf("After Swap A : %d, B : %d\n",a[0],a[1]);
return 0;
}
