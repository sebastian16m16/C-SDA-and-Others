#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* next;
} NodeT;

NodeT* search(NodeT* head, int givenKey) {
	//TODO: search the given key and return the first node containing it or NULL
	if (head == NULL)
		return NULL;
	
	NodeT* node = head;

	while (node != NULL) {
		if (node->key == givenKey)
			return node;
		node = node->next;
	}
	return NULL;
}

void print_list(NodeT* head) {
	//TODO: print list keys
	NodeT* node = head;

	if (node == NULL)
		printf("Empty list! \n");
	else
	{
		while (node != NULL) {
			printf("%d ", node->key);
			node = node->next;
		}
		printf("\n");
	}
	
}

void insert_first(NodeT** head, NodeT** tail, int givenKey) {
	//TODO: insert the given key in the first position of the list given by head and tail;

	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	node->key = givenKey;

	if (*head == NULL) {
		node->next = NULL;
		*head = *tail = node;
	}
	else
	{
		node->next = *head;
		*head = node;
	}

	
}

void insert_last(NodeT** head, NodeT** tail, int givenKey) {
	//TODO: insert the given key in the last position of the list given by head and tail;
	
	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	node->key = givenKey;
	node->next = NULL;

	if (*head == NULL) {
		*tail = *head = node;
	}
	else {
		(*tail)->next = node;
		*tail = node;
	}
}

void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey) {
	//TODO: insert the given key after afterKey, in list given by head and tail;

	NodeT* node = (NodeT*)malloc(sizeof(NodeT));
	NodeT* after = search(*head, afterKey);
	node->key = givenKey;

	if (after != NULL) {
		node->next = after->next;
		after->next = node;

		if (after == *tail) {
			
			*tail = node;
			int i = 0;
		}
	}


}

void delete_first(NodeT** head, NodeT** tail) {
	//TODO: delete first list element
	NodeT* node;
	if (*head != NULL) {

		node = *head;
		(*head) = (*head)->next;
		free(node);

		if (*head == NULL)
			* tail = NULL;
		
	}
}

void delete_last(NodeT** head, NodeT** tail) {
	//TODO: delete last list element
	NodeT* node = *head;
	NodeT* prev = NULL;

	if (*head != NULL) {

		while (node != *tail) {
			prev = node;
			node = node->next;
		}
		
		if (node == *head) {
			*head = *tail = NULL;
		}
		else
		{
			prev->next = NULL;
			*tail = prev;
			
		}

		free(node);
	}
}

void delete_key(NodeT** head, NodeT** tail, int givenKey) {
	//TODO: delete element having given key
	NodeT* node = *head;
	NodeT* prev = NULL;

	if (*head != NULL) {
		while (node->key != givenKey) {
			prev = node;
			node = node->next;

			if (node == NULL)
				break;
		}

		if (node == *tail) {
			prev->next = NULL;
			*tail = prev;
		}
		else  if(node != NULL)
		{
			prev->next = node->next;
		}

		free(node);

	}
	

	
}

int main() {
	NodeT* first = NULL;
	NodeT* last = NULL;

	//perform several insertions
	insert_first(&first, &last, 4);
	insert_first(&first, &last, 1);
	insert_first(&first, &last, 5);
	insert_first(&first, &last, 8);
	insert_last(&first, &last, 3);

	//search for two distinct keys...
	int toSearch = 2;
	NodeT* foundNode = search(first, toSearch);
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
	delete_last(&first, &last);
	delete_key(&first, &last, 22);
	delete_key(&first, &last, 8);

	//print list contents
	print_list(first);


	//TODO: place here code to delete all list
	/*....*/

	//print list contents
	print_list(first);

	return 0;
}