#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int caso = 1; caso <= n; caso++){

        int matriz[9][9];
        int valido = 1;

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
    }

    return 0;
}