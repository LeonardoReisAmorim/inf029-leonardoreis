#include <stdio.h>
#include <stdlib.h>


int validarNascimento(char nascimento[]){
    char zeroum[2],dois,tresquatro[2],cinco,seisanove[4];
    int i=0,ax_tresquatro=0,ax_seisnove=0,aux=0,numerozeroum[2], numerotresquatro[2],auxn1=0,aux2=0,auxn2=0,aux3=0;

    //for para armazenar os dois primeiros digitos da data
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i<=1){
            zeroum[i]=nascimento[i];
        }
    }
    
    for(i=0;i<zeroum[i];i++){
        numerozeroum[auxn1]=zeroum[i] - '0';
        auxn1++;
    }

    for(i=0;i<auxn1;i++){
        if((numerozeroum[i]>=3 && i==0)){
            aux2++;
        }else if(numerozeroum[i]>=2 && i>0){
            aux2++;
        }
    }
    if(aux2>=2){
        return 0;
    }
    
    //for para verificar se os dois primeiros digitos da data contem letras 
    for (i=0; i < zeroum[i] != '\0'; i++){
        if((zeroum[i]>= 'a' && zeroum[i]<='z') || (zeroum[i]>='A' && zeroum[i]<= 'Z')){
            return 0;
        }
    }

    //for para armazenar o sinal de barra
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i==2){
            dois=nascimento[i];
        }
    }

    //verificar se no digito 2 tem a barra
    if(dois!='/'){
        return 0;
    }

    //for para armazenar os digitos 3 e 4 da data
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i>=3 && i<=4){
            tresquatro[ax_tresquatro]=nascimento[i];
            ax_tresquatro++;
        }
    }

    for(i=0;i<ax_tresquatro;i++){
        numerotresquatro[auxn2]=tresquatro[i] - '0';
        auxn2++;
    }

    for(i=0;i<auxn2;i++){
        if(numerotresquatro[i]>=1 && i==0){
            aux3++;
        }else if(numerotresquatro[i]>=3 && i>0){
            aux3+=2;
        }else if(numerotresquatro[i]==2 && i>0){
            aux3++;
        }
    }
    if(aux3==3){
       return 0;
    }

    //for para verificar se os digitos 3 e 4 da data contem letras 
    for (i=0; i < ax_tresquatro; i++){
        if((tresquatro[i]>= 'a' && tresquatro[i]<='z') || (tresquatro[i]>='A' && tresquatro[i]<= 'Z')){
            return 0;
        }
    }

    //for para armazenar o sinal de barra no digito cinco
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i==5){
            cinco=nascimento[i];
        }
    }

    //verificar se no digito 5 tem a barra
    if(cinco!='/'){
        return 0;
    }

    //for para armazenar os digitos de 6 a 9 da data
    for (i=0; i < nascimento[i] != '\0'; i++){
        if(i>=6 && i<=9){
            seisanove[ax_seisnove]=nascimento[i];
            ax_seisnove++;
        }
        if(i>9){
            aux=1;
        }
    }
    
    if(aux==1 || ax_seisnove<4){
        return 0;
    }

    //for para verificar se os digitos 3 e 4 da data contem letras 
    for (i=0; i < ax_seisnove; i++){
        if((seisanove[i]>= 'a' && seisanove[i]<='z') || (seisanove[i]>='A' && seisanove[i]<= 'Z')){
            return 0;
        }
    }
    
    return 1;
}