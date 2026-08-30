/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 26/08/2026
Objetivo    : Ler 100 valores inteiros, determinar o maior valor e a sua posição.
Dificuldade : Nenhuma
Uso de IA   : A IA foi utilizada para a correção de erros e aprendizado acerca de comandos não conhecidos.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main()
{
    int lista[100];
    
    // escaneia os 100 elementos
    for(int i = 0; i < 100; i++){
        scanf("%d", &lista[i]);
    }
    
    int maior_el = lista[0];
    int maior_pos = 0;
    
    // verifica o maior e sua posição
    for(int i = 0; i < 100; i++){
        if(lista[i] > maior_el){
            maior_el = lista[i];
            maior_pos = i;
        }
    }
    
    printf("%d\n%d\n", maior_el, maior_pos + 1);

    return 0;
}