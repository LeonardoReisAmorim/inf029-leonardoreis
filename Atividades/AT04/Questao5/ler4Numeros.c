#include <stdio.h>

typedef struct fournumbers{
    int numero;  
} fournumbers;

fournumbers ler4numeros(){
    fournumbers numbersfour[4];
    int i; 
    for(i=0;i<4;i++){
        printf("digite o numero: ");
        scanf("%d",&numbersfour[i].numero);
        return numbersfour[i];
    }
}