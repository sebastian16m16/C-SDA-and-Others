#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSir(int n, int * sir) {
	int size = sizeof(sir) / sizeof(sir[0]);

	sir[size] = n;
}

int main() {

	int capacity, size, element;
	printf("Capacity: ");
	scanf("%d", &capacity);
	printf("Size: ");
	scanf("%d", &size);

	int *sir;
	if ((sir = (int *) malloc(capacity*sizeof(int)) == NULL)) {
		printf("Memorie insuficienta!\n");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		printf("Sir[%d]: ", i);
		scanf("%d", &element);
		addSir(element, sir);

		for (int j = 0; j < size; j++)
			printf("%d ", sir[j]);

	}

	printf("\n");
	system("pause");
	return 0;
}