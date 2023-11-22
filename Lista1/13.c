#include <stdio.h>

void trocar(int *a, int *b);

void bubbleSort(int vetor[], int tamanho);

int main() {
    int vetor1[10], vetor2[10], vetor3[10];
    int i;

    printf("Digite os elementos do primeiro vetor:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor2[i]);
    }

    printf("Digite os elementos do terceiro vetor:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor3[i]);
    }

    bubbleSort(vetor1, 10);
    bubbleSort(vetor2, 10);
    bubbleSort(vetor3, 10);

    printf("Vetor 1 ordenado em ordem crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor1[i]);
    }
    printf("\n");

    printf("Vetor 2 ordenado em ordem crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor2[i]);
    }
    printf("\n");

    printf("Vetor 3 ordenado em ordem crescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor3[i]);
    }
    printf("\n");

    return 0;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}