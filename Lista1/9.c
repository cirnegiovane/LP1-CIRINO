/*9)  Escrever um programa em C que calcule e imprima o número de caracteres distintos presentes em uma 
cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas.*/
#include <stdio.h>

int main() {
    char cadeia[81];

    printf("Digite uma cadeia de caracteres (até 80 caracteres):\n");
    fgets(cadeia, sizeof(cadeia), stdin);

    int contdistinto = 0;
    printf("Os caracteres distintos sao: ");
    for (int i = 0; cadeia[i] != '\0' && cadeia[i] != '\n'; i++) {
        char charatual = cadeia[i];
        int distinto = 1;

        for (int j = 0; j < i; j++) {
            if (charatual == cadeia[j]) {
                distinto = 0; 
                break;
            }
        }
    if(distinto){
        printf("%c ",charatual);
    }

        contdistinto += distinto;

    }
    printf("\nNumero de caracteres distintos na cadeia: %d\n", contdistinto);

    return 0;
}