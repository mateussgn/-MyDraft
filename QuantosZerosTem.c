#include<stdio.h>

int fat(int numero);
int quantosZerosTem(int resultadoFat);
int numeroValido();

int main() {
	int escolha;
	do {
		printf("1 - Ver quantos zeros tem \n");
		printf("2 - Sair \n");
		scanf_s("%d", &escolha);
		switch (escolha) {
		case 1: quantosZerosTem(fat(numeroValido()));
			break;
		}
	} while (escolha != 2);
}
int numeroValido() {
	int numero;
	do {
		printf("Digite um numero entre 1 e 100.000: \n");
		scanf_s("%d", &numero);
		if (numero < 1 || numero > 100000) {
			printf("Numero invalido\n");
		}
	} while (numero < 1 || numero > 100000);
	return numero;
}
int fat(int numero) {
	int resultadoFat = numero;
	while (numero > 1) {
		numero--;
		resultadoFat = resultadoFat * numero;
	}
	printf("O fatorial e %d \n", resultadoFat);
	return resultadoFat;
}
int quantosZerosTem(int resultadoFat) {
	int numeroDeZeros = 0;
	while (resultadoFat % 10 == 0) {
		numeroDeZeros++;
		resultadoFat = resultadoFat / 10;
	}
	printf("Tem %d zero(s)! \n", numeroDeZeros);
}