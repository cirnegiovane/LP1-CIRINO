#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int dia,mes,ano;
    char nome[20];
    char genero;
}Pessoa;

void escrever(char arquivo[]);
void ler(char arquivo[]);
void aniversario(char arquivo[], char nome[]);
void apagar(char arquivo[],char nome[]);


int main (){
    char arq[] = {"pessoas.dat"};
    int k;
    while(k!=5){
        printf("O que quer fazer?\n(1) Ver as pessoas cadastradas\n(2) Cadastrar uma pessoa nova\n(3) Saber a idade de alguem cadastrado\n(4) Remover alguem ja cadastrado\n(5) Sair\nResposta: ");
        scanf("%d",&k);
        switch(k){
            case 1:
                ler(arq);
                break;
            case 2:
                escrever(arq);
                break;
            case 3:
                printf("\nQual o nome da pessoa (idade)? ");
                int j;
                scanf("%d",&j);
                char nomea[20];
                scanf("%19[^\n]",nomea);
                aniversario(arq,nomea);
                break;
            case 4:
                printf("\nQual o nome da pessoa (remocao)? ");
                int l;
                scanf("%d",&l);
                char nomer[20];
                scanf("%19[^\n]",nomer);
                apagar(arq,nomer);
                break;
            case 5:
                break;
            default:
                printf("\nSe atenha as opcoes.\n");
                break;
        }
    }
    return 0;
}


void aniversario(char arquivo[], char nome[]){
    Pessoa c;
    FILE *file = fopen(arquivo,"rb");
    if(file){
        while(fread(&c,sizeof(Pessoa),1,file)){
            if(!strcmp(c.nome,nome)){
                int idade = 2023 - c.ano;
                printf("\nIdade de %s: %d anos.\n\n",nome,idade);
                break;
            }
        }
        fclose(file);
    }else{
        printf("\nErro ao abrir o arquivo!\n");
    }
}
void escrever(char arquivo[]){
    Pessoa c;
    int t;
    FILE *file;
    file = fopen(arquivo,"ab");
    if(file){
        printf("Digite o nome da pessoa: ");
        scanf("%d",&t);
        scanf("%19[^\n]",c.nome);
        printf("Digite a data de nascimento da pessoa (dd mm aaaa): ");
        scanf("%d %d %d",&c.dia,&c.mes,&c.ano);
        fwrite(&c,sizeof(Pessoa),1,file);
        printf("\n");
        fclose(file);
    }else{
        printf("\nErro ao abrir o arquivo!\n");
    }
}
void ler(char arquivo[]){
    Pessoa c;
    FILE *file = fopen(arquivo,"rb");
    if(file){
        while(fread(&c,sizeof(Pessoa),1,file)){
            printf("\nNome: %s.\nNascimento: %d/%d/%d.\n",c.nome,c.dia,c.mes,c.ano);
        }
        printf("\n");
        fclose(file);
    }else{
        printf("\nErro ao abrir o arquivo, verifique se ja cadastrou alguem!\n");
    }
}
void apagar(char arquivo[],char nome[]){
    Pessoa c;
    FILE *file = fopen(arquivo,"rb");
    if(file){
        FILE *filetemp = fopen("arqtemp.dat","wb");
        if(filetemp){
            int encontrou = 0;
            while(fread(&c,sizeof(Pessoa),1,file)){
                if(!strcmp(c.nome,nome)){
                    encontrou = 1;
                }else{
                    fwrite(&c,sizeof(Pessoa),1,filetemp);
                }
            }
            fclose(file);
            fclose(filetemp);
            if(encontrou){
                printf("\nRegistro removido com sucesso!(%s)\n\n",nome);
                remove(arquivo);
                rename("arqtemp.dat",arquivo);
            }else{
                printf("\nRegistro nao encontrado! (%s)\n\n",nome);
                remove("arqtemp.dat");
            }
        }else{
            printf("\nErro ao abrir o arquivo temporario!\n");
        }
    }else{
        printf("\nErro ao abrir o arquivo!\n");
    }
}