#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
	int id; /* numele nodului */
	/* alte informatii  utile */
	struct node_type *left, *right;
} NodeT;

void fatalError(const char *msg)
{
	printf(msg);
	printf("\n");
	exit(1);
}

void postorder(NodeT *p) {
	//scrieti codul pentru parcurgerea in postordine
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->id);
	}

}

void inorder(NodeT *p) {
	//scrieti codul pentru parcurgerea in inordine
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d ", p->id);
		inorder(p->right);
	}
}

int leaf_node(NodeT *node) {
	//scrieti codul pentru calcularea numarului de frunze ale unui arbore
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL) {
		printf("%d ", node->id);
		return 1;
	}
	return leaf_node(node->left) + leaf_node(node->right);
	
}

int noduri_interne(NodeT *node) {
	//scrieti codul pentru calcularea numarului de noduri interne ale unui
	if(node == NULL)
		return 0;
	if (node->left != NULL || node->right != NULL)
		return 1 + noduri_interne(node->left) + noduri_interne(node->right);
	return 0;
}

int inaltime(NodeT *node) {
	//scrieti codul pentru calcularea inaltimii unui arbore
	if(node==NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 0;
	int is = inaltime(node->left);
	int id = inaltime(node->right);
	return 1 + ((is > id) ? is : id);
}


void preorder(NodeT *p)
/*
 * p = nodul curent;
*/
{
	if (p != NULL)
	{
		printf("%d ", p->id);
		preorder(p->left);
		preorder(p->right);
	}
}
//creaza un arbore binar prin citirea de la tastatura
NodeT *createBinTree(int branch, NodeT *parent)
{
	NodeT *p;
	int id;

	/* read node id */
	if (branch == 0)
		printf("Valoarea pentru radacina [0 pt null] =");
	else if (branch == 1)
		printf("Fiul stang al nodului cu valoarea %d [0 pt null] =",
			parent->id);
	else
		printf("Fiul drept al nodului cu valoarea %d [0 pt null] =",
			parent->id);
	scanf("%d", &id);
	if (id == 0)
		return NULL;
	else
	{
		/* construim nodul la care pointeaza p */
		p = (NodeT *)malloc(sizeof(NodeT));
		if (p == NULL) {
			printf("Nu mai avem memorie in createBinTree");
			exit(1);
		}
		/* fill in node */
		p->id = id;
		p->left = createBinTree(1, p);
		p->right = createBinTree(2, p);
	}
	return p;
}
NodeT *createBinTreeFromFile(FILE* f)
{
	NodeT *p;
	int c;

	/* se citeste id-ul nodului */
	fscanf(f, "%d", &c);
	if (c == 0)
		return NULL; /* arbore vid, nu facem nimic */
	else /* else inclus pentru claritate */
	{ /* construim nodul la care pointeaza p */
		p = (NodeT *)malloc(sizeof(NodeT));
		if (p == NULL)
			fatalError("Nu mai avem memorie in createBinTree");
		/* se populeaza nodul */
		p->id = c;
		p->left = createBinTreeFromFile(f);
		p->right = createBinTreeFromFile(f);
	}
	return p;
}

NodeT* search(NodeT* node, int key) {
	if (node == NULL)
		return NULL;
	if (node->id == key)
		return node;
	NodeT* rs = search(node->left, key);
	if (rs != NULL)
		return rs;
	return search(node->right, key);

}

NodeT* adancime(NodeT* node, int key, int nivel) {
	if (node == NULL)
		return -1;
	if (node->id == key)
		return nivel;
	int ads = adancime(node->left, key, nivel + 1);
	if (ads != -1)
		return ads;
	return adancime(node->right, key, nivel + 1);

	
	return 0;
}

NodeT* creBalBinTree(int nbOfNodes) {
	NodeT* p;

}


int main()
{
	NodeT *root;
	FILE *f = fopen("ArboreBinar.txt", "r");
	if (!f) {
		printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
		return -1;
	}
	root = createBinTreeFromFile(f);
	fclose(f);


	printf("\nParcurgere in PREORDINE: ");
	preorder(root);
	printf("\n");

	//TODO
	printf("Parcurgere in POSTORDINE: ");
	postorder(root);
	printf("\n");

	printf("Parcurgere in INORDINE: ");
	inorder(root);
	printf("\n");

	printf("Frunzele sunt: ");
	int nr_frunze = leaf_node(root);
	printf("\nNumarul de frunze este %d\n", nr_frunze);//3

	printf("Noduri interne = %d \n", noduri_interne(root));//5

	
	int nodeKey = 4;
	NodeT* p = search(root, nodeKey);
	if (p != NULL) {
		printf("Inaltimea nodului %d este %d\n",nodeKey, inaltime(p));
	}
	else
		printf("Negasit!\n");

	int x = adancime(root, nodeKey, 0);//2
	if (x != -1)
		printf("Adancimea nodului %d este %d \n",nodeKey, x);
	else
		printf("Negasit!\n");


	printf("\n");
	system("pause");
	return 0;
}
