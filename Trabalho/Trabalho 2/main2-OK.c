#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido {
    struct Pedido *prox;
    char codpedido[20];
    int qtdpedido;
} Pedido;

typedef struct Mesa {
    struct Mesa *ant, *prox;
    char nummesa[20];
    char codgarcom[20];
    float total;
    Pedido *pedidos;
} Mesa;

typedef struct Produto
{
    char codproduto[20];
    float preco[20];
}Produto;

typedef struct Garcom
{
    char codgarcom[20];
    char nomegarcom[20];
}Garcom;



void ocuparMesa(Mesa **inicio, Mesa **ultimo);
int listaVazia(Mesa *inicio);
void registrarPedido(char nummesa[], Mesa *inicio);
void desocuparMesa(char nummesa[], Mesa **inicio);
void fecharContaMesa(char nummesa[], Mesa **inicio,char arqproduto[],char arqgarcom[]);

int main() {
    Mesa *inicioMesa = NULL;
    Mesa *ultimoMesa = NULL;
    char arqproduto[] = "produto.dat";
    char arqgarcom[] = "garcom.dat";
    int escolha = 99;
    while (escolha != -1) {
        printf("O que deseja fazer?\n(-1) Sair.\n(1) Ocupar mesa.\n(2) Registrar pedido.\n(3) Desocupar mesa.\n(4) Nota fiscal.\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case -1:
                printf("Encerrando programa.\n");
                break;
            case 1:
                ocuparMesa(&inicioMesa, &ultimoMesa);
                break;
            case 2: {
                printf("Qual o numero da mesa? ");
                char num[20];
                fgets(num, 20, stdin);
                int k;
                scanf("%d",&k);
                registrarPedido(num, inicioMesa);
                break;
            }
            case 3: {
                printf("Qual o numero da mesa? ");
                char num2[20];
                fgets(num2, 20, stdin);
                int j;
                scanf("%d",&j);
                desocuparMesa(num2, &inicioMesa);
                break;
            }
            case 4: {
                printf("Qual o numero da mesa? ");
                char num3[20];
                fgets(num3, 20, stdin);
                int l;
                scanf("%d",&l);
                fecharContaMesa(num3,&inicioMesa,arqproduto,arqgarcom);
                break;
            }
            default:
                printf("Se atenha as alternativas.\n");
                break;
        }
    }
    return 0;
}

int listaVazia(Mesa *inicio) {
    return inicio == NULL;
}

void ocuparMesa(Mesa **inicio, Mesa **ultimo) {
    Mesa *aux = malloc(sizeof(Mesa));
    if (aux == NULL) {
        printf("\nERRO AO ALOCAR NOVA MESA!\n");
        return;
    }
    int j,k;
    printf("\nDigite o numero da mesa: ");
    fgets(aux->nummesa, 20, stdin);
    scanf("%d",&j);

    printf("Digite o codigo do garcom: ");
    fgets(aux->codgarcom, 20, stdin);
    scanf("%d",&k);

    aux->pedidos = NULL;

    if (listaVazia(*inicio)) {
        *inicio = aux;
        *ultimo = aux;
    } else {
        aux->ant = *ultimo;
        (*ultimo)->prox = aux;
        *ultimo = aux;
    }
    printf("Mesa ocupada.\n\n");
}

void registrarPedido(char nummesa[], Mesa *inicio) {
    Mesa *aux = inicio;

    while (aux != NULL) {
        if (strcmp(nummesa, aux->nummesa) == 0) {
            Pedido *pedido = malloc(sizeof(Pedido));
            if (pedido == NULL) {
                printf("\nERRO AO ALOCAR NOVO PEDIDO!\n");
                return;
            }

            printf("Digite o codigo do pedido: ");
            fgets(pedido->codpedido, 20, stdin);

            printf("Digite a qtd do pedido: ");
            scanf("%d", &(pedido->qtdpedido));
            getchar();

            pedido->prox = NULL;

            if (aux->pedidos == NULL) {
                aux->pedidos = pedido;
            } else {
                Pedido *lastPedido = aux->pedidos;
                while (lastPedido->prox != NULL) {
                    lastPedido = lastPedido->prox;
                }
                lastPedido->prox = pedido;
            }
            printf("Pedido registrado para a mesa %s.\n", nummesa);
            return;
        }
        aux = aux->prox;
    }
    printf("Mesa nao encontrada.\n");
}

void desocuparMesa(char nummesa[], Mesa **inicio) {
    Mesa *atual = *inicio;
    Mesa *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(nummesa, atual->nummesa) == 0) {
            if (anterior == NULL) {
                *inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Mesa %s desocupada.\n", nummesa);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Mesa %s nao encontrada para desocupar.\n", nummesa);
}

void fecharContaMesa(char nummesa[], Mesa **inicio,char arqproduto[],char arqgarcom[]) {
    Mesa *atual = *inicio;
    Mesa *anterior = NULL;
    FILE *fileproduto = fopen(arqproduto,"rb");
    FILE *filegarcom = fopen(arqgarcom,"rb");
    while (atual != NULL) {
        if (strcmp(nummesa, atual->nummesa) == 0) {
            float totalConta = 0.0;
            Garcom g;
            while(fread(&g,sizeof(Garcom),1,arqgarcom)){
                    if(strcmp(g.codgarcom,atual->codgarcom) == 0){
                        printf("Nome do garçom: %s\n", g.nomegarcom);
                        break;
                    }
                }
            
            printf("Detalhes do consumo:\n");

            Pedido *pedidoAtual = atual->pedidos;
            while (pedidoAtual != NULL) {
                printf("Código do pedido: %s - Quantidade: %d\n", pedidoAtual->codpedido, pedidoAtual->qtdpedido);
                Produto p;
                while(fread(&p,sizeof(Produto),1,arqproduto)){
                    if(strcmp(p.codproduto,pedidoAtual->codpedido) == 0){
                        totalConta += (p.preco * pedidoAtual->qtdpedido);
                        break;
                    }
                }
                pedidoAtual = pedidoAtual->prox;
            }

            printf("Valor total da conta: %.2f\n", totalConta);

            Pedido *pedidoRemover = atual->pedidos;
            Pedido *proximoPedido;
            while (pedidoRemover != NULL) {
                proximoPedido = pedidoRemover->prox;
                free(pedidoRemover);
                pedidoRemover = proximoPedido;
            }

            if (anterior == NULL) {
                *inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Conta da mesa %s fechada e removida da memória.\n", nummesa);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Mesa %s nao encontrada para fechar a conta.\n", nummesa);
}