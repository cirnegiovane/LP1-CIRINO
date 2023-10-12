#include <stdlib.h>
#include <stdio.h>
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
    FILE *arqproduto,*arqcliente,*arqpedido;
    Pedido pedido;
    Cliente cliente;
    Produto produto;
    arqproduto = fopen("produto.dat","wb");
    arqcliente = fopen("cliente.dat","wb");
    arqpedido = fopen("pedido.dat","wb");
    int sair = 0;
    int v,c,x,z,b;
    while(!sair){
        printf("O que gostaria de fazer?\n1.  Carregar Arquivo de Produtos em um vetor  chamado Tabela;\n2.  Localizar Produto na Tabela;\n3.  Inserir Ordenadamente (pelo codigo) um Produto na Tabela; \n4.  Remover Produto da Tabela; \n5.  Modificar Informações sobre um Produto na Tabela; \n6.  Listar Tabela no Vídeo; \n7.  Listar os dados de um cliente juntamente com os seus pedidos; \n8.  Processar a venda para um Cliente : Gerar a Nota Fiscal das Compras (no vídeo) e salvar o \npedido no arquivo de Pedidos; \n9.  Gerar Cliente: Abrir o Arquivo do Cliente e preencher, via teclado, os campos do Arquivo \nCliente e salvá-los depois; \n10. Listar  Mensagem  sobre  o  Total  Arrecadado  pelo  Supermercado  e  o  Número  de  Itens \nVendidos em um dia qualquer; (atenco quanto a restrição para datas futuras) \n11. Menu.");
        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                Produto tabela[15];
                break;
            case 2:

                v = getchar();
                char cod1[10];
                printf("Digite o codigo do produto: ");
                fgets(cod1, sizeof(cod1), stdin);
                localizar(tabela,cod);
                break;
            case 3:

                c = getchar();
                printf("Digite o codigo do produto: ");
                char cod2[10];
                fgets(cod2, sizeof(cod2), stdin);
                inserir(tabela,cod2);
                break;
            case 4:
                b = getchar();
                printf("Digite o codigo do produto: ");
                char cod3[10];
                fgets(cod3, sizeof(cod2), stdin);
                remover(tabela,cod3);
                break;
            case 5:
                // Implemente o código para a opção 5 (modificar informações sobre um produto)
                break;
            case 6:
                listar(tabela);
                // Implemente o código para a opção 6 (listar tabela no vídeo)
                break;
            case 7:

                x = getchar();
                char cod4[10];
                printf("Digite o codigo do cliente: ");
                fgets(cod4, sizeof(cod4), stdin);
                dados(cod4);
                break;
            case 8:
                processar();
                break;
            case 9:
                gerarcliente();
                break;
            case 10:

                z = getchar();
                char data[10];
                printf("Total arrecadado em qual data?");
                fgets(data, sizeof(data), stdin);
                total(data);
                break;
            case 11:
                sair = 1;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}