#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProjetoEscola.h"

int inserirDisciplina (Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof){
    int i,j;
    qtd_prof--;
    setbuf(stdin, 0);

    printf("\n------------ Cadastro de Disciplinas ------------\n");

    printf("\nDigite o código da disciplina: ");
    scanf("%d", &disciplinas[qtd_discip].codigo);
    setbuf(stdin, 0);

    if(disciplinas[qtd_discip].codigo <= 0){
        return erro_cod_disciplina;
    }

    printf("\nDigite o nome da disciplina: ");
    fgets(disciplinas[qtd_discip].nome, 100, stdin); 
    size_t ln = strlen(disciplinas[qtd_discip].nome) - 1; //size_t = unsigned integer type
    if (disciplinas[qtd_discip].nome[ln] == '\n'){
        disciplinas[qtd_discip].nome[ln] = '\0';
    }

    printf("\nInforme o semestre da disciplina: ");
    scanf("%d", &disciplinas[qtd_discip].semestre);
    setbuf(stdin, 0);

    if(disciplinas[qtd_discip].semestre <= 0){
        return erro_semestre_disciplina;
    }

    printf("\nInforme a matrícula do professor da disciplina: ");
    scanf("%d", &disciplinas[qtd_discip].id_professor);
    setbuf(stdin, 0);
    
    //Verificando se a matricula informada é válida e já foi cadastrada.
    for(i = 0; i <= qtd_discip; i++){
        for (j=0; j<=qtd_prof; j++){
           if(disciplinas[i].id_professor == professores[j].matricula){
                return sucesso;
           }
        }
    }
    return erro_matricula;
}

void listarDisciplinas(Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof){
    int i,j;
    
    if(qtd_discip<0){
        printf("\nNão existem disciplinas cadastradas.\n");
    }else{
        printf("\n------------ Listagem de disciplinas ------------\n");

        for(i = 0; i < qtd_discip; i++){
            printf("\n");
            printf("Codigo .....:  %d\n", disciplinas[i].codigo);
            printf("Nome .....:  %s\n", disciplinas[i].nome);
            printf("Semestre .....:  %d\n", disciplinas[i].semestre);
            for(j=0;j<qtd_prof;j++){
                if(disciplinas[i].id_professor == professores[j].matricula){
                    printf("Professor.....:  %s\n", professores[j].nome);
                }
            }
            
        }
    }
}

int excluirDisciplina (Disciplinas disciplinas[], int qtd_discip){

    int i, codigo, posicao = -1;
    if(qtd_discip<0){
        return -2;
    }
    printf("\n------------ Exclusão de disciplina ------------\n");
    printf("\nInforme o código da disciplina a ser excluída: ");
    scanf("%d", &codigo);

    for(i = 0;  i < qtd_discip; i++){
        if(codigo == disciplinas[i].codigo){
            posicao = i;
        }
    }

     if(posicao == -1){
        return 0;
    }
    else{
        for(i = posicao; i < qtd_discip; i++){
        disciplinas[i] = disciplinas[i + 1];
        }
        return sucesso;
    }
}

int inserirAluno_disciplina(Disciplinas disciplinas[], int qtd_discip, Alunos alunos[], int qtd_alunos){
    
    int i, j, matricula, cod;

    printf("\n------- Inserção de alunos nas disciplinas ------\n");
    printf("\nInforme a matrícula do aluno:");
    scanf("%d", &matricula);

    // verificar se matrícula já está cadastrada.

    printf("\nInforme o código da disciplina:");
    scanf("%d", &cod);

    for(i = 0; i < qtd_discip; i++){
        if(cod == disciplinas[i].codigo){
            disciplinas[i].id_aluno[disciplinas[i].qtd_alunos_disc] = matricula;
            disciplinas[i].qtd_alunos_disc++;
            return sucesso;
        }
    }
    return erro_cod_disciplina;
}

int excluirAluno_disciplina(Disciplinas disciplinas[], int qtd_discip, Alunos alunos[], int qtd_alunos){

    int i, j, matricula, cod, posicao1 = -1, posicao2 = -1;

    printf("\nInforme a matricula do aluno que deseja excluir da disciplina: ");
    scanf("%d", &matricula);

    printf("\nInforme o código da disciplina: ");
    scanf("%d", &cod);

    for(i = 0; i < qtd_discip; i++){
        if(cod == disciplinas[i].codigo){
            posicao1 = i;
            for(j = 0;  j < disciplinas[posicao1].qtd_alunos_disc; j++){
                if(matricula == disciplinas[posicao1].id_aluno[j]){
                    posicao2 = j;
                }
            }
         }
    }

    if(posicao1 == -1){
        return 6;
    }
    if(posicao2 == -1){
        return 2;
    }else{
        for(i = posicao2; i < disciplinas[posicao1].qtd_alunos_disc; i++){
            disciplinas[posicao1].id_aluno[i] = disciplinas[posicao1].id_aluno[i + 1];
            disciplinas[posicao1].qtd_alunos_disc--;
        }

        printf("\n");
        printf("Código .....:  %d\n", disciplinas[posicao1].codigo);
        printf("Nome .....:  %s\n", disciplinas[posicao1].nome);
        printf("Semestre .....:  %d\n", disciplinas[posicao1].semestre);
        printf("ID do professor.....:  %d\n", disciplinas[posicao1].id_professor);
        printf("Alunos na disciplina:\n");
        for(j=0; j < disciplinas[posicao1].qtd_alunos_disc; j++){
            printf("%d: %d\n", j+1, disciplinas[posicao1].id_aluno[j]);
        }
        printf("Quantidade de alunos matriculados: %d\n", disciplinas[posicao1].qtd_alunos_disc);

        return sucesso;
    }
}

