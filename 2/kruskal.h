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

typedef struct o
{
    char* nume;
    int id;
    struct o* next;
} Oras;

void swap(Muchie *a,Muchie *b);
int partition(Muchie *arr, int low, int high);
void quickSort(Muchie *arr, int low, int high);
Graph* createGraph(int n,int m);
void Kruskal(Graph *g);
Oras *append_node(Oras *head, char *s);
Oras* searchOras(Oras *head, char *x);

#endif