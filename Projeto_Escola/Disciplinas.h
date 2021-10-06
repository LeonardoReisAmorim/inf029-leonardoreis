#define TAM_ALUNO_DISC 5

typedef struct Disciplinas
{
    char nome[100]; 
    int codigo, semestre, id_professor, id_aluno[TAM_ALUNO_DISC], qtd_alunos_disc;
}Disciplinas;

int inserirDisciplina (Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof);
void listarDisciplinas(Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof);
int excluirDisciplina (Disciplinas disciplinas[], int qtd_discip);
int inserirAluno_disciplina(Disciplinas disciplinas[], int qtd_discip, Alunos alunos[], int qtd_alunos);
int excluirAluno_disciplina(Disciplinas disciplinas[], int qtd_discip, Alunos alunos[], int qtd_alunos);
void listarDisciplinas_completo(Disciplinas disciplinas[], int qtd_disciplinas, Alunos alunos[], int qtd_aluno);
void listarDisciplinas_mais40(Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof);
int AlterarDisciplina (Disciplinas disciplinas[], int qtd_discip, Professores professores[], int qtd_prof);
void listarAlunos_ate2Disciplinas(Alunos alunos[], int qtd_alunos, Disciplinas disciplinas[], int qtd_discip);