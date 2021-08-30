#include <stdio.h>
#include "ler3letras.h"

int main(){
	int i;
    ler3letras letras;
    
    letras=lerletras();

    for(i=0;i<3;i++){
        printf("\nletra %d... eh a letra: %c\n",i+1,letras.letras[i]);
    }
	return 0;
}