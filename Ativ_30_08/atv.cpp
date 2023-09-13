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

void limpar_lista(lista *cartas);

void mostrar_elemento(lista *cartas);

void adicionar_carta(lista *cartas);

void adicionar_escolhendo(lista *cartas);

void remover_escolhido(lista *cartas);



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
	
	while(p < 5){
		adicionar_incio(cartas);
		p++;	
	}
    

    mostrar_lista(cartas);

    montrar_tamanho(cartas);

    remover_incio(cartas);

    montrar_tamanho(cartas);

    adicionar_escolhendo(cartas);

    mostrar_elemento(cartas);
    
    printf("\n\n");

    mostrar_elemento(cartas);

    remover_final(cartas);

    mostrar_lista(cartas);

   	limpar_lista(cartas);


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

    int p = 0;

    while (cartas->prox != NULL){
        cartas = cartas->prox;
        p++;
    }
    
    printf("\nTotal %d:\n", p);

}

void limpar_lista(lista *cartas){

        if(!checa_lista(cartas)){

            lista *aux, *atual, *head;

            head = cartas;
            atual = cartas->prox;

            while(atual->prox != NULL){

                aux = atual -> prox;

                free(atual);

                atual = aux;
            }
            if(atual -> prox == NULL){

            head -> prox = NULL;

            free(atual);
        }

            printf("\nEsta limpo\n");

        }

}

void mostrar_elemento(lista *cartas){

    int enc, p = 0, k = 0;

    printf("\nAgora fala um valor e irei procurar onde está:\n");
    scanf("%d", &enc);

     while (cartas -> prox != NULL){
        cartas = cartas->prox;
        
        if(cartas->valor == enc){
              p++;
              printf("\n\nFoi encontrado na posicao %d \n", k+1);
        }
        k++;
    }

    if(p == 0){
        printf("Nao foi encontrado Nada\n");
    }else{
        printf("O numero %d foi encontrado em %d posicoes\n", enc, p);
    }


}

void adicionar_escolhendo(lista *cartas){

    int posicao;
    
    printf("Digite a posicao onde deseja inserir o novo numero: ");
    scanf("%d", &posicao);
    
    if (posicao < 1) {
        printf("Posicao invalida. Insira uma posicao valida maior que 0.\n");
        return;
    }
    
    lista *novo = (lista *)malloc(sizeof(lista));
    
    if (!novo) {
        printf("Impossivel alocar memoria para o novo elemento.\n");
        return;
    }
    
    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->valor);
    
    lista *atual = cartas;
    int contador = 0;
    
    while (atual->prox != NULL && contador < posicao - 1) {
        atual = atual->prox;
        contador++;
    }
    
    if (contador < posicao - 1) {
        printf("Posicao excede o tamanho atual da lista. O numero sera adicionado no final.\n");
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
    
    printf("Numero %d inserido na posicao %d.\n", novo->valor, posicao);

}

void remover_escolhido(lista *cartas){
    printf("Agora o que acontece: escolha a posicao de uma carta a ser removida\n\n");
    mostrar_lista(cartas);
    printf("\n\n");
}
