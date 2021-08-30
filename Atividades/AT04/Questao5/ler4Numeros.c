#include <stdio.h>

typedef struct fournumbers{
    int numero[4];  
} fournumbers;

fournumbers ler4numeros(){
    fournumbers numbersfour;
    int i; 
    for(i=0;i<4;i++){
        printf("numero: %d.  Digite o numero: ",i+1);
        scanf("%d",&numbersfour.numero[i]);
    }

    return numbersfour;
}