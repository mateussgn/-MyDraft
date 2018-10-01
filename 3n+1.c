#include <stdio.h>

int main() {
	int numero1, numero2, numero3, numero4, numero5, numero6, numero7, numero8;

	printf("Digite dois numeros: \n");
	scanf("%d %d ", &numero1, &numero2);
	scanf_s("%d %d", &numero3, &numero4);
	scanf_s("%d %d", &numero5, &numero6);
	scanf_s("%d %d", &numero7, &numero8);

	cicloMaximo(numero1, numero2);
	cicloMaximo(numero3, numero4);
	cicloMaximo(numero5, numero6);
	cicloMaximo(numero7, numero8);
	
	system("pause");
	return 0;
}
int cicloMaximo(int primeiroNumero, int segundoNumero) {
	int cicloAtual, resultado;
	int maior = 0;
	int menor = 0;
	int cicloAnterior = 0;

	if (primeiroNumero > segundoNumero) {
		maior = primeiroNumero;
		menor = segundoNumero;
	}
	else {
		maior = segundoNumero;
		menor = primeiroNumero;
	}
	while (menor <= maior) {
		cicloAtual = 1;
		resultado = menor;
		while (resultado != 1) {
			if ((resultado % 2) == 0) {
				resultado /= 2;
			}
			else {
				resultado = (resultado * 3) + 1;
			}
			cicloAtual++;
		}
		if (cicloAnterior < cicloAtual) {
			cicloAnterior = cicloAtual;
		}
		menor++;
	}
	printf("%d %d %d \n", primeiroNumero, segundoNumero, cicloAnterior);
	return 0;
}