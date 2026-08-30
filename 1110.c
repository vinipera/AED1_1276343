/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/08/2026
Objetivo    : Simular o descarte e a movimentação das cartas de um baralho utilizando uma lista encadeada.
Dificuldade : Gerenciar corretamente os ponteiros da lista encadeada, realizando a inserção, remoção e movimentação dos nós.
Uso de IA   : A IA foi utilizada para a correção de erros e aprendizado acerca de comandos e conceitos não conhecidos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// cria a estrutura que representa uma carta
struct Carta {
    int valor;
    struct Carta *prox; // aponta para a próxima carta
};

int main()
{
    int n;

    while(1){

        scanf("%d", &n);

        // 0 encerra o programa
        if(n == 0)
            break;

        struct Carta *inicio = NULL;
        struct Carta *fim = NULL;

        // cria o baralho
        for(int i = 1; i <= n; i++){

            struct Carta *novo = malloc(sizeof(struct Carta));

            novo->valor = i;
            novo->prox = NULL;

            // se for a primeira carta
            if(inicio == NULL){
                inicio = novo;
                fim = novo;
            }
            else{
                // a antiga última carta aponta para a nova
                fim->prox = novo;

                // a nova carta passa a ser a última
                fim = novo;
            }
        }

        printf("Discarded cards:");

        int primeiro = 1;
        // enquanto houver pelo menos duas cartas
        while(inicio->prox != NULL){

            // guarda a carta do topo que será descartada
            struct Carta *descartada = inicio;

            // a segunda carta passa a ser o topo
            inicio = inicio->prox;

            if(primeiro){
                printf(" %d", descartada->valor);
                primeiro = 0;
            }
            else{
                printf(", %d", descartada->valor);
            }

            if(inicio->prox != NULL){

                struct Carta *movida = inicio;

                // a próxima carta passa a ser o topo
                inicio = inicio->prox;

                // coloca a carta movida no final
                fim->prox = movida;

                fim = movida;
                fim->prox = NULL;
            }
        }

        printf("\n");
        printf("Remaining card: %d\n", inicio->valor);
        free(inicio);
    }

    return 0;
}