#include <stdio.h>

typedef struct ler3palavras
{
    char palavra1[20];
    char palavra2[20];
    char palavra3[20];
}ler3palavras;

ler3palavras lerpalavras(){
    ler3palavras palavra;

    printf ("Digite a primeira palavra: \n");
    fgets(palavra.palavra1,20,stdin);
    

    printf ("Digite a segunda palavra: \n");
    fgets(palavra.palavra2,20,stdin);
    

    printf ("Digite a terceira palavra: \n");
    fgets(palavra.palavra3,20,stdin);
    
    return palavra;
}
