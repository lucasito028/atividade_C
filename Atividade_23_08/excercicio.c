#include <stdlib.h>
#include <stdio.h>

/*

Implemente um algoritmo que leia um valor n e crie um vetor dinâmico de n
elementos. Na sequência passe o vetor como parâmetro para uma função para 
preencher o vetor. Depois, no programa principal, o vetor preenchido deve ser 
impresso. Ao final, liberar a área de memória alocada.

*/

void q1();

int main(){
    q1();
    return 0;
}

void q1(){

    int tamanho = 0;

    printf("Coloque o Tamanho: ");
    scanf("%d", tamanho);

    int *vetor = (int *)calloc(tamanho, sizeof(int));

    if(vetor = NULL){
        printf("Deu problema");
        return;
    }

    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }
}