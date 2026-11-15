/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1195
*Data        : 15/11/2026
*Objetivo    : Construir uma Árvore Binária de Busca (BST) a partir da inserção sequencial de N números inteiros e exibir seus três percursos clássicos em profundidade: pré-ordem (Pre-order), em-ordem (In-order) e pós-ordem (Post-order).
*Dificuldade : Implementar a alocação dinâmica e inserção recursiva dos nós da árvore binária de busca, controlar a formatação de saída sem espaços em branco sobrando ao final das linhas e liberar a memória alocada após cada caso de teste.
*Uso de IA   : A IA foi utilizada para suporte e revisão do código.
*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criar_no(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void pre_ordem(No *raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void em_ordem(No *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf(" %d", raiz->valor);
        em_ordem(raiz->dir);
    }
}

void pos_ordem(No *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf(" %d", raiz->valor);
    }
}

void liberar_arvore(No *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C; 
    scanf("%d", &C);

    for (int caso = 1; caso <= C; caso++) {
        int N, valor;
        scanf("%d", &N);

        No *raiz = NULL;

        for (int i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);

        printf("Pre.:");
        pre_ordem(raiz);
        printf("\n");

        printf("In..:");
        em_ordem(raiz);
        printf("\n");

        printf("Post:");
        pos_ordem(raiz);
        printf("\n\n");

        liberar_arvore(raiz);
    }

    return 0;
}