// Lista duplamente encadeada
#include <stdlib.h>
#include <stdio.h>
typedef struct no{
    int info;
    struct no *ant, *prox;
}no;
no *inicioD;
no *inicioE;

void startL(){
    inicioD = NULL;
    inicioE = NULL;
}

int listavazia(){
    if(inicioD == NULL)
        return 1;
    return 0;
}

void inserirD(int x){
    no *aux;
    aux = malloc(sizeof(no));
    if(aux == NULL){
        printf("\nERRO!");
    }else{
        aux->info = x;
        aux->prox = NULL;    
        aux->ant = NULL;
        if(listavazia()){
            inicioD = aux;
            inicioE = aux;
        }else{
            aux->ant = inicioD;
            inicioD->prox = aux;
            inicioD = aux;
        }
    }
}



/*void remover(int x){
    no *aux;
    if(!listavazia()){
        aux = buscaNo(x);
        if(aux!=NULL){//elemento encontrado
            if(inicioE==inicioD){
                inicioE = NULL;
                inicioD = NULL;
            }else{
                if(aux->ant==NULL){//inicio pela esquerda
                    inicioE = aux->prox;
                    inicioE->ant = NULL;
                }else{
                    if(aux->prox == NULL){//inicio pela direita
                        inicioD = aux->ant;
                        inicioD->prox = NULL;
                    }else{//elemento no meio da lista
                        no *anterior,*posterior;
                        anterior = aux->ant;
                        posterior = aux->prox;
                        anterior->prox = posterior;
                        posterior->ant = anterior;
                    }
                }
            }
            free(aux);
        }else{
            printf("Elemento não se encontra na lista!");
        }
    }else{
        printf("Lista vazia!");
    }
}
*/
void imprimir(){

    if(listavazia()){
        printf("Lista vazia.");
    }else{
        no *aux;
        aux = inicioE;
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;
        }
        printf("fim.\n");
    }
}

int main() {
    inserirD(8);
    inserirD(5);
    inserirD(3);
    inserirD(16);
    imprimir();
    printf("Teste1\n");
    printf("%d\n",inicioD->ant->ant->info);
    printf("Teste2\n");
    return 0;
}