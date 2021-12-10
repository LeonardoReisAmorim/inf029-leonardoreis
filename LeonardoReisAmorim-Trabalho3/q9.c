#include <stdio.h>

/* 15 - A função fatorial duplo é definida como o produto de todos os números naturais ímpares de 1 até algum
número natural ímpar N. Assim, o fatorial duplo de 5 é 5!! = 1 * 3 * 5 = 15 */
int fatDuplo(int n) {
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatDuplo(n - 2);
}

int main(void) {
    int num;
    printf("\n====================== Q15 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&num);
    printf("\n%d ",fatDuplo(num));

    return 0;
}