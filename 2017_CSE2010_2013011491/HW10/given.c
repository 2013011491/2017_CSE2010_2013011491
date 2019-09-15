#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KEY_SIZE	20	// Ž��Ű�� �ִ����  
#define TABLE_SIZE	7	// �ؽ� ���̺��� ũ�� 
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

///////������ ������ �ڵ�/////////////
int hash_function(char *key)
{
	int tmp[20];//2���� �ӽ����� �迭 
	int bkey[20];//��ȯ�� 2���� ���� �迭 
	int i,j=0;
	int l;//��ȯ�� 2���� ��Ʈ�� ���� 
	int tkey = transform(key)*transform(key);
	for(i=0; tkey>0; i++){//��ȯ�� 2���� �������� ���� 
		tmp[i]=tkey%2;
		tkey/=2;
	}
	l=i-1;
	for(i;i>=1;i--){//���ѵ� 2���� ���� 
		bkey[j]=tmp[i-1];
		printf("%d",bkey[j]);
		j++; 
	}
	printf("    key : %d %d %d\n",bkey[l/2],bkey[l/2+1],bkey[l/2+2]);//�ּҰ� 2���� ��� 
	
	return (bkey[l/2]*4)+(bkey[l/2+1]*2)+(bkey[l/2+2]);//�ּ� �� ��ȯ 
 //fill in the blank

}

void hash_chain_find(element item, struct list *ht[])
{
 //fill in the blank
 struct list*node;
int hash_value = hash_function(item.key);//�ּҰ� ���� 
for(node=ht[hash_value]; node; node=node->link){//ã���� �ϴ� Ű��, �ּҰ��� �ִ� Ű �� 
	if(equal(node->item,item)){//ã����� 
	printf("Ű�� ã����(item.key: %s)\n", item.key);
	return;
	}
	}
	printf("Ű�� ã��������(item.key: %s)\n", item.key);//ã�� ���� ��� 
}
////������ ������ �ڵ�:END//////////// 

////////�ǽ��ð��� �ٷ� �ڵ�(�ϼ��� ����)//////////
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

// ���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number=0;
	// ������ ���� ��� ��� �ڿ��� ����
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
////////�ǽ��ð��� �ٷ� �ڵ�(�ϼ��� ����): END//////////

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
