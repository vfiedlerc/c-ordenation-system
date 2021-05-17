#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

///////////////////////////
// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////
// ESTRUTURAS UTILIZADAS
struct vetor
{
    int *v;
    int n;
};

typedef struct vetor Vetor;

///////////////////////////
// VARIAVEIS GLOBAIS
unsigned long trocas;
unsigned long comparacoes;
clock_t tempoGasto;

/////////////////////////////////////
// PROTOTIPOS DAS FUNCOES UTILIZADAS

void mergesort(int [], int);
void Sort(int *v, int *c, int i, int f);
void Merge(int *v, int *c, int i, int m, int f);

void Heapsort(int v[], int);



/*
    M�TODO DE ORDENA��O POR INSER��O
    RECEBE UM ARRAY DE INTEIROS E O TAMANHO DO MESMO COMO PARAMETRO
    RESPONS�VEL POR ORDENAR O ARRAY PASSADO EM ORDEM CRESCENTE
*/
void Insercao (int[], int);

/*
    M�TODO DE ORDENA��O POR SELECAO
    RECEBE UM ARRAY DE INTEIROS E O TAMANHO DO MESMO COMO PARAMETRO
    RESPONS�VEL POR ORDENAR O ARRAY PASSADO EM ORDEM CRESCENTE
*/
void Selecao (int[], int);

/*
    M�TODO DE ORDENA��O POR SHELL-SORT
    RECEBE UM ARRAY DE INTEIROS E O TAMANHO DO MESMO COMO PARAMETRO
    RESPONS�VEL POR ORDENAR O ARRAY PASSADO EM ORDEM CRESCENTE
*/
void Shell(int[], int);

/*
    M�TODO DE ORDENA��O POR QUICK-SORT
    RECEBE UM ARRAY DE INTEIROS E O TAMANHO DO MESMO COMO PARAMETRO
    RESPONS�VEL POR ORDENAR O ARRAY PASSADO EM ORDEM CRESCENTE
*/
void Quick(int[], int, int);

/*
    M�TODO DE IMPRIMIR
    RECEBE UM ARRAY DE INTEIROS E O TAMANHO DO MESMO COMO PARAMETRO
    RESPONS�VEL POR EXIBIR TODOS ELEMENTOS ARRAY PASSADO COMO PARAMETRO
*/
void Imprimir(int[],int);

/*
    M�TODO DE LIMPAR TELA
    RECEBE NADA COMO PARAMETRO
    RESPONS�VEL POR DAR UMA PAUSA NA TELA E LIMPAR A MESMA AP�S QUALQUER TECLA SER PRESSIONADA
*/
void LimparTela();

/*
    M�TODO DE LER UM INTEIRO
    RECEBE UMA FRASE QUE SERA EXIBIDO AO PEDIR O USUARIO INFORMAR UM VALOR
    RESPONS�VEL POR RETORNAR O INTEIRO DIGITADO PELO USUARIO
    ( FOI CRIADA PARA EVITAR CRIAR VARIAS VEZES PRINTF, FFLUSH E SCANF DURANTE A APLICACAO... )
*/
int LerInteiro(char[]);

/*
    M�TODO DE CARREGAR UM VETOR
    RECEBE O ENDERECO DE UMA STRUCT VETOR PASSADA POR PARAMETRO
    RESPONS�VEL POR PEDIR AO USUARIO INFORMAR OS DADOS DO ARQUIVO DE ONDE SER� CARREGADO O VETOR PARA O VETOR PASSADO POR PARAMETRO
    RETORNA 1 EM CASO DE SUCESSO E 0 EM CASO DE FALHA
*/
int CarregarArquivo(Vetor*);

/*
    M�TODO DE CRIAR UM ARQUIVO COM N ELEMENTOS
    RECEBE O TIPO DO ARQUIVO A SER CRIADO (1.CRESCENTE,2.DECRESCENTE,3.ALEATORIO) E A QUANTIDADE DE ELEMENTOS A SER GERADO NO ARQUIVO
    RESPONS�VEL POR GERAR NO ARQUIVO 'TIPO_TAMANHO.dat' OS ELEMENTOS DISPOSTOS DA FORMA QUE O USUARIO INFORMOU NO PRIMEIRO PARAMETRO DA FUN��O
    RETORNA 1 EM CASO DE SUCESSO E 0 EM CASO DE FALHA
*/
int CriarArquivo(int,int);

/*
    M�TODO DE LIBERAR UM VETOR
    RECEBE O ENDERE�O DE UMA STRUCT VETOR COMO PARAMETRO
    RESPONS�VEL POR LIBERAR O VETOR CASO JA ESTEJA INICIALIZADO E RESETAR O TAMANHO DO VETOR
*/
void LiberarVetor(Vetor*);
/*
    M�TODO DE RESETAR CONTADORES
    RESPONS�VEL POR RESETAR AS VARIAVEIS GLOBAIS PARA O VALOR 0
*/
void ResetarContadores();

/*
    M�TODO DE EXIBIR OS DADOS OBTIDOS APOS UMA ORDENACAO
    RECEBE O NOME DO M�TODO PREVIAMENTE UTILIZADO E O TAMANHO DO ARRAY PREVIAMENTE ORDENADO
    EXIBE NA TELA AS TROCAS, COMPARACOES E TEMPO GASTO
*/
void ImprimirRelatorioOrdenacao(char metodo[], int n);

void MenuAnaliseComparativa();
void MenuConstrucaoArquivos();
void MenuPrincipal();

#endif // FUNC_H_INCLUDED
