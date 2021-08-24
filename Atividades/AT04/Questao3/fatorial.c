#include <stdio.h>

int calcular_fatorial(int num){
    int fat;
    if(num<0){
        return 0;
    }else if(num==0){
        fat=1;
        return fat;
    }else{
        for(fat=1;num>1;num--){
            fat*=num;
        }
        return fat;
    }
    
}