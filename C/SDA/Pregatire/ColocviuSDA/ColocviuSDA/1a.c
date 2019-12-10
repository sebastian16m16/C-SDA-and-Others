#include <stdlib.h>
#include <stdio.h>
#define M  8

typedef struct node {
	int key;
	struct node* next;
	struct node* prev;
	int status;
} NodeDL;

enum { FREE, OCCUPIED };
/* define a List structure, consisting of the addresses
 * (pointers) of the first and last elements
 * */
struct list_header {
	NodeDL* first;
	NodeDL* last;
};


void print_forward(struct list_header L) {
	//TODO insert code here
	NodeDL* node = L.first;

	while (node != NULL) {
		printf("%d ", node->key);
		node = node->next;
	}
	printf("\n");
}

void print_backward(struct list_header L) {
	//TODO insert code here
	NodeDL* node = L.last;

	while (node != NULL) {
		printf("%d ", node->key);
		node = node->prev;
	}
	printf("\n");
}

NodeDL* search(struct list_header L, int givenKey) {
	//TODO insert code here

	NodeDL* node = L.first;

	while (node != NULL) {
		if (node->key == givenKey)
			break;
		node = node->next;
	}

	if (node != NULL)
		return node;

	return NULL;
}

void insert_first(struct list_header* L, int givenKey) {
	//TODO insert code here

	NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
	node->key = givenKey;
	node->prev = NULL;

	if (L->first != NULL) {
		L->first->prev = node;
		node->next = L->first;
		L->first = node;
	}
	else
	{
		node->next = NULL;
		L->first = L->last = node;
	}
}

void insert_last(struct list_header* L, int givenKey) {
	//TODO insert code here
	NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
	node->key = givenKey;
	node->next = NULL;

	if (L->last != NULL) {
		node->prev = L->last;
		L->last->next = node;
		L->last = node;
	}
	else {
		node->prev = NULL;
		L->first = L->last = node;
	}
}

void insert_after_key(struct list_header* L, int afterKey, int givenKey) {
	////TODO insert code here
	//NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
	//node->key = givenKey;

	//NodeDL* afterNode = search(*L, afterKey);

	//if (afterNode != NULL)
	//{
	//	if (afterNode == L->first && L->first != L->last) {
	//		node->prev = afterNode;
	//		node->next = L->first;
	//		L->first->prev = node;
	//		L->first = node;
	//	}
	//	else if (afterNode == L->last && L->last != L->first) {
	//		node->next = NULL;
	//		node->prev = L->last;
	//		L->last->next = node;
	//		L->last = node;
	//	}
	//	else
	//	{
	//		node->prev = afterNode;
	//		node->next = afterNode->next;
	//		afterNode->next->prev = node;
	//		afterNode->next = node;
	//	}
	//}





	//TODO: insert the given key after afterKey, in list given by head and tail;
	NodeDL* p = (NodeDL*)malloc(sizeof(NodeDL));
	p->key = givenKey;

	NodeDL* q = search(*L, afterKey);
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		p->prev = q;

		if (q == L->last) {
			p->prev = L->last;
			L->last->next = p;
			L->last = p;
		}
	}
}

void delete_first(struct list_header* L) {
	//TODO insert code here
	NodeDL* node = L->first;

	if (L->first != NULL) {
		if (L->first == L->last) {
			L->first = L->last = NULL;
		}
		else {

			node->next->prev = NULL;
			L->first = node->next;

			node->next = NULL;
			node->prev = NULL;
		}
		free(node);
	}
}

void delete_last(struct list_header* L) {
	//TODO insert code here

	NodeDL* node = L->last;

	if (L->last != NULL) {
		if (L->last == L->first) {
			node->next = NULL;
			node->prev = NULL;
			L->first = L->last = NULL;
		}
		else {
			node->prev->next = NULL;
			L->last = node->prev;
			node->next = NULL;
			node->prev = NULL;
		}

		free(node);
	}

}

void delete_key(struct list_header* L, int givenKey) {
	//TODO insert code here
	NodeDL* node = search(*L, givenKey);

	if (node != NULL) {
		if (node == L->first && node != L->last) {
			node->next->prev = NULL;
			L->first = node->next;
			node->next = NULL;
		}
		else if (node == L->last && node != L->first) {
			node->prev->next = NULL;
			L->last = node->prev;
			node->prev = NULL;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		free(node);
	}
}

void insertArr(struct list_header* L, int givenKey) {

	if (L->first == NULL) {
		insert_first(L, givenKey);
	}
	else
	{

		NodeDL* node = L->last;

		while (node != NULL) {
			if (givenKey > node->key || givenKey == node->key) {
				insert_after_key(L, node->key, givenKey);
			}
			if (givenKey < L->first->key) {
				insert_first(L, givenKey);
			}
			
			node = node->prev;
		}
	}
}


//int hFunction(int key) {
//	return (key * key) % M;
//}
//
//void insert_key(int k, NodeDL* T, int m, int function)
//{
//	int i;
//	for (i = 0; i < m; i++) {
//		int h = function;
//		if (T[h].status == FREE) {
//			T[h].status = OCCUPIED;
//			T[h].key = k;
//			return;
//		}
//
//	}
//	printf("Nu putem insera elementul %d!\n", k);
//}

/*
void afisare(NodeDL* T, int m)
{
	printf("\n\nTabela de dispersie este \n");
	for (int i = 0; i < m; i++)
	{
		if (T[i].status == OCCUPIED)
			printf("T[%d]=%d\n", i, T[i].key);
		else
			printf("T[%d]= --\n", i);
	}
}
	*/
int main() {
	/* initialize list to empty list */
	struct list_header L = { NULL, NULL };

	int arr[6] = { 8, 10, 5, 8, 6, 9 };

	for (int i = 0; i < 6; i++) {
		 insertArr(&L, arr[i]);
	 }
	

	print_backward(L);

	/*
	//NodeDL tabela[M];

	//NodeDL* T = (NodeDL*)malloc(M * sizeof(NodeDL));

	 


	 for (int i = 0; i < sizeof(tabela) / sizeof(NodeDL); i++)
		 insert_key(arr[i], T, M, hFunction);
	 afisare(T, M);*/

	return 0;
}