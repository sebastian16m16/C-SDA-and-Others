#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	double z, x, y;
	printf("x la putrea y: ");
	scanf("%lf%lf", &x, &y);

	z = pow(x, y);
	printf("%lf la puterea %lf este %lf\n", x, y, z);

	system("pause");
	return 0;
}