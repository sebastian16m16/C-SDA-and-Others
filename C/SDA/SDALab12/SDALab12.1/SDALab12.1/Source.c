#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void merge_sort(int* a, int p, int q) {
	if (p < q) {
		int m = (p + q) / 2;
		merge_sort(a, p, m);
		merge_sort(a, m + 1, q);
		int* b = (int*)malloc((q - p + 1) * sizeof(int));
		int k = 0;
		int i = p;
		int j = m + 1;

		while (i <= m && j <= q) {
			if (a[i] < a[j]) {
				b[k++] = a[i++];
			}
			else
				b[k++] = a[j++];
		}
		while (i <= m)
			b[k++] = a[i++];
		while (j <= q)
			b[k++] = a[j++];
		for (int i = 0; i < k; i++)
			a[p + i] = b[i];

		free(b);
   }
}

int main() {
	int numbers[] = { 4, 9, 3, 1, 5, 7, 8, 6, 2 };
	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int n = (int)(sizeof(numbers) / sizeof(int));
	merge_sort(numbers, 0, n - 1);
	for (int i = 0; i < n; i++) {
		assert(numbers[i] == expected[i]);
	}
	return 0;
}