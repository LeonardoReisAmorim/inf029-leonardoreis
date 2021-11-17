#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int **vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
 
int PosicaoValida(int pos)
{
    return pos<1||pos>10 ? POSICAO_INVALIDA : SUCESSO;
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    if (PosicaoValida(posicao) != SUCESSO)
        return POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao])
        return JA_TEM_ESTRUTURA_AUXILIAR;
    else if (tamanho < 1)
        return TAMANHO_INVALIDO;
    
    vetorPrincipal[posicao] = malloc((tamanho + 1) * sizeof(int**));
    if (!vetorPrincipal[posicao])
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao][0] = malloc(sizeof(int));
    *(vetorPrincipal[posicao][0]) = tamanho;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int Posicao(int pos){
    if (PosicaoValida(pos) != SUCESSO)
        return POSICAO_INVALIDA;
    else if (!vetorPrincipal[pos])
        return SEM_ESTRUTURA_AUXILIAR;
    return 0;
}

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;
    int i = 1;
    while(i <= *(vetorPrincipal[posicao][0])){
        if (!vetorPrincipal[posicao][i]){
            vetorPrincipal[posicao][i] = malloc(sizeof(int));
            *(vetorPrincipal[posicao][i]) = valor;
            return SUCESSO;
        }
        i++;
    }
    return SEM_ESPACO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;

    int i = *(vetorPrincipal[posicao][0]);
    while (i > 0){
        if (vetorPrincipal[posicao][i]){
            free(vetorPrincipal[posicao][i]); vetorPrincipal[posicao][i] = NULL;
            return SUCESSO;
        }
        i--;
    }
    return ESTRUTURA_AUXILIAR_VAZIA;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;

    int i = 1;
    int estruturaVazia = 1;
    while (i <= *(vetorPrincipal[posicao][0])){
        if (vetorPrincipal[posicao][i]){
            estruturaVazia = 0;
            if (*(vetorPrincipal[posicao][i]) == valor){
                free(vetorPrincipal[posicao][i]); 
                return SUCESSO;
            }
        }
        i++;
    }
    return estruturaVazia ? ESTRUTURA_AUXILIAR_VAZIA : NUMERO_INEXISTENTE;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[], int vetTam)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;

    int i=1, j=0;
    while (i <= *(vetorPrincipal[posicao][0]) && j < vetTam){
        if(vetorPrincipal[posicao][i]){
            vetorAux[j] = *(vetorPrincipal[posicao][i]);
            j++;
        }
        i++;
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[], int vetTam)
{
    int ret = 0, i=0, j=0, aux=0;
    
    ret = getDadosEstruturaAuxiliar(posicao, vetorAux, vetTam);

    if (ret==SUCESSO) {
        while (i < vetTam){
            for (j = i + 1; j < vetTam; j++){
                if (vetorAux[j] < vetorAux[i]){
                    aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = aux;
                }
            }
            i++;
        }
    }

    return ret;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[], int vetTam)
{
    int i = 1, j = 0, m = 0;

    while (j < vetTam && i <= TAM){
        if (vetorPrincipal[i]){
            for (m = 1; j < vetTam && m <= *(vetorPrincipal[i][0]); m++){
                if(vetorPrincipal[i][m]){
                    vetorAux[j] = *(vetorPrincipal[i][m]);
                    j++;
                }
            }
        }
        i++;
    }
    return j ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[], int vetTam)
{
    int ret = 0, i=0, j=0, aux=0;

    ret = getDadosDeTodasEstruturasAuxiliares(vetorAux, vetTam);

    if (ret==SUCESSO){
        while (i < vetTam){
            for (j = i + 1; j < vetTam; j++){
                if (vetorAux[j] < vetorAux[i]){
                    aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = aux;
                }
            }
            i++;
        }
    }

    return ret;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;

    int tamAtual, tamNovo, i;

    tamAtual = *(vetorPrincipal[posicao][0]);
    tamNovo = tamAtual + novoTamanho;
    
    if (tamNovo < 1)
        return NOVO_TAMANHO_INVALIDO;
    else if (tamAtual > tamNovo){
        i = tamAtual;
        while (i > tamNovo){
            if (vetorPrincipal[posicao][i]){
                free(vetorPrincipal[posicao][i]); vetorPrincipal[posicao][i] = NULL;
            }
            i--;
        }
    }

    int **nova = realloc(vetorPrincipal[posicao], sizeof(int*) * (tamNovo + 1));

    if (!nova)
        return SEM_ESPACO_DE_MEMORIA;

    if (tamNovo > tamAtual) {
        i = tamAtual+1;
        while (i <= tamNovo){
            nova[i] = NULL;
            i++;
        }
    }

    vetorPrincipal[posicao] = nova;
    *(vetorPrincipal[posicao][0]) = tamNovo;
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if(Posicao(posicao))
        return Posicao(posicao)==POSICAO_INVALIDA ? POSICAO_INVALIDA : SEM_ESTRUTURA_AUXILIAR;

    int Elements = 0, i=1;
    while (i <= *(vetorPrincipal[posicao][0])){
        if (vetorPrincipal[posicao][i])
            Elements++;
        i++;
    }
    return Elements ? Elements : ESTRUTURA_AUXILIAR_VAZIA;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{   
    int i, j=1;

    No *ini = malloc(1 * sizeof(No));

    for (i = 1; i <= TAM; i++) {
        if (vetorPrincipal[i]) {
            while (j <= *(vetorPrincipal[i][0]) && vetorPrincipal[i][j]){
                ini->prox->conteudo = *(vetorPrincipal[i][j]);
                ini = ini->prox;
                j++;
            }
        }
    }
    return ini;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[], int vetTam)
{
    int i = 0;
    No *no = inicio;
    while (no && i < vetTam){
        vetorAux[i] = no->conteudo;
        no = no->prox; i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *no = *inicio;

    while (no){
        No *apagar = no;
        no = no->prox;
        free(apagar);
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
    vetorPrincipal[TAM] = malloc((TAM + 1) * sizeof(int**));
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    int i, j;

    for (i = 1; i <= TAM; i++) {
        if (vetorPrincipal[i]) {
            for (j = 1; j <= *(vetorPrincipal[i][0]); j++) {
                if (vetorPrincipal[i][j]) {
                    free(vetorPrincipal[i][j]);
                }
            }
            free(vetorPrincipal[i][0]);
            free(vetorPrincipal[i]);
        }
    }
    free(vetorPrincipal[0]);
}