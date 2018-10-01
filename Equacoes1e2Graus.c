#include <stdio.h>
#include <math.h>

void resolve1oGrau();
void resolve2oGrau();
float valida(float);
void menuSistema();

int main() {
	int opcao;
	do {
		menuSistema();
		scanf_s("%d", &opcao);
		switch (opcao) {
		case 1: resolve1oGrau();
			break;
		case 2: resolve2oGrau();
			break;
		case 3: printf("Hasta la vista, baby!!!\n");
			break;
		default: printf("Opcao invalid. Preste atencao!!!\n");
		}
	} while (opcao != 3);
	return 0;
}

void resolve1oGrau() {
	float a, b;
	a = valida(a);
	printf("Digite coeficiente b: ");
	scanf_s("%f", &b);
	printf("Raiz = %f\n", -b / a);
}

void menuSistema() {
	printf("1........Resolve equacao 1o grau\n");
	printf("2........Resolve equacao 2o grau\n");
	printf("3........Sair\n");
	printf("\n\n\nOpcao: ");
}

void resolve2oGrau() {
	float a, b, c, delta;
	a = valida(a);
	printf("Digite coeficiente b: ");
	scanf_s("%f", &b);
	printf("Digite coeficiente c: ");
	scanf_s("%f", &c);
	delta = b*b - 4 * a*c;
	if (delta >= 0) { // As raizes sao reais. Ainda nao sei se apenas 1 ou 2 raizes...
		if (delta>0)
			printf("Raiz1=%f,\nRaiz2=%f\n", (-b - sqrt(delta)) / (2 * a),
			(-b + sqrt(delta)) / (2 * a));
		else
			printf("Raiz unica=%f\n", -b / (2 * a));
	}
}

float valida(float c_a) {
	printf("Digite a (a!=0): ");
	scanf_s("%f", &c_a);
	while (c_a == 0) {
		printf("Ooops. a deve ser != 0. Digite novamente: ");
		scanf_s("%f", &c_a);
	}
	return c_a;
}