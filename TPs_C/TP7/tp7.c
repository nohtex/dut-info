#include "ioap123.h"
#include <stdio.h>

void lireFichier(char *nom, int **grille);
int ** allouer2D(int l, int c);
void afficherGrille(int **g);

int main (void)
{
	int** laGrille ;
	laGrille = allouer2D (9 ,9);
	lireFichier ("grilleOK.txt", laGrille );
	afficherGrille ( laGrille );
	return 0;
}

void lireFichier ( char * nom , int ** grille )
{
	FILE * ptf ;
	ptf = fopen ( nom ,"r");
	if( ptf == NULL )
		print_text (" erreur ouverture de fichier \n");
	int i , j ;
	for( i = 0; i <9; i = i +1)
	{
		for( j =0; j <9; j = j +1)
		{
			fscanf ( ptf ,"%d" ,& grille [ i ][ j ]);
		}
	}
}

int ** allouer2D (int l , int c )
{
	int **m;
	int i;
	m = malloc (l*sizeof(int*));
	for( i =0; i < l ; i = i +1)
	{
		m [i] = malloc(c * sizeof(int));
	}
	return m ;
}

void afficherGrille (int ** g )
{
	int i , j;
	print_text("---------------------------\n");
	for(i =0; i <9; i = i +1)
	{

		print_text("| ");
		for(j =0; j <9; j = j +1)
		{
			print_int(g[i][j]);
			print_text(" ");
			if((j == 2 || j == 5) && j != 9)
				print_text(" | ");
			if(j == 8)
				print_text("|");
		}
		print_text("\n");
		if(i == 2 || i == 5)
			print_text("|------------------------\n");
	}
	print_text("---------------------------\n");
}
