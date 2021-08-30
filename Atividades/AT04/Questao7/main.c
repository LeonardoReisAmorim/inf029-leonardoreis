#include <stdio.h>
#include "ler3palavras.h"

int main(){
    
    ler3palavras palavras;

    palavras=lerpalavras();

    printf("a primeira palavra eh: %s\n",palavras.palavra1);
    printf("a segunda palavra eh: %s\n",palavras.palavra2);
    printf("a terceira palavra eh: %s\n",palavras.palavra3);

	return 0;
}