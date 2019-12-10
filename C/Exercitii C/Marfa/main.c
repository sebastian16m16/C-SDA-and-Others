#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNING

struct marfa {

	double cant;
	double pret;
	double folosit;

} faina, zahar, scortisoara, sare, piper;

double randoms(double upper)
{
		double num = 0 + rand() / (RAND_MAX / (upper - 0 + 1) + 1);

		return num;
}


void cantPret() {
	faina.cant = 1000;
	zahar.cant = 4550;
	scortisoara.cant = 2000;
	sare.cant = 500;
	piper.cant = 200;

	faina.pret = 4;
	zahar.pret = 3;
	scortisoara.pret = 5;
	sare.pret = 2;
	piper.pret = 10;

}



void parting(double m) {
	

	
	
	double pret = 0;
	int poz;
	double folos;

	while (m > 0) {
		double arr[5] = { faina.cant, zahar.cant, scortisoara.cant, sare.cant, piper.cant };
		poz = randoms(4);
		folos = randoms(arr[poz]);
		m = m - folos;
		
		
			if (arr[poz] == faina.cant) {
				if (folos > faina.cant) {
					m = m + folos - faina.cant;
					folos = faina.cant;
					 
					
					break;
				}
				faina.cant -= folos;
				faina.folosit = faina.folosit + folos;
				pret = pret + faina.pret * folos;
				if (m < 0) {
					double extra = 0 - m;
					m = m + extra;
					faina.cant += extra;
					pret = pret - faina.pret * extra;
					faina.folosit = faina.folosit - extra;
				}
			}
			if (arr[poz] == zahar.cant) {
				if (folos > zahar.cant) {
					m = m + folos - zahar.cant;
					folos = zahar.cant;


					break;
				}
				zahar.cant -= folos;
				pret = pret + zahar.pret * folos;
				zahar.folosit = zahar.folosit + folos;
				if (m < 0) {
					double extra = 0 - m;
					zahar.cant += extra;
					m = m + extra;
					pret = pret - zahar.pret * extra;
					zahar.folosit = zahar.folosit - extra;
				}
			}
			if (arr[poz] == scortisoara.cant) {
				if (folos > scortisoara.cant) {
					m = m + folos - scortisoara.cant;
					folos = scortisoara.cant;


					break;
				}
				scortisoara.cant -= folos;
				pret = pret + scortisoara.pret * folos;
				scortisoara.folosit = scortisoara.folosit + folos;
				if (m < 0) {
					double extra = 0 - m;
					scortisoara.cant += extra;
					m = m + extra;
					pret = pret - scortisoara.pret * extra;
					scortisoara.folosit = scortisoara.folosit - extra;
				}
			}
			if (arr[poz] == sare.cant) {
				if (folos > sare.cant) {
					m = m + folos - sare.cant;
					folos = sare.cant;


					break;
				}
				sare.cant -= folos;
				pret = pret + sare.pret * folos;
				sare.folosit = sare.folosit + folos;
				if (m < 0) {
					double extra = 0 - m;
					sare.cant += extra;
					m = m + extra;
					pret = pret - sare.pret * extra;
					sare.folosit = sare.folosit - extra;
				}
			}
			if (arr[poz] == piper.cant) {
				if (folos > piper.cant) {
					m = m + folos - piper.cant;
					folos = piper.cant;


					break;
				}
				piper.cant -= folos;
				pret = pret + piper.pret * folos;
				piper.folosit = piper.folosit + folos;
				if (m < 0) {
					double extra = 0 - m;
					piper.cant += extra;
					m = m + extra;
					pret = pret - piper.pret * extra;
					piper.folosit = piper.folosit - extra;
				}
			}
		


	}

	
		printf("AU RAMAS: \n faina | zahar | scortisoara | sare | piper |\n %lf | %lf |%lf |%lf |%lf |\n", faina.cant, 
			zahar.cant,	scortisoara.cant, sare.cant, piper.cant);

		printf("S-au folosit: \n faina | zahar | scortisoara | sare | piper |\n %lf | %lf |%lf |%lf |%lf |\n",
			faina.folosit, zahar.folosit, scortisoara.folosit, sare.folosit, piper.folosit);
		printf("Pretul total pentru marfa este: %lf!\n", pret);

		printf("Mai incape doar %lf kg de marfa!\n", m);
	

}


int main() {
	double m;
	printf("Care e cantitatea maxima?\n");
	scanf_s("%lf", &m);
	printf("Cantitatea maxima este %lf kg. \n", m);

	cantPret();

	parting(m);

	

	printf("\n");
	system("pause");

	return 0;
}