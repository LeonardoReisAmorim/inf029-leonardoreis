#include <stdio.h>
#include "ler4Numeros.h"

int main(){
    fournumbers numbers;
    int i=0;

    numbers=ler4numeros();

    printf("\n");
    for(i=0;i<4;i++){
        printf("numero: %d e: %d\n",i+1,numbers.numero[i]);
    }

	return 0;
}