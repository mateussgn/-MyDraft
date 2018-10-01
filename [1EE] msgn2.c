#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float sorteia();
void tempoDeAtendimentoDiminuindo(float vetor[]);
void entrarMenorFila(int vetorL[], int vetorC[], float tempoAtendimentoL[], float tempoAtendimentoC[]);
void imprimindoVetores(float vetor[]);

int main() {
	//Declaração de variáveis
	int VetL[5] = { 0 };
	int VetC[5] = { 0 };
	float TAtendL[5] = { 0 };
	float TAtendC[5] = { 0 };
	float RelH = 0;
	float NCli;
	float tempo_de_espera_novo_cliente = 0;
	int ContC = 0;
	int menor_fila;
	int i;


	srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios

	//LAÇO DE INCIO 
	while (RelH <= 10.0) { //Programa acaba quando RelH igual ou maior que 10
		NCli = sorteia();

		if (NCli > 0.5) { //Chegou cliente novo
			entrarMenorFila(VetL, VetC, TAtendL, TAtendC);

			ContC += 1;
			menor_fila = VetL[1];
			for (i = 1; i < 5; i++) {
				if (menor_fila > VetL[i])
					menor_fila = VetL[i];
			}
		}
		//else //Não chegou cliente novo 
		tempoDeAtendimentoDiminuindo(TAtendC);// Atualize os vários vetores com o tempo de 0.1 que passou...
		tempoDeAtendimentoDiminuindo(TAtendL);

		imprimindoVetores(TAtendC);	 // Apresente os vetores na tela (formatados) para melhor acompanhamento de seu programa
		imprimindoVetores(TAtendL);


		RelH += 0.1; //Tempo passou
		
	}
	return 0;
}
float sorteia() { 
	return (rand() % 101) / 100.0;
}

void tempoDeAtendimentoDiminuindo(float vetor[]) {
	int i;
	for (i = 0; i < 5; i++) {
		if (vetor[i] > 0)
			vetor[i] -= 0.1;
	}
}

void imprimindoVetores(float vetor[]) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("Caixa %d - Tempo de atendimento: %f", i, vetor[i]);
	}
}

void entrarMenorFila(int vetorL[], int vetorC[], float tempoAtendimentoL[], float tempoAtendimentoC[]) {
	int menorFilaL, menorFilaC, entraNaFilaL, entraNaFilaC, i;
	menorFilaL = vetorL[1];
	for (i = 1; i < 5; i++) { //escolhe menor fila dos caixas para mais de 20 itens
		if (menorFilaL > vetorL[i]) {
			menorFilaL = vetorL[i];
			entraNaFilaL = i;
		}
	}
	for (i = 1; i < 5; i++) { //escolhe menor fila dos caixas para menos de 20 itens
		if (menorFilaC > vetorC[i]) {
			menorFilaC = vetorC[i];
			entraNaFilaC = i;
		}
	}
	if (vetorL[entraNaFilaL] < vetorC[entraNaFilaC]) //escolhe menor fila entre os dois tipos de caixa
		vetorL[entraNaFilaL] += 1;
	else if(vetorL[entraNaFilaL] > vetorC[entraNaFilaC])
		vetorC[entraNaFilaC] += 1;
	else //escolher pelo o menor tempo de espera

}