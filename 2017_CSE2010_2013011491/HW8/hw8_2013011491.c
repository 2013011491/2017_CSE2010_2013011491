#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_STACK_SIZE 20
typedef int element;
typedef struct {
 element stack[MAX_STACK_SIZE];
 int top;
}StackType;
char tmp[MAX_STACK_SIZE] = "";

// 스택 초기화 함수
void init(StackType *s) {
  s->top = -1;
 }
// 공백 상태 검출 함수
int is_empty(StackType *s) {
  return (s->top == -1);
 }
// 포화 상태 검출 함수
int is_full(StackType *s) {
  return (s->top == (MAX_STACK_SIZE-1));
 }
// 삽입함수
void push(StackType *s, element item) {
  if ( is_full(s) ) {
   fprintf(stderr," \n");
   return;
  }else s->stack[++(s->top)] = item;
 
 }
// 삭제함수
element pop(StackType *s) {
 if ( is_empty(s) ) {
  fprintf(stderr, "스택 공백 에러\n");
  exit(1);
  } else return s->stack[(s->top)--];
 }
// 피크함수
element peek(StackType *s) {
 if ( is_empty(s) ) {
  fprintf(stderr, "스택 공백 에러\n");
  exit(1);
  } else return s->stack[s->top];
 }

// 연산자의 우선순위를 반환한다.
int prec(char op) {
 switch(op){
  case '(': case ')': return 0;
  case '+': case '-': return 1;
  case '*': case '/': return 2;
  }
  return -1;
}

//infix to postfix
void infix_to_postfix(char infix[],char postfix[])
{
    StackType s;
    char x,token;
    int i,j;    //i-index of infix, j-index of postfix
    init(&s);
    j=0;
 
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
            postfix[j++]=token;
        else
            if(token=='(')
               push(&s,'(');
        else
            if(token==')')
                while((x=pop(&s))!='(')
                      postfix[j++]=x;
                else
                {
                    while(!is_empty(&s) && (prec(token) <= prec(peek(&s))))
                    {
                        x=pop(&s);
                        postfix[j++]=x;
                    }
                    push(&s,token);
                }
    }
 
    while(!is_empty(&s))
    {
        x=pop(&s);
        postfix[j++]=x;
    }
 
    postfix[j]='\0';
 printf("\npostfix_to_infix expression: %s", postfix);
}

char* postfix_to_infix(char expression[])
{
    StackType s;//스택 생성
    char token,infix[20];
    int i,op1,op2;
 int j=0;   
    init(&s);//스택 초기화
   
    for(i=0;expression[i]!='\0';i++)//후위 표기로 되있는 연산식 스캔
    {
        token=expression[i];
        if(isalnum(token))//읽은 문자가 숫자일 경우
            push(&s,token);
        else{//읽은 문자가 연산자일 경우
         if(j==0){//첫 연산자일 경우
   op2=pop(&s);
         op1=pop(&s);
         infix[j++]='(';
         infix[j++]=(char)op1;
         infix[j++]=token;
         infix[j++]=(char)op2;
         infix[j++]=')';
         infix[j++]='\0';
        }else{//처음 연산이 아닐 경우
         op2=pop(&s);
   memmove(infix+1,infix,sizeof(infix)-1);
         infix[j++]=token;
         infix[j++]=(char)op2;
         infix[j++]=')';
         infix[j++]='\0';
  }
  }}
 printf("\ninfix_to_postfix expression:\n");
 printf("%s",infix);//출력
 /* fill in the blank */


 return expression;
}

int postfixEval(char exp[])
{
    StackType s;//스택 생성
    char token;
    int i,op1,op2;   
    init(&s);//스택 초기화
   
    for(i=0;exp[i]!='\0';i++){//연산식 스캔
     token=exp[i];
        if(isalnum(token))//읽은 문자가 숫자일 경우
            push(&s,token-'0');
        else{//읽은 문자가 연산자일 경우
         op2=pop(&s);
         op1=pop(&s);
         
         switch(token)//연산자의 종류에 따른 연산값 
         {
   case '+' :
   push(&s,op1+op2);
   break;
   
         case '-' :
   push(&s,op1-op2);
   break;
   case '*' :
            push(&s,op1*op2);
   break;
         case '/' :
            push(&s,op1/op2);
   break;  
   }
  }
 }
 return pop(&s);
}

  /* fill in the blank */

 

 

int main() {

 FILE *f;
 char postfix[30];
 char* tmp = (char*)malloc(sizeof(char)*20);
 
 f=fopen("input1.txt","r");
 fscanf(f,"%s", tmp);
 infix_to_postfix(tmp,postfix);
 printf("\neval: %d \n", postfixEval(postfix));

 f=fopen("./input2.txt","r");
 fscanf(f,"%s", tmp);
 postfix_to_infix(tmp);                  
 printf("eval: %d \n", postfixEval(tmp));
 
 
 return 0;
} 

