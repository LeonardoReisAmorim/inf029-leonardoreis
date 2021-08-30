#include <stdio.h>

void ler3numeros(int v,int x[]){
    int i;
    for(i=0;i<v;i++){
        printf("digite o %d numero\n",i+1);
        scanf("%d",&x[i]);
    }

}