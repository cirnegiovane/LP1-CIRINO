#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *arq;
    arq = fopen("C:\\Users\\canal\\OneDrive\\Documentos\\UERJ\\LP1 CIRINO\\Trabalho\\teste.txt","w");
    fprintf(arq,"lua maconheiro");
    fclose(arq);
    return 0;
}