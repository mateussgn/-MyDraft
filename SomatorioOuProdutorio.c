#include <stdio.h>

int serie1(float precisao) {
	return 0;
}
int serie2(float precisao) {
	return 0;
}
int main() {
	float precisao;
	printf("Digite a precisao: ");
	scanf_s("%f", &precisao);
	if (serie1(precisao) > serie2(precisao))
		printf("Serie 1 converge mais rapido! \n");
	else
		printf("Serie 2 converge mais rapido! \n");
	system("pause");
}