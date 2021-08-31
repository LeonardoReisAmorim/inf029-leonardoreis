#include <stdio.h>

typedef struct ler3letras
{
    char letras[3];
}ler3letras;


ler3letras lerletras(){
    ler3letras letras;
    int i;
    for(i=0;i<3;i++){
        printf("\ndigite a %d.  Letra: \n",i+1);
        letras.letras[i] = getchar();
        getchar();
        //__fpurge(stdin);
    }

    return letras;
}

