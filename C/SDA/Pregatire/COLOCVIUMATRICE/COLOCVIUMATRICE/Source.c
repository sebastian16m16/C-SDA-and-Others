#include <stdio.h>
#include <stdlib.h>



typedef struct {
	int n;      // numar de varfuri
	int** m;    // matricea de adiacenta
} Graf;     // structura pentru memorarea grafului prin matrice de adiacenta

typedef struct node {
	int val;
	struct node* next;
}NodeT;

typedef struct {
	NodeT* first;
	NodeT* last;
}Coada;

enum { NEVIZITAT, VIZITAT };

/// TODO: de definit o structura Coada si
/// operatiile initializeaza, enqueue, dequeue, goala

void printErr() {
	printf("Memorie insuficienta!\n");
	exit(1);
}

void initializeaza(Coada* q) {
	q->first = q->last = NULL;
}

void enqueue(int x, Coada* Q) {
	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	node->val = x;
	node->next = NULL;

	if (Q->first == NULL) {
		Q->first = Q->last = node;
	}
	else {
		Q->last->next = node;
		Q->last = node;
	}
}

int goala(Coada Q) {
	return Q.first == NULL;
}

int dequeue(Coada* Q) {
	NodeT* node = Q->first;
	int x = node->val;

	if (Q->first != NULL) {
		Q->first = Q->first->next;
		free(node);
		if (Q->first == NULL)
			Q->last = Q->first;
	}
	else
		printf("Empty QUEUE!");

	return x;
}


void citesteGraf(FILE * f, Graf * pG) {
	fscanf(f, "%d", &pG->n);    // citeste nr. de varfuri

	// Alocam dinamic matricea de adiacenta:
	pG->m = calloc(pG->n, sizeof(int*));
	if (pG->m == NULL) printErr();  // alocare esuata
	int i;
	for (i = 1; i <= pG->n; i++) {
		// alocam dinamic linia i a matricii, cu n elemente intregi
		pG->m[i] = calloc(pG->n+1, sizeof(int));
		if (pG->m[i] == NULL) printErr();
	}

	int v, w;
	// citeste pe rand perechi (v, w) si memoreaza arcul/muchia in matricea de adiacenta:
	while (fscanf(f, "%d%d", &v, &w) == 2) {
		/// TODO: memoreaza arcul/muchia in matricea de adiacenta
		pG->m[v][w] = 1;  //orientat
		pG->m[w][v] = 1; // neorientat
	}

	int max = 0;
	int key = 0;
	int count = 0;
	for (int i = 1; i <= pG->n; i++) {
		count = 0;
		for (int j = 1; j <= pG->n; j++) {
			count += pG->m[i][j];
		}
		if (count > max) {
			key = i;
			max = count;
		}
	}
	printf("Nodul cu cei mai multi vecini = %d", key);
}

//void vecini(Graf* G, int m) {
//	int max = 0;
//	int key = 0;
//	int count = 0;
//	for (int i = 1; i <= m; i++) {
//		count = 0;
//		for (int j = 1; j <= m; j++) {
//			count += G->m[i][j];
//		}
//		if (count > max) {
//			key = i;
//			max = count;
//		}
//	}
//	printf("Nodul cu cei mai multi vecini = %d", key);
//}

int main()
{
	FILE* f = fopen("graf.txt", "r");
	if (f == NULL) {
		perror("graf.txt");
		exit(1);
	}
	Graf G;
	citesteGraf(f, &G);
	fclose(f);

	/*	 int v;
	printf("Numarul de noduri: %d. \nDati nodul sursa: ", G.n);*/
	

	return 0;
}
