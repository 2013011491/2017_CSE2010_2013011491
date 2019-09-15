//for visual stduio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>


typedef struct TreeNode {
 int key;
 struct TreeNode *left, *right;
} TreeNode;

void display(TreeNode *p)
{
 if (p != NULL) {
  printf("(");
  display(p->left);
  printf("%d", p->key);
  display(p->right);
  printf(")");
 }
}

/*
We will implement binary search tree ADT with the three main functions
using iteration: insert, delete, and search.
*/
TreeNode *search(TreeNode *node, int key)
{
while(node!=NULL){//탐색 끝날때 까지 반복
if(key==node->key)
return node;//key값 search 성공시 해당 node 반환 ,반복문 탈출
else if(key<node->key)
node=node->left;//key가 탐색 중인 node의 key보다 작을경우 왼쪽 subtree를 탐색 노드로 설정
else
node=node->right;}//key가 탐색 중인 node의 key보다 클경우 오른쪽  subtree를 탐색 노드로 설정
return NULL;//탐색 실패시 NULL 반환
}


void insert_node(TreeNode **root, int key)
{
TreeNode*p, *q;
TreeNode*n;
p=*root;
q=NULL;
//
while(p!=NULL){
if(key==p->key)
return;//삽입하고자 하는 key 가 이미 있는 경우 반환
q=p;
if(key<p->key)
p=p->left;
else
p=p->right;}//삽입할 위치의 부모노드  탐색
//
n=(TreeNode*)malloc(sizeof(TreeNode));
n->key=key;
n->left=NULL;
n->right=NULL;//삽입할 노드 생성과 데이터 설정
if(q==NULL)
*root=n;//트리가 비어 있을 경우 최초 트리노드 설정
else if(n->key < q->key)
q->left=n;//트리가 이미 있는 경우,key가 부모노드의 key보다 작을경우 부모느드의 왼쪽 subtree로 설정
else
q->right=n;//트리가 이미 있는 경우,key가 부모노드의 key보다 클경우 부모느드의 오른쪽 subtree로 설정
}

void delete_node(TreeNode *node, int key)
{
 TreeNode *d, *pa, *min, *pmin;//삭제될 노드, 삭제될 노드의 부모노드, 삭제할 노드의 오른쪽subtree의 최소 노드, 최소노드의 부모노드
 d=node;
 pa=d;
 if(search(d,key)==NULL){
  printf("key is not in the tree: %d\n",key);
  exit(1);
 }//삭제할 노드가 트리에 없는 경우 함수 탈출
 while(key!=d->key){
 pa=d;
 if(key<d->key)
 d=d->left;
 else
 d=d->right;}//삭제할 노드 탐색, 삭제할 노드의 부모노드 설정
 if(d->left==NULL && d->right==NULL){//삭제할 노드의 자식노드가 하나도 없는 경우
  if(pa->right==d) 
  pa->right=NULL;//삭제할 노드가 부모노드의 오른쪽 자식노드일 경우에 NULL설정
  else
  pa->left=NULL;//삭제할 노드가 부모노드의 왼쪽 자식노드일 경우에 NULL설정
  free(d);//삭제할  노드 동적할당 해제
 }else if(d->left!=NULL && d->right==NULL){//삭제할 노드의 왼쪽 자식노드만 있는 경우
  if(pa->right==d)
  pa->right=d->left;//삭제할 노드가 부모노드의 오른쪽 자식노드일 경우에, 부모노드의 오른쪽노드를 삭제할 노드의 왼쪽노드로 연결
  else
  pa->left=d->left;//삭제할 노드가 부모노드의 왼쪽 자식노드일 경우에, 부모노드의 왼쪽 노드를 삭제할 노드의 왼쪽노드로 연결
  free(d);//삭제할  노드 동적할당 해제
 }else if(d->left==NULL && d->right!=NULL){//삭제할 노드의 오른쪽 자식노드만 있는 경우
  if(pa->right==d)
  pa->right=d->right;//삭제할 노드가 부모노드의 오른쪽 자식노드일 경우에, 부모노드의 오른쪽노드를 삭제할 노드의 오른쪽노드로 연결
  else
  pa->left=d->right;//삭제할 노드가 부모노드의 왼쪽 자식노드일 경우에, 부모노드의 왼쪽 노드를 삭제할 노드의 오른쪽 노드로 연결
  free(d);
 }else if(d->left!=NULL && d->right!=NULL){//삭제할 노드의 자식노드가 모두 있을 경우
  pmin=d;
  min=d->right;
  while(min->left!=NULL){//반복문을 통해  삭제할 노드의 오른쪽 노드에서 최솟값을 지닌 노드 탐색, 그 노드의 부모 노드 설정.
   pmin=min;
   min=min->left;
  }
  d->key=min->key;//삭제할 노드의 데이터를 최소노드의 데이터로 수정
  if(min->right!=NULL){//남아있는 최소노드의 오른쪽 자식 노드가 있는경우, 다시 그 부모노드와 연결.
  if(pmin==d)//최소노드가 삭제할 노드 오른쪽노드일경우
  pmin->right=min->right;
  else
  pmin->left=min->right;
  }
  else{//최소노드가 단일 노드일 경우, 그 부모노드의 subtee NULL설정
   if(pmin==d)//최소노드가 삭제할 노드 오른쪽노드일 경우
  pmin->right=NULL;
  else
  pmin->left=NULL;
  free(min);}}//최소노드 동적할당 해제
  
 }
//If the node to be deleted has both children, it is replaced with the smallest node in the right subtree.

 

void main(int argc, char *argv[])
{
 char command;
 int key;
 FILE *input;
 TreeNode *root = NULL;

 if (argc == 1) input = fopen("input.txt", "r");
 else input = fopen(argv[1], "r");
 while (1) {
  command = fgetc(input);
  if (feof(input)) break;
  switch (command) {
  case 'i':
   fscanf(input, "%d", &key);
   insert_node(&root, key);
   break;
  case 'd':
   fscanf(input, "%d", &key);
   delete_node(root, key);
   break;
  case 's':
   fscanf(input, "%d", &key);
   if (search(root, key) != NULL)printf("key is in the tree: %d\n", key);
   else printf("key is not in the tree: %d\n", key);
   break;
  case 'p':
   display(root);
            printf("\n");
   break;
  default:
   break;
  }
 }
 fclose(input);
} 

