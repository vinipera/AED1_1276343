/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 30/08/2026
Objetivo    : Simular a reorganização dos vagões de um trem na estação utilizando a estrutura de dados Pilha.
Dificuldade : Gerenciar a lógica de empilhar e desempilhar os vagões no momento correto para validar as permutações solicitadas.
Uso de IA   : A IA foi utilizada para a correção de erros e entendimento de lógica.
-------------------------------------------------------------------------- */

#include <stdio.h>
#define MAX 1000

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = 0;
}

int vazia(Pilha *p) {
    return p->topo == 0;
}

int cheia(Pilha *p) {
    return p->topo == MAX;
}

int push(Pilha *p, int x) {
    if (cheia(p)) return 0;
    p->dados[p->topo++] = x;
    return 1;
}

int pop(Pilha *p, int *x) {
    if (vazia(p)) return 0;
    *x = p->dados[--p->topo];
    return 1;
}

// pega o elemento do topo sem removê-lo
int top(Pilha *p) {
    if (vazia(p)) return -1;
    return p->dados[p->topo - 1];
}

int main() {
    
    int N;

    while (scanf("%d", &N) && N != 0) {

        // le as várias permutações de saída para o mesmo N
        while (1) {
            
            int alvo[MAX];

            // le o primeiro vagão da permutação desejada
            scanf("%d", &alvo[0]);

            if (alvo[0] == 0) break;

            // le os demais N-1 vagões da permutação desejada
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            Pilha estacao;
            inicializar(&estacao);

            int vagao_atual = 1; // proximo vagão a vir da entrada A
            int possivel = 1; // verifica se é possível

            // processa cada posição desejada na sequência de saída
            for (int i = 0; i < N; i++) {

                // enquanto o topo não for o vagão desejado em alvo[i], empilha os vagões vindos de A
                while (vagao_atual <= N && (vazia(&estacao) || top(&estacao) != alvo[i])) {
                    push(&estacao, vagao_atual);
                    vagao_atual++;
                }

                // se o topo da pilha é o vagão desejado, remove-o (envia para B)
                if (!vazia(&estacao) && top(&estacao) == alvo[i]) {
                    int removido;
                    pop(&estacao, &removido);
                } else {
                    possivel = 0;
                    break;
                }
            }
            
            if(possivel){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }

        }
        
        printf("\n");

    }

    return 0;
}