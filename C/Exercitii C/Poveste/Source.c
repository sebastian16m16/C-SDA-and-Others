#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int x, int k) {
	int t = k;
	static int n = 0;

	if (x <= 0 || k <= 0) {
		printf("%d ", n);
		return 0;
	}
	int r = x % k;
	n += (x%k) ? 1 : 0;
	int l = x / t;
	return x / t + f(x, k - 1);
	t++;
}

int main() {

	printf("%d\n", f(18, 11));
	printf("%d\n", f(100, 3));

	printf("\n");
	system("pause");
	return 0;
}