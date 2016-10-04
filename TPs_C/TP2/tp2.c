#include "ioap123.h"

void demander();
void testerDateValide(void);
int dateValide(int jour, int mois, int annee);
void testerNbJours(void);
int nbJours(int mois, int annee);
void testerMoisValide(void);
int moisValide(int mois);
void testerBissextile(void);
int estBissextile(int annee);

int main (void)
{
	testerBissextile();
	testerMoisValide();
	testerNbJours();
	testerDateValide();
	demander();

	return 0;
}


void demander()
{
	int userJour, userMois, userAnnee;

	print_text("Saisissez le jour>");
	userJour = read_int();
	print_text("Saisissez le mois>");
	userMois = read_int();
	print_text("Saisissez l'année>");
	userAnnee = read_int();

	if(dateValide(userJour, userMois, userAnnee))
		print_text("La date est valide !");
	else{
		print_text("La date n'est pas valide ! Réessayez !\n");
		demander();
	}
}

void testerDateValide()
{
	if(dateValide(2,2,2000))
		print_text("test de 02/02/2000 OK\n");
	else
		print_text("test de 02/02/2000 ECHEC\n");

	if(!dateValide(32,1,2000))
		print_text("test de 32/01/2000 OK\n");
	else
		print_text("test de 32/01/2000 ECHEC\n");

	if(dateValide(29,2,2000))
		print_text("test de 29/02/2000 OK\n");
	else
		print_text("test de 29/02/2000 ECHEC\n");

	if(!dateValide(29,2,2001))
		print_text("test de 29/02/2001 OK\n");
	else
		print_text("test de 29/02/2001 ECHEC\n");

	if(!dateValide(-2,2,2000))
		print_text("test de -2/02/2000 OK\n");
	else
		print_text("test de -2/02/2000 ECHEC\n");
}

int dateValide(int jour, int mois, int annee)
{
	if (!moisValide(mois))
		return 0;

	if (nbJours(mois, annee) < jour || jour < 0)
		return 0;

	return 1;
}

void testerNbJours()
{
	if(nbJours(1,2000)==31)
		print_text("test de 01/2000 OK\n");
	else
		print_text("test de 01/2000 ECHEC\n");

	if(nbJours(2,2000)==29)
		print_text("test de 02/2000 OK\n");
	else
		print_text("test de 02/2000 ECHEC\n");

	if(nbJours(2,2001)==28)
		print_text("test de 02/2001 OK\n");
	else
		print_text("test de 02/2001 ECHEC\n");

	if(nbJours(3,2000)==31)
		print_text("test de 03/2000 OK\n");
	else
		print_text("test de 03/2000 ECHEC\n");

	if(nbJours(4,2000)==30)
		print_text("test de 04/2000 OK\n");
	else
		print_text("test de 04/2000 ECHEC\n");

	if(nbJours(5,2000)==31)
		print_text("test de 05/2000 OK\n");
	else
		print_text("test de 05/2000 ECHEC\n");

	if(nbJours(6,2000)==30)
		print_text("test de 06/2000 OK\n");
	else
		print_text("test de 06/2000 ECHEC\n");

	if(nbJours(7,2000)==31)
		print_text("test de 07/2000 OK\n");
	else
		print_text("test de 07/2000 ECHEC\n");

	if(nbJours(8,2000)==31)
		print_text("test de 08/2000 OK\n");
	else
		print_text("test de 08/2000 ECHEC\n");

	if(nbJours(9,2000)==30)
		print_text("test de 09/2000 OK\n");
	else
		print_text("test de 09/2000 ECHEC\n");

	if(nbJours(10,2000)==31)
		print_text("test de 10/2000 OK\n");
	else
		print_text("test de 10/2000 ECHEC\n");

	if(nbJours(11,2000)==30)
		print_text("test de 11/2000 OK\n");
	else
		print_text("test de 11/2000 ECHEC\n");

	if(nbJours(12,2000)==31)
		print_text("test de 12/2000 OK\n");
	else
		print_text("test de 12/2000 ECHEC\n");
}

int nbJours(int mois, int annee)
{
	if (!moisValide(mois))
		return 0;

	if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)
	{
		return 31;
	}
	else if ((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11))
	{
		return 30;
	}
	else if (mois == 2)
	{
		if (estBissextile(annee))
		{
			return 29;
		}else{
			return 28;
		}
	}else{
		return -1;
	}
}

void testerMoisValide()
{
	for(int i = -5; i < 20; i = i+4)
	{
		if (moisValide(i))
		{
			print_int(i);
			print_text(" est valide\n");
		}
	}
}

int moisValide(int mois)
{
	if (mois <= 12 && mois >= 1)
		return 1;
	else
		return 0;
}

void testerBissextile()
{
	if(estBissextile(2016))
		print_text("test de 2016 OK\n");
	else
		print_text("test de 2016 ECHEC\n");

	if(estBissextile(2008))
		print_text("test de 2008 OK\n");
	else
		print_text("test de 2008 ECHEC\n");


	if( ! estBissextile(1900))
		print_text("test de 1900 OK\n");
	else
		print_text("test de 1900 ECHEC\n");

	if(estBissextile(2000))
		print_text("test de 2000 OK\n");
	else
		print_text("test de 2000 ECHEC\n");
}

int estBissextile(int annee)
{
	if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
	{
		return 1;
	}else{
		return 0;
	}
}
