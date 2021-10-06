  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjetoEscola.h"
#include <time.h>

void listarProfessores (Professores professores[], int qtd_professores){
    if(qtd_professores<0){
        printf("\nNão existem professores cadastrados.\n");
    }else{
        printf("\n------------ Listagem de professores ------------n");
        int i;

        for(i=0;i<qtd_professores;i++){
            printf("\n");
            printf("Matrícula .....:  %d\n", professores[i].matricula);
            printf("Nome .....:  %s\n", professores[i].nome);
            printf("Sexo .....:  %c\n", professores[i].sexo);
            printf("Data de nascimento .....:  %d/%d/%d\n", professores[i].data_nasc.dia, professores[i].data_nasc.mes, professores[i].data_nasc.ano);
            printf("CPF .....:  %s\n", professores[i].cpf);
        }
    }
}

int inserirProfessor (Professores professores[], int qtd_professores){
    
    int validardata=0, validarcpf=0;
    int validarData_prof(Professores professores[], int n);
    int validarCPF_prof(Professores professores[], int n);

        printf("\n------------ Cadastro do professor ------------\n");

        printf("\nDigite a matrícula do professor(a)...: ");
        scanf("%d",&professores[qtd_professores].matricula);
        setbuf(stdin, 0);
        
        if (professores[qtd_professores].matricula<=0){
            return erro_matricula;
        }

        printf("\nDigite o nome do professor(a)...: ");
        fgets(professores[qtd_professores].nome, 100, stdin); 
        size_t ln = strlen(professores[qtd_professores].nome) - 1; //size_t = unsigned integer type
        if (professores[qtd_professores].nome[ln] == '\n'){
            professores[qtd_professores].nome[ln] = '\0';
        }
            
        printf("\nDigite o sexo do professor(a)...: ");
        scanf("%c", &professores[qtd_professores].sexo); 
        if (professores[qtd_professores].sexo != 'M' && professores[qtd_professores].sexo != 'F' && professores[qtd_professores].sexo != 'm' && professores[qtd_professores].sexo != 'f') {
            return erro_sexo;
        }

        printf("\nDigite o dia de nascimento do professor(a)....: ");
        scanf("%d", &professores[qtd_professores].data_nasc.dia);
    
        printf("\nDigite o mes de nascimento do professor(a)....: ");
        scanf("%d", &professores[qtd_professores].data_nasc.mes);
    
        printf("\nDigite o ano de nascimento do professor(a)....: ");
        scanf("%d", &professores[qtd_professores].data_nasc.ano);
        setbuf(stdin, 0);
        validardata = validarData_prof(professores, qtd_professores);
        if(validardata==1){
            return erro_data_nasc;
        }

        printf("\nDigite o CPF do professor(a)[apenas números]....: ");
        fgets(professores[qtd_professores].cpf, 16, stdin); 
        ln = strlen(professores[qtd_professores].cpf) - 1; 
        if (professores[qtd_professores].cpf[ln] == '\n'){
            professores[qtd_professores].cpf[ln] = '\0';
        }
        
        validarcpf = validarCPF_prof(professores, qtd_professores);
        if(validarcpf==1){
            return erro_cpf;
        }
        
        return sucesso;
}

int excluirProfessor (Professores professores[], int qtd_professores){
    
    int i, matricula, posicao = -1;
    if(qtd_professores<0){
        return -2;
    }
    printf("\n------------ Exclusão do professor ------------\n");
    printf("\nInforme a matrícula do professor(a) a ser excluído(a): ");
    scanf("%d", &matricula);

    for(i = 0;  i < qtd_professores; i++){
        if(matricula == professores[i].matricula){
            posicao = i;
        }
    }

    if(posicao == -1){
        return 0;
    }
    else{
        for(i = posicao; i < qtd_professores; i++){
        professores[i] = professores[i + 1];
        }
        return 1;
    }
}

