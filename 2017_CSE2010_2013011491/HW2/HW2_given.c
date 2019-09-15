//for visual studio 2013(fscanf_s problem)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef struct ElementType{
 int key;
 float value;
}ElementType;
struct Node{
        ElementType element;
        Position next;
};

List MakeEmpty(List L);
int IsEmpty(List L);
int isLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
Position Find(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
void PrintList(List L);

int main(int argc, char *argv[]) {
        char command;
        int key1, key2;
        FILE *input;
 ElementType in;
        Position header = NULL;
        Position tmp = NULL;
        if(argc == 1)
                input = fopen("input.txt", "r");
        else
                input = fopen(argv[1], "r");
        header = MakeEmpty(header);
        while(1) {
                command = fgetc(input);
                if(feof(input)) break;
                switch(command) {
                case 'i':
                        fscanf(input, "%d %d", &key1, &key2);
   in.key = key1;
   //duplication check
   tmp = Find(in, header);
                        if(tmp != NULL) {
                                printf("There already is an element with key %d. Insertion failed\n", key1);
                                break;
                        }
            /*
   HINT:find at key2(after the node key y)


   HINT:insert at key1(a new node key x)
   */
            if(key2==-1){
        tmp = header;
   }//key2가 -1일때 삽입될 위치  첫번째 노드로 설정
   else{
   in.key = key2;
   tmp = Find(in, header);
   in.key = key1;}//삽입될 위치 설정
                        Insert(in, header, tmp);
                        break;
                case 'd':
                        fscanf(input, "%d", &key1);
   in.key = key1;
                        Delete(in, header);
                        break;
                case 'f':
                        fscanf(input, "%d", &key1);
   in.key = key1;
                        tmp = FindPrevious(in, header);
                        if(isLast(tmp, header))
                                printf("Could not find %d in the list\n", key1);
                        else {
    if(tmp->element.key>0)
     printf("Key of the previous node of %d is %d.\n", key1, tmp->element.key);
                                else
                                        printf("Key of the previous node of %d is header.\n", key1);
                        }
                        break;
                case 'p':
                        PrintList(header);
                        break;
                default:
                        ;
                }
        }
  system("PAUSE");
 DeleteList(header);
        fclose(input);
        return 0;
}

//create header node
List MakeEmpty(List L) {
        L = (List)malloc(sizeof(struct Node));
        L->element.key = -30;
 L->element.value = -30.0;
        L->next = NULL;
        return L;
}
//check the list is empty when L == header(except error case)
int isEmpty(List L) {
        return L->next == NULL;
}

//check the position P is at the last of the list L
int isLast(Position P, List L) {
        Position cur = L;
        while(cur->next != NULL) {
                cur = cur->next;
        }
        return P == cur;
}

//return last position when X is not in L. else, return previous position of element X exist
Position FindPrevious(ElementType X, List L) {
        Position P = NULL;
        P = L;
 while(P->next != NULL && P->next->element.key !=X.key) {
                P = P->next;
        }
        return P;
}

//delete whole list
void DeleteList(List L) {
 Position P = NULL, Tmp = NULL;
 P = L->next; /* Header assumed */
 L->next = NULL;
 while (P != NULL)
 {
  Tmp = P->next;
  free(P);
  P = Tmp;
 }
}
//negative will be header
Position Find(ElementType X, List L) {
        Position P = NULL;
  if(X.key<0) return L;
  P = FindPrevious(X, L);
        return P->next;
}

//////////////HW2/////////////////
void Insert(ElementType X, List L, Position P) {
        Position Tmp = NULL;
        //input should be positive integer
 if(X.key<0) {
                printf("Please use positive input. %d cannot be inserted\n", X.key);
                return;
        }
 
 /* hw value값 설정*/
 X.value = 3.14;//ElementType 구조체속 value값 설정
 
        Tmp = (Position)malloc(sizeof(struct Node));
 Tmp->element = X;
        if(P==NULL) {
                printf("Insertion(%d) Failed : cannot find the location to be inserted\n", X.key);
                free(Tmp);
                return;
        }
        Tmp->next = P->next;
        P->next = Tmp;
}


void PrintList(List L) {
        PtrToNode tmp = NULL;
        tmp = L->next;
        if(tmp==NULL) {
                printf("list is empty!\n");
                return;
        }
        while(tmp!=NULL) {
                /*
  fill in the blank
  */
  printf("key : %d value : %.3f         ",tmp->element.key,tmp->element.value);//리스트배열에 저장되 있는 구조체속 값 출력
  tmp = tmp->next;//다음읽을 리스트배열로 넘김
        }
        printf("\n");
}

void Delete(ElementType X, List L) {
        Position P = NULL, Tmp = NULL;

  P = FindPrevious(X, L);
        if (!isLast(P, L)) {
          /*
 fill in the blank
 */
         Tmp = P->next;//삭제할 노드 설정
         P->next = Tmp->next;//삭제할 노드의 앞 노드를 뒷노드로 연결
         Tmp->next = NULL;//삭제될 노드의 연결노드 지움
         free(Tmp);//삭제
         

    
        } else {
   printf("Deletion failed : element %d is not in the list\n", X.key);
        }
}

////////////// HW2 ////////////// 

