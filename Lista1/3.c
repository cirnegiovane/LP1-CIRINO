/*3)  Um  inteiro  perfeito  n  é  igual  a  soma  de  todos  os  seus  divisores  próprios.  A  faina  de  seus  divisores 
próprios vai de 1 a (n-1). Por  enemplo : 6 é um inteiro perfeito; a soma de todos os seus divisores próprios (1 + 2 + 3) é igual a 6. 
Escreva um programa em C que determine se um número no intervalo de 1 a 32767 é um inteiro perfeito. */
#include <stdlib.h>
#include <stdio.h>
int perfeito(int n);
int main(){
    int n;
    printf("Qual numero quer saber se eh perfeito? ");
    scanf("%d", &n);
    if(perfeito(n) == 1)
        printf("%d eh perfeito!", n);
    else
        printf("%d nao eh perfeito seu merda",n);
    return 0;
}


int perfeito(int n){
    int soma = 0;
    printf("Sao divisores de %d:",n);
    for(int j = 1; j < (n/2)+1; j++){
        if(n%j==0){
            soma+=j;;
            printf(" %d",j);
        }
    }
    printf(".\nA soma deles eh: %d.\n",soma);
    if(soma==n)
        return 1;
    else
        return 0;
}