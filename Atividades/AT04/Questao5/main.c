#include <stdio.h>
#include "ler4Numeros.h"

int main(){
    fournumbers numbers[4];
    int i=0;

    for(i=0;i<4;i++){
        numbers[i]=ler4numeros();
    }
    printf("\n");
    for(i=0;i<4;i++){
        printf("numero: %d e: %d\n",i+1,numbers[i]);
    }

	return 0;
}