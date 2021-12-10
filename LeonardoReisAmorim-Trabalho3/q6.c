#include <stdio.h>

/* 6 - Crie um programa em C, que contenha uma função recursiva que receba dois inteiros positivos k e n e calcule kn.
Utilize apenas multiplicações. O programa principal deve solicitar ao usuário os valores de k e n e imprimir o resultado
da chamada da função. */
int potenciakn(int k, int n) {
	if(n == 1) {
		return k;
	}
	return k * potenciakn(k, n - 1);
}

int main(void) {
    int k,n;
    printf("\n====================== Q6 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&k);
    printf("digite outro numero: ");
    scanf("%d",&n);
    printf("\n%d ",potenciakn(k, n));
    return 0;
}