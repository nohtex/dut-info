#include "ioap123.h"

void demanderNotesEleves(double eleves[][3], int taille);
void moyenne(double eleves[][3], int taille);
void lire(double *adresse, int taille);
void fonction(double *adresse, int taille);

int main(void)
{
	//double array[5]; Q<4
	//double *p; Q<4
	double eleves[5][3];

	/*fonction(p, 5);
	lire(p, 5);*/
	demanderNotesEleves(eleves, 5);
	moyenne(eleves, 5);
	return 0;
}

void demanderNotesEleves(double eleves[][3], int taille)
{
	for(int i = 0; i < taille; i++)
	{

		for(int i2 = 0; i2 < 2; i2++)
		{
			print_text("(Eleve ");
			print_int(i+1);
			print_text(") Note ");
			print_int(i2+1);
			print_text(" : ");
			eleves[i][i2] = read_double();
		}
	}
}

void moyenne(double eleves[][3], int taille)
{
	double sum;
	int count;

	print_text("\n\n");
	for(int i = 0; i < taille; i++) // 0 to 5
	{
		count = 0;
		sum = 0;
		for (int i2 = 0; i2 < 2; i2++) // 0 to 1
		{
			if (eleves[i][i2] == -1)
			{
				eleves[i][i2] = 0;
				count++;
			}
			if (eleves[i][i2] == -2)
				eleves[i][i2] = 0;
			sum += eleves[i][i2];
		}
		if (count == 2)
			eleves[i][2] = -1;
		else
			eleves[i][2] = sum/(2-count);
		print_text("Moyenne Eleve ");
		print_int(i+1);
		print_text(" : ");
		print_double(eleves[i][2]);
		print_text("\n\n");
	}
}

void lire(double *adresse, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		print_double(adresse[i]);
		print_text("\n");
	}
}

void fonction(double *adresse, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		print_text("Valeur de ");
		print_int(i);
		print_text(" : ");
		adresse[i] = read_double();
		print_text("\n");
	}
}
