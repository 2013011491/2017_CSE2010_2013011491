#include<stdio.h>
#define MAX_ELEMENT 10

typedef struct {
int key;
} element;
typedef struct {
element heap[MAX_ELEMENT];
int heap_size;
} HeapType;

void init();
void print_heap();
void insert_max_heap();
element delete_max_heap();

void main()
{
element e1 = {10}, e2 = {5}, e3 = {30};
element d1;
HeapType heap;
init(&heap);

insert_max_heap(&heap, e1);
insert_max_heap(&heap, e2);
insert_max_heap(&heap, e3);
print_heap(&heap);

d1 = delete_max_heap(&heap);
printf("\n<del. %d>\n",d1.key);
print_heap(&heap);
}

void init(HeapType*h)
{
h->heap_size=0;
}

void print_heap(HeapType*h)
{
int i;
int level=1;
printf("\n====================");
for(i=1;i<=h->heap_size;i++){
if(i==level){
printf("\n");
level*=2;
}
printf("\t%d",h->heap[i].key);
}
printf("\n===================");
}

void insert_max_heap(HeapType*h, element item)
{
int i,tmp;
h->heap_size +=1;
i=h->heap_size;
h->heap[i] = item;
while(i!=1 && h->heap[i].key > h->heap[i/2].key){
tmp=h->heap[i].key;
h->heap[i].key=h->heap[i/2].key;
h->heap[i/2].key=tmp;
i/=2;
}
}

element delete_max_heap(HeapType*h)
{
int parent, child,largest;
element item, temp;
item = h->heap[1];
parent=1;
child=2;
h->heap[1].key=h->heap[h->heap_size].key;
h->heap_size-=1;
while(child<h->heap_size){
if(child<h->heap_size && h->heap[child+1].key > h->heap[child].key)
largest=child+1;
else
largest=child;
if(h->heap[largest/2].key>h->heap[largest].key)
break;
temp=h->heap[largest/2];
h->heap[largest/2]=h->heap[largest];
h->heap[largest]=temp;
child=largest*2;}
return item;
}
