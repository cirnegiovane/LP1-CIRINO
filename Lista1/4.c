/*4) Escreva um programa em C que calcule o fatorial de um número inteiro positivo.*/
#include <stdlib.h>
#include <stdio.h>
long fat(long x);
int main(){
    long n=0;
    printf("Digite o valor de n: ");
    scanf("%ld",&n);
    printf("O valor de %ld! eh: %ld.",n,fat(n));
    return 0;
}
long fat(long x){
    if(x<2)
        return 1;
    else
        return x*fat(x-1);
}