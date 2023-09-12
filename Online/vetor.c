#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    switch(strcmp("a111111agio","1111lua")){
        case 1:
        printf("segundo maior");
        case 0:
        break;
        printf("iguais");
        case -1:
        break;
        printf("primeiro maior");
        break;
    }
    return 0;
}