#include <stdio.h>

int main() {
	int x = 2;
	int *ponteiro = &x;
	printf("x(main) = %d \n", x);
	*ponteiro = 5;
	printf("End. x = %d \n", x);
	getchar();
	return 0;
}