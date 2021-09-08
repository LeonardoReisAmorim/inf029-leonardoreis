#include <stdio.h>
#include "cadastrarCliente.h"

int main(){
    cadastrarCliente cliente;
    cliente = cadastraCliente();
    int i,cadastrofeito=0,tem=0;
    
    printf("\n**********************************************************\n");
    for(i=0;i<4;i++){
        if(cliente.verifica[i]==0 && i==0){
            printf("\nCADASTRO NAO REALIZADO. erro ao cadastrar o nome\n");
            tem=1;
        }else if(cliente.verifica[i]==0 && i==1){
            printf("\nCADASTRO NAO REALIZADO. erro ao cadastrar a data de nascimento\n");
            tem=1;
        }else if(cliente.verifica[i]==0 && i==2){
            printf("\nCADASTRO NAO REALIZADO. erro ao cadastrar o cpf\n");
            tem=1;
        }else if(cliente.verifica[i]==0 && i==3){
            printf("\nCADASTRO NAO REALIZADO. erro ao cadastrar o sexo\n");
            tem=1;
        }else{
            cadastrofeito=0;
        }
    }
    if(!cadastrofeito && !tem){
        printf("\nCADASTRO FEITO COM SUCESSO\n");
    }
    printf("\n**********************************************************\n");

    return 0;
}