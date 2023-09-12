#include <stdio.h>
int main(){
    float f,c = 0;
    printf("Escreva a temperatura em f: ");
    scanf("%f",&f);
    c = (5*(f-32))/9;
    printf("\nA temperatura em c é: %.2f", c);
    return 0;
}

//114f