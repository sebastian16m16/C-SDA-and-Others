#include <stdio.h>
#include <stdlib.h>

/*****************************************************
  Citirea datelor despre un graf dintr-un fisier
  cu reprezentarea grafului prin liste de adiacenta dinamice.
  In fisier se da numarul n de varfuri ale grafului,
  apoi muchiile sub forma de perechi i j, cu 0<=i,j<n
  (i si j reprezinta indicii varfurilor conectate prin
   arc (sau muchie)).
  Graful se parcurge BFS si se scriu într-un fisier
  nodurile în ordinea parcurgerii.
******************************************************/

typedef struct nod {
	int val;
	struct nod* next;
} NodeT;

typedef struct {
	int n;      // numar de varfuri
	NodeT** t;    // tabloul de liste (va fi alocat dinamic)
} Graf;     // structura pentru memorarea grafului prin liste de adiacenta dinamice

/// TODO: de definit o structura Coada si
typedef struct {
	NodeT* first;
	NodeT* last;
}Coada;

enum { NEVIZITAT, VIZITAT };


/// operatiile initializeaza, enqueue, dequeue, goala
void initializeaza(Coada* Q) {
	Q->first = Q->last = NULL;
}

void enqueue(int x, Coada* Q) {
	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	node->val = x;
	node->next = NULL;

	if (Q->first == NULL) {
		//node->next = Q->first;
		Q->first =   Q->last = node;
	}
	else {
		Q->last->next = node;
		Q->last = node;
	}
}

int dequeue(Coada* Q) {
	NodeT* node = Q->first;
	int x = node->val;

	if (Q->first != NULL) {
		Q->first = Q->first->next;
		free(node);
	}
	else {
		printf("Queue EMPTY!");
	}

	return x;
}

int goala(Coada Q) {
	return Q.first == NULL;
}

void printErr() {
	printf("Memorie insuficienta!\n");
	exit(1);
}

void bfs(Graf G, int nodSursa)
{
	int k = 0;
	int* vizitate; /* pentru marcarea nodurilor vizitate */
	vizitate = calloc(G.n, sizeof(int));
	if (vizitate == NULL) printErr();

	Coada Q; /* coada nodurilor - intregi */

	int i, v, w; /* noduri */
	int* arr = (int*)malloc(7 * sizeof(int));

	initializeaza( &Q );
	for (i = 0; i < G.n; i++) /* marcam toate nodurile ca nevizitate */
		vizitate[i] = NEVIZITAT;
	vizitate[nodSursa] = VIZITAT; /* marcam nodul sursa ca vizitat */
//	procesam informatia pt nodSursa;
	printf("%d ", nodSursa);
	enqueue( nodSursa, &Q );
	// nodSursa va fi primul nod scos din coada
	while( !goala( Q ))
	{
		v = dequeue( &Q );
		NodeT* node = G.t[v];
		while (node != NULL) {
			w = node->val;
			if (vizitate[w] == NEVIZITAT)
			{
				vizitate[w] = VIZITAT;
				//procesam informatia pt w;
				printf("%d ", w);
				arr[k++] = w;
				enqueue(w, &Q);
			}
			node = node->next;
		}
	}
			
}

void insereaza(int v, int w, Graf* pG) {
	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	node->val = w;
	node->next = pG->t[v];
	pG->t[v] = node; //add first
}

void citesteGraf(FILE * f, Graf * pG) {
	fscanf(f, "%d", &pG->n);    // citeste nr. de varfuri

	// Alocam dinamic tabloul de liste de adiacenta de dimensiune n:
	pG->t = calloc(pG->n, sizeof(NodeT*));
	if (pG->t == NULL) printErr();  // alocare esuata

	int i;
	for (i = 0; i < pG->n; i++) {
		// initializam (liste vide)
		pG->t[i] = NULL;
	}

	int v, w;
	// citeste pe rand perechi (v, w) si memoreaza arcul/muchia in listele de adiacenta:
	while (fscanf(f, "%d%d", &v, &w) == 2) {
		/// TODO: memoreaza arcul/muchia in listele de adiacenta
		//insereaza(w, v, pG);
		insereaza(v, w, pG);

	}
}

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

	int v;
	printf("Numarul de noduri: %d. \nDati nodul sursa: ", G.n);
	scanf("%d", &v);

	bfs(G, v);

	return 0;
}
