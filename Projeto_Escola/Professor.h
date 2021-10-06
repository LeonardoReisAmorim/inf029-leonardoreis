typedef struct Professores
{
    int matricula;
    char nome[100];
    char sexo; 
    Data data_nasc;
    char cpf[16];
}Professores;

void listarProfessores (Professores professores[], int qtd_professores);
int inserirProfessor (Professores professores[], int qtd_professores);
int excluirProfessor (Professores professores[], int qtd_professores);
void listar_por_sexo_prof(Professores professores[], int qtd_prof);
void listarProf_data_nasc (Professores professores[], int qtd_professores);
int AlterarProf (Professores professores[], int qtd_professores);
void listar_professor_busca(Professores professor[], int qtd_prof);
void prof_ordenados_nome(Professores professor[], int qtd_prof);
void aniv_mes_prof(Professores professores[], int qtd_professores);
int validarData_prof(Professores professores[], int n);
int validarCPF_prof(Professores professores[], int n);
