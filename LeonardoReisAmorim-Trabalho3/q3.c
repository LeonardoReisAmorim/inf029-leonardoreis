#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* 3 - Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 - 321 */
int inverte(int n) {
	if((n / 10) == 0) {
		return n;
	}
	return inverte(n / 10) + (n % 10) * pow(10, abs((int)log10(n)));
}

int inverteSig(int n) {
	if(n < 0) {
		return -1 * inverte(n * -1);
	}
	return inverte(n);
}

int main(void) {
    int q3;
    printf("\n====================== Q3 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&q3);
    printf("\n%d ",inverte(q3));
    return 0;
}