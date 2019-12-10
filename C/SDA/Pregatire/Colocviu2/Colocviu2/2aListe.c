#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int val;
	struct nod* next;
} NodeT;

typedef struct {
	int n;      // numar de varfuri
	NodeT** t;  // tabloul de liste (va fi alocat dinamic)
	int* pi; //vectorul de parinti
	int* d; //timpii de descoperire
	int* f; //timpii de finalizare
	int* color; //informatia de culoare
} Graf;     // structura pentru memorarea grafului prin liste de adiacenta dinamice; tine si informatia de parcurgere

enum {
	WHITE, GRAY, BLACK
};

void push(NodeT** stiva, int val) { //insert first in a linked list

	NodeT* el = (NodeT*)malloc(sizeof(NodeT));
	el->val = val;
	el->next = (*stiva);
	*stiva = el;
}

/* sterge elementul din varful stivei si returneaza valoarea lui */
int pop(NodeT** stiva)
{
	int n = -1;
	if (*stiva != NULL) {
		NodeT* firstElement = (*stiva);
		*stiva = (*stiva)->next;
		n = firstElement->val;
		free(firstElement);
	}
	return n;
}

/* returneaza 1 daca stiva este goala */
int empty(NodeT* stiva)
{
	return stiva == NULL;
}

void init(NodeT** stiva) {
	*stiva = NULL;
}

void printErr() {
	printf("Memorie insuficienta!\n");
	exit(1);
}

//TODO implementati parcurgerea iterativa
void dfs_visit_iterativ(Graf* G, int start)
{
	NodeT* s;
	init(&s);
	push(&s, start);

	while (!empty(s)) {
		int v = pop(&s);
		if (G->color[v] == WHITE) {
			G->color[v] = GRAY;
			printf("%d ", v);
			NodeT* p = G->t[v];

			while (p != NULL) {
				int w = p->val;
				if (G->color[w] == WHITE) {
					push(&s, w);
					G->pi[w] = v;
				}
				p = p->next;
			}
		}
	}

}


void citesteGraf(FILE * f, Graf * pG) {

	fscanf(f, "%d", &pG->n);  // citeste nr. de varfuri

	pG->t = (NodeT * *)calloc(pG->n, sizeof(NodeT*));
	if (pG->t == NULL) printErr();  // alocare esuata

	pG->pi = (int*)calloc(pG->n, sizeof(int));
	pG->d = (int*)calloc(pG->n, sizeof(int));
	pG->f = (int*)calloc(pG->n, sizeof(int));
	pG->color = (int*)calloc(pG->n, sizeof(int));

	int i;
	for (i = 1; i < pG->n; i++) {
		pG->t[i] = NULL;
		pG->pi[i] = -1;
	}

	int v, w;
	while (fscanf(f, "%d%d", &v, &w) == 2) {
		//graful va fi neorientat, se adauga atat arcul (v,w) cat si (w,v)
		push(&pG->t[w], v);
		push(&pG->t[v], w);
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void reInitTraversalData(Graf * G)
{
	for (int i = 0; i < G->n; i++)
	{
		G->d[i] = -1;
		G->pi[i] = -1;
		G->f[i] = -1;
		G->color[i] = WHITE;
	}

}



void vecini(Graf G, int m) {
	int max = 0;
	int key = 0;
	int count = -1;
	for (int i = 1; i <= m; i++) {
		NodeT* node = G.t[i];
		count = 0;
		while (node != NULL) {
			count++;
			node = node->next;
		}
		if (count > max) {
			key = i;
			max = count;
		}
	}
	printf("Nodul cu cei mai multi vecini = %d", key);
}


int main() {
	int m = 7;
	FILE* f = fopen("graf.txt", "r");
	if (f == NULL) {
		perror("graf.txt");
		exit(1);
	}
	Graf G;
	citesteGraf(f, &G);
	fclose(f);

	vecini(G, G.n);

	


	














	//eliberam memoria
	free(G.color);
	free(G.d);
	free(G.f);

	int i;
	for (i = 0; i < G.n; i++) {
		/// TODO: eliberati nodurile din lista de adiacenta a lui i, daca e nevida
		while (!empty(G.t[i]))
			pop(&(G.t[i]));
	}

	free(G.t);

	return 0;
}
