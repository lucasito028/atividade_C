#include <stdio.h>
#include <stdlib.h>

struct No
{
    int valor;
    struct No *prox;
};



typedef struct No lista;



void inicializa(lista *cartas);

int checa_lista(lista *cartas);



int main(void){

    lista *cartas = (lista *) malloc(sizeof(lista));


    if(!cartas){
        printf("Nao tem como alocar");
        exit(1);
    }
    else 
        printf ("Deu certo\n");

    inicializa(cartas);


    int i = checa_lista(cartas);

    if(i == 1)
        printf("Lista vazia\n");

    else if ( i == 0){
        printf("Lista nao vazia\n");
    }



    free(cartas);
    return 0;
}

void inicializa(lista *cartas){
    cartas->prox = NULL;
    printf("Lista cartas inicalizada");
}


int checa_lista(lista *cartas){
    if(cartas->prox == NULL)
        return 1;
    else 
        return 0;
}
