#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void readProcess(char* numeFis,  char * numere, int *n) {


	FILE *pf = fopen(numeFis, "r");

	if (pf == NULL) {
		printf("Couldn't open File");
		exit(1);
	}

	int x;
	char ch, lastchar;

	*n = 0;

	while (1) {

		if (fscanf(pf, "%c", &ch) != 1) {
			break;
		}
		fseek(pf, -1, SEEK_CUR);
		do {

			fscanf(pf, "%c", &ch);
			if (ch == ' ' || ch == '\n') {
				numere[*n] = ' ';
				(*n)++;
				do {
					fscanf(pf, "%c", &ch);
				} while (ch == ' ');
				fseek(pf, -1, SEEK_CUR);
			}
			else {
				numere[*n] = ch;
				lastchar = ch;
				(*n)++;

			}

		} while (ch != '|');


	}

	fclose(pf);
}

void getSume(char* numere, int * sume, int n) {

	char ch;
	int count = 0;
	int sum = 0, i = 0;

	while (count != n) {
		do {
			if (numere[count] == '.') {
				count++;
			}
			else {
				sum = sum + numere[count];
				count++;
				ch = numere[count];
			}
		} while (ch != ' ');
		count++;
		sume[i] = sum;
		i++;
	}
}

void writeFile(char* numeFis, char* numere, int n) {

	FILE *pf = fopen(numeFis, "w");

	int sume[999];
	int x = 0, c;

	getSume(numere, sume, n);

	int length = sizeof(sume) / sizeof(sume[0]);

	for (int i = 0; i < length-1; i++){
		for (int j = i+1; j < length; j++) {
			if (sume[i] == sume[j]) {
				x++;
				c = sume[i];
			}
		}
		fprintf(pf, "%d elemente, suma cifrelor %d\n", x, c);
	}

	fflush(pf);
	fclose(pf);

}


int main() {
	
	char numere[1000000];
	int n;
	
	readProcess("numere.txt", numere, &n);
	writeFile("multimi.txt", numere, n);

	system("pause");
	return 0;
}