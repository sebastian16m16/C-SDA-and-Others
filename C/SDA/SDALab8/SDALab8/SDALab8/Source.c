#include <stdio.h>
#include <stdlib.h>

/*****************************************************
  Citirea grafului se face din fisierul graf.txt;
  reprezentarea grafului este prin liste de adiacenta dinamice.
  In fisier se da numarul n de varfuri ale grafului,
  apoi muchiile sub forma de perechi i j, cu 0<=i,j<n
  (i si j reprezinta indicii varfurilor conectate prin
   arc (sau muchie)).
  Graful se parcurge in maniera DFS si se salveaza arborele (arborii)
  de parcurgere, in vectorul pi; de asemenea, la varianta recursiva se
  inregistreaza si informatia de culoare si timpii de descoperire si
  finalizare (informatie mentinuta in structura grafului)
******************************************************/

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
	NodeT* S;
	init(&S);
	push(&S, start);

	while (!empty(S)) {
		int v = pop(&S);
		if (G->color[v] == WHITE) {
			G->color[v] = GRAY;
			printf("%d ", v);
			NodeT* p = G->t[v];
			while (p != NULL) {
				int w = p->val;
				if (G->color[w] == WHITE) {
					push(&S, w);
					G->pi[w] = v;
				}
				p = p->next;
			}
		}
	}
}

void dfs_iterativ(Graf* G)
{
	int i;
	for (i = 0; i < G->n; i++)
		if (G->color[i] == WHITE)
			dfs_visit_iterativ(G, i);
}



// TODO: Implementati dfs recursiv cu colorarea nodurilor si marcaje de timp
void dfs_visit(int v, Graf * G, int* time) {
	
	printf("*%d*", v);
	(*time)++;
	G->d[v] = *time;
	G->color[v] = GRAY;
	NodeT* p = G->t[v];
	while (p != NULL) {
		int w = p->val;
		if (G->color[w] == WHITE) {
			G->pi[w] = v;
			printf("\n (%d, %d) - ARBORE\n", v, w);
			dfs_visit(w, G, time);
		}
		else {
			if (G->color[w] == GRAY) {
				printf("\n (%d, %d) - INAPOI \n", v, w);
			}else
				if(G->d[v]<G->d[w])
					printf("\n (%d, %d) - INAINTE \n", v, w);
				else
				{
					printf("\n (%d, %d) - TRANSVERSAL \n", v, w);
				}
		}
		
		p = p->next;
	}
	G->color[v] = BLACK;
	(*time)++;
	G->f[v] = *time;
}

void dfs_recursiv(Graf * G) {

	int time = 0, i;

	for (i = 0; i < G->n; i++) {
		if (G->color[i] == WHITE) {
			dfs_visit(i, G, &time);
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
	for (i = 0; i < pG->n; i++) {
		pG->t[i] = NULL;
		pG->pi[i] = -1;
	}

	int v, w;
	while (fscanf(f, "%d%d", &v, &w) == 2) {
		//graful va fi neorientat, se adauga atat arcul (v,w) cat si (w,v)
		//push(&pG->t[w], v);
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


int main() {
	FILE* f = fopen("graf.txt", "r");
	if (f == NULL) {
		perror("graf.txt");
		exit(1);
	}
	Graf G;
	citesteGraf(f, &G);
	fclose(f);

	//varianta iterativa
	printf("\n DFS varianta iterativa: ");
	dfs_iterativ(&G);
	printf("Vectorul de parinti:");
	print(G.pi, G.n);

	reInitTraversalData(&G);
	//varianta recursiva
	printf("\n DFS varianta recursiva: \n");
	dfs_recursiv(&G);
	printf("\nVectorul de parinti:");
	print(G.pi, G.n);
	printf("Timpii de descoperire:");
	print(G.d, G.n);
	printf("Timpii de finalizare:");
	print(G.f, G.n);


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
