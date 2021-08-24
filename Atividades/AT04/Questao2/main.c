#include <stdio.h>
#include "subtrai.h"

int main(){

    int valor1 = 0;
    int valor2 = 0;
    int valor3 = 0;
    int subtracao = 0;

    printf("digite o primeiro valor: \n");
    scanf("%d",&valor1);
    printf("digite o segundo valor: \n");
    scanf("%d",&valor2);
    printf("digite o terceiro valor: \n");
    scanf("%d",&valor3);

    subtracao = subtrai(valor1,valor2,valor3);

    printf("o resultado da subtracao dos tres valores e: %d",subtracao);
    return 0;
}