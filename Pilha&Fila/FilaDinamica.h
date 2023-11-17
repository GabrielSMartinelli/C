#ifndef FILADINAMICA
#define FILADINAMICA

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//estrutura da lista ligada da fila (variavel que recebe a informacao e ponteiro para o proximo nodo)//
typedef struct Nodo_Fila{
    int info;
    struct Nodo_Fila *prox;
}nodo_Fila;

//estrutura da fila dinamica (um nodo que eh o inicio (a cabeca) da lista e outro que eh o fim (ultimo nodo))//
typedef struct {
    nodo_Fila *inicio;
    nodo_Fila *fim;
}Fila;

Fila *cria_Fila();

int vazia_Fila(Fila *f);

void push_Fila(Fila *f, int x);

int pop_Fila(Fila *f);

void Imprime_programa(int n);

int Reinicio(Fila *f);

int Recursao1(Fila *f, nodo_Fila *lista);

int Primeiro(Fila *f, int x);

int Recursao2(nodo_Fila *lista, int x);

int Tamanho_Fila(Fila *f);

int Recursao3(nodo_Fila *lista);

#endif