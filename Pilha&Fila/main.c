#include "FilaDinamica.h"
#include "PilhaDinamica.h"

int main() {

    /*cria variaveis, um vetor q com os tamanhos das pilhas, um vetor v de strings para
    receber os codigos das pilhas, um vetor p de pilhas e cria a fila f*/
    int N, i, j, k, l, a, b, x, q[MAX];
    char v[MAX][MAX][MAX];
    Pilha *p[MAX];
    Fila *f = cria_Fila();

    //recebe o numero de pilhas//
    scanf("%d", &N);

    //laco para passar por cada pilha//
    for(i=0;i<N;i++) {
        
        //cria as pilhas//
        p[i] = cria_Pilha();

        //recebe o numero de simbolos de cada pilha//
        scanf("%d", &q[i]);

        //laco para percorrer a pilha//
        for(j=0;j<q[i];j++)

            //recebe os simbolos da pilha//
            scanf("%s", v[i][j]);
    }

    j = 0;

    /*laco para inserir os programas na fila e executar o primeiro comando de cada pilha,
    pois depois dessa etapa elas soh estarao vazias quando os programas acabarem*/
    for(i=0;i<N;i++) {

        /*verifica se o simbolo eh um numero, caso seja, insere o programa na fila,
        insere o numero na pilha do programa e imprime essa acao*/
        if(v[i][j][0] != '+' && v[i][j][0] != '-' && v[i][j][0] != '*' && v[i][j][0] != '/') {
            push_Fila(f, i);
            x = atoi(v[i][j]);
            push_Pilha(p[i], x);
            Imprime_programa(i+1);
            Imprime_empilha(x);
        }

        //caso nao seja, o programa eh invalido e imprime uma mensagem de erro//
        else {
            Imprime_programa(i+1);
            Imprime_erro();
        }
    }

    /*j eh a variavel que identifica a posicao dos simbolos da pilha, por isso recebe o valor 1,
    ja que o primeiro simbolo de cada programa ja foi identificado*/
    j = 1;

    //laco para rodar os programas enquanto a fila nao estiver vazia//
    while(vazia_Fila(f) != 1) {
        
        //a variavel k recebe o tamanho da fila antes da execucao do programa//
        k = Tamanho_Fila(f);

        //a variavel i identifica os programas, por isso recebe o valor retirado da fila//
        i = pop_Fila(f);

        //verifica se o programa termina de forma invalida//
        if(v[i][j][0] == '\0') {
            Imprime_programa(i+1);
            Imprime_erro();
            while(vazia_Pilha(p[i]) != 1)
                pop_Pilha(p[i]);
        }

        /*verifica se o simbolo eh um numero, caso seja,
        insere o numero na pilha do programa e imprime essa acao*/
        if(v[i][j][0] != '+' && v[i][j][0] != '-' && v[i][j][0] != '*' && v[i][j][0] != '/' && v[i][j][0] != '\0') {
            x = atoi(v[i][j]);
            push_Pilha(p[i], x);
            Imprime_programa(i+1);
            Imprime_empilha(x);
        }

        //verifica se o simbolo nao eh um numero//
        if(v[i][j][0] == '+' || v[i][j][0] == '-' || v[i][j][0] == '*' || v[i][j][0] == '/') {
            
            //laco que executa apenas uma vez, serve para que o break saia apenas do if acima//
            do {
                /*verifica se a pilha contem apenas um elemento, se for o caso,
                imprime mensagem de erro e faz um pop para deixar a pilha vazia,
                de forma que o programa em questao nao seja mais executado, e faz o break*/
                if(Um_Elemento(p[i]) == 1) {
                    Imprime_programa(i+1);
                    Imprime_erro();
                    pop_Pilha(p[i]);
                    break;
                }

                //a mesma funcionalidade do if anterior, mas nesse caso verifica se a pilha esta vazia//
                if(vazia_Pilha(p[i]) == 1) {
                    Imprime_programa(i+1);
                    Imprime_erro();
                    break;
                }
                
                /*caso a expressao seja valida, faz dois pops, ou seja, desempilha os dois
                numeros que estao no topo da pilha e os salva nas variaveis a e b*/
                a = pop_Pilha(p[i]);
                b = pop_Pilha(p[i]);

                /*verifica se vai ocorrer divisao por zero, se ocorrer, imprime mensagem de erro
                e esvazia a pilha para que o programa em questao nao continue a rodar, e faz o break*/
                if(v[i][j][0] == '/' && a == 0) {
                    Imprime_programa(i+1);
                    Imprime_erro();
                    while(vazia_Pilha(p[i]) != 1)
                        pop_Pilha(p[i]);
                    break;
                }

                /*caso nao haja nenhum dos erros anteriores, executa a operacao e
                insere o elemento na pilha (faz o push)*/
                x = operacao(a, b, v[i][j][0]);
                push_Pilha(p[i], x);

                //se o programa ainda continua, apenas imprime o que foi feito na pilha//
                if(j != q[i]-1) {
                    Imprime_programa(i+1);
                    Imprime_desempilha(a, b, x);
                }

                if(j == q[i]-1 && Um_Elemento(p[i]) == 0) {
                    Imprime_programa(i+1);
                    Imprime_desempilha(a, b, x);
                }

                /*verifica se eh o final do programa, caso seja, imprime a acao e a mensagem de fim,
                e faz um pop na pilha para que fique vazia e esse programa nao continue rodando*/
                if(j == q[i]-1 && Um_Elemento(p[i]) == 1) {
                    Imprime_programa(i+1);
                    Imprime_fim(a, b, x);
                    pop_Pilha(p[i]);
                }
            } while(0);
        }

        //verifica se a pilha esta vazia, se nao estiver insere ela novamene na fila//
        if(vazia_Pilha(p[i]) != 1)
            push_Fila(f, i);

        //a variavel l recebe o tamanho da fila apos a execucao do programa//
        l = Tamanho_Fila(f);

        /*identifica o momento no qual todos os programas foram executados uma vez e
        incrementa a variavel j, para que os programas executem sua proxima acao*/
        if(k == l || (k != l && Primeiro(f, i) == 0))
            if(Reinicio(f) == 1)
                j++;
    }

    //laco para liberar todas as pilhas//
    for(i=0;i<N;i++)
        free(p[i]);

    //libera a fila//
    free(f);

    return 0;
}