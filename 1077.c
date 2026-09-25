/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 25/09/2026
Objetivo    : Converter expressões matemáticas da notação Infixa para Pós-fixa utilizando a estrutura de dados Pilha (Stack).
Dificuldade : Gerenciar a precedência de operadores e o balanceamento de parênteses usando manipulação de índices de vetor para a pilha.
Uso de IA   : A IA foi utilizada para auxiliar na compreensão da lógica de precedência de operadores e correção do algoritmo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <ctype.h> // saber se eh letra ou numero

int prioridade(char caractere){
    
    if(caractere == '^'){
        return 3;
    }

    else if(caractere == '*' || caractere == '/'){
        return 2;
    }
    
    else if(caractere == '+' || caractere == '-'){
        return 1;
    }
    else{
        return 0;
    }

}

int main()
{
    int N;
    scanf("%d", &N); // lemos a qtd de casos de teste
    
    // para cada caso lemos a expressao completa e criamos a pilha
    for (int i = 0; i < N; i++){
        
        char expressao[1100];
        scanf("%s", expressao);
        
        char pilha[1000];
        int topo = -1; // vazia
        int tamanho = strlen(expressao);
        
        // processo de ver caractere por caractere
        for(int i = 0; i < tamanho; i++){
            
            char caractere = expressao[i];
            
            // Regra 1: se for número/letra imprime direto
            if(isalnum(caractere)){
                printf("%c", caractere);
            }
            
            // Regra 2: Se for ( empilha no topo de uma pilha
            else if(caractere == '('){
                topo++;
                pilha[topo] = caractere;
            }
            
            // Regra 3: Se for ) desempilha tudo e acha (
            else if(caractere == ')'){
                
                // imprime tudo que estava guardado
                while (topo >= 0 && pilha[topo] != '('){
                    printf("%c", pilha[topo]);
                    topo--;
                }
                
                // quando ( aparece, paramos e tiramos fora
                if(topo >= 0 && pilha[topo] == '('){
                    topo--;
                }
            }
            
            // Regra 4: Se for + - * /
            else{
                // se a prioridade do topo da pilha for tao ou mais forte que ele, ele sai da pilha e é impresso
                while(topo >= 0 && prioridade(pilha[topo]) >= prioridade(caractere)){
                    printf("%c", pilha[topo]);
                    topo--;
                }
                
                topo++;
                pilha[topo] = caractere;
            }
            
        }
        
        // desempilha e imprime todos os restantes da pilha
        while(topo >= 0){
            printf("%c", pilha[topo]);
            topo--;
        }
        
        printf("\n");
        
        
    }

    return 0;
}