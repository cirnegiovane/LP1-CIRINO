/*8)Para um vetor A de 50 números inteiros, escrever um programa em C que determine o maior e o segundo 
maior elemento desse vetor. Assumir que todos os elementos são distintos.*/
#include <stdio.h>
#include <limits.h>
#define max 50
void maiores(int vetor[],int n);
int main() {
    int A[max];
    for(int i = 0;i<max;i++){
        printf("Digite o elemento de indice %d: ",i+1);
        scanf("%d",&A[i]);
    }
    maiores(A,max);
    return 0;
}
void maiores(int vetor[], int n){
    int maior = INT_MIN;
    int segundomaior = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (vetor[i] > maior) {
            segundomaior = maior;
            maior = vetor[i];
        } else if (vetor[i] > segundomaior && vetor[i] != maior) {
            segundomaior = vetor[i];
        }
    }
    printf("O primeiro e segundo maior sao: %d e %d.\n",maior,segundomaior);
}