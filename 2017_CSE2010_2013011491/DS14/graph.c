#include<stdio.h>
#define MAX_VERTICES 6

typedef struct graph
{
int node;
struct graph *link;
} list;
list *adj_list[MAX_VERTICES];

int adj_mat[MAX_VERTICES][MAX_VERTICES]={
{0,1,0,0,1,0},
{0,0,0,1,0,0},
{0,0,0,1,0,1},
{0,0,0,0,1,0},
{0,1,0,0,0,0},
{0,0,0,0,0,0}
};
int visited[MAX_VERTICES];
int sorted[MAX_VERTICES];
int top = -1;
int n=6;

void graph_dfs_mat(int v)
{
int w;
visited[v] = 1;
printf("%d",v);
for(w=0; w<n; w++){
if(!visited[w]&&adj_mat[v][w]==1)
graph_dfs_mat(w);
}
sorted[++top]=v;
}

void dfs_topsort(){
printf("\ntopSorted:");
for(int i=top; i>=0; i--){
printf("$%d",sorted[i]);
}
}

void main()
{
for(int i=0; i<n; i++)
if(visited[i] ==0){
printf("[%d]",i);
graph_dfs_mat(i);
}
dfs_topsort();
}
