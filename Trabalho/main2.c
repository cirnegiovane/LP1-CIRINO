#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char cod[10];
    char nome[40];
    float preco;
}Produto;

typedef struct {
    char cod[10];
    char razao[40];
    char cnpj[19];
    char inscricao[15];
    char endereco[25];
    char telefone[12];
    char email[20];
}Cliente;

typedef struct {
    char num[10];
    char codprod[10];
    char codcli[10];
    int qtd;
    float total;
    char data[11];
}Pedido;


int main(){
    return 0;
}