#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "kruskal.h"

int main()
{
    struct dirent *entry;
	DIR *pDir;

	pDir = opendir("files");
	if (pDir == NULL)
	{
		printf("Cannot open directory\n");
		exit(1);
	}

	Oras *head = NULL, *aux, *aux1;

	entry = readdir(pDir);
	entry = readdir(pDir);

	int i = 0,j;
	FILE *f;
	char *buffer = (char *)malloc(40), *s = (char *)malloc(40);

	while ((entry = readdir(pDir)))
	{
		// printf("d_name: %s\n", entry->d_name);
		char filename[50] = "files/";

		strcat(filename, entry->d_name);
		//printf("filename: %s\n",filename);
		f = fopen(filename, "r");
		if (f == NULL)
		{
			printf("Fisierul nu a putut fi deschis\n");
			exit(1);
		}

		fgets(buffer, 40, f);
		buffer[strlen(buffer) - 1] = '\0';
		s = strtok(buffer, ",");

		while (!feof(f))
		{
			aux = searchOras(head, s);
			if (aux == NULL)
			{
				head = append_node(head, s);
				i++;
			}
			fgets(buffer, 40, f);
			buffer[strlen(buffer) - 1] = '\0';
			s = strtok(buffer, ",");
		}
		fclose(f);
	}
	closedir(pDir);
    
    int **a;

    a=(int**)malloc(i*sizeof(int*));
	if(a==NULL)
	{
		printf("Alocare esuata.\n");
		exit(1);
	}

    for(j=0;j<i;j++)
        a[j]=(int*)calloc(i,sizeof(int));
    
    int a1, a2;

	pDir = opendir("files");
	if (pDir == NULL)
	{
		printf("Cannot open directory\n");
		exit(1);
	}

	entry = readdir(pDir);
	entry = readdir(pDir);
	

	while ((entry = readdir(pDir)))
	{
		char filename[50] = "files/";
		strcat(filename, entry->d_name);
		// printf("filename: %s\n", filename);

		f = fopen(filename, "r");
		if (f == NULL)
		{
			printf("Fisierul nu a putut fi deschis\n");
			exit(1);
		}

		fgets(buffer, 40, f);
		buffer[strlen(buffer) - 1] = '\0';

		s = strtok(buffer, ",");
		aux = searchOras(head, s);
		s = strtok(NULL, ", ");
		a1 = atoi(s);
		aux1 = NULL;

		while (!feof(f))
		{
			fgets(buffer, 40, f);
			buffer[strlen(buffer) - 1] = '\0';
			s = strtok(buffer, ",");
			aux1 = searchOras(head, s);
			s = strtok(NULL, ", ");
			a2 = atoi(s);

			if (aux1 != NULL)
			{
				a[aux->id][aux1->id]=a[aux1->id][aux->id]=a2-a1;
			}
			aux = aux1;
			a1 = a2;
		}

		fclose(f);
	}
	closedir(pDir);
    j=0;
    // Numar numarul de muchii
    for(a1=0;a1<i-1;a1++)
        for(a2=a1+1;a2<i;a2++)
            if (a[a1][a2]) j++;

	
    Graph*g=createGraph(i,j);
    j=0;
	
    for(a1=0;a1<i-1;a1++)
        for(a2=a1+1;a2<i;a2++)
            if (a[a1][a2])
            {
                g->e[j].v1=a1;
                g->e[j].v2=a2;
                g->e[j].cost=a[a1][a2];
                j++;
            }
	
    Kruskal(g);
	
    return 0;
}