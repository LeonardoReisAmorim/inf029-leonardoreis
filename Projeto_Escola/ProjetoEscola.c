#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplinas.h"
#define TAM 5
#define sucesso 1
#define erro_matricula 2
#define erro_data_nasc 3
#define erro_sexo 4
#define erro_cpf 5
#define erro_cod_disciplina 6
#define erro_semestre_disciplina 7

int menu_principal();
int menu_cadastro();
int menu_exclusao();
int menu_alteracao();
int menu_relatorios();

int main()
{
    Alunos alunos[TAM];
    Professores professores[TAM];
    Disciplinas disciplinas[TAM];

    int opcao_principal, opcao_cadastro, opcao_exclusao, opcao_alteracao, opcao_relatorios, qtd_aluno = 0, qtd_prof = 0, qtd_disciplinas = 0, sair = 0, retorno=0,listagem=0;;
    
    while (!sair){
        retorno = 0;
        if(qtd_aluno == -1){
            qtd_aluno = 0;
        }
        if (qtd_prof == -1){
            qtd_prof = 0;
        }
        if (qtd_disciplinas == -1){
            qtd_disciplinas = 0;
        }
        opcao_principal=menu_principal();
        switch (opcao_principal){
            case 0:
                sair = 1;
                break;
            case 1:
                opcao_cadastro=menu_cadastro();
                switch (opcao_cadastro){
                    case 1:
                        retorno = Inseriraluno(alunos, qtd_aluno);
                        if(retorno==1){
                            printf("\nMatrícula realizada com sucesso!\n");
                            qtd_aluno++;
                        }else if (retorno==2){
                            printf("\nMatrícula inválida\n");

                        }else if(retorno == 3){
                            printf("\nData de nascimento inválida.\n");

                        }else if(retorno==4){
                            printf("\nSexo inválido.\n");
                        }else if(retorno == 5){
                            printf("\nCPF inválido.\n");
                        }
                        break;
                    case 2:
                        retorno = inserirProfessor(professores, qtd_prof);
                        if(retorno==1){
                            printf("\nMatrícula realizada com sucesso!\n");
                            qtd_prof++;
                        }else if (retorno==2){
                            printf("\nMatrícula inválida.\n");
                        }else if(retorno == 3){
                            printf("\nData de nascimento inválida.\n");

                        }else if(retorno==4){
                            printf("\nSexo inválido.\n");

                        }else if(retorno == 5){
                            printf("\nCPF inválido.\n");
                        }
                        break;
                    case 3:
                        retorno = inserirDisciplina(disciplinas, qtd_disciplinas, professores, qtd_prof);
                        if(retorno==1){
                            printf("\nCadastro realizado com sucesso!\n");
                            qtd_disciplinas++;
                        }
                        else if(retorno==6){
                            printf("\nCódigo inválido.\n");
                        }
                        else if(retorno==2){
                            printf("\nMatrícula do professor da disciplina inválida.\n");
                        }
                        break;
                    default:
                        printf("Opção inválida\n");
                        break;
                }
                break;
            case 2:
                opcao_exclusao=menu_exclusao();
                switch (opcao_exclusao){
                case 1:
                    if(qtd_aluno==0){
                        qtd_aluno=-1;
                    }
                    retorno = excluirAluno(alunos, qtd_aluno);
                    if(retorno == 1)
                    {
                        printf("\nExclusão realizada com sucesso!\n");
                        qtd_aluno--;
                    }
                    else if(retorno==0){
                        printf("Erro na exclusão. A matrícula informada é inválida.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem alunos cadastrados.\n");
                    }
                    break;
                case 2:
                    if(qtd_prof==0){
                        qtd_prof=-1;
                    }
                    retorno = excluirProfessor(professores, qtd_prof);
                    if(retorno == 1)
                    {
                        printf("\nExclusão realizada com sucesso!\n");
                        qtd_prof--;
                    }
                    else if(retorno==0){
                        printf("Erro na exclusão. A matrícula informada é inválida.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem professores cadastrados.\n");
                    }
                    break;
                case 3:
                    if(qtd_disciplinas==0){
                        qtd_disciplinas=-1;
                    }
                    retorno = excluirDisciplina(disciplinas, qtd_disciplinas);
                    if(retorno == 1)
                    {
                        printf("\nExclusão realizada com sucesso!\n");
                        qtd_disciplinas--;
                    }
                    else if(retorno==0){
                        printf("Erro na exclusão. O codigo informado é invalido.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem disciplinas cadastradas.\n");
                    }
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
                }
                break;
            case 3:
                opcao_alteracao=menu_alteracao(); 
                switch (opcao_alteracao){
                case 1:
                    if(qtd_aluno==0){
                        qtd_aluno=-1;
                    }
                    retorno = AlterarAluno(alunos, qtd_aluno);
                    //printf("\nretorno alteracao aluno %d\n",retorno);
                    if(retorno==1){
                        printf("\nAlteração realizada com sucesso!\n");
                    }else if (retorno==2){
                        printf("\nMatrícula inválida na alteração.\n");
                    }else if(retorno == 3){
                        printf("\nData de nascimento inválida.\n");
                    }else if(retorno==4){
                        printf("\nSexo inválido\n");
                    }else if(retorno==-1){
                        printf("\nErro na alteração. A matrícula informada para alteração é inválida.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem alunos cadastrados.\n");
                    }
                    break;
                case 2:
                   if(qtd_prof==0){
                        qtd_prof=-1;
                    }
                    retorno = AlterarProf(professores, qtd_prof);
                    //printf("\nretorno alteracao aluno %d\n",retorno);
                    if(retorno==1){
                        printf("\nAlteração realizada com sucesso!\n");
                    }else if (retorno==2){
                        printf("\nMatrícula inválida na alteração.\n");
                    }else if(retorno == 3){
                        printf("\nData de nascimento inválida.\n");
                    }else if(retorno==4){
                        printf("\nSexo inválido\n");
                    }else if(retorno==-1){
                        printf("\nErro na alteração. A matricula informada para alteração é inválida.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem professores cadastrados.\n");
                    }
                    break;
                case 3:
                    if(qtd_disciplinas==0){
                        qtd_disciplinas=-1;
                    }
                    retorno = AlterarDisciplina(disciplinas, qtd_disciplinas, professores, qtd_prof);
                    //printf("\nretorno alteracao aluno %d\n",retorno);
                    if(retorno==1){
                        printf("\nAlteração realizada com sucesso!\n");
                    }else if (retorno==6){
                        printf("\nCódigo inválido.\n");
                    }else if(retorno == 7){
                        printf("\nSemestre inválido.\n");
                    }else if(retorno==-1){
                        printf("\nErro na alteração. O código informado para alteração é inválido.\n");
                    }else if(retorno==-2){
                        printf("\nNão existem disciplinas cadastradas.\n");
                    }else if(retorno==-3){
                        printf("\nMatrícula do professor da disciplina inválida.\n");
                    }
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
                break;
            case 4:
                printf("Inserir aluno em uma disciplina\n");
                retorno = inserirAluno_disciplina(disciplinas, qtd_disciplinas, alunos, qtd_aluno);
                if(retorno == 1)
                {
                    printf("\nCadastro realizado com sucesso!\n");
                }
                else if(retorno == 6)
                {
                    printf("\nO código da disciplina informado está incorreto.\n");
                }
                break;
            case 5:
                printf("Excluir aluno de uma disciplina\n");
                retorno = excluirAluno_disciplina(disciplinas, qtd_disciplinas, alunos, qtd_aluno);
                if(retorno == 1)
                {
                    printf("\nExclusão realizada com sucesso!\n");
                }
                else if(retorno == 6)
                {
                    printf("\nO código da disciplina informado está incorreto.\n");
                }else if(retorno == 2){
                    printf("\nA matricula informada está incorreta.\n");                
                }
                break;
            case 6:
                opcao_relatorios=menu_relatorios();
                switch (opcao_relatorios){
                    case 1:
                        if(qtd_aluno==0){
                            qtd_aluno=-1;
                        }
                        Listaralunos(alunos, qtd_aluno);
                        break;
                    case 2:
                        if(qtd_prof==0){
                            qtd_prof=-1;
                        }
                        listarProfessores(professores, qtd_prof);
                        break;
                    case 3:
                        if(qtd_disciplinas==0){
                            qtd_disciplinas=-1;
                        }
                        listarDisciplinas(disciplinas, qtd_disciplinas, professores, qtd_prof);
                        break;
                    case 4:
                        if(qtd_disciplinas==0){
                            qtd_disciplinas=-1;
                        }
                        if(qtd_aluno==0){
                            qtd_aluno=-1;
                        }
                        listarDisciplinas_completo(disciplinas, qtd_disciplinas, alunos, qtd_aluno);
                        break;
                    case 5:
                        if(qtd_aluno==0){
                            qtd_aluno=-1;
                        }
                        listar_por_sexo(alunos, qtd_aluno);
                        break;
                    case 6:
                        if(qtd_aluno==0){
                            qtd_aluno=-1;
                        }
                        alunos_ordenados_nome(alunos, qtd_aluno);
                        break;
                    case 7:
                        //listar alunos por ordem de data de nascimento
                        if(qtd_aluno==0){
                            qtd_aluno=-1;
                        }
                        listarAluno_data_nasc(alunos, qtd_aluno);
                        break;
                    case 8:
                        if(qtd_prof==0){
                            qtd_prof=-1;
                        }
                        listar_por_sexo_prof(professores, qtd_prof);
                        break;
                    case 9:
                       if(qtd_prof==0){
                            qtd_prof=-1;
                        }
                        prof_ordenados_nome(professores, qtd_prof);
                        break;
                    case 10:
                        //listagem de professores por ordem de data de nascimento
                        if(qtd_prof==0){
                            qtd_prof=-1;
                        }
                        listarProf_data_nasc (professores, qtd_prof);
                        break;
                    case 11:
                        /* Aniversariantes do mês */
                        printf("\n************** ANIVERSARIANTES DO MÊS **************\n");
                        if(qtd_aluno == 0){
                            qtd_aluno = -1;
                        }
                        aniv_mes_alunos(alunos, qtd_aluno);
                        if(qtd_prof == 0){
                            qtd_prof = -1;
                        }
                        aniv_mes_prof(professores, qtd_prof);
                        break;
                    case 12:
                        printf("\nEscolha:\n1 - Professor\n2 - Aluno\n");
                        scanf("%d",&listagem);
                        if(listagem==1){
                            listar_professor_busca(professores,qtd_prof);
                        }else if(listagem==2){
                            listar_aluno_busca(alunos, qtd_aluno);
                        }else{
                            printf("\nOpção inválida.");
                        }
                        break;
                    case 13:
                        /* alunos matriculados em menos de 3 disciplinas */
                        if(qtd_aluno == 0){
                            qtd_aluno = -1;
                        }
                        if(qtd_disciplinas == 0){
                            qtd_disciplinas = -1;
                        }
                        listarAlunos_ate2Disciplinas(alunos,qtd_aluno,disciplinas,qtd_disciplinas);
                        break;
                    case 14:
                        if(qtd_disciplinas == 0){
                            qtd_disciplinas = -1;
                        }
                        listarDisciplinas_mais40(disciplinas, qtd_disciplinas, professores, qtd_prof);
                        break;

                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                break;
            default:
                printf("Opção inválida.\n");
                sair=1;
            break;
        }
    }
    
    return 0;
}

int menu_principal(){
    int opcao=0;

    printf("\n=============================== MENU PRINCIPAL ===============================\n");
    printf("\nDigite a opção:\n");
    printf("0 - Sair\n");
    printf("1 - Cadastro\n");
    printf("2 - Exclusão\n");
    printf("3 - Alteração\n");
    printf("4 - Inserir aluno em uma disciplina\n");
    printf("5 - Excluir aluno de uma disciplina\n");
    printf("6 - Relatórios\n");
    printf("\n==============================================================================\n");
    scanf("%d",&opcao);

    return opcao;
}

int menu_cadastro(){
    int opcao=0;

    printf("\n=============================== MENU CADASTROS ===============================\n");
    printf("\nDigite a opção:\n");
    printf("1 - Cadastro de Aluno\n");
    printf("2 - Cadastro de Professor\n");
    printf("3 - Cadastro de Disciplina\n");
    printf("\n==============================================================================\n");
    scanf("%d",&opcao);

    return opcao;
}

int menu_exclusao(){
    int opcao=0;

    printf("\n================================ MENU EXCLUSÃO ===============================\n");
    printf("\nDigite a opção:\n");
    printf("1 - Excluir Aluno\n");
    printf("2 - Excluir Professor\n");
    printf("3 - Excluir Disciplina\n");
    printf("\n==============================================================================\n");
    scanf("%d",&opcao);

    return opcao;
}

int menu_alteracao(){
    int opcao=0;

    printf("\n=============================== MENU ALTERAÇÃO ===============================\n");
    printf("\nDigite a opção:\n");
    printf("1 - Alterar Aluno\n");
    printf("2 - Alterar Professor\n");
    printf("3 - Alterar Disciplina\n");
    printf("\n==============================================================================\n");
    scanf("%d",&opcao);

    return opcao;
}

int menu_relatorios(){
    int opcao=0;

    printf("\n=============================== MENU RELATÓRIOS ==============================\n");
    printf("\nDigite a opção:\n");
    printf("1 - Listar Alunos:\n");
    printf("2 - Listar Professores:\n");
    printf("3 - Listar Disciplinas (dados da disciplina sem os alunos):\n");
    printf("4 - Listar uma disciplina (dados da disciplina e os alunos matriculados):\n");
    printf("5 - Listar Alunos por sexo (Masculino/Feminino):\n");
    printf("6 - Listar Alunos ordenados por Nome:\n");
    printf("7 - Listar Alunos ordenados por data de nascimento:\n");
    printf("8 - Listar Professores por sexo (Masculino/Feminino):\n");
    printf("9 - Listar Professores ordenados por Nome:\n");
    printf("10 - Listar Professores ordenados por data de nascimento:\n");
    printf("11 - Aniversariantes do mês:\n");
    printf("12 - Lista de pessoas (professor/aluno) a partir de uma busca:\n");
    printf("13 - Lista de alunos matriculados em menos de 3 disciplinas:\n");
    printf("14 - Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.:\n");
    printf("\n==============================================================================\n");
    scanf("%d",&opcao);

    return opcao;
}