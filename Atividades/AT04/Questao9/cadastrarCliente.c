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

typedef struct verificacadastro
{
    int verifica[4];
}verificacadastro;



verificacadastro cadastraCliente(){
    int i,n_cliente,n_data,n_cpf,n_sexo,tem=0;
    cadastrarCliente cliente;
    char ax_nome[20],ax_data_nasc[11],ax_cpf[15],ax_sexo;
    verificacadastro verifica;

    printf("\ndigite o nome do cliente: ");
    fgets(ax_nome,20,stdin);
    n_cliente=validarnome(ax_nome);
    if(n_cliente==1){
        //printf("\n************nome valido\n");
        verifica.verifica[0]=n_cliente;
    }else{
        verifica.verifica[0]=n_cliente;
        //printf("\n------------nome invalido\n");
    }

    printf("\ndigite a data de nascimento do cliente: ");
    fgets(ax_data_nasc,11,stdin);
    n_data=validarNascimento(ax_data_nasc);
    if(n_data==1){
        //printf("\n************data valida\n");
        verifica.verifica[1]=n_data;
    }else{
        //printf("\n------------data invalida");
        verifica.verifica[1]=n_data;
    }

    printf("\ndigite o cpf do cliente: ");
    fgets(ax_cpf,15,stdin);
    n_cpf=validarCPF(ax_cpf);
    if(n_cpf==1){
        //printf("\n************cpf valido\n");
        verifica.verifica[2]=n_cpf;
    }else{
        //printf("\n------------cpf invalido\n");
        verifica.verifica[2]=n_cpf;
    }

    printf("\ndigite o sexo do cliente: \nm ou M para masculino\nf ou F para feminino\ne O para outro ");
    ax_sexo = getchar();
    n_sexo=validarsexo(ax_sexo);
    if(n_sexo==1){
        //printf("\n************sexo valido\n");
        verifica.verifica[3]=n_sexo;
    }else{
        //printf("\n------------sexo invalido\n");
        verifica.verifica[3]=n_sexo;
    }

    for(i=0;i<4;i++){
        if(verifica.verifica[i]==0){
            tem=1;
        }
    }

    if(!tem){
        for(i=0; ax_nome[i] != '\0'; i++){
            cliente.nome[i]=ax_nome[i];
        }
        cliente.nome[i]='\0';
        printf("\nnome do cliente.....: %s\n",cliente.nome);
        //---------------------------------------------
        for(i=0; ax_data_nasc[i] != '\0'; i++){
            cliente.data_nasc[i]=ax_data_nasc[i];
        }
        cliente.data_nasc[i]='\0';
        printf("\ndata de nascimento do cliente.........: %s\n",cliente.data_nasc);
        //-----------------------------------------------------
        for(i=0; ax_cpf[i] != '\0'; i++){
            cliente.cpf[i]=ax_cpf[i];
        }
        cliente.cpf[i]='\0';
        printf("\ncpf do cliente.........: %s\n",cliente.cpf);
        //---------------------------------------------
        cliente.sexo = ax_sexo;
        printf("\nsexo do cliente........: %c\n",cliente.sexo);
    }

    return verifica;    
}
