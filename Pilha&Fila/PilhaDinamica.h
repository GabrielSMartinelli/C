#ifndef PILHADINAMICA
#define PILHADINAMICA

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//estrutura da lista ligada (uma variavel que recebe a informacao e um ponteiro para o proximo nodo)//
typedef struct Nodo{
    int info;
    struct Nodo *prox;
}nodo;

//estrutura da pilha dinamica (a cabeca da lista)//
typedef struct {
    nodo *cabeca;
}Pilha;

Pilha *cria_Pilha();

int vazia_Pilha(Pilha *p);

void push_Pilha(Pilha *p, int x);

int pop_Pilha(Pilha *p);

int operacao(int a, int b, char simb);

int Um_Elemento(Pilha *p);

void Imprime_empilha(int a);

void Imprime_desempilha(int a, int b, int c);

void Imprime_fim(int a, int b, int c);

void Imprime_erro();

#endif