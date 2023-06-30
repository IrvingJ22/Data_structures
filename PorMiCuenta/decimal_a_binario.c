#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>

int main(){
    int numero_a_convertir, bin[999];
    int i = 0;

    printf("Ingresa el numero en decimal: ");
    scanf("%i",&numero_a_convertir);

    while(numero_a_convertir != 0){
        bin[i] = numero_a_convertir % 2;
        numero_a_convertir /= 2;
        i++;
    }
    i--;

    printf("Binario: \n");

    while(i >= 0){
        printf("%i",bin[i]);
        i--;
    }

    return 0;
}