/*6)  Um  motorista  acaba  de  retornar  de  um  feriado  prolongado.  Em  cada  parada  de  reabastecimento  ele 
registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o 
tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de 
partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total 
de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados  relativos à compra de 
gasolina e calcular : 
a)  a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento; 
b)  a quilometragem obtida por litro de gasolina em toda a viagem 
c)  custo do combustível por quilometro rodado em toda a viagem*/
#include <stdlib.h>
#include <stdio.h>
int main(){
    printf("Quantos reabastecimentos foram feitos? ");
    int n;
    scanf("%d",&n);
    float odometro[n],qtdgas[n],precogas[n];
    for(int i=0; i<n;i++){
        printf("Dados para os calculos do abastecimento %d:\n ",i+1);
        printf("Odometro (km): ");
        scanf("%f",&odometro[i]);
        printf("Qtd em gasolina: ");
        scanf("%f",&qtdgas[i]);
        printf("Preco gas: ");
        scanf("%f",&precogas[i]);
    }
    printf("Km por litro entre cada abastecimento: %.2f",32.2);


    return 0;
}
