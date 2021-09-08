#include <stdio.h>
#include "validarCPF.h"
#include "validarNascimento.h"
#include "validarNome.h"
#include "validarSexo.h"

typedef struct cadastrarCliente
{
    int verifica[4];
    char nome[50];
    char data_nasc[12];
    char cpf[16];
    char sexo;
}cadastrarCliente;


cadastrarCliente cadastraCliente(){
    int i,n_cliente,n_data,n_cpf,n_sexo,tem=0;
    cadastrarCliente cliente;
    char ax_nome[50],ax_data_nasc[12],ax_cpf[16],ax_sexo;

    printf("\ndigite o nome do cliente: ");
    fgets(ax_nome,50,stdin);
    
    n_cliente=validarnome(ax_nome);
    if(n_cliente==1){
        //printf("\n************nome valido\n");
        cliente.verifica[0]=n_cliente;
        
    }else{
        cliente.verifica[0]=n_cliente;
        //printf("\n------------nome invalido\n");
    }
    
    printf("\ndigite a data de nascimento do cliente: ");
    
    fgets(ax_data_nasc,12,stdin);
    n_data=validarNascimento(ax_data_nasc);
    if(n_data==1){
        //printf("\n************data valida\n");
        cliente.verifica[1]=n_data;
    }else{
        //printf("\n------------data invalida");
        cliente.verifica[1]=n_data;
    }
    
    printf("\ndigite o cpf do cliente: ");
    
    fgets(ax_cpf,16,stdin);
    n_cpf=validarCPF(ax_cpf);
    if(n_cpf==1){
        //printf("\n************cpf valido\n");
        cliente.verifica[2]=n_cpf;
    }else{
        //printf("\n------------cpf invalido\n");
        cliente.verifica[2]=n_cpf;
    }
    printf("\ndigite o sexo do cliente: \nm ou M para masculino\nf ou F para feminino\ne O para outro ");
    
    ax_sexo = getchar();
    n_sexo=validarsexo(ax_sexo);
    if(n_sexo==1){
        //printf("\n************sexo valido\n");
        cliente.verifica[3]=n_sexo;
    }else{
        //printf("\n------------sexo invalido\n");
        cliente.verifica[3]=n_sexo;
    }

    for(i=0;i<4;i++){
        if(cliente.verifica[i]==0){
            tem=1;
        }
    }

    if(!tem){
        for(i=0; ax_nome[i] != '\0'; i++){
            cliente.nome[i]=ax_nome[i];
        }
        printf("\n\n********************************************");
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

    return cliente;    
}
