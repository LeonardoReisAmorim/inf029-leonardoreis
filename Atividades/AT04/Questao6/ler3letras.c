#include <stdio.h>

char ler3letras(){
    int i;
    char letra[3];

    for(i=0;i<3;i++){
        printf("\ndigite a letra: \n");
        scanf(" %c",&letra[i]);
        
        
        return letra[i];
    }
}

