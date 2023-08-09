/*Olá professor tudo bem, :)
Se sim essa é a revisão sobre as aulas de Estruturas de dados
*/
#include <stdio.h>

//Contadora mundial
int i = 0;

//Um struct aluno
struct Aluno{
    int nota1;
    int nota2;
    char nome[50];
};

void questao_01();

void questao_02();

void questao_03();

int main()
{
    //Questão 1
    // questao_01();
    
    //Questão 2
    // questao_02();
    
    //Questão 3
    // 
    questao_03();
    
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
float media;

    while (i < 6){
        printf("Nome do Aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);  
    }
}