#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nume[100];
	int greutate;
	int valoare;
}obiect;

int comparare(const void* a, const void* b) {
	obiect* aa = (obiect*)a;
	obiect* bb = (obiect*)b;
	float ra = (float)aa->valoare / aa->greutate;
	float rb = (float)bb->valoare / bb->greutate;

	// trebuie sa returneze ceva negativ daca vreau sa il pun pe "a" inainte de "b"
	// sa returneze pozitiv daca vreau sa il pun pe b dupa a
	// 0 daca sunt egale

	if (ra > rb)
		return -1;
	if (rb > ra)
		return 1;
	return 0;
}

int main() {
	FILE* pf = fopen("obiecte.txt", "r");
	if (!pf)
		return 0;
	int n;
	fscanf(pf, "%d", &n);
	obiect* a = (obiect*)malloc(n * sizeof(obiect));
	for (int i = 0; i < n; i++) {
		fscanf(pf,"%s %d %d", a[i].nume, &a[i].greutate, &a[i].valoare);
	}

	printf("Greutatea maxima a rucsacului: ");

	int g;
	scanf("%d", &g);

	qsort(a, n, sizeof(obiect), comparare);
	
	int cant = 0;

	for(int i=0; i<n; i++)
		if (a[i].greutate <= g) {
			printf("In rucsac: %s (greutate: %d valoare: %d) \n", a[i].nume, a[i].greutate, a[i].valoare);
			g -= a[i].greutate;
		}


	free(a);
	fclose(pf);

	return 0;
}