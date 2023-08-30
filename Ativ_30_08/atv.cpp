#include <stdio.h>
#include <stdlib.h>

struct No
{
    int valor;
    struct No *prox;
};

typedef struct No lista;

int main(void){
    
    lista * cartas = (lista *) malloc(sizeof(lista));

    if(!cartas){
        printf("Impossivel alocar");
        exit(1);
    }
    else 
        printf ("Memoria alocada\n");

    free(cartas);
    return 0;
}
