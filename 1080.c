#include <stdio.h>

int main()
{
    int lista[100];
    
    for(int i = 0; i < 100; i++){
        scanf("%d", &lista[i]);
    }
    
    int maior_el = lista[0];
    int maior_pos = 0;
    
    for(int i = 0; i < 100; i++){
        if(lista[i] > maior_el){
            maior_el = lista[i];
            maior_pos = i;
        }
    }
    
    printf("%d\n%d\n", maior_el, maior_pos + 1);

    return 0;
}