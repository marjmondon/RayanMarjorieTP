// TP1RayanMarjorie.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


int nbrDeFrac;
int* tabFraction = new int[nbrDeFrac * 2];
int numerateur;
int denominateur;
int a = 0;
bool diff = true;

void demandeInfo();
void afficherResultat();
int calculerPGCD(int num1, int num2);
void simplifieFrac(int* num1, int* num2, int PGCD);

int main()
{
	demandeInfo();
	afficherResultat();
}
//Demande a l'utilisateur le nombre de fraction qu'il veut entrer ainsi que les numérateurs et dénominateurs en s'assurant qu'il ne sont pas plus petit ou égale a 0!
void demandeInfo() {
	std::cout << "Combien de fractions voulez-vous traiter?\n";
	std::cin >> nbrDeFrac;

	for (int i = 0; i < (nbrDeFrac * 2); i = i + 2)
	{
		a++;
		diff = true;
		while (diff) {
			std::cout << "Quel le numerateur de la fration numero " << a << " ?\n";
			std::cin >> numerateur;
			if (numerateur <= 0) {
				std::cout << "Le numerateur doit etre different et plus grand que 0!  \n";
			}
			else {
				diff = false;
				tabFraction[i] = numerateur;
			}
		}
		diff = true;
		while (diff) {
			std::cout << "Quel le denominateur de la fration numero " << a << " ?\n";
			std::cin >> denominateur;
			if (denominateur <= 0) {
				std::cout << "Le denominateur doit etre different et plus grand que 0!  \n";
			}
			else {
				diff = false;
				tabFraction[i + 1] = denominateur;
			}
		}
	}

}

//Affichage des fractions avant et apres la simplification!
void afficherResultat() {
	for (int i = 0; i < (nbrDeFrac * 2); i = i + 2)
	{
		std::cout << std::endl << tabFraction[i] << "/" << tabFraction[i + 1] << " >>> ";
		simplifieFrac(&tabFraction[i], &tabFraction[i + 1], calculerPGCD(tabFraction[i], tabFraction[i + 1]));
		std::cout << tabFraction[i] << "/" << tabFraction[i + 1] << std::endl;
	}
}

//Simplification de la fraction en prenant numérateur et dénominateur et les divisant par le PGCD!
void simplifieFrac(int* num1, int* num2, int PGCD) {
	*num1 = *num1 / PGCD;
	*num2 = *num2 / PGCD;
}

//Calcul du PGCD avec l'Algortithme de Stein!
int calculerPGCD(int num1, int num2)
{
	if (num1 == num2)
		return num1;

	if (~num1 & 1)
	{
		if (num2 & 1)
			return calculerPGCD(num1 >> 1, num2);
		else
			return calculerPGCD(num1 >> 1, num2 >> 1) << 1;
	}

	if (~num2 & 1)
		return calculerPGCD(num1, num2 >> 1);

	if (num1 > num2)
		return calculerPGCD((num1 - num2) >> 1, num2);

	return calculerPGCD((num2 - num1) >> 1, num1);
}