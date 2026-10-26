/*--------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 26/10/2026
Objetivo    : Imprimir a sequência de valores para I e J no formato "I=X J=Y", onde I começa em 1 e avança de 3 em 3, e J começa em 60 e recua  de 5 em 5 até atingir 0.
Dificuldade : Controlar a estrutura de repetição (loop) até que a condição de parada de J seja atingida, aplicando os incrementos e decrementos corretos a cada iteração.
Uso de IA   : A IA não foi utilizada.
--------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int i = 1;
    int j = 60;

    while (j >= 0) {
        printf("I=%d J=%d\n", i, j);
        i += 3;
        j -= 5;
    }

    return 0;
}