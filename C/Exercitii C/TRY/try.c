#include <stdio.h>
#include <stdlib.h>


typedef struct NodeT {
	int key;
	struct NodeT *left;
	struct NodeT *right;
} NodeT;


NodeT* insertNode(NodeT *root, int key) {
	NodeT* p = (NodeT*)malloc(sizeof(NodeT));

	p->key = key;
	p->left = p->right = NULL;

	if (root == NULL)
		return p;
	NodeT* q = root;
	while (1) {
		if (key < q->key) {
			if (q->left == NULL) {
				q->left = p;
				return root;
			}
			q = q->left;
		}
		else
		{
			if (q->right == NULL) {
				q->right = p;
				return root;
			}
			q = q->right;
		}
	}
}


NodeT* searchKey(NodeT *root, int key) {
	if (root == NULL)
		return NULL;
	if (root->key == key)
		return root;
	if (key < root->key)
		return searchKey(root->left, key);
	return searchKey(root->right, key);
}

NodeT *findMin(NodeT *root) {

}

NodeT *findMax(NodeT *root) {

}

NodeT* succesor(NodeT *root, NodeT *node) {

}

NodeT* predecesor(NodeT *root, NodeT *node) {

}

NodeT *deleteKey(NodeT *root, int key) {

}

void inOrder(NodeT *root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->key);
		inOrder(root->right);
	}
}

void preOrder(NodeT *root) {
	if (root != NULL) {
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(NodeT *root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->key);
	}
}

void prettyPrint(NodeT *root, int level) {
	if (root != NULL) {
		prettyPrint(root->right, level + 1);
		for (int i = 0; i < level; i++)
			printf("    ");
		printf("%d\n", root->key);
		prettyPrint(root->left, level + 1);
	}
}

int main() {

	NodeT *root = NULL;
	NodeT *p;

	int n = 11;
	int keys[] = { 15, 6, 18, 17, 20, 3, 7, 2, 4, 13, 9 };

	root = insertNode(root, keys[0]);

	for (int i = 1; i < n; i++) {
		root = insertNode(root, keys[i]);
	}

	printf("\nPreorder listing\n");
	preOrder(root);
	printf("\nInorder listing\n");
	inOrder(root);
	printf("\nPostorder listing\n");
	postOrder(root);
	printf("\n\n");
	prettyPrint(root, 0);

	int key = 13;
	p = searchKey(root, key);
	if (p != NULL) {
		printf("\nNod cu cheia = %d gasit\n", key);
		NodeT *m = findMin(p);
		printf("Minimul din subarborele care are ca radacina nodul %d este %d \n", p->key, m->key);
	}
	else
		printf("Nodul NU a fost gasit \n");

	NodeT *s = succesor(root, p);
	if (s != NULL) {
		printf("Nod cu cheia = %d are sucesor pe %d\n", p->key, s->key);
	}
	else
		printf("Nodul NU are succesor !\n");

	NodeT *q = predecesor(root, p);
	if (q != NULL) {
		printf("Nod cu cheia = %d are predecesor pe %d\n", p->key, q->key);
	}
	else
		printf("Nodul NU are predecesor !\n");


	key = 15;
	printf("Nodul de sters este: %d\n", key);
	root = deleteKey(root, key);
	inOrder(root);


	// printf("\n");
	// system("pause");
	return 0;
}