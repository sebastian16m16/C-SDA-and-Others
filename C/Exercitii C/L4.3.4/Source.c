#include <stdio.h>
#include <stdlib.h>


int main() {

	int n;
	printf("ENTER NR: ");
	scanf("%d", &n);

	int p = 1;

	while (p <= n) {
		if (p == 2 || p == 3 || p == 5) {
			printf("%d ", p);
		}
		if (p % 2 != 0 && p%3 !=0 && p%5 != 0) {
			
			printf("%d ", p);
		}
		p++;
	}

	printf("\n");
	system("pause");
	return 0;
}