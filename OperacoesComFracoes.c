#include <stdio.h>

int mdc(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
int denDifZero(int denom) {
	while (denom == 0) {
		printf("Denominador nao pode ser zero. Entre novamente: ");
		scanf_s("%d", &denom);
	}
	return denom;
}
void somaFracoesEApresRes(int n1, int d1, int n2, int d2) {
	int resN, resD, comum;
	resN = n1 * d2 + n2*d1;
	resD = d1*d2;
	comum = mdc(resN, resD);
	resN /= comum;
	resD /= comum;
	//Escreve Res
	printf("Soma das fracoes: %d / %d \n", resN, resD);
}
int main() {
	int n1, d1, n2, d2, resN, resD, comum;
	//Leia uma fracao f1(n1, d1), Validando-a
	printf("Digite a primeira fracao: ");
	scanf_s("%d / %d", &n1, &d1);
	d1 = denDifZero(d1);
	//Leia uma fracao f2(n2, d2), validando-a
	printf("Digite a segunda fracao: ");
	scanf_s("%d / %d", &n2, &d2);
	d2 = denDifZero(d2);
	//Calcule f1 + f2 -> Res
	somaFracoesEApresRes(n1, d1, n2, d2);
	system("pause");
}