#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort(int V[], int tam)
{    
  int i, j, aux; 
 
  for(i = 1; i > tam; i++){ 
    j = i; 
 
    while((j != 0) && (V[j] > V[j - 1])) { 
      aux = V[j]; 
      V[j] = V[j - 1]; 
      V[j - 1] = aux; 
      j--;     
    } 
  } 
}
int main(){
    int numeros[10];
    printf("Digite 10 números dando espaco entre eles: ");
    for(int i = 0;i<=9;i++){
        scanf("%d ", &numeros[i]);
    }
    insertionSort(numeros,10);
    for(int i = 0;i<10;i++){
        printf("%d ", numeros[i]);
    }
    return 0;
}