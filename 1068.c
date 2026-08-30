/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 30/08/2026
Objetivo    : Verificar se o balanço de parênteses de várias expressões matemáticas está correto usando pilha.
Dificuldade : Implementar a estrutura de dados em pilha para validar o emparelhamento correto de '(' e ')'.
Uso de IA   : A IA foi utilizada para a correção de erros e aprendizado acerca de comandos não conhecidos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>

#define MAX 1005

// estrutura da Pilha
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void adicionar(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->topo++;
        p->dados[p->topo] = c;
    }
}

void desempilhar(Pilha *p) {
    if (!vazia(p)) {
        p->topo--;
    }
}

int main()
{
    char expressao[MAX];

    while (scanf("%s", expressao) != EOF) {
        Pilha pilha;
        inicializar(&pilha);
        int correto = 1;

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                adicionar(&pilha, '(');
            } else if (expressao[i] == ')') {
                if (vazia(&pilha)) {
                    correto = 0; // fechou parêntese sem nenhum '(' aberto na pilha
                    break;
                } else {
                    desempilhar(&pilha);
                }
            }
        }

        // se a pilha não estiver vazia ao final, sobrou '(' sem fechar
        if (!vazia(&pilha)) {
            correto = 0;
        }

        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}