//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
 element queue[MAX_QUEUE_SIZE ];
 int front, rear;
} QueueType;

void init(QueueType *q);
void error(char *message);
int is_empty(QueueType *q);
int is_full (QueueType *q);
void enqueue( QueueType *q, element item );
element dequeue(QueueType *q);
element peek(QueueType *q);

int main(int argc, char *argv[])
{
 char command;//주어진 커맨드 저장할 변수
 int key;//삽입할 데이터 저장 변수
 
 FILE*input=fopen(argv[1],"r");//input파일 열기
 QueueType q;//큐 생성
 
 init(&q);//큐 초기화
 printf("init front =0, rear=0\n");//큐 초기화 상황 출력
 while(1){
 command = fgetc(input);
 if(feof(input)) break;
 switch(command){
  case 'e' :
   fscanf(input,"%d",&key);
   enqueue(&q,key);
   break;
   /* 파일로부터 e를 입력받을경우 enqueue함수 실행*/
  case 'd' :
   key=dequeue(&q);
   break;
   /* 파일로부터 d를 입력받을경우 dequeue함수 실행*/
  case 'p' :
   key=peek(&q);
   break;
   /* 팡일로부터 p를 입력받을경우 peek함수 실행*/
 }
 }
 fclose(input);//파일 종료
 /* fill in the blank*/
    return 0;
}

void error(char *message)
{
        fprintf(stderr,"%s\n",message);
        exit(1);
}


void init(QueueType *q)
{
  q->front =0;
  q->rear = 0;
}

int is_empty(QueueType *q)
{
 if(q->front==q->rear){
 return 1;
}else{
 return 0;
}/*큐의 front와 rear가 같은 곳을 지목할 경우 빈큐이므로 1반환, 아닐경우 0반환*/ 
/* fill in the blank*/
}

int is_full (QueueType *q)
{
 if((q->front) - (q->rear) == (-1)*(MAX_QUEUE_SIZE-1) || (q->front) - (q->rear) == 1){
  return 1;
 }else
     return 0;
/*큐의 front가 rear보다 한칸 뒤에 있을 경우 full 큐,
원형 큐이므로 rear가 배열 마지막을 가리킬경우 rear와 front의 차이는 -(최대큐사이즈-1)이므로 이때도 full queue*/
/* fill in the blank*/
}

void enqueue( QueueType *q, element item )
{
 if(is_full(q)){
  error("Queue is full\n");
 }//큐가 full일 경우 에러메세지
 else if(q->rear != MAX_QUEUE_SIZE-1)
 {
  q->rear++;
  }//rear가 가리키는 곳이 배열의 마지막부분이 아닐경우 그대로 rear 증가
 else{
 q->rear =0;
  }//rear가 가리키는 곳이 배열의 마지막부분일 경우 가리키는 곳 0으로 설정
 q->queue[q->rear]=item;//큐에 저장
 printf("enqueue() = %d\n",item);
 printf("front = %d, rear = %d \n",q->front, q->rear);//input상황 출력
/* fill in the blank*/
}

element dequeue(QueueType *q){
 if(is_empty(q)){
  error("Queue is empty\n");//큐가 비었을 경우 에러메세지 출력
 }else if(q->front != MAX_QUEUE_SIZE-1){
  q->front++;//front가 가리키는 곳이 배열의 끝이 아닐경우 그대로 front 증가
 }else{
  q->front=0;//front가 가리키는 곳이 배열의 끝일 경우 front 0으로 설정
 }
 printf("dequeue() = %d\n",q->queue[q->front]);
 printf("front = %d, rear = %d\n",q->front,q->rear);//삭제 상황 출력
 return q->queue[q->front];
/* fill in the blank*/
}

element peek(QueueType *q)
{
 if(is_empty){
  error("Queue is empty\n");//큐가 비었을 경우 에러메세지 출력
 }else{
  printf("%d\n",q->queue[q->front+1]);//맨앞에저장된 요소 출력
  return q->queue[q->front+1];
 }
/* fill in the blank*/
} 

