#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int s, f; //timpii de start si final 
	char nume[100]; //denumire
}activitate;
activitate activitati[100];
int n;


void select_activitati(int x[], int* nr_activitati) {
	//se selecteaza activitatile conform strategiei greedy
	//x[i] contine numere 0:n-1
	//x[i] = k, inseamna ca am selectat activitatea k
	//nr_activitati se modifica
	x[0] = 0;
	*nr_activitati = 1;
	for (int i = 1; i < n; i++) {
		if (activitati[i].s >= activitati[x[*nr_activitati - 1]].f){
			x[*nr_activitati] = i;
			(*nr_activitati)++;
		}
	}
}

void afisare(int x[], int nr) {
	printf("Am selectat %d activitati\n", nr);
	for (int i = 0; i < nr; i++) {
		printf("(%2d) %2d : %2d %s", x[i], activitati[x[i]].s, activitati[x[i]].f, activitati[x[i]].nume);
	}
}

int cmp(const void* a, const void* b) {
	activitate* aa = (activitate*)a;
	activitate* bb = (activitate*)b;

	return (aa->f) - (bb->f);
}

int main() {
	FILE* f = fopen("date_activitati.txt", "r");
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(f, "%d%d", &activitati[i].s, &activitati[i].f);
		fgets(activitati[i].nume, 100, f);
	}
	fclose(f);

	qsort(activitati, n, sizeof(activitate), cmp);

	int x[100];
	int nr_activitati = 0;
	select_activitati(x, &nr_activitati);
	afisare(x, nr_activitati);
	return 0;
}
