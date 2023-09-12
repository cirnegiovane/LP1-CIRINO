/*2) Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via
teclado, é ou não primo. */
#include <stdlib.h>
#include <stdio.h>

int main(){
    int x, primo;
    primo = 1;
    printf("Entre com o numero: ");
    scanf("%d",&x);
    for(int i = 2;i<=x/2+1;i++){
        if(x%i==0){
            printf("%d nao eh primo (divisivel por %d).",x,i);
            primo = 0;
            break;
        }
    }
    if(primo){
        printf("%d eh primo.",x);
    }
    return 0;
}