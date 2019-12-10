#include <stdio.h>
#include <stdlib.h>

int n = 4;
int x[100];

void afisare(int k) {
	for (int i = 1; i <= k; i++)
		printf("%d ", x[i]);
	
	printf("\n");
}

int phi(int k) {
	for (int i = 1; i < k; i++) 
		if (x[i] == x[k])
			return 0;
	return 1;
}

void backtracking(int k) {
	for (int i = 1; i <= n; i++) {
		x[k] = i;
		afisare(k);
		if (phi(k)) {
			if (k < n) {
				backtracking(k + 1);
			}
			else
			{
				printf(" - Solution\n");
			}
		}
	}
}

int main() {


	backtracking(1);
	return 0;
}