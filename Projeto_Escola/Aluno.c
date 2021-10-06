#include <stdio.h>
#include <stdlib.h>
#include "ProjetoEscola.h"
#include "string.h"
#include <time.h>

void Listaralunos(Alunos alunos[], int qtd_alunos){
    setbuf(stdin,0);
    if(qtd_alunos<0){
        printf("\nNão existem alunos cadastrados.\n");
    }else{
        printf("\n------------ Listagem de alunos -------------\n");
        int i;

        for(i=0;i<qtd_alunos;i++){
            printf("\n");
            printf("Matrícula .....:  %d\n",alunos[i].matricula);
            printf("Nome .....:  %s\n",alunos[i].nome);
            printf("Sexo .....:  %c\n",alunos[i].sexo);
            printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
            printf("CPF .....:  %s\n",alunos[i].cpf);
        }
    }
    
}

int Inseriraluno(Alunos alunos[], int qtd_alunos){
    
    int validardata=0, validarcpf=0;
    int validarData_aluno(Alunos alunos[], int n);
    int validarCPF_aluno(Alunos alunos[], int n);

    setbuf(stdin,0);
    printf("\n------------ Cadastro do aluno ------------\n");

    printf("\nDigite a matrícula do aluno...: ");
    scanf("%d",&alunos[qtd_alunos].matricula);
    setbuf(stdin, 0);
    
    if (alunos[qtd_alunos].matricula<=0){
        return erro_matricula;
    }

    // Adicionar verificação de matrícula com matrículas já cadastradas.

    printf("\nDigite o nome do aluno...: ");
    fgets(alunos[qtd_alunos].nome, 100, stdin); 
    size_t ln = strlen(alunos[qtd_alunos].nome) - 1; 
    if (alunos[qtd_alunos].nome[ln] == '\n'){
        alunos[qtd_alunos].nome[ln] = '\0';
    }
        
    printf("\nDigite o sexo do aluno...: ");
    scanf("%c", &alunos[qtd_alunos].sexo); 
    if (alunos[qtd_alunos].sexo != 'M' && alunos[qtd_alunos].sexo != 'F' && alunos[qtd_alunos].sexo != 'm' && alunos[qtd_alunos].sexo != 'f') {
        return erro_sexo;
    }

    printf("\nDigite o dia de nascimento do aluno....: ");
    scanf("%d", &alunos[qtd_alunos].data_nasc.dia);
   
    printf("\nDigite o mês de nascimento do aluno....: ");
    scanf("%d", &alunos[qtd_alunos].data_nasc.mes);
   
    printf("\nDigite o ano de nascimento do aluno....: ");
    scanf("%d", &alunos[qtd_alunos].data_nasc.ano);
    setbuf(stdin, 0);

    validardata = validarData_aluno(alunos, qtd_alunos);
    if(validardata==1){
        return erro_data_nasc;
    }

    printf("\nDigite o CPF do aluno (apenas números)....: ");
    fgets(alunos[qtd_alunos].cpf, 16, stdin); 
    ln = strlen(alunos[qtd_alunos].cpf) - 1; 
    if (alunos[qtd_alunos].cpf[ln] == '\n'){
        alunos[qtd_alunos].cpf[ln] = '\0';
    }
    validarcpf = validarCPF_aluno(alunos, qtd_alunos);
    if(validarcpf==1){
        return erro_cpf;
    }
    return sucesso;
}

int excluirAluno (Alunos alunos[], int qtd_alunos){
    setbuf(stdin,0);
    int i, matricula, posicao = -1;
    if(qtd_alunos<0){
        return -2;
    }
    printf("\n------------ Exclusão do aluno ------------\n");
    printf("\nInforme a matrícula do aluno a ser excluído: ");
    scanf("%d", &matricula);

    for(i = 0;  i < qtd_alunos; i++){
        if(matricula == alunos[i].matricula){
            posicao = i;
        }
    }

    if(posicao == -1){
        return 0;
    }
    else{
        for(i = posicao; i < qtd_alunos; i++){
            alunos[i] = alunos[i + 1];
        }
        return sucesso;
    }
}