void listar_por_sexo_prof(Professores professores[], int qtd_prof){

    int i, sexo=0,achou=0;
    char sexo_informado;

    if(qtd_prof<0){
        printf("\nNão existem professores cadastrados.\n");
    }else{ 
        setbuf(stdin, 0);
        printf("\nDigite o sexo a ser listado...: ");
        scanf("%c",&sexo_informado);
        if(sexo_informado == 'm' || sexo_informado == 'M'){
            printf("\n------------ Sexo masculino ------------\n");
                for(i=0;i<qtd_prof;i++){
                    if(professores[i].sexo == 'm' || professores[i].sexo == 'M'){
                        printf("\n");
                        printf("Matrícula .....:  %d\n",professores[i].matricula);
                        printf("Nome .....:  %s\n",professores[i].nome);
                        printf("Sexo .....:  %c\n",professores[i].sexo); 
                        printf("Data de nascimento .....:  %d/%d/%d\n",professores[i].data_nasc.dia, professores[i].data_nasc.mes, professores[i].data_nasc.ano);
                        printf("CPF .....:  %s\n",professores[i].cpf);
                        achou=1;
                    }else{
                        sexo=1;
                    }
                }
                if(sexo==1 && achou==0){
                    printf("\nNão existem professores do sexo masculino cadastrados.\n");
                }
        }else if(sexo_informado == 'f' || sexo_informado == 'F'){
            printf("\n\n");
    
            printf("\n------------ Sexo feminino ------------\n");
            for(i=0;i<qtd_prof;i++){
                if(professores[i].sexo == 'f' || professores[i].sexo == 'F'){
                    printf("\n");
                    printf("Matrícula .....:  %d\n",professores[i].matricula);
                    printf("Nome .....:  %s\n",professores[i].nome);
                    printf("Sexo .....:  %c\n",professores[i].sexo); 
                    printf("Data de nascimento .....:  %d/%d/%d\n",professores[i].data_nasc.dia, professores[i].data_nasc.mes, professores[i].data_nasc.ano);
                    printf("CPF .....:  %s\n",professores[i].cpf);
                    achou=1;
                }else{
                    sexo=1;
                }
            }
            if(sexo==1 && achou==0){
                printf("\nNão existem professores do sexo femininos cadastrados.\n");  
            }
        }
    } 
}

void listarProf_data_nasc (Professores professores[], int qtd_professores){

    int i, j;
    Professores aux;

    printf("\n---------- Listagem de Professores por ordem de nascimento ----------\n");
    if(qtd_professores <= 0){
        printf("\nNão existem alunos cadastrados.\n");
    }

    for(i = 0; i < qtd_professores - 1; i++)
    {
       if(professores[i+1].data_nasc.ano >= professores[i].data_nasc.ano)
        {
            aux = professores[i];
            professores[i] = professores[i+1];
            professores[i+1] = aux;
        }
    }

    for(i = 0; i < qtd_professores - 1; i++)
    {
        if(professores[i+1].data_nasc.mes >= professores[i].data_nasc.mes && professores[i+1].data_nasc.ano >= professores[i].data_nasc.ano){
            aux = professores[i];
            professores[i] = professores [i+1];
            professores[i+1] = aux;
        }
    }
    
    for(i = 0; i < qtd_professores - 1; i++){
        if(professores[i+1].data_nasc.dia >= professores[i].data_nasc.dia && professores[i+1].data_nasc.mes >= professores[i].data_nasc.mes && professores[i+1].data_nasc.ano >= professores[i].data_nasc.ano){
            aux = professores[i];
            professores[i] = professores [i+1];
            professores[i+1] = aux;
        }
    }

    for(i = 0; i < qtd_professores; i++)
    {
        printf("\nMatrícula .....:  %d\n",professores[i].matricula);
        printf("Nome .....:  %s\n",professores[i].nome);
        printf("Sexo .....:  %c\n",professores[i].sexo);
        printf("Data de nascimento .....:  %d/%d/%d\n",professores[i].data_nasc.dia, professores[i].data_nasc.mes, professores[i].data_nasc.ano);
        printf("CPF .....:  %s\n",professores[i].cpf);
    }
}

