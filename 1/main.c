#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kruskal.h"

int main()
{   
    int n,m,i;
    FILE* f;
    Graph *g=NULL;
    

    if((f=fopen("input.txt","rt"))==NULL)
    {
        printf("Fisierul nu a putut fi deschis.\n");
        exit(1);
    }

    fscanf(f,"%d%d",&n,&m);
    g=createGraph(n,m);

    for(i=0;i<m;i++)
        {
            fscanf(f,"%d%d%d",&g->e[i].v1,&g->e[i].v2,&g->e[i].cost);
            // am scazut 1 ca sa inceapa numerotarea de la nodul 0
            g->e[i].v1=g->e[i].v1-1;
            g->e[i].v2=g->e[i].v2-1;
        }
    
    Kruskal(g);

    fclose(f);
    return 0;
}