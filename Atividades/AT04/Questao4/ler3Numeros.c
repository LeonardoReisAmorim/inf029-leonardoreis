#include <stdio.h>
#include <stdlib.h>

int ler3numeros(){
    int threenumbers[3],i;

    for(i=0;i<3;i++){
        printf("digite o %d numero\n",i);
        scanf("%d",&threenumbers[i]);
        return threenumbers[i];
    }

}