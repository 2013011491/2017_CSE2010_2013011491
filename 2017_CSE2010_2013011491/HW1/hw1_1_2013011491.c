#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentT{
 char*name;
 int literature;
 int math;
 int science;
}studentT; //구조체 정의

int main(int argc,char*argv[]){
 int count;//입력받을 학생 수
 studentT arr[3];//input file로부터 읽어올 데이터 저장 배열
 studentT Sum={"Ave.",0,0,0};//구조체 데이터의 평균 계산을 위한 구조체
 FILE*fp1 = fopen(argv[1],"rt");//읽어올 파일 열기
 FILE*fp2 = fopen(argv[2],"wt");//outFILE 생성
 if(fp1==NULL||fp2==NULL){
  puts("파일오픈 실패");
  return -1;}//파일오픈 실패시 비정상종료 표시.
 printf("입력할 학생수 : ");
 fscanf(fp1,"%d",&count);//input file로부터 입력 받을 학생수 불러온뒤 count에 저장
 printf("%d\n",count);

  for(int i=0;i<count;i++){
  arr[i].name=(char*)malloc(sizeof(char)*30);//문자열을 저장 할 수있도록 메모리 동적할당
  fscanf(fp1,"%s %d %d %d",arr[i].name,&arr[i].literature,&arr[i].math,&arr[i].science);//input file로부터 구조체로 데이터 저장
  printf("%s %d %d %d\n",arr[i].name,arr[i].literature,arr[i].math,arr[i].science);//저장된 데이터 출력
  Sum.literature+=arr[i].literature;//literature점수 평균계산을 위한 합계
  Sum.math+=arr[i].math;//math점수 평균 계산을 위한 합
  Sum.science+=arr[i].science; //scienc점수 평균 계산을 위한 합
  }

 
 fputs("Name   Literature   Math   Science   Ave.\n",fp2);//output파일에 과목 입력
 for(int j=0;j<count;j++){
  fprintf(fp2, "%-5s %7d %9d %7d %9.2f\n",arr[j].name,arr[j].literature,arr[j].math,arr[j].science,(arr[j].literature+arr[j].math+arr[j].science)/(float)3);
  };//output file에 구조체 내용 입력
  fprintf(fp2, "%-5s %7.2f %9.2f %7.2f %9.2f\n",Sum.name,Sum.literature/(float)count,Sum.math/(float)count,Sum.science/(float)count,(Sum.literature+Sum.math+Sum.science)/(float)9);//output file에 평균 계산 입력
 
 fclose(fp1);//input file 닫기
 fclose(fp2);//output file 닫기
 for(int i=0;i<count;i++){
  free(arr[i].name);//동적할당 해제
 }
 return 0;
} 
