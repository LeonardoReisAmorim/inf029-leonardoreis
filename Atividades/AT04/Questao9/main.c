#include <stdio.h>
#include "cadastrarCliente.h"

int main(){
    
    cadastrarCliente cliente;

    cliente = cadastraCliente();
    printf("**********************************************************");
    printf("\no nome do cliente e: %s\n",cliente.nome);
    printf("\na data de nascimento e: %s\n",cliente.data_nasc);
    printf("\no cpf do cliente e: %s\n",cliente.cpf);
    printf("\no sexo do cliente e: %c\n",cliente.sexo);
    return 0;
}