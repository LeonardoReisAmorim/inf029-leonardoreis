#include <stdio.h>
#include <stdlib.h>


int validarNascimento(char nascimento[]){
    printf("\n%s\n",nascimento);
    char zeroum[3],dois,tresquatro[3],cinco,seisanove[5];
    int i=0,ax_tresquatro=0,ax_seisnove=0;
    int numerozeroum, numerotresquatro;

    //for para armazenar os dois primeiros digitos da data
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i<=1){
            zeroum[i]=nascimento[i];
        }
    }

    //printf("\n0 e 1...: %s\n",zeroum);
    //numerozeroum = zeroum - '0';
    //printf("\nnumero: %d\n",numerozeroum);

    //for para verificar se os dois primeiros digitos da data contem letras 
    for (i=0; i < zeroum[i] != '\0'; i++){
        if((zeroum[i]>= 'a' && zeroum[i]<='z') || (zeroum[i]>='A' && zeroum[i]<= 'Z')){
            return 0;
            //erro=0;
        }
    }

    //for para armazenar o sinal de barra
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i==2){
            dois=nascimento[i];
        }
    }

    //printf("\ndigito 2 %c\n",dois);

    //verificar se no digito 2 ha a barra
    if(dois!='/'){
        return 0;
        //erro=0;
    }

    //for para armazenar os dois primeiros digitos da data
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i<=1){
            zeroum[i]=nascimento[i];
        }
    }

    //printf("\n0 e 1...: %s\n",zeroum);
    //numerozeroum = zeroum - '0';
    //printf("\nnumero: %d\n",numerozeroum);

    //for para verificar se os dois primeiros digitos da data contem letras 
    for (i=0; i < zeroum[i] != '\0'; i++){
        if((zeroum[i]>= 'a' && zeroum[i]<='z') || (zeroum[i]>='A' && zeroum[i]<= 'Z')){
            return 0;
            //erro=0;
        }
    }
    
    /*
    
    //for para armazenar o sinal de ponto
    for (i=0; i < cpf[i] != '\0'; i++){
        if(i==7){
            sete=cpf[i];
        }
    }

    //verificar se no digito 7 ha o ponto
    if(sete!='.'){
        return 0;
        //erro=0;
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
            //erro=0;
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
        //erro=0;
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
            //erro=0;
        }
    }
    */
    return 1;
}