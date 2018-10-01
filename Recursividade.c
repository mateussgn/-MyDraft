#include <stdio.h>

int fatorial(int n) {
	int resultado;
	if (n == 0) resultado = 1;
	else resultado = n + fatorial(n - 1);
	return resultado;
}
int sequenciaDeFibonacci(int n) {
	int resultado;
	if (n == 1 || n == 2) resultado = 1;
	else resultado = sequenciaDeFibonacci(n - 1) + sequenciaDeFibonacci(n - 2);
	return resultado;
}
int main() {
	printf("Fatorial(10) = %d \n", fatorial(10));
	printf("Sequencia de Fibonacci(15) = %d \n", sequenciaDeFibonacci(15));
	system("pause");
	return 0;
}