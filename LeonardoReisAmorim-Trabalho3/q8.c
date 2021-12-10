#include <stdio.h>

/* 10 - A multiplicação de dois números inteiros pode ser feita através de somas sucessivas. Proponha um algoritmo recursivo
Multip_Rec(n1,n2) que calcule a multiplicação de dois inteiros */
int multRec(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + multRec(a, b - 1);
}

int main(void) {
    int n1,n2;
    printf("\n====================== Q10 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&n1);
    printf("digite outro numero: ");
    scanf("%d",&n2);
    printf("\n%d ",multRec(n1, n2));
    return 0;
}