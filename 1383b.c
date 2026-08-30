/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Vinícius Pereira de Morais
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 30/08/2026
Objetivo    : Verificar se matrizes 9x9 fornecidas representam soluções válidas de Sudoku, usando alocação dinâmica de matrizes.
Dificuldade : Gerenciar corretamente a alocação dinâmica de memória com malloc para a matriz e garantir a desalocação completa (free).
Uso de IA   : A IA foi utilizada para a correção de erros e aprendizado acerca de comandos não conhecidos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int caso = 1; caso <= n; caso++){

        int **matriz; // ponteiro para a matriz
        matriz = malloc(9 * sizeof(int *)); // aloca espaço para 9 linhas

        int valido = 1;

        // aloca espaço para 9 inteiros em cada linha
        for(int i = 0; i < 9; i++){
            matriz[i] = malloc(9 * sizeof(int));
        }
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        // verifica linhas
        for(int i = 0; i < 9; i++){

            int checar[10] = {0};

            for(int j = 0; j < 9; j++){
                int num = matriz[i][j];

                if(checar[num] == 1){
                    valido = 0;
                }

                checar[num] = 1;
            }
        }

        // verifica colunas
        for(int j = 0; j < 9; j++){

            int checar[10] = {0};

            for(int i = 0; i < 9; i++){
                int num = matriz[i][j];

                if(checar[num] == 1){
                    valido = 0;
                }

                checar[num] = 1;
            }
        }

        // verifica quadrados 3x3
        for(int linha = 0; linha < 9; linha += 3){
            for(int coluna = 0; coluna < 9; coluna += 3){

                int checar[10] = {0};

                for(int i = linha; i < linha + 3; i++){
                    for(int j = coluna; j < coluna + 3; j++){

                        int num = matriz[i][j];

                        if(checar[num] == 1){
                            valido = 0;
                        }

                        checar[num] = 1;
                    }
                }
            }
        }

        printf("Instancia %d\n", caso);

        if(valido)
            printf("SIM\n");
        else
            printf("NAO\n");

        printf("\n");
        
        // libera cada linha da matriz
        for(int i = 0; i < 9; i++){
            free(matriz[i]);
        }

        // libera o espaço dos ponteiros das linhas
        free(matriz);
    }

    return 0;
}