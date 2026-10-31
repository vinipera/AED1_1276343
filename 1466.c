/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1466
*Data        : 26/10/2026
*Objetivo    : Montar uma Árvore Binária de Busca (BST) a partir de N inteiros e realizar o percurso por níveis (Level Order Traversal / BFS) utilizando uma fila auxiliar.
*Dificuldade : Implementar a fila (Queue) em C para visitar a árvore nível por nível, controlar a formatação sem espaço sobressalente no final da linha e imprimir uma linha em branco após cada caso de teste.
*Uso de IA   : A IA foi utilizada para suporte e revisão do código.
*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void caminhadaPorNivel(No *raiz) {
    if (raiz == NULL) return;

    // fila auxiliar
    No* fila[500];
    int inicio = 0, fim = 0;
    int primeiro = 1; // controle do primeiro laço

    // insere a raiz na fila
    fila[fim++] = raiz;

    // 2. processa os nós na ordem FIFO - First In, First Out
    while (inicio < fim) {
        No *atual = fila[inicio++];

        // formatação dos espaços na impressão
        if (primeiro) {
            printf("%d", atual->valor);
            primeiro = 0;
        } else {
            printf(" %d", atual->valor);
        }

        // coloca os filhos do nó atual na fila (esq -> dir)
        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
    printf("\n");
}

// liberação de memória da árvore após cada caso 
void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C, N, valor;

    if (scanf("%d", &C) != EOF) {
        
        for (int i = 1; i <= C; i++) {
            scanf("%d", &N);
            No *raiz = NULL;

            // insere os N números fornecidos no caso de teste
            for (int j = 0; j < N; j++) {
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
            }

            // impressão da resposta formatada
            printf("Case %d:\n", i);
            caminhadaPorNivel(raiz);
            printf("\n");

            liberarArvore(raiz);
        }
    }

    return 0;
}