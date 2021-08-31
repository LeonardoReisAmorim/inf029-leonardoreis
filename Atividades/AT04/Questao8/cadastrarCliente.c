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
    fgets(cliente.nome,20,stdin);

    printf("\ndigite a data de nascimento do cliente: ");
    fgets(cliente.data_nasc,11,stdin);

    printf("\ndigite o cpf do cliente: ");
    fgets(cliente.cpf,15,stdin);

    printf("\ndigite o sexo do cliente: ");
    cliente.sexo = getchar();

    return cliente;    
}
