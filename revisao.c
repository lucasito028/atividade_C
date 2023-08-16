/*Olá professor tudo bem, :)
Se sim. essa é a revisão sobre as aulas de Estruturas de dados
(Se quiser responder só botar a coisa abaixo)
R:
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//Contadora mundial
int i = 0;

//Está relacionada a questão 3
struct Aluno{
    float nota1;
    float nota2;
    char nome[50];
};

void questao_01();

void questao_02();

void questao_03();

void questao_04();

void questao_05();

void questao_06();

void questao_07();


int main()
{
    //Questão 1
    // questao_01();
    
    //Questão 2
    // questao_02();
    
    //Questão 3
    // questao_03();
    
    //Questão 4
    // questao_04();
    
    //Questão 5
    // questao_05();
    
    //Questão 6
    // questao_06();
    
    //Questão 7
    // questao_07();
    
}

void questao_01(){
    int menor = 0, maior = 0;
    int num[10];
    float media = 0;
    
    printf("Esse e um sistema de pegar o numero media e maior e menor\n");
    
    while(i < 10){
        printf("Numero %d:", i +1);
        scanf("%d", & num[i]);

        if(i == 0){
            maior = num[i];
            menor = num[i];
        }
        else{
            if(num[i] > maior)
                maior = num[i];
                
            if(menor > num[i])
                menor = num[i];
            
            media += num[i];
        }
        i++;
    }
    
    media /= 10;
    
    printf("Total: %f\n", media);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    
}

void questao_02(){
    int j = 0, p = 0, num;
    int par[5], impar[5];
    
    for(i = 0; i < 30; i++){
        printf("N%d: ", i+1);
        scanf("%d", &num);
        
        if(num % 2 ==0){
            if(p < 5){
                par[p] = num;
                p++;
            }
            
        }
        
        else{
            if(j < 5){
                impar[j] = num;
                j++;}
            
        }
        
        if(j == 5 && p == 5){
            i = 30;
        }
        
    }

    
    printf("\n\n");
    
    i = 0;
    printf("Pares: \n");
    while(i < 5){
        printf(" %d ", par[i]);
        i++;
    }
    i = 0;
    printf("\nImpares: \n");
    while(i < 5){
        printf(" %d ", impar[i]);
        i++;
    }
}

void questao_03(){

    struct Aluno aluno[6];

    int aprovado, reprovado, exame;

    float media, meta;
    char final[10];

    while (i < 6){

        printf("Nome do Aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);  

        printf("Nota %d do Aluno %d\n", 1, i+1);
        scanf("%f", & aluno[i].nota1);

        printf("Nota %d do Aluno %d\n", 2, i+1);
        scanf("%f", & aluno[i].nota2);

        meta = (aluno[i].nota1 +  aluno[i].nota2);
        meta /= 2;
        
        if(meta >= 7 ){
            strcpy(final, "Aprovado");
            aprovado += 1;
        }

        else if(meta < 7 && meta > 3){
            strcpy(final, "Exame");
            exame += 1;
        }

        else if(meta < 3){
             strcpy(final, "Reprovado");
             reprovado += 1;
        }
        
        printf("Media: %f\n", meta);
        printf("Está %s\n\n", final);
        
        media += meta;
        
        i+=1;
    }
    
    printf("Aprovado: %d\n", aprovado);
    printf("Exame: %d\n", exame);
    printf("Reprovados: %d\n", reprovado);
    
    printf("Média da classe %f\n", media/i);
}

void questao_04(){
    
    int matriz[3][3];
    int i, j, pegar, maior, menor; 

    srand(time(NULL)); 

    for (i = 0; i < 3; i++) {
        
        for (j = 0; j < 3; j++) {
            
            matriz[i][j] = (rand() % 9) + 1;
            printf("%d ", matriz[i][j]); 
        }
        printf("\n");
    }

    printf("Pesquise um Numero \n");
    scanf("%d", &pegar);

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {  
            if(matriz[i][j] > pegar)
                maior +=1;
            else if(matriz[i][j] < pegar)
                menor +=1;
        }

    }

    printf("Maiores são: %d\n", maior);
    printf("Menores são: %d\n", menor);

}

void questao_05(){
    int matriz[4][3];
    int i, j, pegar; 

    srand(time(NULL)); 

    for (i = 0; i < 4; i++) {
        
        for (j = 0; j < 3; j++) {
            
            matriz[i][j] = (rand() % 9) + 1;
            printf("%d ", matriz[i][j]); 
        }
        printf("\n");
    }

    printf("Pesquise um Numero \n");
    scanf("%d", &pegar);

    for (i = 0; i < 4; i++) {

        for (j = 0; j < 3; j++) {  
            if(matriz[i][j] == pegar)
                matriz[i][j] = 0;
                printf("%d ", matriz[i][j]); 
        }
        printf("\n");
    }


}

void questao_06(){
    int vetor[10], invertdo[10];
    int i = 0, j = 9; 

    srand(time(NULL));

    while(i < 10){
        vetor[i] = (rand() % 9) + 1;
        invertdo[j] = vetor[i];
        j--;
        i++;
    }
    
    i = 0;
    printf("Normal:\n");
    while(i < 10){
        printf("%d ", vetor[i]);
        i++;
    }
    i = 0;
    printf("\nInvertido:\n");
    while(i < 10){
        printf("%d ", invertdo[i]);
        i++;
    }

}

void questao_07(){
    int vetor[10];
    int pegado;

    srand(time(NULL));
    printf("Vetores\n");

    for (int i = 0; i < 10; i++) {
        vetor[i] = (rand() % 9) + 1;
        printf("%d ", vetor[i]);
    }

    printf("\nTente encontrar um numero ai\n");
    scanf("%d", &pegado);

    for (int i = 0; i < 10; i++) {
        if (pegado == vetor[i]) {
            printf("Encontrado na Posição: %d\n", i);
        }

    }
    
}