void listar_por_sexo(Alunos alunos[], int qtd_alunos){
    int i, sexo=0,achou=0;
    char sexo_informado;
    setbuf(stdin,0);
    if(qtd_alunos<0){
        printf("\nNão existem alunos cadastrados.\n");
    }else{ 
        printf("\nDigite o sexo a ser listado...: ");
        scanf("%c",&sexo_informado);
        //printf("%c", &sexo_informado);
        if(sexo_informado == 'm' || sexo_informado == 'M'){
            printf("\n------------ Sexo masculino ------------\n");
                for(i=0;i<qtd_alunos;i++){
                    if(alunos[i].sexo == 'm' || alunos[i].sexo == 'M'){
                        printf("\n");
                        printf("Matrícula .....:  %d\n",alunos[i].matricula);
                        printf("Nome .....:  %s\n",alunos[i].nome);
                        printf("Sexo .....:  %c\n",alunos[i].sexo); 
                        printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
                        printf("CPF .....:  %s\n",alunos[i].cpf);
                        achou=1;
                    }else{
                        sexo=1;
                    }
                }
                if(sexo==1 && achou==0){
                    printf("\nNão existem alunos do sexo masculino cadastrados.\n");
                }
        }else if(sexo_informado == 'f' || sexo_informado == 'F'){
            printf("\n\n");
    
            printf("\n------------ Sexo feminino ------------\n");
            for(i=0;i<qtd_alunos;i++){
                if(alunos[i].sexo == 'f' || alunos[i].sexo == 'F'){
                    printf("\n");
                    printf("Matrícula .....:  %d\n",alunos[i].matricula);
                    printf("Nome .....:  %s\n",alunos[i].nome);
                    printf("Sexo .....:  %c\n",alunos[i].sexo); 
                    printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
                    printf("CPF .....:  %s\n",alunos[i].cpf);
                    achou=1;
                }else{
                    sexo=1;
                }
            }
            if(sexo==1 && achou==0){
                printf("\nNão existem alunos do sexo femininos cadastrados.\n");  
            }
        }
    }
}

void listar_aluno_busca(Alunos alunos[], int qtd_alunos){
    char nome[100];
    int i=0,resultado,achei=0;;
    setbuf(stdin,0);
    printf("\n------------ Buscar aluno ------------\n");
    
    printf("\nDigite o nome do aluno que deseja pesquisar....:  ");
	fgets(nome, 101, stdin);
    size_t ln = strlen(nome) - 1; 
    if (nome[ln] == '\n'){
        nome[ln] = '\0';
    }
	for(i=0;i<qtd_alunos;i++){
		resultado=strcmp(alunos[i].nome,nome);
		if(resultado==0){
			printf("\n====================================== LISTA DE ALUNOS COM O NOME: %s =================================\n",nome);
            printf("Matrícula .....:  %d\n",alunos[i].matricula);
            printf("Nome .....:  %s\n",alunos[i].nome);
            printf("Sexo .....:  %c\n",alunos[i].sexo); 
            printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
            printf("CPF .....:  %s\n",alunos[i].cpf);
			achei=1;
		}
	}
	if(achei==0){
		printf("\nAluno não encontrado.\n");
	}
}

