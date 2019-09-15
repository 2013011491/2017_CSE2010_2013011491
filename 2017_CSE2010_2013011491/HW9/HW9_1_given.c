#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) {t=x; x=y; y=t;}
#define MAX_SIZE 10
#define NAME_SIZE 32

/* i는 정렬된 왼쪽리스트에 대한 인덱스
   j는 정렬된 오른쪽리스트에 대한 인덱스
   k는 정렬될 리스트에 대한 인덱스 */
void merge(int list[], int left, int mid, int right)
{ 
   int i, j, k, l;
   int tmplist[MAX_SIZE];//정렬된 배열을 저장할 임시 리스트
   i=left;  j=mid+1;  k=left;
   l=right;
  
   while(i<=mid && j<=l)//왼쪽리스트와 오른쪽 리스트 비교
   {
    if(list[i]<=list[j])//왼쪽리스트 값이 작을경우
    tmplist[k++]=list[i++];
    else//오른쪽 리스트 값이 작을경우
    tmplist[k++]=list[j++];
   }
  
   while(i<=mid)//더이상 비교할 수가 없을때 왼쪽리스트에 값이 남아있는경우
   tmplist[k++]=list[i++];
   while(j<=l)//더이상 비교할 수가 없을때 오른쪽리스트에 값이 남아있는경우
   tmplist[k++]=list[j++];
  
   for(left; left<=right; left++)//임시리스트에 저장된 배열,배열할 리스트로 옮기기
   list[left]=tmplist[left];
   //fill in the blank
}


void merge_sort(int list[], int left, int right)
{ 
   int mid;
   if(left<right){
      mid = (left+right)/2;     /* 리스트의 균등 분할 */
      merge_sort(list, left, mid);    /* 부분 리스트 정렬 */
      merge_sort(list, mid+1, right); /* 부분 리스트 정렬 */
   merge(list, left, mid, right);    /* 합병 */
   }
}

void main()
{ 
   FILE *f;
   int i;
   int list1[MAX_SIZE];
   f= fopen("input1.txt","r");
   fscanf(f,"%d %d %d %d %d %d %d %d %d %d",
    &list1[0],&list1[1],&list1[2],&list1[3],&list1[4],
    &list1[5],&list1[6],&list1[7],&list1[8],&list1[9]);
   
   //합병정렬
   merge_sort(list1, 0, MAX_SIZE-1); /* 선택정렬 호출 */
   printf("merge_sort: \n");
   for(i=0; i<MAX_SIZE; i++)
   printf("%d \t",list1[i]); //printf("%d \t", );
   fclose(f);
} 

