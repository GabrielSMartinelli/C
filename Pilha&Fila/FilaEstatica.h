#ifndef FILAESTATICA
#define FILAESTATICA

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//estrutura da fila estatica (um vetor e variaveis que apontam o inicio e o final da fila no vetor)//
typedef struct {
    int v[MAX];
    int inicio, fim;
}Fila;

Fila *cria_Fila();

int vazia_Fila(Fila *f);

void push_Fila(Fila *f, int x);

int pop_Fila(Fila *f);

void Imprime_programa(int n);

int Reinicio(Fila *f);

int Primeiro(Fila *f, int x);

int Tamanho_Fila(Fila *f);

#endif