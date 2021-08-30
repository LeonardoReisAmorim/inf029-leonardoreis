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
    gets(palavra.palavra1);
    fflush(stdin);

    printf ("Digite a segunda palavra: \n");
    gets(palavra.palavra2);
    fflush(stdin);

    printf ("Digite a terceira palavra: \n");
    gets(palavra.palavra3);
    fflush(stdin);

    return palavra;
}
