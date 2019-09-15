#include<stdio.h>

#define MAX_SIZE 100
int n=9;
int list[MAX_SIZE]={9,8,7,6,5,4,3,2,1};
#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))
void quick_sort();

int main()
{
quick_sort(list,0,8);
}

void print(int list[],int n)
{
int i;
for(i=0; i<n; i++)
printf("%d",list[i]);
printf("\n");
}

int partition(int v[], int left, int right)
{
int ipivot=(left+right)/2;
int store = -1;
int i=0;

int swap = v[ipivot];
v[ipivot]=v[right];
v[right]=swap;

store = left;

for(int i=left; i<right; i++){
if(v[i]<=v[right]){
SWAP(v[i],v[store],swap);
store++;
}
}
SWAP(v[store],v[right],swap);
return store;
}

void quick_sort(int list[],int left,int right)
{
if(left<right){
int q=partition(list,left,right);
print(list,9);
quick_sort(list,left, q-1);
quick_sort(list,q+1,right);
}
}

