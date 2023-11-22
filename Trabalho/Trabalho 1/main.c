#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tam 100
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

void cadastrarprod();
void carregartabela(Produto *tabela[]);
void listartabela(Produto tabela[]);
int main(){
    int sair = 0;
    int quantprod = 0;
    Produto tabela[100];
    while(!sair){
        printf("O que gostaria de fazer?\n1. Carregar Arquivo de Produtos em um vetor chamado Tabela;\n2. Localizar Produto na Tabela;\n3. Inserir Ordenadamente (pelo codigo) um Produto na Tabela; \n4. Remover Produto da Tabela; \n5. Modificar Informações sobre um Produto na Tabela; \n6. Listar Tabela no Vídeo; \n7. Listar os dados de um cliente juntamente com os seus pedidos; \n8. Processar a venda para um Cliente : Gerar a Nota Fiscal das Compras (no vídeo) e salvar o pedido no arquivo de Pedidos; \n9. Gerar Cliente: Abrir o Arquivo do Cliente e preencher, via teclado, os campos do Arquivo Cliente e salvá-los depois; \n10. Listar  Mensagem  sobre  o  Total  Arrecadado  pelo  Supermercado  e  o  Número  de  Itens Vendidos em um dia qualquer; (atencao quanto a restrição para datas futuras) \n11. Menu.\n");
        int escolha;
        scanf("%d", &escolha);
        switch (escolha)
        {
        case -1:
            sair = 1;
            break;
        case 1:{
            printf("Importante: para carregar o vetor com os produtos, eh preciso ter cadastrado ao menos um produto. Deseja cadastrar?\n1- sim\n2- nao\n");
            int escolha1;
            scanf("%d",&escolha1);
            switch (escolha1)
            {
            case 1:
                cadastrarprod();
                carregartabela(tabela);
                printf("Vetor carregado!\n");
                break;
            case 2:
                carregartabela(tabela);
                printf("Vetor carregado!\n");
                break;
            default:
                break;
            }
            break;
        }
        case 6:{
            listartabela(tabela);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
void cadastrarprod(){
    scanf("%*c");
    FILE *arqprod = fopen("produto.dat","wb");
    Produto c;
    if(arqprod){
        printf("Digite o codigo do produto: ");
        fgets(c.cod,10,stdin);
        printf("Digite o nome do produto: ");
        fgets(c.nome,40,stdin);
        printf("Digite o preco do produto: ");
        scanf("%f",&c.preco);
        fwrite(&c,sizeof(Produto),1,arqprod);
        printf("Produto cadastrado com sucesso.\n");
    }else{
        printf("Falha ao abrir arquivo de produtos.\n");
    }
    fclose(arqprod);
}

void carregartabela(Produto *tabela[]){
    int i = 0;
    FILE *arqprod = fopen("produto.dat","wb");
    Produto c;
    while(fread(&c,sizeof(c),1,arqprod)){
        strcpy(tabela[i]->cod, c.cod);
        strcpy(tabela[i]->nome, c.nome);
        tabela[i]->preco = c.preco;
        i++;
    }
}

void listartabela(Produto tabela[]){
    for(int i=0;i<tam;i++){
        printf("Produto %d:\n",i+1);
        printf("Codigo: %s.\n",tabela[i].cod);
        printf("Nome: %s.\n",tabela[i].nome);
        printf("Preco: %.2f.\n",tabela[i].preco);
    }
}