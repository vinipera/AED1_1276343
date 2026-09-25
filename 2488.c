/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 25/09/2026
Objetivo    : Calcular o tempo total gasto por um carteiro para entregar encomendas em ordem, utilizando Busca Binária para localizar o índice das casas eficientemente.
Dificuldade : Implementar a Busca Binária para evitar limite de tempo (TLE) e gerenciar o acúmulo de distância com tipos de dados adequados (long long).
Uso de IA   : A IA foi utilizada para a correção de erros no código.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

// descobre em que índice está uma casa específica
int busca_binaria(int casas[], int N, int alvo){
    
    int inicio = 0;
    int fim = N - 1;
    
    while (inicio <= fim){
        
        int meio = (inicio + fim) / 2;
    
        if(casas[meio] == alvo){
            return meio;
        }
        else if(casas[meio] < alvo){
            
            inicio = meio + 1; // ajusta o inicio para direita
        }
        else{
            
            fim = meio - 1; // ajusta o fim para esquerda
        }
    
    }
    
    return -1; 
}


int main()
{
    int N, M;
    long long tempo = 0; // guarda o tempo
    int pos_atual = 0; // primeira casa
    
    // numero de casas
    scanf("%d", &N);
    // numero de encomendas
    scanf("%d", &M);
    
    if(N>0){
        int casas[45000];
        
        for(int i = 0; i < N; i++){
            scanf("%d", &casas[i]);
        }
        
        for(int i = 0; i < M; i++){
            
            int encomenda;
            
            scanf("%d", &encomenda);
            
            // calcula o índice
            int prox_pos = busca_binaria(casas, N, encomenda);
            
            // calcula a distancia em passos da diferenca do indice para a pos pos_atual 
            // (abs -> modulo)
            tempo += abs(prox_pos - pos_atual);
            
            pos_atual = prox_pos;
            
        }
        
        printf("%lld\n", tempo);
        
    }
    

    return 0;
}