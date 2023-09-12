/*5) O troco em moedas é uma combinação de moedas com os seguintes valores : 
R$ 1,00 ;  0,50;   0,25;   0,10;    0,05;   0,01 
     Escreva um programa em C que leia qualquer valor em centavos (R$0,01 até R$1,00). Calcule e imprima 
seu equivalente em moedas. Encontre a solução que utilize o menor número possível de moedas. */

#include <stdlib.h>
#include <stdio.h>

int main(){
    int cents,moeda1,moeda5,moeda10,moeda50,moeda25,moeda100;
    printf("Digite o valor em centavos: ");
    scanf("%d",&cents);
    moeda100 = cents/100;
    cents%=100;
    moeda50 = cents/50;
    cents%=50;
    moeda25 = cents/25;
    cents%=25;
    moeda10 = cents/10;
    cents%=10;
    moeda5 = cents/5;
    cents%=5;
    moeda1 = cents;
    printf("Troco em moedas:\n");
    printf("Moedas de 1: %d\n",moeda1);
    printf("Moedas de 5: %d\n",moeda5);
    printf("Moedas de 10: %d\n",moeda10);
    printf("Moedas de 25: %d\n",moeda25);
    printf("Moedas de 50: %d\n",moeda50);
    printf("Moedas de 1 real: %d\n",moeda100);
    return 0;
}