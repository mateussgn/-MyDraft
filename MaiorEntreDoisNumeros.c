#include <stdio.h>

int max2(int a, int b) {
	int resultMax2;
	if (a > b) resultMax2 = a;
	else resultMax2 = b;
	return resultMax2;
}

int main() {
	int maior, entrada;
	scanf_s("%d, %d, %d", &maior, &entrada);
	while (entrada != 0) {
		maior = max2(maior, entrada);
		printf("O maior ate agora é: %d \n", maior);
		scanf_S("%d", &entrada);
	}
	printf("Maior de todos: %d \n", maior);
}