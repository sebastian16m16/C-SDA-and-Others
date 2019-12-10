#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int key;
	struct node* next;
	struct node* prev;
} NodeDL;


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
	//TODO insert code here
	NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
	node->key = givenKey;

	NodeDL* afterNode = search(*L, afterKey);

	if (afterNode != NULL)
	{
		if (afterNode == L->first && L->first != L->last) {
			node->prev = NULL;
			node->next = L->first;
			L->first->prev = node;
			L->first = node;
		}
		else if (afterNode == L->last && L->last != L->first) {
			node->next = NULL;
			node->prev = L->last;
			L->last->next = node;
			L->last = node;
		}
		else
		{
			node->prev = afterNode;
			node->next = afterNode->next;
			afterNode->next->prev = node;
			afterNode->next = node;
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
	NodeDL* foundNode = search(L, toSearch);
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
	print_forward(L);
	delete_last(&L);
	print_forward(L);
	delete_key(&L, 4);
	print_forward(L);
	delete_key(&L, 15);
	print_forward(L);

	/* print list contents */
	print_forward(L); // 2 3 6
	print_backward(L); // 6 3 2

	delete_key(&L, 2);
	delete_key(&L, 6);

	/* print list contents */
	print_forward(L); // 3
	print_backward(L); // 3

	return 0;
}