/*14) Faça um programa em C que simule um cronômetro com horas, minutos e segundos. A simulação deverá mostrar no vídeo o cronômetro no seguinte formato HH: MM: SS. Inicialmente o cronômetro será zerado ( 00: 00: 00 ), sendo que os segundos começarão a ser incrementados, depois os minutos e depois as horas. Lembre-se que a cada 60 segundos os minutos deverão ser incrementados, depois os minutos voltarão a zero. Quando as horas estiverem prestes a chegar em 24, o cronômetro deverá voltar a zero ( 00: 00: 00 ). */
#include <stdio.h>

int main() {
    int parou = 0;
    int h = 0,m=0,s = 00;
    while(!parou){
        printf("%.2dh:%.2dmin:%.2ds\n",h,m,s);
        s+=1;
        if(s==60){
            m+=1;
            s=0;
        }
        if(m==60){
            h+=1;
            m=0;
        }
        if(h==24){
            h=0;
            printf("%.2dh:%.2dmin:%.2ds\n",h,m,s);
            parou = 1;
        }
    }
    return 0;
}