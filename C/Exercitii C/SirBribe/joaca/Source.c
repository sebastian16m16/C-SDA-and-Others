#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void minimumBribes(int* q) {
	int cnt = 0;
	int test = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (q[i] > q[j]) {
				test++; //  8 5 1 3 7 6 2
				if (test > 2) {
					printf("Too chaotic\n");
					return;
				}

			}
		}
		if (test > 2) {
			break;
		}
		cnt = cnt + test;
		test = 0;

	}
	if (test <= 2) {
		printf("%d\n", cnt);
	}
		
	

}



int main() {
	int q[8] = { 1, 2, 3, 7,5, 8, 6, 4 };
	minimumBribes(q);

	system("pause");
	return 0;
}