#include <stdio.h>

void ordenando_vetor(int vetor[], int tamanho_vetor);
void imprime_vetor(int vetor[], int tamanho_vetor);

int main() {
	int quantidade_de_numeros = 0, i = 0;
	int numeros_digitados[51];

	printf("Quantos numeros serao digitados? ");
	scanf_s("%d", &quantidade_de_numeros);
	printf("Agora digite os numeros: ");
	//LENDO OS NUMEROS
	for (i = 0; i < quantidade_de_numeros; i++) {
		scanf_s("%d", &numeros_digitados[i]);
	}
	//ORDENANDO O VETOR
	ordenando_vetor(numeros_digitados, quantidade_de_numeros);
	//IMPRIMINDO VETOR
	imprime_vetor(numeros_digitados, quantidade_de_numeros);
	
	system("pause");
	return 0;
}
//ORDENANDO OS NUMEROS
void ordenando_vetor(int vetor[], int tamanho_vetor) {
	int i, j, ordena;
	for (i = 1; i < tamanho_vetor; i++) {
		ordena = vetor[i];
		for (j = i - 1; (j >= 0) && (ordena < vetor[j]); j--) {
			vetor[j + 1] = vetor[j];
		}
		vetor[j + 1] = ordena;
	}
}
//IMPRIMINDO OS NUMEROS
void imprime_vetor(int vetor[], int tamanho_vetor) {
	int i;
	for (i = 0; i < tamanho_vetor; i++) {
		if (vetor[i] != vetor[i - 1]) {
			if (i == tamanho_vetor - 1)
				printf("%d \n", vetor[i]);
			else
				printf("%d ", vetor[i]);
		}
	}
}