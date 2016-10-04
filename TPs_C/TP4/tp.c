#include "ioap123.h"
#include <stdio.h>
#include <math.h>
int convertBinToDecimal(int *arr);
void affHexa(int *arr);
void affBinaire(int *arr);
int saisiEnt();
void saisiHexa(int *ptr);
void saisiBinaire(int *ptr);

int main()
{
	printf("%i %i\n", 456/16, 456%16);
	int binArray[8];
	saisiBinaire(binArray);
	//affBinaire(binArray);
	printf("Binaire converti en Décimal :%i\n", convertBinToDecimal(binArray));	

	/*int binHexa[2];
	saisiHexa(binHexa);
	affHexa(binHexa);

	printf("%i\n", saisiEnt());*/
}

int convertBinToDecimal(int *arr)
{
	int result;
	result = 0;
	for(int i = 7; i >= 0; i--)
	{
		if (arr[i] == 1)
			result = result + pow(2, 7-i);
	}
	return result;
}

void affHexa(int *arr)
{
	for(int i = 0; i < 2; i++)
	{
		if(arr[i] < 10)
			print_int(arr[i]);
		else{
			switch (arr[i]){
				case 10:
					print_char('A');
					break;
				case 11:
					print_char('B');
					break;
				case 12:
					print_char('C');
					break;
				case 13:
					print_char('D');
					break;
				case 14:
					print_char('E');
					break;
				case 15:
					print_char('F');
					break;
				default:
					printf("Je n'ai aucune phrase de prete pour ton age  ");
					break;
			}
		}
	}
}

void affBinaire(int *arr)
{
	for(int i = 0; i < 8; i++)
	{
		print_int(arr[i]);
	}
}

int saisiEnt()
{
	return read_int();
}

void saisiHexa(int *ptr)
{
	int i;
	printf("Entrez une valeur hexa valide pt1\n:");
	ptr[0] = read_int();
	printf("Entrez une valeur hexa valide pt2\n");
	ptr[1] = read_int();
	for(i = 0; i < 2; i++)
	{
		if(ptr[i]  < 0 || ptr[i] > 15)
		{
			printf("Erreur de saisie, les numéros héxa doivent être entre 0 et 15. Réessayez\n");
			saisiHexa(ptr);
		}
	}
}

void saisiBinaire(int *ptr)
{
	int i;
	char saisi[8];
	char *p;
	p = saisi;
	printf("Entrez un nombre binaire valide:\n");
	p = read_line();
	//Vérification
	for(i = 0; i < 8; i++)
	{
		//print_char(p[i]); //Debug
		if(p[i] == '0')
			ptr[i] = 0;
		else if (p[i] == '1')
			ptr[i] = 1;
		else{
			print_text("Erreur il n'y a pas que des 0 ou des 1\n");
			saisiBinaire(ptr);
		}		
	}

}
