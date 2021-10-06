#define TAM 5
#define TAM_ALUNO_DISC 5
#define sucesso 1
#define erro_matricula 2
#define erro_data_nasc 3
#define erro_sexo 4
#define erro_cpf 5
#define erro_cod_disciplina 6
#define erro_semestre_disciplina 7

typedef struct Data
{
    int dia, mes, ano;
}Data;

typedef struct Alunos
{
    int matricula;
    char nome[100];
    char sexo; 
    Data data_nasc;
    char cpf[16];
}Alunos;

typedef struct Professores
{
    int matricula;
    char nome[100];
    char sexo; 
    Data data_nasc;
    char cpf[16];
}Professores;

typedef struct Disciplinas
{
    char nome[100]; 
    int codigo, semestre, id_professor, id_aluno[TAM_ALUNO_DISC], qtd_alunos_disc;
}Disciplinas;