void listarAluno_data_nasc (Alunos alunos[], int qtd_alunos){

    int i, j;
    Alunos aux;

    printf("\n---------- Listagem de Alunos por ordem de data de nascimento ----------\n");
    if(qtd_alunos <= 0){
        printf("\nNão existem alunos cadastrados.\n");
    }

    for(i = 0; i < qtd_alunos - 1; i++)
    {
       if(alunos[i+1].data_nasc.ano >= alunos[i].data_nasc.ano)
        {
            aux = alunos[i];
            alunos[i] = alunos[i+1];
            alunos[i+1] = aux;
        }
    }

    for(i = 0; i < qtd_alunos - 1; i++)
    {
        if(alunos[i+1].data_nasc.mes >= alunos[i].data_nasc.mes && alunos[i+1].data_nasc.ano >= alunos[i].data_nasc.ano){
            aux = alunos[i];
            alunos[i] = alunos [i+1];
            alunos[i+1] = aux;
        }
    }
    
    for(i = 0; i < qtd_alunos - 1; i++){
        if(alunos[i+1].data_nasc.dia >= alunos[i].data_nasc.dia && alunos[i+1].data_nasc.mes >= alunos[i].data_nasc.mes && alunos[i+1].data_nasc.ano >= alunos[i].data_nasc.ano){
            aux = alunos[i];
            alunos[i] = alunos [i+1];
            alunos[i+1] = aux;
        }
    }

    for(i = 0; i < qtd_alunos; i++)
    {
        printf("\nMatrícula .....:  %d\n",alunos[i].matricula);
        printf("Nome .....:  %s\n",alunos[i].nome);
        printf("Sexo .....:  %c\n",alunos[i].sexo);
        printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
        printf("CPF .....:  %s\n",alunos[i].cpf);
    }
}

int AlterarAluno (Alunos alunos[], int qtd_alunos){
    
    setbuf(stdin,0);
    int i, matricula, achei=0, aux=0, validardata;
    int validarData_aluno(Alunos alunos[], int n);

    if(qtd_alunos<0){
        return -2;
    }
    printf("\n------------ Alteração do aluno ------------\n");
    printf("\nInforme a matrícula do aluno para alterar: ");
    scanf("%d", &matricula);
    for(i = 0;  i < qtd_alunos; i++){
        if(matricula == alunos[i].matricula){
            printf("\nDigite a matrícula do aluno...: ");
            scanf("%d",&alunos[i].matricula);
            setbuf(stdin, 0);
            if (alunos[i].matricula<=0){
                return erro_matricula;
            }

            // Adicionar verificação de matrícula com matrículas já cadastradas.
            printf("\nDigite o nome do aluno...: ");
            fgets(alunos[i].nome, 100, stdin); 
            size_t ln = strlen(alunos[i].nome) - 1; 
            if (alunos[i].nome[ln] == '\n'){
                alunos[i].nome[ln] = '\0';
            }
                
            printf("\nDigite o sexo do aluno...: ");
            scanf("%c", &alunos[i].sexo); 
            if (alunos[i].sexo != 'M' && alunos[i].sexo != 'F' && alunos[i].sexo != 'm' && alunos[i].sexo != 'f') {
                return erro_sexo;
            }

            printf("\nDigite o dia de nascimento do aluno....: ");
            scanf("%d", &alunos[i].data_nasc.dia);
        
            printf("\nDigite o mes de nascimento do aluno....: ");
            scanf("%d", &alunos[i].data_nasc.mes);
        
            printf("\nDigite o ano de nascimento do aluno....: ");
            scanf("%d", &alunos[i].data_nasc.ano);
            setbuf(stdin, 0);
            validardata = validarData_aluno(alunos, qtd_alunos);
            if(validardata==1){
                return erro_data_nasc;
            }

            printf("\nDigite o CPF do aluno (apenas números)....: ");
            fgets(alunos[i].cpf, 16, stdin); 
            ln = strlen(alunos[i].cpf) - 1; 
            if (alunos[i].cpf[ln] == '\n'){
                alunos[i].cpf[ln] = '\0';
            }
            aux=1;
        }else{
            achei=1;
        }
    }

    if(achei && !aux){
        return -1;
    }
    return sucesso;
}

void alunos_ordenados_nome(Alunos alunos[], int qtd_alunos){
    int i=0,j=0,r;
    char aux[100];

    if(qtd_alunos<0){
        printf("\nNão existem alunos cadastrados.\n");
    }else{
        for(i=0;i<=qtd_alunos;i++){
            for(j=i+1;j<=qtd_alunos;j++){
                r = strcmp(alunos[i].nome, alunos[j].nome);
                if(r>0){
                    strcpy(aux,alunos[i].nome);
                    strcpy(alunos[i].nome, alunos[j].nome);
                    strcpy(alunos[j].nome, aux);
                }
            }
        }

        for(i=0;i<qtd_alunos;i++){
            printf("\n");
            printf("Nome .....:  %s\n",alunos[i].nome);
            printf("Matrícula .....:  %d\n",alunos[i].matricula);   
            printf("Sexo .....:  %c\n",alunos[i].sexo);
            printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
            printf("CPF .....:  %s\n",alunos[i].cpf);
        }
    }
}

