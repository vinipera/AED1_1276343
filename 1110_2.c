/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/08/2026
Objetivo    : Simular o descarte e a movimentação das cartas de um baralho utilizando uma lista encadeada.
Dificuldade : Gerenciar corretamente os ponteiros da lista encadeada, realizando a inserção, remoção e movimentação dos nós.
Uso de IA   : A IA foi utilizada para a correção de erros.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct{
    No *inicio;
    No *fim;
    int qtd;
} Fila;

void inicializa(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
}

int push(Fila *f, int x){
    
    No *novo = (No*) malloc(sizeof(No)); // cria uma carta
    if(novo == NULL) return 0;
    
    novo->valor = x; // coloca o numero da carta
    novo->prox = NULL;
    
    if(f->inicio == NULL){
        f->inicio = novo; // passa a ser o novo início
    }
    else{
        f->fim->prox = novo; // o fim eh a carta que acabou de chegar
    }
    
    f->fim = novo;
    f->qtd++;
    return 1;
    
}

// remove a carta do topo da fila e retorna o valor
int pop(Fila *f){
    
    if(f->inicio == NULL) return 0;
    
    // guarda o ponteiro do no atual do inicio e seu valor antes da remoção
    No *aux = f->inicio;
    int valor = aux->valor; // salva o valor da carta
    
    f->inicio = f->inicio->prox; // avança o início
    
    if(f->inicio == NULL){ // se a fila esvaziou, o fim tbm
        f->fim = NULL;
    }
    
    free(aux); // libera o valor
    f->qtd--;
    
    return valor;
    
}

int main()
{
    int n;
    
    while(scanf("%d", &n) == 1 && n != 0){
        
        Fila f;
        
        inicializa(&f);
        
        // preenche a fila com cartas de 1 ate n
        for(int i = 1; i <= n; i++){
            push(&f, i);
        }
        
        printf("Discarded cards:");
        int primeiro = 1;
        
        // processa enquanto houver pelo menos 2 cartas
        while(f.qtd >= 2){
            
            int descartada = pop(&f); // descarta a carta do topo
            int movida = pop(&f); // remove a próxima carta
            push(&f, movida); // move a carta para a base da fila
            
            if(!primeiro){
                printf(",");
            }
            printf(" %d", descartada);
            primeiro = 0;
        }
        
        printf("\nRemaining card: %d\n", pop(&f));
        
    }

    return 0;
}