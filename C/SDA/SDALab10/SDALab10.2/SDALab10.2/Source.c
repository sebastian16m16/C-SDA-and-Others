#include <stdio.h>
#define MAX 1000

int n, a[MAX], lmax[MAX], indexPrec[MAX];
int maxLmax, indexMaxLmax;
void read();
void DP();
void write();
int main()
{
	read();
	DP();
	write();
	return 0;
}
void read()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
}
void DP()
{
	for (int i = 0; i < n; i++) {
		lmax[i] = 1;
		indexPrec[i] = i;
	}
	maxLmax = 1;
	indexMaxLmax = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] >= a[j] && 1 + lmax[j] > lmax[i]){
				lmax[i] = 1 + lmax[j];
				indexPrec[i] = j;
				if (lmax[i] > maxLmax) {
					maxLmax = lmax[i];
					indexMaxLmax = i;
				}
			}
		}

	}

}

void recAfis(int index) {
	if (index != indexPrec[index])
		recAfis(indexPrec[index]);
	printf("%d ", a[index]);
	
}

void write()
{
	printf("%d \n", maxLmax);
	recAfis(indexMaxLmax);
}
