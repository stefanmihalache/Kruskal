#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    // for (i = 0; i < g->V - 1; i++)
    //     printf("%d %d %d\n", (a[i].v1), (a[i].v2), (a[i].cost));
    
}

Oras *append_node(Oras *head, char *s)
{
    Oras *a;
    a = (Oras *)malloc(sizeof(Oras));
    if (a == NULL)
    {
        printf("Alocare esuata.\n");
        exit(1);
    }
    a->nume = strdup(s);
    a->next = NULL;

    if (head == NULL)
    {
        head = a;
        head->id = 0;
        return head;
    }
    else
    {
        Oras *aux = head;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = a;
        a->id = aux->id + 1;
        return head;
    }
}

Oras* searchOras(Oras *head, char *x)
{
    if (head == NULL)
        return NULL;

    while (head != NULL)
    {
        if ((strcmp(x, head->nume)) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}