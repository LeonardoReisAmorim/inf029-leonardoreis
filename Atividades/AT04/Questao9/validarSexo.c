#include <stdio.h>

int validarsexo(char sexo){
    if(sexo=='m'||sexo=='M'||sexo=='f'||sexo=='F'||sexo=='O'){
        return 1;
    }else{
        return 0;
    }
}