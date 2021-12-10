#include <stdio.h>

/* 2 - Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência Fibonacci.
        Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89...        */
int fibonacci(int n) {
	if(n == 0) {
		return 0;
	}else if(n < 2){
        return 1;
    }
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    int q2;
    printf("\n====================== Q2 =======================\n");
    printf("digite um numero: ");
    scanf("%d",&q2);
    printf("\n%d ",fibonacci(q2));
    return 0;
}