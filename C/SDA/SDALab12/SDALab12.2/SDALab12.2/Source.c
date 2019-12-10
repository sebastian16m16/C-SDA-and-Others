#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int size(int x) {
	if (x < 10)
		return 1;
	return 1 + size(x / 10);
}

void split(int x, int m, int* x1, int* x0) {

	int t = pow10(m);
	*x1 = x / t;
	*x0 = x * t;
}

int pow10(int x) {
	if (x == 0)
		return 1;
	return 10 * pow10(x - 1);
}


int karatsuba(int x, int y) {
	if (x < 10 || y < 10)
		return x * y;
	int m;
	int sx = size(x);
	int sy = size(y);
	m = (sx > sy) ? sx / 2 : sy / 2;

	int x1, x0, y1, y0;
	split(x, m, &x1, &x0);
	split(y, m, &y1, &y0);

	int z0 = karatsuba(x0, y0);
	int z2 = karatsuba(x1, y1);
	int z1 = karatsuba(x1 + x0, y1 + y0) - z2 - z0;

	return z2 * pow10(2 * m) + z1 * pow10(m) + z0;
}

int main() {

	printf("%d", karatsuba(4532, 2341));

	return 0;
}