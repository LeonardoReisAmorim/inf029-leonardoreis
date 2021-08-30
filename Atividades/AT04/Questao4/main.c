#include <stdio.h>
#include "ler3Numeros.h"

int main(){
    int numeros[3],i;

    ler3numeros(3,numeros);

    for (i = 0; i < 3; i++){
        printf("numero %d, e o numero: %d\n",i+1,numeros[i]);
    }
    

    return 0;
}