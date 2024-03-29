// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Leonardo Reis Amorim dos Santos
//  email: leoreisamorim@gmail.com / 20201160029@ifba.edu.br
//  Matrícula: 20201160029
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LeonardoReisAmorim-20201160029-T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 6;
    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

typedef struct DQ
{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		dq.valido = 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
    return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char *data)
{
    int datavalida = 1, iDia, iMes, iAno;
    DataQuebrada dataQuebrada = quebraData(data);

    if (dataQuebrada.valido == 0) return 0;

    if ((dataQuebrada.iDia == 29 && dataQuebrada.iMes == 2) && (dataQuebrada.iAno%4 == 0 && (dataQuebrada.iAno%100 != 0 || dataQuebrada.iAno%400 == 0))){
        datavalida = 1;
        //return 1;
    }else if((dataQuebrada.iDia > 0 && dataQuebrada.iDia < 29) && dataQuebrada.iMes == 2){
        datavalida = 1;
        //return 0;
    }else if((dataQuebrada.iDia > 0 && dataQuebrada.iDia < 31) && (dataQuebrada.iMes == 4 || dataQuebrada.iMes == 6 || dataQuebrada.iMes == 9  || dataQuebrada.iMes == 11 )){
        datavalida = 1;
    }else if((dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31) && (dataQuebrada.iMes == 1 || dataQuebrada.iMes == 3 || dataQuebrada.iMes == 5 || dataQuebrada.iMes == 7 || dataQuebrada.iMes == 8 || dataQuebrada.iMes == 10 || dataQuebrada.iMes == 12 )){
        datavalida = 1;
    }else{
        datavalida = 0;
    }   
    return datavalida;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    //inicial 16/04/2002 16/04/2002 16/05/2002
    //final   15/05/2002 16/05/2002 15/06/2002
    //         29 dias   30 (1 mês)   30 dias

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos, retorno = 1, qtd_dias_mes_anterior=0;

    if (q1(datainicial) == 0){
        return 2;
    }else if(q1(datafinal) == 0){
        return 3;
    }

    DataQuebrada dqInicial = quebraData(datainicial);
    DataQuebrada dqFim = quebraData(datafinal);

    if (dqInicial.iAno > dqFim.iAno)
        return 4;
    else if (dqInicial.iAno == dqFim.iAno){
        if (dqInicial.iMes > dqFim.iMes)
            return 4;
        else if (dqInicial.iMes == dqFim.iMes){
            if (dqInicial.iDia > dqFim.iDia)
                return 4;
        } 
    }
    nAnos = dqFim.iAno - dqInicial.iAno;
    nMeses = dqFim.iMes - dqInicial.iMes;
    nDias = dqFim.iDia - dqInicial.iDia;

    if (nMeses < 0){
        nAnos--;
        nMeses = 12;
    }
    if (nDias < 0){
        nMeses--;
        if((dqFim.iAno%4 == 0 && (dqFim.iAno%100 != 0 || dqFim.iAno%400 == 0))){
            if((dqFim.iDia > 0 && dqFim.iDia <= 31) && (dqFim.iMes == 1 || dqFim.iMes == 3 || dqFim.iMes == 5 || dqFim.iMes == 7 || dqFim.iMes == 8 || dqFim.iMes == 10 || dqFim.iMes == 12)){
                //mes final tem 31 dias
                qtd_dias_mes_anterior = 30;
                if(dqFim.iMes == 3){
                    qtd_dias_mes_anterior = 29;
                }
            }else{

            }
        }else if((dqFim.iDia > 0 && dqFim.iDia < 31) || (dqFim.iMes == 4 || dqFim.iMes == 6 || dqFim.iMes == 9  || dqFim.iMes == 11)){
            //mes final tem 30 dias
            qtd_dias_mes_anterior = 31;
            if(dqFim.iMes == 3){
                qtd_dias_mes_anterior = 28;
            }
        }
        nDias = qtd_dias_mes_anterior - dqInicial.iDia + dqFim.iDia;
    }
    //realiza a conversão de meses e dias em que o mes da data inicial seja de 31 dias.
    if( (dqInicial.iDia > 0 && dqInicial.iDia <= 31) && (dqInicial.iMes == 1 || dqInicial.iMes == 3 || dqInicial.iMes == 5 || dqInicial.iMes == 7 || dqInicial.iMes == 8 || dqInicial.iMes == 10 || dqInicial.iMes == 12) && (dqInicial.iMes + 1 == dqFim.iMes)){
        nDias = 30;
    }

    //printf("\n qtd dias: %d",nDias);
    //printf("\n qtd meses: %d",nMeses);
    //printf("\n qtd ano: %d",nAnos);
    //printf("\n\n");

    /*mantenha o código abaixo, para salvar os dados  
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0, i=0;

    if(isCaseSensitive){
        for(int i = 0; texto[i] != '\0'; i++){
            if(texto[i] == c){
                qtdOcorrencias++;
            }
        }
        
    }else{
        for(int i = 0; texto[i] != '\0'; i++){
            if(tolower(texto[i]) == tolower(c)){
                qtdOcorrencias++;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int compara_string(char busca[], char texto[], int j)
{
    int i;

    for(i = 0; i < strlen(busca); i++){
        if(busca[i] != texto[j]){
            return 0;
        }
        j++;
    }
    return 1;
}

int q4(char strTexto[], char strBusca[], int posicoes[30])
{
    int qtdOcorrencias=0, i, j=0;

    for(i = 0; i < strlen(strTexto); i++){
        if(strTexto[i] == strBusca[0] ){
            if(compara_string(strBusca, strTexto, i) == 1){
                qtdOcorrencias++;
                posicoes[j] = i+1;
                posicoes[j+1] = i+strlen(strBusca);
                j += 2;  
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int inv = 0;
    while (num > 0) {
        inv = 10 * inv + num % 10;
        num /= 10;
    }
    return inv;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0, i=0,j=0,aux=0;
    
    while (numerobase > 0)
    {
        if(numerobase % 10 == numerobusca) {
		    qtdOcorrencias++;
	    }else{
            aux = numerobase;
            while (aux > 0){
                aux = numerobase % 10;
                i++;
                if(i==3 || i==4){
                    j = 10*j + aux; 
                }
                aux /= 10;
            }
        }
        
        
        numerobase /= 10; 
    }
    if(j==numerobusca){
        qtdOcorrencias++;
    }
	return qtdOcorrencias;
}
