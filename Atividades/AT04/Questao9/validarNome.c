#include <stdio.h>

int validarnome(char nome[]){
    
    int i=0,achou=0;
    
    while (nome[i] != '\0'){
        achou++;
        i++;
    }

    if(achou<=20){  
        return 1;
    }else{  
        return 0;
    }
}