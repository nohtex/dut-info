#include "ioap123.h"
int estPremier(int entier);
double mediane(double *notes, int ns);
void cumul(int *h, int *ec);
void histogramme(double *notes, int ns, int *histo, int hs);
void printIntArray(int *t, int c);

int main(void)
{
	double notes[5] = {3.7, 12.3, 3.6, 16.9, 4};
	int histo[21];
	histogramme(notes, 5, histo, 21);
	printIntArray(histo, 21);
	print_text("\n");
	int cumulArr[21];
	cumul(histo, cumulArr); //Les tableaux sont de taille [21]
	printIntArray(cumulArr, 21);
	print_text("\n");
	print_double(mediane(notes, 5)); //fonction mediane pas bonne du tout (à refaire)
	print_text("\n\n");
	print_int(estPremier(6));
	return 0;
}

int estPremier(int entier)
{
	for(int i = 2; i < entier; i++)
	{
		if(entier%i == 0)
			return 0;
	}
	return 1;
}

double mediane(double *notes, int ns)
{
	int index;
	if(ns%2 == 0) //est pair
	{
		index = ns/2;
	}else{ //impair
		index = (ns+1)/2;
	}
	return notes[index];
}

void cumul(int *h, int *ec) //taille : 21
{
	int i;
	for(i = 0; i < 21; i++)
	{
		if(i == 0)
			ec[i] = h[i];
		else
			ec[i] = ec[i-1] + h[i];
	}
}

void histogramme(double *notes, int ns, int *histo, int hs)
{
	int i, j, count;
	for (i = 0; i < hs; i++) //foreach histo
	{
		count = 0;
		for(j = 0; j < ns; j++) //foreach notes
		{
			if(notes[j] >= i && notes[j] < i+1)
				count++;
		}
		histo[i] = count;
	}
}

void printIntArray(int *t, int c)
{
	for(int i = 0; i < c; i++)
	{
		print_int(t[i]);
	}
}
