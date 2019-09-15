#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) {t=x; x=y; y=t;}
#define MAX_SIZE 10
#define NAME_SIZE 32

//adjust 함수의 구현은 수업시간에 다루었고 동일한 알로기즘으로 구현되어 있음
void adjust(int heap[], int root, int n)//heap로 만드는 함수
{
int temp=heap[root];//임시 값에 heap루트값 저장
int child=2*root+1;//자식노드의 배열에서의 순서값 설정
while(child<=n-1){//자식노드가 마지막노드가 될때까지 비교
 if((child<n-1)&&(heap[child]<heap[child+1])) child++;//두 자식 노드의 값중에 큰값을 child로 설정
 if(temp>heap[child]) break;//루트 노드가 자식노드 보다 클경우 비교 종료
 else{//자식노드가 루트노드보다 더 클경우
  heap[(child-1)/2]=heap[child];
  child = 2*child +1;
 }
 }
 heap[(child-1)/2] = temp;
}


void heap_sort(int list[], int n)
{
 int i,j;
 int temp;
 for(i=(n-2)/2; i>=0; i--)
  adjust(list,i,n);//마지막 노드부터 재정렬
 for(i=n-1; i>=0; i--)//히프중 첫째값을 마지막 값과 바꾼뒤 마지막 배열을 제외하고 재정렬
 {
  SWAP(list[0],list[i],temp);
  adjust(list,0,i);
 }
 
 //fill in the balnk

}


void main()
{ 
   FILE *f;
   int i;
   int list1[MAX_SIZE];
   f= fopen("input2.txt","r");
   fscanf(f,"%d %d %d %d %d %d %d %d %d %d",
    &list1[0],&list1[1],&list1[2],&list1[3],&list1[4],
    &list1[5],&list1[6],&list1[7],&list1[8],&list1[9]);
   //힙정렬
   heap_sort(list1, MAX_SIZE); /* 선택정렬 호출 */
   printf("heap_sort: \n");
   for(i=1; i<=MAX_SIZE; i++)
   printf("%d   ",list1[i-1]); //printf("%d \t", );

} 

