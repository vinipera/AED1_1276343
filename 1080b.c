/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 30/08/2026
Objetivo    : Ler 100 valores inteiros, determinar o maior valor e a sua posição, usando alocação dinâmica de vetores.
Dificuldade : Uso de "malloc"
Uso de IA   : A IA foi utilizada para a correção de erros e aprendizado acerca de comandos não conhecidos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 100;
    
    int *lista; // ponteiro para o vetor
    lista = malloc(n * sizeof(int)); // aloca espaço para 100 inteiros
    
    if(lista != NULL){ // verifica se a alocação funcionou
    
        for(int i = 0; i < n; i++){
            scanf("%d", &lista[i]);
        }
        
        int maior_el = lista[0];
        int maior_pos = 0;
        
        // verifica o maior e sua posição
        for(int i = 0; i < n; i++){
            if(lista[i] > maior_el){
                maior_el = lista[i];
                maior_pos = i;
            }
        }
        
        printf("%d\n%d\n", maior_el, maior_pos + 1);   
    }
    
    free(lista); // libera a memória alocada

    return 0;
}