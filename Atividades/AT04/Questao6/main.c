#include <stdio.h>
#include "ler3letras.h"

int main(){
	int i;
    char letras[3];

    for(i=0;i<3;i++){
        letras[i]=ler3letras();
    }

    for(i=0;i<3;i++){
        printf("\nletra :%c\n",letras[i]);
    }
	return 0;
}