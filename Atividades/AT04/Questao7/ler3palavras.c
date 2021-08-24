#include <stdio.h>

typedef struct ler3palavras
{
    char palavra[20];
}ler3palavras;

ler3palavras lerpalavras(){
    int i;
    ler3palavras palavra[3];

    for(i=0;i<3;i++){
        printf ("Digite a palavra: \n");
        gets(palavra[i].palavra);
        return palavra[i];
    }
}
