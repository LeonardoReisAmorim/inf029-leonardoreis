#include <stdio.h>
#include "validarCPF.h"
#include "validarNascimento.h"
#include "validarNome.h"
#include "validarSexo.h"

typedef struct cadastrarCliente
{
    char nome[20];
    char data_nasc[11];
    char cpf[15];
    char sexo;
}cadastrarCliente;

cadastrarCliente cadastraCliente(){
    int i,n_cliente,n_data,n_cpf,n_sexo;
    cadastrarCliente cliente;
    
    printf("\ndigite o nome do cliente: ");
    gets(cliente.nome);
    n_cliente=validarnome(cliente.nome);
    if(n_cliente==1){
        printf("nome menor q 20 caractere");
    }else{
        printf("nome maior que 20");
    }

    printf("\ndigite a data de nascimento do cliente: ");
    gets(cliente.data_nasc);

    printf("\ndigite o cpf do cliente: ");
    gets(cliente.cpf);

    printf("\ndigite o sexo do cliente: \nm ou M para masculino\nf ou F para feminino\ne O para outro ");
    cliente.sexo = getchar();
    n_sexo=validarsexo(cliente.sexo);
    if(n_sexo==1){
        printf("sexo m, M, f ou F ou O outro");
    }else{
        printf("sexo invalido");
    }

    return cliente;    
}
