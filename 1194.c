/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1194
*Data        : 15/11/2026
*Objetivo    : Reconstruir o percurso pós-ordem (Post-order) de uma árvore binária a partir das sequências dos percursos pré-ordem (Pre-order) e em-ordem (In-order) fornecidas na entrada.
*Dificuldade : Utilizar recursão para identificar a raiz atual no percurso pré-ordem, localizar sua posição no percurso em-ordem para dividir as subárvores esquerda e direita por meio de índices, e imprimir a raiz somente após visitar ambos os filhos.
*Uso de IA   : A IA foi utilizada para suporte e revisão do código.
*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int idx_pre;

void pos_ordem(char S1[], char S2[], int ini_in, int fim_in) {

    if (ini_in > fim_in) {
        return;
    }

    char raiz = S1[idx_pre++];
    
    int pos_raiz = ini_in;
    while (pos_raiz <= fim_in && S2[pos_raiz] != raiz) {
        pos_raiz++;
    }

    // tudo o que está à esquerda de 'pos_raiz' em S2 pertence à subárvore esquerda
    pos_ordem(S1, S2, ini_in, pos_raiz - 1);

    // tudo o que está à direita de 'pos_raiz' em S2 pertence à subárvore direita
    pos_ordem(S1, S2, pos_raiz + 1, fim_in);

    printf("%c", raiz);
}

int main() {
    int C; 
    scanf("%d", &C);

    while (C--) {
        int N;    
        char S1[60], S2[60]; // strings para pré-ordem (S1) e em-ordem (S2)

        scanf("%d %s %s", &N, S1, S2);

        // reinicia o índice do pré-ordem para o começo da string S1
        idx_pre = 0;

        // inicia a recursão abrangendo todos os nós de 0 até N - 1
        pos_ordem(S1, S2, 0, N - 1);
        printf("\n");
    }

    return 0;
}