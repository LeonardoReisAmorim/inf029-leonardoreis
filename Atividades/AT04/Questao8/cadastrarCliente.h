#include <stdio.h>

typedef struct cadastrarCliente
{
    char nome[20];
    char data_nasc[11];
    char cpf[15];
    char sexo;
}cadastrarCliente;

cadastrarCliente cadastraCliente();