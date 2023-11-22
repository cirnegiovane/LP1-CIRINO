#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 80

void countWordFrequency(char *string) {
    char words[MAX_LENGTH][MAX_LENGTH];
    int frequency[MAX_LENGTH];
    int wordCount = 0;

    for (int i = 0; i < MAX_LENGTH; i++) {
        frequency[i] = 0;
    }

    char *token = strtok(string, " ");

    while (token != NULL) {
        int found = 0;

        for (int i = 0; i < strlen(token); i++) {
            words[wordCount][i] = tolower(token[i]);
        }
        words[wordCount][strlen(token)] = '\0';

        for (int i = 0; i <= wordCount; i++) {
            if (strcmp(words[i], words[wordCount]) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            frequency[wordCount]++;
            wordCount++;
        }

        token = strtok(NULL, " ");
    }

    printf("Frequência das palavras:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }
}

int main() {
    char input[MAX_LENGTH * 10];

    printf("Digite a cadeia de caracteres (máx. 80 colunas):\n");
    fgets(input, sizeof(input), stdin);

    countWordFrequency(input);

    return 0;
}