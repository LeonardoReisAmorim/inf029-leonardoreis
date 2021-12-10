#include <stdio.h>

/* Ex21 --> Os números tetranacci iniciam com quatro termos pré-determinados e a partir daí todos os demais números são
obtidos pela soma dos quatro números anteriores. Os primeiros números tetranacci são:
0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208... Faça uma função recursiva que receba um número N e retorne o
N-ésimo termo da sequência de tetranacci. */
int tetranacci(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 0;
	}
	if(n == 3) {
		return 1;
	}
	return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}

int main(void) {
    int n;
    printf("\n====================== Q21 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&n);
    printf("\n%d ",tetranacci(n));
    return 0;
}