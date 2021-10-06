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
    char cpf[13];
}Alunos;

void Listaralunos(Alunos alunos[], int qtd_alunos);
int Inseriraluno(Alunos alunos[], int qtd_alunos);
int excluirAluno (Alunos alunos[], int qtd_alunos);
void listar_por_sexo(Alunos alunos[], int qtd_alunos);
void listar_aluno_busca (Alunos alunos[], int qtd_alunos);
void listarAluno_data_nasc (Alunos alunos[], int qtd_alunos);
int AlterarAluno (Alunos alunos[], int qtd_alunos);
void alunos_ordenados_nome(Alunos alunos[], int qtd_alunos);
void aniv_mes_alunos(Alunos alunos[], int qtd_alunos);
int validarData_aluno(Alunos alunos[], int n);
int validarCPF_aluno(Alunos alunos[], int n);