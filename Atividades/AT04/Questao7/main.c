#include <stdio.h>
#include "ler3palavras.h"

int main(){
    
    ler3palavras palavras[3];
    int i;

    for(i=0;i<3;i++){
        palavras[i]=lerpalavras();
    }
    printf("\n");
    for(i=0;i<3;i++){
        printf("a palavra %d e %s\n",i+1,palavras[i]);
    }

	return 0;
}