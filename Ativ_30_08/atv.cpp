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

void adiciona_fim(lista *cartas);

void mostrar_lista(lista *cartas);

void adicionar_incio(lista *cartas);

void remover_incio(lista *cartas);

void remover_final(lista *cartas);

void montrar_tamanho(lista *cartas);



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


    adiciona_fim(cartas);
    
	int p = 0;
	
	while(p < 3){
		adicionar_incio(cartas);
		p++;	
	}
    

    mostrar_lista(cartas);

    remover_incio(cartas);

    mostrar_lista(cartas);

    remover_final(cartas);

    mostrar_lista(cartas);

    montrar_tamanho(cartas);

    free(cartas);
    return 0;
}

void inicializa(lista *cartas){
    cartas->prox = NULL;
    printf("Lista cartas inicalizada\n");
}


int checa_lista(lista *cartas){
    if(cartas->prox == NULL)
        return 1;
    else 
        return 0;
}

void adiciona_fim(lista *cartas){
    lista *novo = (lista *) malloc(sizeof(lista));
    if(!novo){
        printf("Deu errado o adicionar\n");
        exit(1);
    }

    printf("Digite a ultima carta do baralho: \n");
    scanf("%d", &novo->valor);

    novo->prox = NULL;

    if(checa_lista(cartas)){
        cartas->prox = novo;}

    else{
    	int i = 0;
        lista *aux = cartas->prox;
        while(aux-> prox != NULL){
        	printf("%d\n", i);
            aux = aux->prox;
        }

        printf("\n");
        aux->prox = novo;
    }

}

void mostrar_lista(lista *cartas){

    if(checa_lista(cartas)){
        printf("Lista Vazia\n");
        return ;
    }

    lista *aux = cartas->prox;

	printf("Cartas -> ");
    while(aux != NULL){
        printf("%d  ", aux->valor);
        aux = aux->prox;
    }
}


void adicionar_incio(lista *cartas){
	
    lista *novo = (lista *) malloc(sizeof(lista));

    if(!novo){
        printf("Impossivel alocar \n");
        return ;
    }

    printf("Coloque em ordem de pilha\n");
    scanf("%d", &novo->valor);
    lista *aux = cartas->prox;
    cartas->prox = novo;
    novo->prox = aux;

}

void remover_incio(lista *cartas){
    lista *aux = cartas->prox;
    printf("Removendo o primeiro elemento do bralago\n");
    cartas->prox = cartas->prox -> prox;
    free(aux);
}

void remover_final(lista *cartas){
    while(cartas->prox->prox != NULL){
        cartas = cartas->prox ;
    }
    free(cartas->prox);
    cartas->prox = NULL;
    printf("Removendo o ultimo elemento \n");
}

void montrar_tamanho(lista *cartas){
    if(checa_lista(cartas)){
        printf("Lista Vazia\n");
        return ;
    }

    lista *aux = cartas->prox;

    int k = 0;
    while(aux != NULL){
        k++;
    }
    printf("\nTems %d", k);
}