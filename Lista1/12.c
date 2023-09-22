/*12)Escrever um programa em C que leia um valor inteiro (limite na casa do milhar), e o imprima em forma de caracteres, ou seja, por extenso. Ex. : 98 = noventa e oito. */
#include <stdio.h>
void printcentena(int centena);
void printdezena1(int dezena);
void printdezena2(int unidade);
void printunidade(int unidade);
int main() {
    int numero,centena,dezena,unidade;
    printf("Digite o numero: ");
    scanf("%d",&numero);
    if(numero<0 || numero > 999){
        printf("Numero fora do intervalo.");
        return 0;
    }
    if(numero==0){
        printf("zero");
        return 0;
    }
    if(numero==100){
        printf("cem");
        return 0;
    }
    centena = numero/100;
    dezena = (numero%100)/10;
    unidade = numero%10;
    if(centena>0){
        printcentena(centena);
        if(unidade>0 || dezena>0)
            printf(" e ");
    }
    if(dezena>0){
        if(dezena == 1 && unidade==0)
            printf("dez");
        else if(dezena>1){
            printdezena1(dezena);
            if(unidade>0)
                printf(" e ");}
        else
            printdezena2(unidade);
    }
    if(unidade>0){
        if(!(dezena == 1 && unidade != 0))
            printunidade(unidade);
    }
    return 0;
}
void printcentena(int centena){
    char *extenso[]={"","cento","duzentos","trezentos","quatrocentos","quinhentos","seiscentos","setescentos","oitocentos","novecentos"};
    printf("%s",extenso[centena]);
}
void printdezena1(int dezena){
    char *extenso[]={"","","vinte","trinta","quarenta","cinquenta","sessenta","setenta","oitenta","noventa"};
    printf("%s",extenso[dezena]);
}
void printdezena2(int unidade){
    char *extenso[]={"","onze","doze","treze","quatorze","quinze","dezesseis","dezessete","dezoito","dezenove"};
    printf("%s",extenso[unidade]);
}
void printunidade(int unidade){
    char *extenso[]={"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    printf("%s",extenso[unidade]);
}