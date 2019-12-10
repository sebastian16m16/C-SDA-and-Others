#include <stdio.h>
#include <stdlib.h>

int n = 7;
int p = 4;
int x[100];
int nrSol;

void afisare(int k) {
	for (int i = 1; i <= k; i++)
		printf("%d ", x[i]);

	printf("\n");
}

int phi(int k) {
	if (k > 1 && x[k] <= x[k - 1])
		return 0;
	return 1;
}

void backtracking(int k) {
	for (int i = 1; i <= n; i++) {
		x[k] = i;
		if (phi(k)) {
			if (k < p) {
				backtracking(k + 1);
			}
			else
			{
				afisare(k);
				nrSol++;

			}
		}
	}
}

int main() {


	backtracking(1);
	printf("Numar solutii: %d", nrSol);
	return 0;
}