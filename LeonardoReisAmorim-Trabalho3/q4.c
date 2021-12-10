#include <stdio.h>

/* 4 - Faça uma função recursiva que permita somar os elementos de um vetor de inteiros. */
int somaVetor(int vet[], int n) {
	if(n == 1) {
		return vet[0];
	}
	return vet[n - 1] + somaVetor(vet, n - 1);
}

int main(void) {
    int i=0,num;
    printf("\n====================== Q4 =======================\n");
    printf("digite quantos elementos deseja somar: ");
    scanf("%d",&num);
    int vet[num];
    for(i=0;i<num;i++){
        printf("\ndigite um numero: ");
        scanf("%d",&vet[i]);
    }
    printf("\n%d ",somaVetor(vet, num));
    return 0;
}