#include <stdio.h>
#include "soma.h"

int main(){
    int numero1 = 0;
    int numero2 = 0;
    int soma = 0;

    printf("digite o primeiro numero....:  ");
    scanf("%d",&numero1);
    printf("digite o segundo numero....: ");
    scanf("%d",&numero2);

    soma = somar(numero1,numero2);

    printf("\nresultado da soma e: %d",soma);

    return 0;
}