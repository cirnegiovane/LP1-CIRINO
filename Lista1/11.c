#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehVogal(char c) {
    c = tolower(c);
    
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

int contarVogais(char *palavra) {
    int vogais = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (ehVogal(palavra[i]))
            vogais++;
    }
    return vogais;
}

int main() {
    char texto[1000];
    
    printf("Digite uma cadeia de caracteres: ");
    fgets(texto, sizeof(texto), stdin);
    
    printf("Palavras com três ou mais vogais:\n");
    
    char *token = strtok(texto, " \n");
    while (token != NULL) {
        if (contarVogais(token) >= 3) {
            printf("%s\n", token);
        }
        token = strtok(NULL, " \n");
    }
    
    return 0;
}