#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char nume[30];
	double media;
}student;

void proceseaza(char* numeFis, student*t, int *n)
{
	FILE *pf = fopen(numeFis, "r");
	if (pf == NULL)
	{
		printf("Fisierul nu a putut fi deschis");
		exit(1);
	}

	*n = 0;

	while (1) {
		if (fscanf(pf, "%s", t[*n].nume) != 1)
			break;
		t[*n].nume[strlen(t[*n].nume) - 1] = '\0';
		char ch;
		int x;
		int suma = 0, nrNote = 0;
		do {
			fscanf(pf, "%d%c", &x, &ch);
			suma += x;
			nrNote++;
		} while (ch != '.');

		t[*n].media = (double)suma / nrNote;
		(*n)++;
	}
	fclose(pf);
}


void salveazaText(student *t, int n, char * numeFis)
{
	FILE *pf = fopen(numeFis, "w");
	for (int i = 0; i < n; i++)
		fprintf(pf, "%s are media %f\n", t[i].nume, t[i].media);
	fclose(pf);
}

void salveazaBinar(student *t, int n, char *numeFis)
{
	FILE *pf = fopen(numeFis, "wb");
	fwrite(t, sizeof(student), n, pf);
	fclose(pf);

}

void main()
{

	student t[100];
	int n;
	proceseaza("studenti.txt", t, &n);
	salveazaText(t, n, "medii.txt");
	salveazaBinar(t, n, "medii.bin");

	system("pause");
}