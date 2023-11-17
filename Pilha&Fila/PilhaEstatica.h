#ifndef PILHAESTATICA
#define PILHAESTATICA

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*estrutura da pilha estatica (um vetor com os elementos e uma variavel que mostra
a posicao no vetor do elemento que esta no topo da pilha)*/
typedef struct {
    int v[MAX];
    int topo;
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