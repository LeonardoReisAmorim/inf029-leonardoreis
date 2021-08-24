#include <stdio.h>
#include "fatorial.h"

int main(){
    int numero = 0;
    int fatorial = 0;

    printf("digite um numero para calcular o fatorial: \n");
    scanf("%d",&numero);
    
    fatorial = calcular_fatorial(numero);

    if(fatorial==0){
        printf("impossivel calcular fatorial\n");
    }else{
        printf("fatorial: %d",fatorial);
    }

    return 0;
}