#include <stdio.h>
#include <stdlib.h>

int ler3numeros(){
    int treenumbers[3],i;

    for(i=0;i<3;i++){
        printf("digite o %d numero\n",i);
        scanf("%d",&treenumbers[i]);
        return treenumbers[i];
    }

}