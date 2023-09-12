/*7) Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas acima da média da turma. Considerar que a turma tenha 50 alunos. Usar a estrutura multivalorada vista em sala de aula. */
#include <stdio.h>
#define max 10
typedef struct taluno{
    char nome[15];
    float nota;
}aluno;
int main() {
    aluno alunos[max];
    float somanota =0;
    float notamaior = -1;
    float media;
    printf("Iniciando coleta de dados.\n");
    for(int i = 0;i<max;i++){
        printf("Digite nome do aluno %d: ",i+1);
        scanf(" %[^\n]",alunos[i].nome);
        printf("Digite a nota desse aluno: ");
        scanf("%f",&alunos[i].nota);
        somanota += alunos[i].nota;
    }
    media = somanota/max;
    printf("\nMedia da turma: %.2f\n",media);
    int cont =0;
    for(int i = 0;i<max && cont < 5;i++){
        if(alunos[i].nota > media){
            printf("%s - Nota: %.2f.\n",alunos[i].nome,alunos[i].nota);
            cont++;
        }
    }