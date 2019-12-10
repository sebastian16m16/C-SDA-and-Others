#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *next;
} NodeT;

NodeT *search(NodeT *head, int givenKey) {
	//TODO: search the given key and return the first node containing it or NULL

	NodeT *p = head;
	while (p != NULL) {
		if (p->key == givenKey) {
			return p;
		}
		else {
			p = p->next;
		}
	}
	return NULL;
}

void print_list(NodeT *head) {
	//TODO: print list keys
	NodeT *p = head;

	if (p == NULL) {
		printf("Empty list! \n");
	}
	else {
		while (p != NULL) {
			printf("%d ", p->key);
			p = p->next;
		}
		printf("\n");
	}

}

void insert_first(NodeT **head, NodeT **tail, int givenKey) {
	//TODO: insert the given key in the first position of the list given by head and tail;
	NodeT * p = (NodeT*)malloc(sizeof(NodeT));
	p->key = givenKey;
	if (*head == NULL) {
		
		p->next = NULL;
		*head = *tail = p;
	}
	else {
		p->next = *head;
		*head = p;
	}
}

void insert_last(NodeT **head, NodeT **tail, int givenKey) {
	//TODO: insert the given key in the last position of the list given by head and tail;
	NodeT * p = (NodeT*)malloc(sizeof(NodeT));
	p->key = givenKey;
	p->next = NULL;

	if (*tail == NULL) {

		p->next = NULL;
		*head = *tail = p;
	}
	else {
		(*tail) -> next = p;
		*tail = p;
	}
}

void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey) {
	//TODO: insert the given key after afterKey, in list given by head and tail;
	NodeT * p = (NodeT*)malloc(sizeof(NodeT));
	p->key = givenKey;

	NodeT *q = search(*head, afterKey);
	if (q != NULL) {
		p->next = q->next;
		q->next = p;

		if (q == *tail) *tail = p;
	}
}

void delete_first(NodeT** head, NodeT** tail) {
	//TODO: delete first list element
	NodeT *p;
	if (*head != NULL)
	{ /* non-empty list */
		p = *head;
		(*head) = (*head)->next;
		/* free up memory */
		free(p);
		if (*head == NULL)
			/* list is now empty */
			*tail = NULL;
	}
}

void delete_last(NodeT** head, NodeT** tail) {
	//TODO: delete last list element
	NodeT *q, *q1;
	q1 = NULL; /* initialize */
	q = *head;
	if (q != NULL)
	{ /* non-empty list */
		while (q != *tail)
		{ /* advance towards end */
			q1 = q;
			q = q->next;
		}
		if (q == *head)
		{ /* only one node */
			*head = *tail = NULL;
		}
		else
		{ /* more than one node */
			q1->next = NULL;
			*tail = q1;
		}
		free(q);
	}
}

void delete_key(NodeT** first, NodeT** last, int givenKey) {
	//TODO: delete element having given key
	NodeT *q, *q1;
	q1 = NULL; /* initialize */
	q = *first;
	/* search node */
	while (q != NULL)
	{
		if (q->key == givenKey) break;
		q1 = q;
		q = q->next;
	}
	if (q != NULL)
	{ // found a node with supplied key
		if (q == *first)
		{ /* is the first node */
			(*first) = (*first)->next;
			free(q); /* release memory */
			if (*first == NULL) *last = NULL;
		}
		else
		{ /* other than first node */
			q1->next = q->next;
			if (q == *last) *last = q1;
			free(q); /* release memory */
		}
	}
}

int main() {
	NodeT *first = NULL;
	NodeT *last = NULL;

	//perform several insertions
	insert_first(&first, &last, 4);
	insert_first(&first, &last, 1);
	insert_last(&first, &last, 3);

	//search for two distinct keys...
	
	int toSearch = 2;
	NodeT *foundNode = search(first, toSearch);
	if (foundNode == NULL) {
		printf("Node %d not found!\n", toSearch);
	}
	else {
		printf("%d found!\n", foundNode->key);
	}

	toSearch = 3;
	foundNode = search(first, toSearch);
	if (foundNode == NULL) {
		printf("Node %d not found!\n", toSearch);
	}
	else {
		printf("%d found!\n", foundNode->key);
	}

	//perform some insertions
	insert_after_key(&first, &last, 4, 22);
	insert_after_key(&first, &last, 3, 25);

	//print list contents
	print_list(first);
	

	//perform some deletions
	delete_first(&first, &last);
	print_list(first);
	delete_last(&first, &last);
	print_list(first);

	delete_key(&first, &last, 22);
	delete_key(&first, &last, 8);

	//print list contents
	print_list(first);
	


	//TODO: place here code to delete all list
	while (first != NULL) {
		NodeT *p = first;
		first = first->next;
		free(p);
	}
	last = NULL;

	//print list contents
	print_list(first);
	

	printf("\n");
	system("pause");
	return 0;
}