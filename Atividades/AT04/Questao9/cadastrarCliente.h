#include <stdio.h>

typedef struct cadastrarCliente
{
    int verifica[4];
    char nome[50];
    char data_nasc[12];
    char cpf[16];
    char sexo;
}cadastrarCliente;

cadastrarCliente cadastraCliente();