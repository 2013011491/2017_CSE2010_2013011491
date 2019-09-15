#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

struct avl_node   {
    struct avl_node *left_child, *right_child;  /* Subtrees. */
    int data;                   /* Pointer to data. */
};

struct avl_node *root;

// 오른쪽 회전 함수
struct avl_node* rotate_right(struct avl_node *parent)
{
 /*fill in the blank*/
 struct avl_node *child = parent->left_child;//child 노드를 parent노드의 왼쪽 자식노드로 설정
 parent->left_child = child->right_child;//parent 노드의 왼쪽 자식노드를 child노드의 오른쪽 자식노드로 설정
 child->right_child = parent;//child 노드의 오른쪽 노드를 parent 노드로 지정
 return child;
}

// 왼쪽 회전 함수
struct avl_node* rotate_left(struct avl_node *parent)
{
 struct avl_node *child = parent->right_child;
 parent->right_child = child->left_child;
 child->left_child = parent;
 return child;
}
 
// 오른쪽-왼쪽 회전 함수
struct avl_node* rotate_right_left(struct avl_node *parent)
{
 /*fill in the blank*/
 struct avl_node *child = parent->right_child;//child 노드를 parent 노드의 오른쪽 서브노드로 설정
 parent->right_child=rotate_right(child);//child노드를 오른쪽 회전시킨뒤 parent노드의 오른쪽 서브트리로 설정
 child=rotate_left(parent);//parent를 왼쪽회전 시킨뒤 child 노드로 설정
 return child;
}
 
// 왼쪽-오른쪽 회전 함수
struct avl_node* rotate_left_right(struct avl_node *parent)
{
 /*fill in the blank*/
 struct avl_node *child = parent->left_child;//child 노드를 parent 노드의 왼쪽 서브노드로 설정
 parent->left_child=rotate_left(child);//child노드를 왼쪽 회전시킨뒤 parent노드의 왼쪽 서브트리로 설정
 child=rotate_right(parent);//parent를 오른회전 시킨뒤 child 노드로 설정
 return child;
}

// 트리의 높이를 반환
int get_height(struct avl_node *node)
{
 int height=0;
 if( node != NULL )
  height = 1 + max(get_height(node->left_child), get_height(node->right_child));
 return height;
}

// 노드의 균형인수를 반환
int get_height_diff(struct avl_node *node)
{
 if( node == NULL ) return 0;
 return get_height(node->left_child) - get_height(node->right_child);
}

// 트리를 균형트리로 만든다
struct avl_node* rebalance(struct avl_node **node)
{
 int height_diff = get_height_diff(*node);
 if( height_diff > 1 ){
  if( get_height_diff((*node)->left_child) > 0 )
   *node = rotate_right(*node);//왼쪽 subtree의 높이가 더 크고 그 왼쪽 subtree의 높이또한 왼쪽subtree가 클경우 
   /*fill in the blank: rotate_right*/
  else
   *node = rotate_left_right(*node);//왼쪽 subtree의 높이가 더 크고 그 왼쪽 subtree의 높이가 오른쪽subtree가 클경우
   /*fill in the blank: rotate_left_right*/
 }
 else if ( height_diff < -1 ){
  if( get_height_diff((*node)->right_child) < 0 )
   *node = rotate_left(*node);
  else
   *node = rotate_right_left(*node);//오른쪽 subtree의 높이가 더 크고 그 왼쪽 subtree의 높이가 왼쪽subtree가 클경우
   /*fill in the blank: rotate_right_left*/
 }
 return *node;
}

// AVL 트리의 삽입 연산
struct avl_node * avl_add(struct avl_node **root, int new_key)
{
 if( *root == NULL ){
  *root = (struct avl_node *)malloc(sizeof(struct avl_node));
  if( *root == NULL ){
   exit(1);
  }
  (*root)->data = new_key;
  (*root)->left_child = (*root)->right_child = NULL;
 }
 else if( new_key < (*root)->data ){
  (*root)->left_child=avl_add(&((*root)->left_child), new_key);//avl트리가 이미 형성돼 있고, key의 값이 노드의 데이터보다 작을 경우 왼쪽 subtree로 이동해 다시 avl_add
  *root = rebalance(root);//avl트리 재균형
  /* fill in the blank */
 }
 else if( new_key > (*root)->data ){
  (*root)->right_child=avl_add(&((*root)->right_child), new_key);
  *root = rebalance(root);
 }
 else{
  printf("중복된 키\n");
  exit(1);
 }
 return *root;
}
//출력함수 구현되어있음
void display(struct avl_node *node)
{
 if (node != NULL) {
  printf("(");
  display(node->left_child);
  printf("%d", node->data);
  display(node->right_child);
  printf(")");
 }
}
// AVL 트리의 탐색함수
struct avl_node *avl_search(struct avl_node *node, int key)
{
 if( node == NULL ) return NULL;
 printf("%d ", node->data);
 if( key == node->data ) return node;
 else if( key < node->data )
     return avl_search(node->left_child, key);
 else
  return avl_search(node->right_child, key);
}

void main()
{
 char command;
 int key;
 FILE *input;
 root = NULL;
 input = fopen("input.txt", "r");

 while (1) {
  command = fgetc(input);
  if (feof(input)) break;
  switch (command) {
  case 'i':
   fscanf(input, "%d", &key);
   avl_add(&root, key);
   break;
  default:
   break;
  }
 }
 
 display(root);

} 

