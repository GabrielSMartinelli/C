#include "PilhaDinamica.h"

//funcao que cria a pilha dinamica, armazenando um espaco de pilha (struct)//
Pilha *cria_Pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->cabeca = NULL;
    return p;
}

//funcao que verifica se a pilha esta vazia//
int vazia_Pilha(Pilha *p) {
    if(p->cabeca == NULL)
        return 1;
    return 0;
}

//funcao para inserir elemento na pilha//
void push_Pilha(Pilha *p, int x) {
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = p->cabeca;
    p->cabeca = novo;
}

//funcao para remover elemento da pilha e retornar esse elemento//
int pop_Pilha(Pilha *p) {
    int x = p->cabeca->info;
    nodo *aux = p->cabeca->prox;
    free(p->cabeca);
    p->cabeca = aux;
    return x;
}

//funcao que executa a operacao da pilha e retorna o resultado//
int operacao(int a, int b, char simb) {
    int res;
    if (simb == '+')
        res = b + a;
    if (simb == '-')
        res = b - a;
    if (simb == '*')
        res = b * a;
    if (simb == '/')
        res = b / a;
    return res;
}

//funcao que verifica se a pilha tem apenas um elemento (serve para identificar programas invalidos)//
int Um_Elemento(Pilha *p) {
    if(p->cabeca->prox == NULL)
        return 1;
    return 0;
}

//funcao que imprime a acao de empilhar na pilha//
void Imprime_empilha(int a) {
    printf("empilha %d\n", a);
}

//funcao que imprime a acao de desempilhar da pilha//
void Imprime_desempilha(int a, int b, int c) {
    printf("desempilha %d, desempilha %d, empilha %d\n", a, b, c);
}

/*funcao que imprime a acao de desempilhar da pilha quando eh a ultima acao da pilha,
ou seja, quando o programa chega em seu fim*/
void Imprime_fim(int a, int b, int c) {
    printf("desempilha %d, desempilha %d, empilha %d, fim\n", a, b, c);
}

//funcao que imprime a mensagem de erro//
void Imprime_erro() {
    printf("erro, fim\n");
}