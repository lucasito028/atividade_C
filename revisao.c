#include <stdio.h>
int i = 0;

void questao_01();

void questao_02();
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
    float total = 0;
    
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
            
            total += num[i];
        }
        i++;
    }
    
    total /= 10;
    
    printf("Total: %f\n", total);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    
}

void questao_02(){
    int j = 0;
    int par[5], impar[5], numbers[30];
    
    while(i < 5 && j < 5){
        
        printf("Numero %d\n", i+1);
        scanf("%d", &numbers[i]);
        
        if(numbers[i] % 2 == 0){
            par[i] = numbers[i];
            i++;}
        
        else{
            impar[i] = numbers[i];
            j++}
        
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