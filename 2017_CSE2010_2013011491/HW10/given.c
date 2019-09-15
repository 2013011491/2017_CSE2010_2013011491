#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KEY_SIZE	20	// 탐색키의 최대길이  
#define TABLE_SIZE	7	// 해싱 테이블의 크기 
#define equal(e1,e2) (!strcmp(e1.key,e2.key))

int transform(char*);

typedef struct				
{   
    char key[KEY_SIZE];	
} element;

struct list
{   
    element item;
    struct list *link;
};
struct list *hash_table[TABLE_SIZE];

///////숙제로 구현할 코드/////////////
int hash_function(char *key)
{
	int tmp[20];//2진수 임시저장 배열 
	int bkey[20];//변환된 2진수 저장 배열 
	int i,j=0;
	int l;//변환된 2진수 비트수 저장 
	int tkey = transform(key)*transform(key);
	for(i=0; tkey>0; i++){//변환된 2진수 역순서로 저장 
		tmp[i]=tkey%2;
		tkey/=2;
	}
	l=i-1;
	for(i;i>=1;i--){//변한된 2진수 저장 
		bkey[j]=tmp[i-1];
		printf("%d",bkey[j]);
		j++; 
	}
	printf("    key : %d %d %d\n",bkey[l/2],bkey[l/2+1],bkey[l/2+2]);//주소값 2진수 출력 
	
	return (bkey[l/2]*4)+(bkey[l/2+1]*2)+(bkey[l/2+2]);//주소 값 반환 
 //fill in the blank

}

void hash_chain_find(element item, struct list *ht[])
{
 //fill in the blank
 struct list*node;
int hash_value = hash_function(item.key);//주소값 생성 
for(node=ht[hash_value]; node; node=node->link){//찾고자 하는 키와, 주소값에 있는 키 비교 
	if(equal(node->item,item)){//찾은경우 
	printf("키를 찾았음(item.key: %s)\n", item.key);
	return;
	}
	}
	printf("키를 찾지못했음(item.key: %s)\n", item.key);//찾지 못한 경우 
}
////숙제로 구현할 코드:END//////////// 

////////실습시간에 다룬 코드(완성된 상태)//////////
void hash_chain_print(struct list *ht[])
{
   struct list *node;
   int i;
   for(i=0;i<TABLE_SIZE;i++){
      printf("[%d] ->", i);
      for(node=ht[i]; node; node=node->link){  
	     printf("%s->", node->item.key);
      }
      printf("\n");
   }
}

// 문자로 된 탐색키를 숫자로 변환
int transform(char *key)
{
	int number=0;
	// 간단한 덧셈 방식 사용 자연수 생성
	while(*key) number += *(key++);
	return number;
}

void hash_chain_add(element item, struct list *ht[])
{
   int hash_value = hash_function(item.key);
   struct list *ptr; 
   struct list *node_before=NULL, *node = ht[hash_value];
   for(; node; node_before=node, node=node->link){  
	  if(equal(node->item, item)){ 
                printf("input err\n");
                return;
      }
   }

ptr = (struct list *)malloc(sizeof(struct list));
ptr->item = item;
ptr->link = NULL;

if(node_before) node_before->link = ptr;
else ht[hash_value]=ptr;
}
////////실습시간에 다룬 코드(완성된 상태): END//////////

void main()
{

	FILE* f;
	element tmp;
	char input[KEY_SIZE]=" ";
	f=fopen("input.txt","r");
	while(fscanf(f, "%s", &input) != EOF){
		strcpy(tmp.key, input);
		hash_chain_add(tmp, hash_table);
	}
	hash_chain_print(hash_table);
	
	strcpy(tmp.key, "x");
	hash_chain_find(tmp, hash_table);
	strcpy(tmp.key, "c");
	hash_chain_find(tmp, hash_table);
}
