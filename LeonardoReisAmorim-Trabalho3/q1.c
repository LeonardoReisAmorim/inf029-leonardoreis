#include <stdio.h>

/* 1 - Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N. */
int fatorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * fatorial(n - 1);
}

int main(void) {
    int q1;
    printf("\n====================== Q1 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&q1);
    printf("\n%d ",fatorial(q1));
    return 0;
}