int AlterarProf (Professores professores[], int qtd_professores){
    
    setbuf(stdin,0);
    int i, matricula,achei=0,aux=0, validardata=0;
    int validarData_prof(Professores professores[], int n);
    int validarCPF_prof(Professores professores[], int n);

    if(qtd_professores<0){
        return -2;
    }
    printf("\n------------ Alteração do Professor ------------\n");
    printf("\nInforme a matrícula do Professor para alterar: ");
    scanf("%d", &matricula);
    for(i = 0;  i < qtd_professores; i++){
        if(matricula == professores[i].matricula){
            printf("\nDigite a matrícula do Professor...: ");
            scanf("%d",&professores[i].matricula);
            setbuf(stdin, 0);
            if (professores[i].matricula<=0){
                return erro_matricula;
            }

            // Adicionar verificação de matrícula com matrículas já cadastradas.
            printf("\nDigite o nome do Professor...: ");
            fgets(professores[i].nome, 100, stdin); 
            size_t ln = strlen(professores[i].nome) - 1; 
            if (professores[i].nome[ln] == '\n'){
                professores[i].nome[ln] = '\0';
            }
                
            printf("\nDigite o sexo do Professor...: ");
            scanf("%c", &professores[i].sexo); 
            if (professores[i].sexo != 'M' && professores[i].sexo != 'F' && professores[i].sexo != 'm' && professores[i].sexo != 'f') {
                return erro_sexo;
            }

            printf("\nDigite o dia de nascimento do Professor....: ");
            scanf("%d", &professores[i].data_nasc.dia);
        
            printf("\nDigite o mes de nascimento do Professor....: ");
            scanf("%d", &professores[i].data_nasc.mes);
        
            printf("\nDigite o ano de nascimento do Professor....: ");
            scanf("%d", &professores[i].data_nasc.ano);
            setbuf(stdin, 0);
            validardata = validarData_prof(professores, qtd_professores);
            if(validardata==1){
                return erro_data_nasc;
            }

            printf("\nDigite o CPF do Professor(a) [apenas números]....: ");
            fgets(professores[i].cpf, 16, stdin); 
            ln = strlen(professores[i].cpf) - 1; 
            if (professores[i].cpf[ln] == '\n'){
                professores[i].cpf[ln] = '\0';
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

void listar_professor_busca(Professores professor[], int qtd_prof){
    char nome[100];
    int i=0,resultado,achei=0;;
    setbuf(stdin,0);
    printf("\n------------ Buscar Professor ------------\n");

    printf("\nDigite o nome do professor que deseja pesquisar....:  ");
	fgets(nome, 101, stdin);
    size_t ln = strlen(nome) - 1; 
    if (nome[ln] == '\n'){
        nome[ln] = '\0';
    }
	for(i=0;i<qtd_prof;i++){
		resultado=strcmp(professor[i].nome,nome);
		if(resultado==0){
			printf("\n====================================== LISTA DE PROFESSORES COM O NOME: %s =================================\n",nome);
            printf("Matrícula .....:  %d\n", professor[i].matricula);
            printf("Nome .....:  %s\n", professor[i].nome);
            printf("Sexo .....:  %c\n", professor[i].sexo);
            printf("Data de nascimento .....:  %d/%d/%d\n", professor[i].data_nasc.dia, professor[i].data_nasc.mes, professor[i].data_nasc.ano);
            printf("CPF .....:  %s\n", professor[i].cpf);
			achei=1;
		}
	}
	if(achei==0){
		printf("\nProfessor não encontrado.\n");
	}
}

void prof_ordenados_nome(Professores professor[], int qtd_prof){
    int i=0,j=0,r;
    char aux[100];
    if(qtd_prof<0){
        printf("\nNão existem alunos cadastrados.\n");
    }else{
        for(i=0;i<=qtd_prof;i++){
            for(j=i+1;j<=qtd_prof;j++){
                r = strcmp(professor[i].nome, professor[j].nome);
                if(r>0){
                    strcpy(aux,professor[i].nome);
                    strcpy(professor[i].nome, professor[j].nome);
                    strcpy(professor[j].nome, aux);
                }
            }
        }

        for(i=0;i<qtd_prof;i++){
            printf("\n");
            printf("Nome .....:  %s\n",professor[i].nome);
            printf("Matrícula .....:  %d\n",professor[i].matricula);   
            printf("Sexo .....:  %c\n",professor[i].sexo);
            printf("Data de nascimento .....:  %d/%d/%d\n",professor[i].data_nasc.dia, professor[i].data_nasc.mes, professor[i].data_nasc.ano);
            printf("CPF .....:  %s\n",professor[i].cpf);
        }
    }
}

void aniv_mes_prof(Professores professores[], int qtd_professores){

    int i = 0;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    printf("\n--------------- Professores ---------------\n");
    if(qtd_professores < 0){
        printf("\nNão existem professores cadastrados.\n");
    }else{
        for(i = 0; i < qtd_professores; i++){
            if(professores[i].data_nasc.mes == (tm.tm_mon + 1)){
                printf("Matrícula....: %d\n", professores[i].matricula);
                printf("Nome....: %s\n", professores[i].nome);
                printf("Data de nascimento....: %d/%d/%d\n", professores[i].data_nasc.dia, professores[i].data_nasc.mes, professores[i].data_nasc.ano);
                printf("-----\n");
            }
        }
    }
}

int validarData_prof(Professores professores[], int n){

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int bissexto = 0;

    if(professores[n].data_nasc.ano >= 1900 && professores[n].data_nasc.ano <= tm.tm_year + 1900){
        if(professores[n].data_nasc.ano%4==0 && (professores[n].data_nasc.ano%100!=0 || professores[n].data_nasc.ano%400==0)){
            bissexto = 1; //o ano é bissexto
        }else{
            bissexto = -1; //o ano não é bissexto
        }
        
        if(professores[n].data_nasc.mes >= 1 && professores[n].data_nasc.mes <= 12){
            if(professores[n].data_nasc.mes == 4 || professores[n].data_nasc.mes == 6 || professores[n].data_nasc.mes == 9 || professores[n].data_nasc.mes == 11){
                if(professores[n].data_nasc.dia >= 1 && professores[n].data_nasc.dia <= 30){
                    return 0;
                }else{
                    return 1;
                }
            }else{
                if(professores[n].data_nasc.mes == 2){
                    if(bissexto == 1){
                        if(professores[n].data_nasc.dia >= 1 && professores[n].data_nasc.dia <= 29){
                            return 0;
                        }else{
                            return 1;
                        }
                    }
                    else{
                        if(professores[n].data_nasc.dia >= 1 && professores[n].data_nasc.dia <= 28){
                            return 0;
                        }
                        else{
                            return 1;
                        }
                    }
                }else{
                    if(professores[n].data_nasc.dia >= 1 && professores[n].data_nasc.dia <= 31){
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

int validarCPF_prof(Professores professores[], int n){
    
    int i, j, digito1 = 0, digito2 = 0;

    if(strlen(professores[n].cpf) != 11)
        return 1;
    else if((strcmp(professores[n].cpf,"00000000000") == 0) || (strcmp(professores[n].cpf,"11111111111") == 0) || (strcmp(professores[n].cpf,"22222222222") == 0) ||
            (strcmp(professores[n].cpf,"33333333333") == 0) || (strcmp(professores[n].cpf,"44444444444") == 0) || (strcmp(professores[n].cpf,"55555555555") == 0) ||
            (strcmp(professores[n].cpf,"66666666666") == 0) || (strcmp(professores[n].cpf,"77777777777") == 0) || (strcmp(professores[n].cpf,"88888888888") == 0) ||
            (strcmp(professores[n].cpf,"99999999999") == 0))
        return 1;
    else
    {
        //verificando digito 1
        for(i = 0, j = 10; i < strlen(professores[n].cpf)-2; i++, j--)
            digito1 += (professores[n].cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((professores[n].cpf[9]-48) != digito1)
            return 1;
        else
        //verificando digito 2
        {
            for(i = 0, j = 11; i < strlen(professores[n].cpf)-1; i++, j--)
                    digito2 += (professores[n].cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((professores[n].cpf[10]-48) != digito2)
            return 1;
        }
    }
    return 0;
}