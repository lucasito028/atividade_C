#include <stdio.h>
#include <stdlib.h>

void questao_02(int *vetor, int tamanho);

int main() {
    questao_01();
    return 0;
}

void questao_01() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)calloc(tamanho, sizeof(int));

    if (vetor == NULL) {
        printf("Não foi possível alocar memória.\n");
        return; // Saímos da função em caso de erro
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    questao_02(vetor, tamanho);
    free(vetor);
}

void questao_02(int *vetor, int tamanho) {
    int novoTamanho;
    printf("Digite o novo tamanho desejado para o vetor: ");
    scanf("%d", &novoTamanho);

    int *novoVetor = (int *)realloc(vetor, novoTamanho * sizeof(int));

    if (novoVetor == NULL) {
        printf("Não foi possível realocar memória.\n");
        free(vetor);
        return; // Saímos da função em caso de erro
    }

    if (novoTamanho > tamanho) {
        printf("Digite os novos elementos do vetor:\n");
        for (int i = tamanho; i < novoTamanho; i++) {
            scanf("%d", &novoVetor[i]);
        }
    }

    printf("Todos os elementos do vetor:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", novoVetor[i]);
    }
    printf("\n");

    free(novoVetor);
}
