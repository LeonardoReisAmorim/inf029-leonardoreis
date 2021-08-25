#include <stdio.h>

typedef struct cadastrarCliente
{
    char nome[20];
    char data_nasc[11];
    char cpf[15];
    char sexo;
}cadastrarCliente;

cadastrarCliente cadastraCliente(){
    int i;
    cadastrarCliente cliente;
    
    printf("\ndigite o nome do cliente: ");
    gets(cliente.nome);

    printf("\ndigite a data de nascimento do cliente: ");
    gets(cliente.data_nasc);

    printf("\ndigite o cpf do cliente: ");
    gets(cliente.cpf);

    printf("\ndigite o sexo do cliente: ");
    cliente.sexo = getchar();

    return cliente;    
}
