#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*

Implemente um algoritmo que leia um valor n e crie um vetor dinâmico de n
elementos. Na sequência passe o vetor como parâmetro para uma função para 
preencher o vetor. Depois, no programa principal, o vetor preenchido deve ser 
impresso. Ao final, liberar a área de memória alocada.

*/
int i = 0;
void questao1();
int *questao1_c(int tam);

void questao2();
int **questao2_c(int tam);

void questao3();


int main(){
	// Questão 1
    // questao1();
    
    // Questão 2
    // questao2();
    
    // Questão 3
    // 
	
	questao3();
    return 0;
}

void questao1(){

    int tamanho;

    printf("Coloque o Tamanho: ");
    scanf("%d", &tamanho);

    int *vetor = questao1_c(tamanho);
    
    for(i = 0; i < tamanho; i++){
    	printf("\nValor %d: %d", i+1, vetor[i]);
	}
    
    free(vetor);
}

int *questao1_c(int tam){

    srand(time(NULL));
    
    int *vet = (int *)calloc(tam, sizeof(int));
    
    if(vet == NULL){
    	printf("Deu pau");
    	return 0;
	}
	
	printf("Preencha o Vetor\n");
	for(i = 0; i < tam; i++){
	printf("Valor %d\n", i+1);
	scanf("%d", &vet[i]);
	}
	
	return vet;
}


void questao2(){
	int tamanho = 0;
	
	printf("Bote um Tamanho ai\n");
	scanf("%d", &tamanho);
	
	int **vet = questao2_c(tamanho);
	
	int j = 0;
	for(i =0; i < tamanho; i++){
		printf("\n");
		for(j =0; j < tamanho; j++){
			printf("    Valor %d e %d: %d", i + 1, j + 1, vet[i][j]);
			
		}
	}	
	free(vet);
}

int **questao2_c(int tam){
	
	srand(time(NULL));
	int **vet = (int **)malloc(tam * sizeof(int *));
	
	if(vet == NULL){
		printf("Deu Pau");
		return 0;
	}
	for(i = 0; i < tam; i++){
		vet[i] = (int *)calloc(tam, sizeof(int));
	}
	
	int j = 0;
	for(i =0; i < tam; i++){
		
		for(j =0; j < tam; j++){
			vet[i][j] = rand();
			
		}
	}
	
	return vet;
}


void questao3(){
	int p[2];
	
	int **matrix = (int **) malloc(p[1] * sizeof(int**));
	
	if(matrix == NULL){
		printf("Deu pau");
	}
	
	for(i = 0; i < p[1]; i++){
		matrix[i] = int(*) calloc(p[2] sizeof(int));
	}
	
	int j = 0;
	
	for(i = 0; i < p[1]; i++){
		for(j = 0; j < p[2]; p++){
			matrix[i][j] = rand();
		}
	}
}
	

