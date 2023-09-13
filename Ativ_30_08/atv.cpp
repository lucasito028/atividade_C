#include <stdio.h>
#include <stdlib.h>


struct No
{
    int valor;
    struct No *prox;
};



typedef struct No lista;


void menu(lista *cartas);

void inicializa(lista *cartas);

int checa_lista(lista *cartas);

void adiciona_fim(lista *cartas);

void mostrar_lista(lista *cartas);

void adicionar_incio(lista *cartas);

void remover_incio(lista *cartas);

void remover_final(lista *cartas);

int montrar_tamanho(lista *cartas);

void limpar_lista(lista *cartas);

void mostrar_elemento(lista *cartas);

void adicionar_carta(lista *cartas);

void adicionar_escolhendo(lista *cartas);

void remover_escolhido(lista *cartas);

void organizar_baralho(lista *cartas);



int main(){

    lista *cartas = (lista *) malloc(sizeof(lista));


    if(!cartas){
        printf("Nao tem como alocar");
        exit(1);
    }
    else 
        printf ("Deu certo\n");

    inicializa(cartas);


    menu(cartas);

    return 0;

}


void menu(lista *cartas){

    int co = 1, op, i;

    while(co != 0){

        printf("Seleciona as opecoes\n");
        scanf("%d", &op);
        switch(op){

            case 1:
                i = checa_lista(cartas);

                if(i == 1)
                    printf("Lista vazia\n");

                else if ( i == 0){
                    printf("Lista nao vazia\n");
                }

                break;

            case 2:
                adiciona_fim(cartas);
                break;

            case 3:
                adicionar_incio(cartas);
                break;

            case 4:
                remover_incio(cartas);
                break;

            case 5:
                remover_final(cartas);
                break;

            case 6:
                montrar_tamanho(cartas);
                break;

            case 7:
                mostrar_elemento(cartas);
                break;

            case 8:
                adicionar_carta(cartas);
                break;

            case 9:
                adicionar_escolhendo(cartas);
                break;

            case 10:
                remover_escolhido(cartas);
                break;

            case 11:
                organizar_baralho(cartas);
                break;

            case 12:
                limpar_lista(cartas);
                break;

            case 21:
                co = 0;
                break;


    }

    }
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


int montrar_tamanho(lista *cartas){

    int p = 0;

    while (cartas->prox != NULL){
        cartas = cartas->prox;
        p++;
    }
    
    return p;

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

    printf("\nAgora fala um valor e irei procurar onde estÃ¡:\n");
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
    int cont = 1, pos, i;

    lista *aux = cartas;

    lista *ant = cartas;

    i = montrar_tamanho(cartas);

    printf("Qual posisao de (1 a %d) deseja remover\n", i);

    scanf("%d", &pos);

    if(pos > 0 && pos <= i){
        while (cont <= pos)
        { ant = aux;
        aux = aux->prox;

        if(cont == pos){
            ant->prox = aux->prox;
            free(aux);
        }
        cont++;

        }
    }
    if(cont == 0)
        printf("NÃ£o foi encontrado nada");



}


void organizar_baralho(lista *cartas){

    lista *f, *k;

    f = cartas->prox;

    while(f != NULL){

        k = f->prox;

            while(k != NULL){

                if(k->valor > k->valor){

                    int p = f->valor;
                    f->valor = k->valor;
                    k->valor = p;

                }

                k = k->prox;

            }

            f = k->prox;
        
    }

    printf("Baralho organizado\n");

    mostrar_lista(cartas);

}
