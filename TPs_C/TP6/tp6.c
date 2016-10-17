#include "ioap123.h"
#include <time.h>
#include <stdio.h>
#include <signal.h>

int **allouerTab2D(int nbL, int nbC);
void afficherTableau(int l, int c, int **damier);
void afficher(int l, int c, int **damier);
void init(int l, int c, int **damier);
int nbVoisins(int l, int c, int **damier, int x, int y);
int **nGen(int l, int c, int **damier);

int main()
{
	int ux, uy;
	print_text("Combien en longueur ?");
	ux = read_int();
	print_text("Combien en hauteur ?");
	uy = read_int();
	srand(time(NULL));
	//int damier[NUML][NUMC] = {0};
	int **damier = allouerTab2D(uy, ux);
	//int damier[16] = {0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1};
	//afficherTableau(damier, 16);
	
	print_int(rand()%2);
	print_text("\n\n");
	print_text("INITIALISATION:\n");
	init(uy, ux, damier);
	
	print_text("\n\nAFFICHAGE TABLEAU:\n");
	afficherTableau(uy, ux, damier);
	
	print_text("\n\nAFFICHAGE:\n");
	afficher(uy, ux, damier);

	print_text("\n\nNB VOISINS\n");
	print_int(nbVoisins(uy, ux, damier, 4, 4));

	print_text("\n\nNEW GENERATION:\n");
	afficherTableau(uy, ux, damier);
	for (int i = 0; i < 500; i++){
		system("clear");
		damier = nGen(uy, ux, damier);
		afficherTableau(uy, ux, damier);
		system("sleep 0.1");
	}
	print_text("\n\n");
	return 0;
}

/*int estVide(int l, int c, int **damier)
{
	int i, j;
	for (i=0; i<l; i++)
	{
		for (j=0; j < c; j++)
		{
			if(damier[i][j])
		}
	}
	
}*/

int **nGen(int l, int c, int **damier)
{
	int i,j, nbv;
	int **nDamier;
	nDamier = allouerTab2D(l, c);
	for (i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++)
		{
			nbv = nbVoisins(l, c, damier, j, i);
			if(damier[i][j]) //si la case a une cellule
			{
				if(nbv == 2 || nbv == 3) //obli?
					nDamier[i][j] = 1;
				if(nbv < 2)
					nDamier[i][j] = 0;
				if(nbv > 3)
					nDamier[i][j] = 0;
			}
			else //case vide
			{
				if(nbv == 3)
					nDamier[i][j] = 1;	
			}
		}
	}
	return nDamier;
}

int nbVoisins(int l, int c, int **damier, int x, int y)
{
	int count = 0;
	if (x > 0) //gauche
	{
		if(damier[y][x-1])
			count++;
	}
	if(x < c-1) //droite
	{
		if(damier[y][x+1])
			count++;
	}
	if(y > 0) //bas
	{
		if(damier[y-1][x])
			count++;
	}
	if(y < l-1) //haut
	{
		if(damier[y+1][x])
			count++;
	}
	if(y > 0 && x > 0) //c haut gauche
	{
		if(damier[y-1][x-1])
			count++;
	}
	if(y < l-1 && x < c-1) //c bas droite
	{
		if(damier[y+1][x+1])
			count++;
	}
	if(x > 0 && y < l-1) //c bas gauche
	{
		if(damier[y+1][x-1])
			count++;
	}
	if(x < c-1 && y >0) //c haut droite //SEGFAULT HERE
	{
		if(damier[y-1][x+1])
			count++;
	}
	//if(x <)

	return count;
}

void afficher(int l, int c, int **damier)
{
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%i", damier[i][j]);
		}
		print_char(' ');
	}
}

void afficherTableau(int l, int c, int **damier)
{
	int i, j;
	print_text("-----------\n");
	for (i = 0; i < l; i++)
	{
		print_char('|');
		for (j = 0; j < c; j++)
		{
			if(damier[i][j] == 1)
				print_text("*");
			else
				print_char(' ');
			print_char('|');
		}
		print_char('\n');
	}
	print_text("-----------\n");
}


void init(int l, int c, int **damier)
{
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			damier[i][j] = rand()%2;
			print_int(damier[i][j]);
		}
		print_char(' ');
	}
}

int **allouerTab2D(int nbL, int nbC)
{
	int **lePointeur;
	int i;
	lePointeur = malloc(sizeof(int *)*nbL);
	for(i =0; i < nbL; i = i +1)
	{
		lePointeur [i] = malloc(sizeof(int)*nbC);
	}
	return lePointeur;
}
