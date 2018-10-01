#include <stdio.h>

typedef struct {
	float  pR, pI;
}TComplex;

TComplex addC(TComplex a, TComplex b) {
	TComplex c = { a.pR + b.pR, a.pI + b.pI };
	//c.pR = a.pR + b.pR;
	//c.pI = a.pI + b.pI;
	return c;
}

void scanC(TComplex *c) {
	scanf_s("%f %f", (*c).pR, (*c).pI);
//	scanf_s("%f %f", c->pR, c->pI); outra notação
}

void printC(TComplex c) {
	if (c.pI > 0)
		printf("%f + %fi \n", c.pR, c.pI);
	else if (c.pI < 0)
		printf("%f %fi \n", c.pR, c.pI);
	else
		printf("%f \n", c.pR);
}

int main() {
//	TComplex c1 = { 1.0, 0.0 }, c2 = { 0.5, -3.5 }, c3 = { 0.5, 2.5 };
	TComplex c1, c2, c3;
	printf("Leitura de 2 complexos \n");
//	scanC(&c1);
//	scanC(&c2);
	scanf_s("%f %f", &(c1.pR), &(c1.pI));
	printf("Soma dos complexos \n");
//	printC(c1);
//	printC(c2);
	c3 = addC(c1, c2);
	printC(c3);
	system("pause");
	return 0;
}