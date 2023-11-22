#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Mesas : Lista Duplamente Encadeada onde cada nó deverá conter as seguintes informações: Número 
da mesa, código do garçom, total do pedido e um elo para a lista de pedidos.
Para  cada  mesa  ocupada  no  restaurante,  deverá  existir  um  nó  na  lista  de  mesas.  Cada  nó  na  lista  de  mesas 
deverá conter uma lista simplesmente encadeada de pedidos. O campo que se refere ao total da mesa, deverá 
ser atualizado sempre que um cliente fizer um novo pedido.
*/
typedef struct {
    struct Nomesa *ant,*prox;
    char nummesa[20];
    char codgarcom[20];
    float total;
    struct Nopedido *pedidos;
}Nomesa;

/*
Pedidos : Lista Simplesmente Encadeada onde cada nó deverá conter o Código do Pedido, Quantidade 
do pedido e um elo para o próximo pedido;
*/

typedef struct {
    struct Nopedido *prox;
    char codpedido[20];
    int qtdpedido;
}Nopedido;


/*
Deverão  ser  criados  dois  arquivos  binários:  01)  com  um  struct  com  os  pratos,  as  bebidas,  seus  respectivos 
códigos e preços; 02) com um struct com o nome do garçom e seu código. Quando do fechamento da conta de 
uma mesa, o sistema deverá gerar uma nota fiscal com a discriminação do consumo e o valor total da conta e 
o  nome  do garçom  que  atendeu  a  mesa. A  nota fiscal deverá  ser apresentada  em vídeo.  Os  nós  referentes  à 
mesa e aos pedidos que foram computados na nota fiscal deverão ser retirados de memória. 
*/

typedef struct {
    char codprato[20];
    float preco;
}Prato;

typedef struct {
    char nomegarcom[20];
    char codgarcom[20];
}Garcom;

void ocuparmesa(Nomesa *inicio,Nomesa *ultimo);
int listavazia();
void registrarpedido(char nummesa[], Nomesa *inicio);

int main(){
    Nomesa *iniciomesa = NULL;
    Nomesa *ultimomesa = NULL;
    //char arqpratos = "pratos.dat";
    //char arqgarcons = "garcons.dat";
    int escolha = 99;
    while(escolha!=-1){
        printf("O que deseja fazer?\n(-1) Sair.\n(1) Ocupar mesa.\n(2) Registrar pedido.\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case -1:
            printf("Encerrando programa.\n");
            break;
        case 1:
            ocuparmesa(iniciomesa,ultimomesa);
            break;
        case 2:{
            printf("Qual o numero da mesa? ");
            char num[20];
            fgets(num,20,stdin);
            registrarpedido(num,iniciomesa);
            break;
        }
        case 3:{
            Nomesa *teste;
            teste = iniciomesa;
            if(teste == NULL)
                printf("\nTeste nulo\n");
            while(teste != NULL){
                if(strcmp(teste->nummesa,"15") == 0){
                    printf("Numero do garcom: %s.\n",teste->codgarcom);
                }
                teste = teste->prox;
            }
            printf("OK");
            break;
        }
        default:
            printf("Se atenha as alternativas.\n");
            break;
        }
    }
    return 0;
}

int listavazia(Nomesa *inicio){
    if(inicio == NULL)
        return 1;
    return 0;
}

void ocuparmesa(Nomesa *inicio,Nomesa *ultimo){
    Nomesa *aux;
    aux = malloc(sizeof(Nomesa));
    if(aux == NULL){
        printf("\nERRO AO ALOCAR NOVA MESA!\n");
    }else{
        int k,j;
        printf("\nDigite o numero da mesa: ");
        fgets(aux->nummesa,20,stdin);
        scanf("%d",&k);
        printf("Digite o codigo do garcom: ");
        fgets(aux->codgarcom,20,stdin);
        scanf("%d",&j);
        aux->pedidos = NULL;
        if(listavazia(inicio)){
            printf("Lista tava vazia.\n");
            inicio = aux;
            ultimo = aux;
        }else{
            printf("Lista nao tava vazia.\n");
            aux->ant = ultimo;
            ultimo->prox = aux;
            ultimo = aux;
        }
        printf("Mesa ocupada.\n\n");
    }
}

void registrarpedido(char nummesa[], Nomesa *inicio){
    Nomesa *aux = inicio;
    Nopedido *pedido;
    int achou = 0;
    while(!achou){
        if(strcmp(nummesa,aux->nummesa)){
            pedido = malloc(sizeof(Nopedido));
            int k,j;
            printf("Digite o codigo do pedido: ");
            fgets(pedido->codpedido,20,stdin);
            scanf("%d",&k);
            printf("Digite a qtd do pedido: ");
            scanf("%d",&j);
            fgets(pedido->qtdpedido,20,stdin);
            if(!aux->pedidos){
                aux->pedidos = pedido;
            }
            achou = 1;
        }
    }
}