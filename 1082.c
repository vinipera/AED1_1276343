/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1082
*Data        : 15/11/2026
*Objetivo    : Representar um grafo não direcionado por meio de uma matriz de adjacência e identificar todos os seus componentes conexos utilizando Busca em Profundidade (DFS), listando os vértices de cada grupo em ordem alfabética.
*Dificuldade : Garantir a impressão dos vértices de cada componente em ordem crescente (alfabética) após a execução da DFS, manipular a conversão de caracteres ('a'-'z') para índices numéricos e seguir estritamente a formatação de saída com vírgulas e linhas em branco exigida pelo juiz.
*Uso de IA   : A IA foi utilizada para suporte e revisão do código.
*--------------------------------------------------------------------------*/

#include <stdio.h>

// busca dfs
void dfs(int grafo[26][26], int v, int visitado[], int V){
    visitado[v] = 1;
    
    for(int i = 0; i < V; i++){
        if(grafo[v][i] && !visitado[i]){
            dfs(grafo, i, visitado, V);
        }
    }
}

int main()
{
    int N;
    int grafo[26][26];
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++){
        
        int V, E;
        scanf("%d %d", &V, &E);
        
        // cria e zera o vetor visitado para os numeros ja buscados
        int visitado[26] = {0};

        // preenchimento de zeros no grafo
        for(int b = 0; b < 26; b++){
            for(int k = 0; k < 26; k++){
                grafo[b][k] = 0;
            }
        }
        
        // leitura das E arestas
        char u, w;
        for(int c = 0; c < E; c++){
            scanf(" %c %c", &u, &w);
            grafo[u - 'a'][w - 'a'] = 1; // conversao de caractere para indice numerico
            grafo[w - 'a'][u - 'a'] = 1;
        }
        
        printf("Case #%d:\n", i + 1);
        int comp = 0; // contador de grupos conexos
        
        for(int v = 0; v < V; v++){
            
            if(!visitado[v]){
                
                // resgata os visitados antes da inspeção
                int antes[26];
                for(int k = 0; k < V; k++){
                    antes [k] = visitado[k];
                }
                
                // faz a busca 
                dfs(grafo, v, visitado, V);
                
                // impressao em ordem alfabetica
                for(int k = 0; k < V; k++){
                    if(!antes[k] && visitado[k]){
                        printf("%c,", k + 'a');
                    }
                }
                printf("\n");
                comp++;
            }
        }
        
        printf("%d connected components\n\n", comp);
        
    }

    return 0;
}