void aniv_mes_alunos(Alunos alunos[], int qtd_alunos){
    
    int i = 0;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    printf("\n----------------- Alunos -----------------\n");
    if(qtd_alunos < 0){
        printf("\nNão existem alunos matriculados.\n");
    }else{
        for(i = 0; i < qtd_alunos; i++){
            if(alunos[i].data_nasc.mes == (tm.tm_mon + 1)){
                printf("Matrícula....: %d\n", alunos[i].matricula);
                printf("Nome....: %s\n", alunos[i].nome);
                printf("Data de nascimento....: %d/%d/%d\n", alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
                printf("-----\n");
            }
        }
    }
}

int validarData_aluno(Alunos alunos[], int n){

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int bissexto = 0;

    if(alunos[n].data_nasc.ano >= 1900 && alunos[n].data_nasc.ano <= tm.tm_year + 1900){
        if(alunos[n].data_nasc.ano%4==0 && (alunos[n].data_nasc.ano%100!=0 || alunos[n].data_nasc.ano%400==0)){
            bissexto = 1; //o ano é bissexto
        }else{
            bissexto = -1; //o ano não é bissexto
        }
        
        if(alunos[n].data_nasc.mes >= 1 && alunos[n].data_nasc.mes <= 12){
            if(alunos[n].data_nasc.mes == 4 || alunos[n].data_nasc.mes == 6 || alunos[n].data_nasc.mes == 9 || alunos[n].data_nasc.mes == 11){
                if(alunos[n].data_nasc.dia >= 1 && alunos[n].data_nasc.dia <= 30){
                    return 0;
                }else{
                    return 1;
                }
            }else{
                if(alunos[n].data_nasc.mes == 2){
                    if(bissexto == 1){
                        if(alunos[n].data_nasc.dia >= 1 && alunos[n].data_nasc.dia <= 29){
                            return 0;
                        }else{
                            return 1;
                        }
                    }
                    else{
                        if(alunos[n].data_nasc.dia >= 1 && alunos[n].data_nasc.dia <= 28){
                            return 0;
                        }
                        else{
                            return 1;
                        }
                    }
                }else{
                    if(alunos[n].data_nasc.dia >= 1 && alunos[n].data_nasc.dia <= 31){
                        return 0;
                    }else{
                        return 1;
                    }
                }
            }
        }else{
            return 1;
        }
    }else{
        return 1;
    }
}

int validarCPF_aluno(Alunos alunos[], int n){
    
    int i, j, digito1 = 0, digito2 = 0;

    if(strlen(alunos[n].cpf) != 11)
        return 1;
    else if((strcmp(alunos[n].cpf,"00000000000") == 0) || (strcmp(alunos[n].cpf,"11111111111") == 0) || (strcmp(alunos[n].cpf,"22222222222") == 0) ||
            (strcmp(alunos[n].cpf,"33333333333") == 0) || (strcmp(alunos[n].cpf,"44444444444") == 0) || (strcmp(alunos[n].cpf,"55555555555") == 0) ||
            (strcmp(alunos[n].cpf,"66666666666") == 0) || (strcmp(alunos[n].cpf,"77777777777") == 0) || (strcmp(alunos[n].cpf,"88888888888") == 0) ||
            (strcmp(alunos[n].cpf,"99999999999") == 0))
        return 1;
    else
    {
        //verificando digito 1
        for(i = 0, j = 10; i < strlen(alunos[n].cpf)-2; i++, j--)
            digito1 += (alunos[n].cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((alunos[n].cpf[9]-48) != digito1)
            return 1;
        else
        //verificando digito 2
        {
            for(i = 0, j = 11; i < strlen(alunos[n].cpf)-1; i++, j--)
                    digito2 += (alunos[n].cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((alunos[n].cpf[10]-48) != digito2)
            return 1;
        }
    }
    return 0;
}