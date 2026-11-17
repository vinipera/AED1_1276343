/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 25/09/2026
Objetivo    : Detectar a presença de ciclos em grafos direcionados utilizando Busca em Profundidade (DFS) com três estados para resolver o problema de dependências circulares.
Dificuldade : Gerenciar a alocação dinâmica de listas de adjacências e evitar limite de tempo (TLE) ou estouro de memória em múltiplos casos de teste.
Uso de IA   : A IA foi utilizada na estruturação e implementação da solução em C99.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// nó na lista de adjacência
typedef struct No {
    int destino;
    struct No* proximo;
} No;

typedef struct {
    int numVertices;
    No** listaAdj;
} Grafo;

Grafo* criarGrafo(int numVertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->listaAdj = (No**) malloc((numVertices + 1) * sizeof(No*));
    for (int i = 0; i <= numVertices; ++i) {
        grafo->listaAdj[i] = NULL;
    }
    return grafo;
}

// adiciona uma aresta direcionada (origem -> destino)
void adicionarAresta(Grafo* grafo, int origem, int destino) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;
}

// libera a memória alocada pelo grafo
void liberarGrafo(Grafo* grafo) {
    for (int i = 0; i <= grafo->numVertices; ++i) {
        No* atual = grafo->listaAdj[i];
        while (atual != NULL) {
            No* temporario = atual;
            atual = atual->proximo;
            free(temporario);
        }
    }
    free(grafo->listaAdj);
    free(grafo);
}

// Busca em Profundidade (DFS)
int buscaProfundidade(int u, int* visitado, Grafo* grafo) {
    visitado[u] = 1; 

    No* atual = grafo->listaAdj[u];
    while (atual != NULL) {
        int v = atual->destino;

        if (visitado[v] == 1) {
            return 1; // ciclo encontrado
        }
        if (visitado[v] == 0) {
            if (buscaProfundidade(v, visitado, grafo)) {
                return 1;
            }
        }
        atual = atual->proximo;
    }

    visitado[u] = 2; // marca como totalmente processado
    return 0;
}

// verifica se existe algum ciclo no grafo inteiro
int possuiCiclo(Grafo* grafo) {
    int* visitado = (int*) calloc(grafo->numVertices + 1, sizeof(int));

    for (int i = 1; i <= grafo->numVertices; ++i) {
        if (visitado[i] == 0) {
            if (buscaProfundidade(i, visitado, grafo)) {
                free(visitado);
                return 1; // achou ciclo
            }
        }
    }

    free(visitado);
    return 0; // nao tem ciclo
}

int main() {
    int casosTeste;
    if (scanf("%d", &casosTeste) != 1) return 0;

    while (casosTeste--) {
        int numDocumentos, numDependencias;
        if (scanf("%d %d", &numDocumentos, &numDependencias) != 2) break;

        Grafo* grafo = criarGrafo(numDocumentos);

        for (int i = 0; i < numDependencias; ++i) {
            int docA, docB;
            scanf("%d %d", &docA, &docB);
            adicionarAresta(grafo, docA, docB);
        }

        if (possuiCiclo(grafo)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        liberarGrafo(grafo);
    }

    return 0;
}
