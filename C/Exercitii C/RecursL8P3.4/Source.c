#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void invers(int n)
{
	char c[50];
	scanf("%s", c);

	if (n > 1)
		invers(n - 1);

	printf("%s\n", c);
}

void main()

{

	int n;
	printf("n=");
	scanf("%d", &n);
	invers(n);

	printf("\n");
	system("pause");
	return 0;
}