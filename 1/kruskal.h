#ifndef KRUSKAL_H
#define KRUSKAL_H

typedef struct 
{
    int v1,v2,cost;
}Muchie;

typedef struct 
{
    int E,V;
    Muchie *e;
}Graph;

void swap(Muchie *a,Muchie *b);
int partition(Muchie *arr, int low, int high);
void quickSort(Muchie *arr, int low, int high);
Graph* createGraph(int n,int m);
void Kruskal(Graph *g);

#endif