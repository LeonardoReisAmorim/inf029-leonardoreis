#include <stdio.h>
#include "ler3Numeros.h"
#include <stdlib.h>

int main(){
	int numeros[3],i;

    for(i=0;i<3;i++){
        numeros[i]=ler3numeros();
    }
    printf("\n");
    for(i=0;i<20;i++){
        printf("*");
    }
    printf("\n");
    for(i=0;i<3;i++){
        printf("\n%d\n",numeros[i]);
    }

	return 0;
}