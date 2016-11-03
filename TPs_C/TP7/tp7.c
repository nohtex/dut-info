#include "ioap123.h"
#include <stdio.h>

void lireFichier(char *nom, int **grille);
int ** allouer2D(int l, int c);
void afficherGrille(int **g);
int verifierGrille(int **g);

int main (void)
{
	int** laGrille ;
	laGrille = allouer2D (9 ,9);
	lireFichier ("grilleNOK.txt", laGrille );
	printf("\n\n");
	print_int(verifierGrille(laGrille));
	printf("\n\n");
	afficherGrille ( laGrille );
	return 0;
}

int verifierGrille(int **g)
{
	int i, j, k;
	for (i=0; i < 9; i++)//foreach lines
	{
		for(j=0; j < 9; j++)//foreach column
		{
			//VERIF LINE
			for(k=0; k < 9; k++)
			{
				if(k != j){
					//printf("%i %i\n", g[i][j], g[i][k]);
					if(g[i][j] == g[i][k]){
						printf("g[i][j]=%i g[i][k]=%i i=%i j=%i k=%i\n\n", g[i][j], g[i][k], i, j, k);
						return 0;
					}
				}
			}

			//VERIF COLUMN
			for(k=0; k < 9; k++)
			{
				if (k != i){
					if(g[i][j] == g[k][j])
					{
						printf("g[%i][%i]=%i g[%i][%i]=%i i=%i j=%i k=%i\n",i, j, g[i][j], k, j, g[k][j], i, j, k);
						return 0;
					}
				}
			}

			//VERIF CASE
			/*int cases[9][9], l, m;
			for(k=0; k<9; k++)
			{
				for(l=0; l<9; l++)
				{
					
				}	
			}*/
		}
	}
	return 1;
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
