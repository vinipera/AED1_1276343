/*--------------------------------------------------------------------------*
*Disciplina  : Algoritmo e Estrutura de Dados 2026S1
*Nome        : Vinícius Pereira de Morais
*Linguagem   : C
*Problema    : https://judge.beecrowd.com/pt/problems/view/1094
*Data        : 26/10/2026
*Objetivo    : Ler o número de casos de teste e contabilizar a quantidade total de cobaias (coelhos, ratos e sapos), calculando os totais e percentuais individuais de cada tipo com 2 casas decimais.
*Dificuldade : Tratar a leitura dos caracteres corretamente (ignorando espaços/quebras de linha com " %c") e realizar a conversão para double na hora de calcular os percentuais.
*Uso de IA   : A IA não foi utilizada.
*--------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int N, quant;
    char tipo;
    
    int total = 0;
    int coelhos = 0;
    int ratos = 0;
    int sapos = 0;
    
    if (scanf("%d", &N) == 1 && N > 0) {
        for (int i = 0; i < N; i++) {
            scanf("%d %c", &quant, &tipo);
            
            total += quant;
            
            if (tipo == 'C') {
                coelhos += quant;
            } else if (tipo == 'R') {
                ratos += quant;
            } else if (tipo == 'S') {
                sapos += quant;
            }
        }
    }
    
    double p_coelhos = (double)coelhos / total * 100.0;
    double p_ratos = (double)ratos / total * 100.0;
    double p_sapos = (double)sapos / total * 100.0;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelhos);
    printf("Total de ratos: %d\n", ratos);
    printf("Total de sapos: %d\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", p_coelhos);
    printf("Percentual de ratos: %.2f %%\n", p_ratos);
    printf("Percentual de sapos: %.2f %%\n", p_sapos);
    
    return 0;
}