void listarDisciplinas_completo(Disciplinas disciplinas[], int qtd_discip, Alunos alunos[], int qtd_aluno){
    
    int i, j;

    if(qtd_discip < 0){
        printf("\nNao existem disciplinas cadastradas.\n");
    }else{
        printf("\n------- Listagem de disciplinas com dados e alunos matriculados -------\n");
        for(i = 0; i < qtd_discip; i++)
        {
            printf("\n");
            printf("Código .....:  %d\n", disciplinas[i].codigo);
            printf("Nome .....:  %s\n", disciplinas[i].nome);
            printf("Semestre .....:  %d\n", disciplinas[i].semestre);
            printf("ID do professor.....:  %d\n", disciplinas[i].id_professor);
            printf("Alunos na disciplina:\n");
            if(qtd_aluno<0){
                printf("\nnao existem alunos matriculados");
            }else{
                for(j=0; j < disciplinas[i].qtd_alunos_disc; j++){
                    printf("%d: %d\n", j+1, disciplinas[i].id_aluno[j]);
                }
                printf("\n-----------------------------------------------------------------------\n");
            }
            
        }
    }
}

void listarDisciplinas_mais40(Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof){

    int i = 0, j = 0, vagas = 40, achou = 0;

    if(qtd_discip < 0){
        printf("\nNao existem disciplinas cadastradas.\n");
    }else{
        printf("\n------------ Listagem de disciplinas que extrapolam %d vagas ------------\n", vagas);
        for(i = 0; i < qtd_discip; i++){
            if(disciplinas[i].qtd_alunos_disc > vagas){
                achou++;
                printf("\n");
                printf("Código .....:  %d\n", disciplinas[i].codigo);
                printf("Nome .....:  %s\n", disciplinas[i].nome);
                printf("Semestre .....:  %d\n", disciplinas[i].semestre);
                printf("ID do professor.....:  %d\n", disciplinas[i].id_professor);
                for(j = 0; j < qtd_prof; j++){
                    if(disciplinas[i].id_professor == professores[j].matricula)
                        printf("Nome do professor.....: %s\n", professores[j].nome);
                }
                printf("\n------------------------------------------------------------------------\n");
            }
        }
        if(achou <= 0)
            printf("\nNão foram encontradas disciplinas que extrapolam %d vagas.\n", vagas);
    }
}

int AlterarDisciplina (Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof){

    setbuf(stdin,0);
    int i, codigo, achei=0, aux=0,j;
    if(qtd_discip<0){
        return -2;
    }
    printf("\n------------ Alteracao de Disciplinas ------------\n");
    printf("\nDigite o código da disciplina para alterar: ");
    scanf("%d", &codigo);
    for(i = 0;  i < qtd_discip; i++){
        if(codigo == disciplinas[i].codigo){
            printf("\nDigite o código da disciplina: ");
            scanf("%d", &disciplinas[i].codigo);
            setbuf(stdin, 0);
            if(disciplinas[i].codigo <= 0){
                return erro_cod_disciplina;
            }
            printf("\nDigite o nome da disciplina: ");
            fgets(disciplinas[i].nome, 100, stdin); 
            size_t ln = strlen(disciplinas[i].nome) - 1; //size_t = unsigned integer type
            if (disciplinas[i].nome[ln] == '\n'){
                disciplinas[i].nome[ln] = '\0';
            }
            printf("\nInforme o semestre da disciplina: ");
            scanf("%d", &disciplinas[i].semestre);
            setbuf(stdin, 0);
            if(disciplinas[i].semestre <= 0){
                return erro_semestre_disciplina;
            }
            printf("\nInforme a matrícula do professor da disciplina: ");
            scanf("%d", &disciplinas[i].id_professor);
            setbuf(stdin, 0);
            for (j=0; j<=qtd_prof; j++){
                if(disciplinas[i].id_professor == professores[j].matricula){
                    return sucesso;
                }else{
                    return -3;
                }
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

void listarAlunos_ate2Disciplinas(Alunos alunos[], int qtd_alunos, Disciplinas disciplinas[], int qtd_discip){

    int i = 0, j = 0, k = 0, achou = 0;

    if(qtd_alunos < 0){
        printf("\nNão existem alunos cadastrados.\n");
    }else if(qtd_discip < 0){
            printf("\nNão existem disciplinas cadastradas.\n");
    }else{
        for(i = 0; i < qtd_alunos; i++){
            achou = 0;
            for (j = 0; j < qtd_discip; j++){
                for(k = 0; k < disciplinas[j].qtd_alunos_disc; k++){
                    if(alunos[i].matricula == disciplinas[j].id_aluno[k]){
                    achou++;
                    }
                }
            }
            if(achou < 3){
                printf("\n");
                printf("Nome .....:  %s\n",alunos[i].nome);
                printf("Matrícula .....:  %d\n",alunos[i].matricula);   
                printf("Sexo .....:  %c\n",alunos[i].sexo);
                printf("Data de nascimento .....:  %d/%d/%d\n",alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
                printf("CPF .....:  %s\n",alunos[i].cpf);
                printf("------\n");
            }
        }
    }
}