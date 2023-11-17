#include "FilaDinamica.h"

//funcao que cria a fila dinamica, armazenando um espaco de fila (struct)//
Fila *cria_Fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

//funcao que verifica se a fila esta vazia//
int vazia_Fila(Fila *f) {
    if(f->inicio == NULL)
        return 1;
    return 0;
}

//funcao que insere o numero de um programa na fila (no fim dela)//
void push_Fila(Fila *f, int x) {
    nodo_Fila *novo = (nodo_Fila *)malloc(sizeof(nodo_Fila));
    novo->info = x;
    novo->prox = NULL;
    if(f->fim != NULL)
        f->fim->prox = novo;
    f->fim = novo;
    if(f->inicio == NULL)
        f->inicio = novo;
}

//funcao que remove o numero de um programa da fila e o retorna (do inicio dela)//
int pop_Fila(Fila *f) {
    int x = f->inicio->info;
    nodo_Fila *aux = f->inicio->prox;
    if(f->fim == f->inicio)
        f->fim = NULL;
    free(f->inicio);
    f->inicio = aux;
    return x;
}

//funcao que imprime qual programa esta sendo executado//
void Imprime_programa(int n) {
    printf("programa %d: ", n);
}

/*funcao que identifica se todos os programas foram executados. No caso,
essa funcao verifica se o numero na ultima posicao da fila eh maior que os anteriores,
se for o caso, ela retorna 1, caso contrario retorna 0. Por se tratar de uma lista ligada,
existe outra funcao chamada recursao que faz essa verificacao entre os elementos da lista.*/
int Reinicio(Fila *f) {
    return Recursao1(f, f->inicio);
}

//recursao para a funcao reinicio//
int Recursao1(Fila *f, nodo_Fila *lista) {
    if(lista == f->fim)
        return 1;
    if(lista->info > f->fim->info)
        return 0;
    return Recursao1(f, lista->prox);
}

//funcao que verifica se o numero recebido eh menor que todos os numeros da lista//
int Primeiro(Fila *f, int x) {
    return Recursao2(f->inicio, x);
}

//recursao para a funcao primeiro//
int Recursao2(nodo_Fila *lista, int x) {
    if(lista == NULL)
        return 1;
    if(x > lista->info)
        return 0;
    return Recursao2(lista->prox, x);
}

//funcao recursiva que retorna o tamanho da fila//
int Tamanho_Fila(Fila *f) {
    return Recursao3(f->inicio);
}

//recursao para a funcao tamanho_fila//
int Recursao3(nodo_Fila *lista) {
    if(lista == NULL)
        return 0;
    return 1 + Recursao3(lista->prox);
}