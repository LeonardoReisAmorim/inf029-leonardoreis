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
    char ax_nome[20],ax_data_nasc[11],ax_cpf[15],ax_sexo;

    printf("\ndigite o nome do cliente: ");
    gets(ax_nome);
    n_cliente=validarnome(ax_nome);
    if(n_cliente==1){
        printf("\nnome valido\n");
    }else{
        printf("\nnome invalido\n");
    }

    printf("\ndigite a data de nascimento do cliente: ");
    gets(ax_data_nasc);
    n_data=validarNascimento(ax_data_nasc);
    if(n_data==1){
        printf("\ndata valida\n");
    }else{
        printf("\n\ndata invalida");
    }

    printf("\ndigite o cpf do cliente: ");
    gets(ax_cpf);
    n_cpf=validarCPF(ax_cpf);
    if(n_cpf==1){
        printf("\ncpf valido\n");
    }else{
        printf("\ncpf invalido\n");
    }

    printf("\ndigite o sexo do cliente: \nm ou M para masculino\nf ou F para feminino\ne O para outro ");
    ax_sexo = getchar();
    n_sexo=validarsexo(ax_sexo);
    if(n_sexo==1){
        printf("sexo m, M, f ou F ou O outro\n");
    }else{
        printf("sexo invalido\n");
    }

    return cliente;    
}
