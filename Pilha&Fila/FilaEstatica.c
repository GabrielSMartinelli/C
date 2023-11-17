#include "FilaEstatica.h"

//funcao que cria a fila estatica, armazenando um espaco de fila (struct)//
Fila *cria_Fila() {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = 0;
    return f;
}

//funcao que verifica se a fila esta vazia//
int vazia_Fila(Fila *f) {
    if(f->inicio == f->fim)
        return 1;
    return 0;
}

//funcao que insere o numero de um programa na fila (no fim dela)//
void push_Fila(Fila *f, int x) {
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
}

//funcao que remove o numero de um programa da fila e o retorna (do inicio dela)//
int pop_Fila(Fila *f) {
    int x = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return x;
}

//funcao que imprime qual programa esta sendo executado//
void Imprime_programa(int n) {
    printf("programa %d: ", n);
}

/*funcao que identifica se todos os programas foram executados. No caso,
essa funcao verifica se o numero na ultima posicao da fila eh maior que os anteriores,
se for o caso, ela retorna 1, caso contrario retorna 0*/
int Reinicio(Fila *f) {
    int x;
    for(x=f->inicio; x<f->fim-1; x++) {
        if(f->v[f->fim-1] < f->v[x])
            return 0;
    }
    return 1;
}

//funcao que verifica se o elemento da fila eh menor que todos os outros//
int Primeiro(Fila *f, int x) {
    int i;
    for(i=f->inicio; i<f->fim; i++) {
        if(f->v[i] < x)
            return 0;
    }
    return 1;
}

//funcao que calcula o tamanho da fila//
int Tamanho_Fila(Fila *f) {
    return f->fim - f->inicio;
}