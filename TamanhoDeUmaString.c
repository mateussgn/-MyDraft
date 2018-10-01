#include <stdio.h>

int main() {
	char c[20];
	scanf_s("%19[^\n]", c);
	printf("Li frase de tamanho %d \n", tam(c));
	return 0;
}
int tam(char f[]) {
	int i;
	for (i = 0; f[i] != '\0'; i++);
	return i;
}