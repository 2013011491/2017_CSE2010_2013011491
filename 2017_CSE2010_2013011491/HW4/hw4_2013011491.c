//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef int element;
typedef struct _TreeNode
{
 element data;
 struct _TreeNode * left;
 struct _TreeNode * right;
} TreeNode;

TreeNode * createTreeNode(void)
{
TreeNode*tmp = (TreeNode*)malloc(sizeof(TreeNode));//노드 생성
tmp->left = NULL;
tmp->right = NULL;//노드의 좌우 포인터 초기화
return tmp;
}

void setData(TreeNode * node, element data)
{
node->data = data;//노드에 데이터 저장
}

element getData(TreeNode * node)
{
return node->data;//노드에 있는 데이터 출력
}

void makeLeftSubTree(TreeNode * main, TreeNode * sub)
{
if(main->left!=NULL)
exit(1);//부모노드의 왼쪽노드가 이미 있는 경우에  함수 종료
else
main->left=sub;//부모노드에 왼쪽 subtree  추가
}

void makeRightSubTree(TreeNode * main, TreeNode * sub)
{
if(main->right!=NULL)
exit(1);//부모노드의 오른쪽노드가 이미 있는 경우에 함수 종료
else
main->right=sub;//부모노드에 오른쪽 subtree 추가
}

TreeNode * getLeftSubTree(TreeNode * node)
{
return node->left;//노드의 왼쪽 subtree 출력
}

TreeNode * getRightSubTree(TreeNode * node)
{
return node->right;//노드의 오른쪽 subtree 출력
}
void printInorder(TreeNode *root){
if(root==NULL)//중위 순휘  재귀 탈출 조건
return;
printInorder(getLeftSubTree(root));//왼쪽 subtree로 가서 중위 순회
printf("%d ",getData(root));//왼쪽 subtree 출력 후에 node의 데이터 출력
printInorder(getRightSubTree(root));//오른쪽 subtree로 가서 중위 순회
}
void printPreorder(TreeNode *root){
 if(root==NULL)//전위 순회 재귀 탈출 조건
 return;
 printf("%d ",getData(root));//전위순회이므로 node의 데이터 먼저 출력
 printPreorder(getLeftSubTree(root));//node의 데이터 출력 후 왼쪽 subtree 전위 순회
 printPreorder(getRightSubTree(root));//왼쪽 subtree 순회후 오른쪽 subtree로 가서 전위 순회
}
void printPostorder(TreeNode *root){
 if(root==NULL)//후위 순회 재귀 탈출 조건
 return;
 printPostorder(getLeftSubTree(root));//먼저 왼쪽 subtree 순회
 printPostorder(getRightSubTree(root));//왼쪽 subtree 순회 후 오른쪽 subtree 순회
 printf("%d ",getData(root)); //후위 순회 이므로 node의 데이터 나중 출력

}
int main(int argc,char*argv[]){
 FILE *input;
 input = fopen(argv[1], "r");//input파일 오픈
 char command;//명령어 저장 변수 생성
 
 TreeNode*t1=createTreeNode();
 TreeNode*t2=createTreeNode();
 TreeNode*t3=createTreeNode();
 TreeNode*t4=createTreeNode();
 TreeNode*t5=createTreeNode();
 TreeNode*t6=createTreeNode();
 TreeNode*t7=createTreeNode();
 TreeNode*t8=createTreeNode();
 TreeNode*t9=createTreeNode();
 TreeNode*t10=createTreeNode();//노드 생성
 setData(t1,54);
 setData(t2,27);
 setData(t3,89);
 setData(t4,13);
 setData(t5,44);
 setData(t6,71);
 setData(t7,92);
 setData(t8,1);
 setData(t9,37);
 setData(t10,64);//노드들에 데이터 설정
 makeLeftSubTree(t1,t2);
 makeRightSubTree(t1,t3);
 makeLeftSubTree(t2,t4);
 makeRightSubTree(t2,t5);
 makeLeftSubTree(t4,t8);
 makeLeftSubTree(t5,t9);
 makeLeftSubTree(t3,t6);
 makeRightSubTree(t3,t7);
 makeLeftSubTree(t6,t10);//노드들 이진트리로 만들기
 
 while(1){
 command = fgetc(input);
 if(feof(input)) break;//입력 파일 다 읽을 시 반복문 탈출
  switch(command) {
   case 'i': printf("Inorder:   "); printInorder(t1); printf("\n");
     break;//command i입력받을 경우 중위순회
   case 'r': printf("Preorder:  "); printPreorder(t1); printf("\n");
     break;//command r입력받을 경우 전위순회
   case 'o': printf("Postorder: "); printPostorder(t1); printf("\n");
    break;//command o입력받을 경우 후위순회
   default:
    break;
  }}


 fclose(input);//파일 종료
    return 0;
}
