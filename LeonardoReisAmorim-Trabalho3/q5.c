#include <stdio.h>

/* 5 - Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a N */
int soma1aN(int n) {
	if(n == 1) {
		return 1;
	}
	return n + soma1aN(n - 1);
}

int main(void) {
    int q5;
    printf("\n====================== Q5 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&q5);
    printf("\n%d ",soma1aN(q5));
    return 0;
}