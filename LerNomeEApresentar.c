//Ler nome com uma string, inclusive os espacos e apresentar no modelo americano(Nascimento, Mateus)
#include <stdio.h>

int determinar_Tamanho(char s[]) {
	int i = 
		0;
	while (s[i++] != '\0');
	return i;
}

int locUltB(char s[], int final) {
	int i = final;
	while (s[i--] != ' ');
	return i;
}

int main() {
	char nome[50];
	int tam, ultB, i;

	//Ler nome de tamaho máximo 49
	printf("Digite seu nome completo:\n"); 
	scanf_s(" %[^\n]", nome);

	//Achar tamanho do nome lido
	tam = determinar_Tamanho(nome);

	//Localizar ultimo caractere em branco
	ultB = locUltB(nome, tam);

	//Imprimir deste ponto ao final
	for (i = ultB; i < tam + 1; i++) {
		printf("%c", nome[i]);
	}
	nome[ultB] = '\0';

	//virgula
	//imprimir o começo
	printf(", %s", nome);

	system("pause");
	return 0;
}