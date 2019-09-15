#include<stdio.h>
#include<stdlib.h>

void SWAP(char*list2,int i, int j){



char temp;
temp = list2[i];
list2[i]=list2[j];
list2[j]=temp;
}

void perm(char*list, int i, int n){
int j, temp;
if(i==n){
for(j=0; j<=n; j++)
printf("%c",list[j]);
printf("\n");
}
else{
for(j=i;j<=n;j++){
SWAP(list,i,j);
perm(list,i+1,n);
SWAP(list,i,j);
}
}
}

int main(void){
char list[3];


printf("Input: ");
scanf("%s",list);
printf("\n");
perm(list,0,2);
return 0;
}



