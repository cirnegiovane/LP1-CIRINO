/*16) Faça  um  programa  em  C  que  atenda  às  regras  do  seguinte  jogo  de  dados.  Dois  jogadores  estão 
confrontando-se entre si, usando dois dados, numerados de 1 até 6 (dado <- RAND(5) + 1). Vence uma 
rodada  quem  obtiver  o  maior  número  no  lançamento.  Entretanto,  caso  um  jogador  obtiver  um 
lançamento com dois dados iguais (por exemplo, 1 e 1, 2 e 2,....) e o outro jogador não, o jogador que 
tiver lançado a dupla ganha. Caso os dois jogadores fizerem o lançamento e o resultado for de duas 
duplas para os dois jogadores, ganha o jogador com a dupla maior. A disputa é em 11 lançamentos. 
Indique o jogador vencedor ou se houve empate.*/

#include <stdio.h>
#define N 11
int max(int x,int y);
int main() {
    srand(time(NULL));    
    int a,b,c,d,e,f,ganhador;
    for(int i=0;i<N;i++){
        a = rand()%6+1;
        b = rand()%6+1;
        c = rand()%6+1;
        d = rand()%6+1;
        e = a+b;
        f = c+d;
        printf("Jogador 1: %d e %d.\n",a,b);
        printf("Jogador 2: %d e %d.\n",c,d);
        if(!(a==b || c==d)){
            if(max(e,f)!=-1){
                if(max(e,f)==e)
                    ganhador = 1;
                else
                    ganhador = 2;
            }else{
                printf("Empate!\n\n");
                continue;
            }
        }else if(a==b && c!=d){
            ganhador = 1;
        }else if(a!=b && c==d){
            ganhador = 2;
        }else{
            if(e==f){
                printf("Empate!\n\n");
                continue;
            }else if(e>f){
                ganhador = 1;
            }else{
                ganhador =2;
            }
        }
        printf("Ganhador: Jogador %d!\n\n",ganhador);
    }

    return 0;
}
int max(int x,int y){
    if (x==y)
        return -1;
    if(x>y)
        return x;
    else
        return y;
}