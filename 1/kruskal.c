#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

/**
 * @brief aloca spatiu pentru un graf
 * 
 * @param n numarul de varfuri
 * @param m numarul de muchii
 * @return Graph* 
 */
Graph *createGraph(int n, int m)
{
    Graph *g = malloc(sizeof(Graph));
    g->V = n;
    g->E=m;
    g->e=(Muchie*)malloc(sizeof(Muchie)*g->E);
    return g;
}

void swap(Muchie *a, Muchie *b)
{
    Muchie aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int partition(Muchie *arr, int low, int high)
{
    int j;
    Muchie pivot = arr[high];
    int i = (low - 1);
    for (j = low; j <= high - 1; j++)
        if (arr[j].cost < pivot.cost)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Muchie *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Kruskal(Graph *g)
{
    int i, j, min, max, nrMuchiiSelectate = -1;
    int c[g->V]; 
    
    for (i = 0; i < g->V; i++)
        c[i] = i;

    Muchie a[g->V - 1];             
    quickSort(g->e, 0, (g->E) - 1); 
    i=0;

    for (i = 0; nrMuchiiSelectate < g->V - 1 && i<g->E; i++)
    {                                         
       
        if (c[g->e[i].v1] != c[g->e[i].v2]) 
            a[++nrMuchiiSelectate] = g->e[i];


        if (c[g->e[i].v1] < c[g->e[i].v2])
        {
            min = c[g->e[i].v1];
            max = c[g->e[i].v2];
        }
        else
        {
            max = c[g->e[i].v1];
            min = c[g->e[i].v2];
        }


        for (j = 0; j < g->V; j++) 
            if (c[j] == max)
                c[j] = min;

        
    }

    
    for (i = 0; i < g->V - 1; i++)
        printf("%d %d %d\n", (a[i].v1), (a[i].v2), (a[i].cost));
    
}