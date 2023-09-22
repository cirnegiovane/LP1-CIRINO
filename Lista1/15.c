/*15) O Departamento de trânsito do estado anotou dados de acidentes de trânsito no último ano. Para cada
motorista envolvido no acidente, tem-se as seguintes informações:
- Ano de nascimento;
- Sexo (M - Masculino, F - Feminino)
- Procedência ( 0 - Capital, 1 - Interior, 2 - Outro estado);
Faça um programa em C que :
a) Calcule a porcentagem de motoristas com menos de 21 anos;
b) Calcule quantas mulheres são da capital;
c) Calcule quantos motoristas do interior do estado tem idade maior que 60 anos;
d) Verifique se existe alguma mulher com idade maior que 60 anos;*/
#include <stdio.h>
typedef struct nasc{
    int ano;
    int mes;
    int dia;
}nasci;
typedef struct {
    struct nasc nasc;
    char sexo;
    int procedencia;
    int idade;
}motorista;
int main() {
    int v;
    int qtd;
    printf("Quantos motoristas entrevistados? ");
    scanf("%d",&qtd);
    printf("\n");
    motorista motoristas[qtd];
    printf("Informações sobre os motoristas:\n");
    for(int i=0;i<qtd;i++){
        printf("Pessoa %d:\n",i+1);
        printf("Informe o nascimento (dd mm aaaa): ");
        scanf("%d %d %d",&motoristas[i].nasc.dia,&motoristas[i].nasc.mes,&motoristas[i].nasc.ano);
        v = getchar();
        printf("Informe o sexo (h,m): ");
        scanf("%c",&motoristas[i].sexo);
        printf("Procedencia (0-Capital, 1-Interior, 2-Outro estado): ");
        scanf("%d",&motoristas[i].procedencia);
        motoristas[i].idade = 2023-motoristas[i].nasc.ano;
        printf("\n");
    }
    //Calcule a porcentagem de motoristas com menos de 21 anos; 
    float qtd1 = qtd;
    float contA=0;
    for(int i = 0;i<qtd;i++){
        if(motoristas[i].idade<21)
            contA+=1;
    }
    float porcentagem = (contA/qtd1)*100;
    printf("Porcentagem de motoristas com menos de 21 anos: %.2f.\n",porcentagem);
    //Calcule quantas mulheres são da capital;
    int contb=0;
    for(int i = 0;i<qtd;i++){
        if(motoristas[i].sexo == 'm' && motoristas[i].procedencia==0)
            contb+=1;
    }
    printf("Qtd de mulheres na capital: %d.\n",contb);
    //Calcule quantos motoristas do interior do estado tem idade maior que 60 anos;
    int contc = 0;
    for(int i = 0;i<qtd;i++){
        if(motoristas[i].procedencia == 1 && motoristas[i].idade>60)
            contc+=1;
    }
    printf("Qtd de motoristas do interior com mais de 60 anos: %d.\n",contc);
    //Verifique se existe alguma mulher com idade maior que 60 anos;
    int contd=0;
    for(int i = 0;i<qtd;i++){
        if(motoristas[i].sexo == 'm' && motoristas[i].idade>60)
            contd+=1;
    }
    printf("Qtd de motoristas de mulheres com mais de 60 anos: %d.\n",contd);
    return 0;
}