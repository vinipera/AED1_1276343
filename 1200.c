/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1200
*Data        : 31/10/2026
*Objetivo    : Implementar uma Árvore Binária de Busca (BST) capaz de realizar inserções de caracteres, buscas de elementos e impressões dos percursos infixo, prefixo e posfixo.
*Dificuldade : Tratar a leitura contínua dos comandos até o fim de arquivo (EOF), consumir corretamente os espaços em branco na leitura do caractere (" %c") e controlar a formatação dos espaços nos percursos para evitar Presentation Error.
*Uso de IA   : A IA foi utilizada para suporte e revisão do código.
*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char valor;
    struct No *esq;
    struct No *dir;
};

struct No* criarNo(char valor) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

struct No* inserir(struct No *raiz, char valor) {
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

int buscar(struct No *raiz, char valor) {
    if (raiz == NULL) return 0;
    if (raiz->valor == valor) return 1;
    if (valor < raiz->valor) return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

// Esquerda, Raiz, Direita
void INFIXA(struct No *raiz, int *primeiro) {
    if (raiz != NULL) {
        INFIXA(raiz->esq, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        INFIXA(raiz->dir, primeiro);
    }
}

// Raiz, Esquerda, Direita
void PREFIXA(struct No *raiz, int *primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        PREFIXA(raiz->esq, primeiro);
        PREFIXA(raiz->dir, primeiro);
    }
}

// Esquerda, Direita, Raiz
void POSFIXA(struct No *raiz, int *primeiro) {
    if (raiz != NULL) {
        POSFIXA(raiz->esq, primeiro);
        POSFIXA(raiz->dir, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

int main() {
    struct No *raiz = NULL;
    char comando[10];
    char letra;

    while (scanf("%s", comando) != EOF) {
        
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);
            raiz = inserir(raiz, letra);
        } 
        
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            INFIXA(raiz, &primeiro);
            printf("\n");
        } 
        
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            PREFIXA(raiz, &primeiro);
            printf("\n");
        } 
        
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            POSFIXA(raiz, &primeiro);
            printf("\n");
        } 
        
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (buscar(raiz, letra)) {
                printf("%c existe\n", letra);
            } else {
                printf("%c nao existe\n", letra);
            }
        }
    }

    return 0;
}