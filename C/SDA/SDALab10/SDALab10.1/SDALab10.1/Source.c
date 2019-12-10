#include <stdio.h>
#define MAX 1000

int s, n, monede[MAX], nrmin[MAX + 1], valAdaug[MAX + 1];
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
	scanf("%d", &s);
	for (i = 0; i < n; i++)
		scanf("%d", &monede[i]);
}
void DP()
{
	//TO DO
	//Your code goes here
	for (int i = 0; i <= s; i++)
		nrmin[i] = s;	//infinit
	nrmin[0] = 0;

	for (int i = 1; i <= s; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= monede[j] && 1 + nrmin[i - monede[j]] < nrmin[i]) {
				nrmin[i] = 1 + nrmin[i - monede[j]];
				valAdaug[i] = monede[j];
			}
		}
	}

}
void write()
{
	printf("%d \n", nrmin[s]);
	int t = s;
	while (t != 0) {
		printf("%d ", valAdaug[t]);
		t -= valAdaug[t];
	}
}
