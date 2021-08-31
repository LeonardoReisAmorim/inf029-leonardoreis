#include <stdio.h>


int validarCPF(char cpf[]){
    char zeroadois[4],tres,quatroaseis[4],sete,oitoadez[4],onze,dozeetreze[3];
    int i=0,ax_quatroaseis=0,ax_oitoadez=0,ax_dozeetreze=0;
    
    //for para armazenar os tres primeiros digitos do cpf
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i<=2){
            zeroadois[i]=cpf[i];
        }
    }
    
    //for para verificar se nos tres primeiros digitos contem letras
    for (i=0; i < zeroadois[i] != '\0'; i++){
        if((zeroadois[i]>= 'a' && zeroadois[i]<='z') || (zeroadois[i]>='A' && zeroadois[i]<= 'Z')){
            return 0;
        }
    }

    //for para armazenar o sinal de ponto
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i==3){
            tres=cpf[i];
        }
    }

    //verificar se no digito 3 ha o ponto
    if(tres!='.'){
        return 0;
    }

    //for para armazenar os digitos quatro a seis do cpf
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i>=4 && i<=6){
            quatroaseis[ax_quatroaseis]=cpf[i];
            ax_quatroaseis++; 
        }
    }

    //for para verificar se nos digitos 4 a 6 contem letras
    for (i=0; i < ax_quatroaseis; i++){
        if((quatroaseis[i]>= 'a' && quatroaseis[i]<='z') || (quatroaseis[i]>='A' && quatroaseis[i]<= 'Z')){
            return 0;
        }
    }
    
    //for para armazenar o sinal de ponto
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i==7){
            sete=cpf[i];
        }
    }

    //verificar se no digito 7 ha o ponto
    if(sete!='.'){
        return 0;
    }
    
    //for para armazenar os digitos oito a dez do cpf
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i>=8 && i<=10){
            oitoadez[ax_oitoadez]=cpf[i];
            ax_oitoadez++; 
        }
    }

    //for para verificar se nos digitos 8 a 10 contem letras
    for (i=0; i < ax_oitoadez; i++){
        if((oitoadez[i]>= 'a' && oitoadez[i]<='z') || (oitoadez[i]>='A' && oitoadez[i]<= 'Z')){
            return 0;
        }
    }

    //for para armazenar o sinal de traço
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i==11){
            onze=cpf[i];
        }
    }

    //verificar se no digito 11 ha o traço
    if(onze!='-'){
        return 0;
    }

    //for para armazenar os digitos dozeetreze do cpf
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i>=12 && i<=13){
            dozeetreze[ax_dozeetreze]=cpf[i];
            ax_dozeetreze++; 
        }
    }

    //for para verificar se nos digitos 12 a 13 contem letras
    for (i=0; i < ax_dozeetreze; i++){
        if((dozeetreze[i]>= 'a' && dozeetreze[i]<='z') || (dozeetreze[i]>='A' && dozeetreze[i]<= 'Z') && (i>=0 && i<=2)){
            return 0;
        }
    }

    return 1;
}