#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libwc.h"

void readFile(char* filename, char* txt) //Fonction pour lire le fichier et garde les caractères
{
	int n = 0;
	FILE *f = NULL;
	f=fopen(filename, "r");
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[n]);
		n++;
	}
	fclose(f);
}

int lineCount(char* filename, char* txt)				     //Fonction pour compter les lignes
{
	int i = 0, l = 0;
	FILE *f = NULL;
	f=fopen(filename, "r");
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[i]);
		if(txt[i]=='\n')
		{
			l++;
		}
		i++;
	}
	fclose(f);
	return (l);
}

int wordCount(char* filename, char* txt)			     //Fonction pour compter les mots
{
	int w = 0;
	FILE *f = NULL;
	f=fopen(filename, "r");
	while(feof(f) != 1)
	{
		fscanf(f, "%s", &txt[w]);
		w++;
	}
	fclose(f);
	return (w-1);
}

int charCount(char* filename, char* txt)			     //Fonction pour compter les caractères
{
	int c = 0;
	FILE *f = NULL;
	f=fopen(filename, "r");
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[c]);
		c++;
	}
	fclose(f);
	return (c-1);
}

int LeagthCount(char* filename, char* txt, int* tab)
{
	int i = 0, l = 0, L;
	FILE *f = NULL;
	f=fopen(filename, "r");
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[i]);
		if(txt[i]=='\n')
		{
			tab[l] = i;
			i = 0;
			l++;
		}
		i++;
	}
	fclose(f);
	for(i = 0; i < l-1; i++)
	{
		if(tab[i] >= tab[i+1])
		{
			tab[i+1] = tab[i];
			L = tab[i];
		}
	}
	return (L-1);
}

char* allocation()
{
	char* txt = NULL;
	txt = (char*)malloc(10000*sizeof(char));
	if(txt == NULL)
	{
		printf("Erreur d'allocation");
		exit (1);
	}
	return (txt);
}

int* allocation2(int l)
{
	int *tab = NULL;
	tab = (int*)malloc(l*sizeof(int));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit (1);
	}
	return (tab);
}

void afficheWcDefaut(char* filename, int c, int l, int w)
{
	printf(" %d  %d %d %s\n", l, w-1, c-1, filename);
}

void afficheWc(char* filename, int c, int l, int w, int L, char* option)
{
	if(strcmp(option, "-m") == 0 || strcmp(option, "-c") == 0)
	{
		printf("%d %s\n", c, filename);
	}
		else if(strcmp(option, "-l") == 0)
	{
		printf("%d %s\n", l, filename);
	}
	else if(strcmp(option, "-w") == 0)
	{
		printf("%d %s\n", w, filename);
	}
	else if(strcmp(option, "-L") == 0)
	{
		printf("%d %s\n", L, filename);
	}
}
