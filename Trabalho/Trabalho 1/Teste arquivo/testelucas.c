#include <stdio.h>
#include <stdlib.h>
struct produto
    {
        char codigo_produto[10] , nome_produto[40];
        float preco_produto;
    };

void criaFileProduto(struct produto p , struct produto tabela[] , int quantidade_produto){

    scanf("%*c");
    printf("Digite o codigo do produto (maior que 0): ");
    fgets(p.codigo_produto , 10 , stdin);

    printf("Digite o nome do produto: ");
    fgets(p.nome_produto , 40 , stdin);

    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco_produto);

    tabela[quantidade_produto] = p;
}

void salvarNoArquivoBinarioProduto(struct produto tabela[] , int quantidade_produto) {
    FILE *arq = fopen("produtoBinario.dat" , "wb");
    if (arq){
        fwrite(tabela , sizeof(struct produto) , quantidade_produto , arq);
    } else {
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);
    printf("\nArquivo salvo com sucesso.\n");
}
void lerArquivoBinarioProduto(int quantidade_produto) {
    struct produto tabela[100];
    FILE *arq = fopen("produtoBinario.dat" , "rb");
    if (arq) {
        fread(tabela, sizeof(struct produto), quantidade_produto, arq);
    } else {
        printf("Arquivo falhou em abrir.");
    }
    fclose(arq);

    printf("\n\n-=-=-=-=- Produtos -=-=-=-=-\n");
    for (int i = 0; i < quantidade_produto; i++) {
        if (tabela[i].codigo_produto != 0){
            printf("\n\n-=-=- Produto %d -=-=-\n" , i + 1);
            printf("\nCodigo: %s", tabela[i].codigo_produto);
            printf("Nome: %s", tabela[i].nome_produto);
            printf("Preco: %.2f\n", tabela[i].preco_produto);
        }
    }
}