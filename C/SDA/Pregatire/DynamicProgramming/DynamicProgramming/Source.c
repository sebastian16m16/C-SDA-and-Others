#include <stdio.h>
#define MAX 1000

int s, n, monede[MAX], combinatii[MAX + 1];
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
	scanf("%d", &n); //numar monede
	scanf("%d", &s); //suma
	for (i = 0; i < n; i++)
		scanf("%d", &monede[i]);
}
void DP()
{
	//TO DO
	//Your code goes here
	for (int i = 0; i <= s; i++)
		combinatii[i] = 0;
	combinatii[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = monede[i]; j <= s; j++)
			combinatii[j] += combinatii[j - monede[i]];
	}
}
void write()
{
	printf("%d \n", combinatii[s]);
	for (int i = 0; i <= s; i++)
		printf("%d ", combinatii[i]);
}
