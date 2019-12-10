#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int key;
	struct node *next;
	struct node *prev;
} NodeDL;


/* define a List structure, consisting of the addresses
 * (pointers) of the first and last elements
 * */
struct list_header {
	NodeDL *first;
	NodeDL *last;
};


void print_forward(struct list_header L) {
	//TODO insert code here
	if (L.first != NULL) {
		NodeDL *p = L.first;
		while (p != NULL) {
			printf("%d ", p->key);
			p = p->next;
		}
	}
	else
		printf("Empty List!");
	printf("\n");
}

void print_backward(struct list_header L) {
	//TODO insert code here
	if (L.last != NULL) {
		NodeDL *p = L.last;
		while (p != NULL) {
			printf("%d ", p->key);
			p = p->prev;
		}
	}
	else
		printf("Empty List!");
	printf("\n");

}

NodeDL *search(struct list_header L, int givenKey) {
	//TODO insert code here
	NodeDL *p = L.first;

	while (p != NULL) {
		if (p->key == givenKey) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}


void insert_first(struct list_header *L, int givenKey) {
	//TODO insert code here
	NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
	p->key = givenKey;
	p->next = L->first;
	p->prev = NULL;
	if (L->first != NULL) {
		L->first->prev = p;
	}
	else {
		L->last = p;
	}
	L->first = p;
}


void insert_last(struct list_header *L, int givenKey) {
	//TODO insert code here
	NodeDL *p = (NodeDL*)malloc(sizeof(NodeDL));
	p->key = givenKey;
	p->next = NULL;
	p->prev = L->last;
	if (L->last != NULL) {
		L->last->next = p;
	}
	else {
		L->first = p;
	}
	L->last = p;
}

void insert_after_key(struct list_header *L, int afterKey, int givenKey) {
	//TODO insert code here
}

void delete_first(struct list_header *L) {
	//TODO insert code here
	if (L->first != NULL) {
		NodeDL *p = L->first;
		L->first = L->first->next;
		if (L->first != NULL) {
			L->first->prev = NULL;
		}
		else
		{
			L->last = NULL;
		}
		free(p);
	}
}

void delete_last(struct list_header *L) {
	//TODO insert code here
	if (L->last != NULL) {
		NodeDL *p = L->last;
		L->last = L->last->prev;
		if (L->last != NULL) {
			L->last->next = NULL;
		}
		else
		{
			L->first = NULL;
		}
		free(p);
	}
}

void delete_key(struct list_header *L, int givenKey) {
	//TODO insert code here
	NodeDL * p = search(*L, givenKey);
	if (p != NULL) {
		if (p->prev != NULL)
			p->prev->next = p->next;
		else
			L->first = p->next;
		if (p->next != NULL)
			p->next->prev = p->prev;
		else
			L->last = p->prev;

		free(p);
	}
}


int main() {
	/* initialize list to empty list */
	struct list_header L = { NULL, NULL };

	/* test insertion operations */
	/* insert some elements at the beginning */
	insert_first(&L, 3);
	insert_first(&L, 4);
	insert_first(&L, 2);
	insert_first(&L, 1);

	/* ... and some at the end */
	insert_last(&L, 6);
	insert_last(&L, 8);

	/* print list contents */
	print_forward(L); // 1 2 4 3 6 8
	print_backward(L); // 8 6 3 4 2 1

	/* test search operation */
	//search for two distinct keys...
	int toSearch = 2;
	NodeDL *foundNode = search(L, toSearch);
	if (foundNode == NULL) {
		printf("Node %d NOT found!\n", toSearch);
	}
	else {
		printf("Node %d found!\n", foundNode->key);
	}

	toSearch = 9;
	foundNode = search(L, toSearch);
	if (foundNode == NULL) {
		printf("Node %d NOT found!\n", toSearch);
	}
	else {
		printf("Node %d found!\n", foundNode->key);
	}


	/* test deletions */
	delete_first(&L);
	delete_last(&L);
	delete_key(&L, 4);
	delete_key(&L, 15);

	/* print list contents */
	print_forward(L); // 2 3 6
	print_backward(L); // 6 3 2

	delete_key(&L, 2);
	delete_key(&L, 6);

	/* print list contents */
	print_forward(L); // 3
	print_backward(L); // 3

	printf("\n");
	system("pause");

	return 0;
}