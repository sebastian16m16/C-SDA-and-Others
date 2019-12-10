#include <stdio.h>
#include <stdlib.h>
#define M 7 //dimensiunea tabelei de dispersie

typedef struct node {
	int val;
	struct node* next;
}NodeT;

int hFunction(int key) {
	return abs(key) % M;
}

void insert(NodeT* hTable[M], int key) {
	NodeT* elem = (NodeT*)malloc(sizeof(NodeT));
	if (!elem)
		return;
	elem->val = key;
	int poz = hFunction(key);
	elem->next = hTable[poz];
	hTable[poz] = elem;
}


NodeT* search(NodeT* hTable[M], int key) {
	int poz = hFunction(key);
	NodeT* p = hTable[poz];
	while (p != NULL) {
		if (p->val == key)
			return p;
		p = p->next;
	}

	return NULL;
}


void deleteKey(NodeT* hTable[M], int key) {
	//TODO: delete element having given key
	NodeT* q, * q1;
	q1 = NULL; /* initialize */
	q = hTable[hFunction(key)];
	/* search node */
	while (q != NULL)
	{
		if (q->val == key) break;
		q1 = q;
		q = q->next;
	}

	if (q != NULL)
	{ // found a node with supplied key
		if (q == hTable[hFunction(key)])
		{ /* is the first node */
			(hTable[hFunction(key)]) = (hTable[hFunction(key)])->next;
			free(q); /* release memory */
			
		}
		else
		{ /* other than first node */
			q1->next = q->next;
			
			free(q); /* release memory */
		}
	}
}

//afisarea tuturor elmentelor din tebela de dispersie
void showAll(NodeT* hTable[M]) {
	int i;
	for (i = 0; i < M; i++)
	{
		printf(" %d :", i);
		//verificam daca la slotul i am adaugat ceva
		if (hTable[i] != NULL)
		{

			NodeT* p;
			p = hTable[i];
			while (p != NULL)
			{
				printf(" %d ", p->val);
				p = p->next;
			}
		}
		printf("\n");
	}
	printf("\n");
}


int main() {

	//initializare
	NodeT* hTable[M];
	for (int i = 0; i < M; i++) {
		hTable[i] = NULL;
	}

	//test inserare
	int vals[] = { 36, 18, 6, 43, 72, 10, 5, 15 };
	for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
		insert(hTable, vals[i]);
	showAll(hTable);

	// 0:
	// 1: 15 43 36
	// 2: 72
	// 3: 10
	// 4: 18
	// 5: 5
	// 6: 6
	int searchKey = 50;
	if (search(hTable, searchKey))
		printf("%d gasit!\n", searchKey);
	else
		printf("%d negasit!\n", searchKey);

	//test stergere
	int todel[] = { 43, 36, 10, 61, -5 };
	for (int i = 0; i < sizeof(todel) / sizeof(int); i++)
		deleteKey(hTable, todel[i]);
	showAll(hTable);

	// 0:
	// 1: 15
	// 2: 72
	// 3:
	// 4: 18
	// 5: 5
	// 6: 6

	return 0;
}
