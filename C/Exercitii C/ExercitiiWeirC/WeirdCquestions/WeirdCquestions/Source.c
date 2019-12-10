#include <stdlib.h>
#include <stdio.h>

int main() {

	char array[5] = "knot";
	char* ptr = &array[1];
	char* ptr1 = ptr + 3;
	*ptr1 = 101;

	for(int i=0; i<4; i++)
		printf("%c", *ptr++);

	return 0;
}