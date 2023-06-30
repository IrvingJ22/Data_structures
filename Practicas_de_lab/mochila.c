#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <math.h>


typedef struct Elemento{
    int peso;
    int valor;
} Objeto;


/*void decimal_a_binario(int decimal, char binario[]) {
    int i = 0;
    while (decimal > 0) {
        binario[i++] = (decimal % 2) + '0'; // Obtiene el residuo y lo convierte a un dígito ASCII
        decimal /= 2; // División entre 2
    }
    binario[i] = '\0'; // Agrega el caracter nulo al final de la cadena
    strrev(binario); // Invierte la cadena de dígitos binarios
}*/
void decimal_a_binario(int decimal, char binario[]) {
    int i = 0, j;
    char temp[32]; // Cadena temporal para almacenar los dígitos binarios

    while (decimal > 0) {
        temp[i++] = (decimal % 2) + '0'; // Obtiene el residuo y lo convierte a un dígito ASCII
        decimal /= 2; // División entre 2
    }

    // Invierte la cadena de dígitos binarios en la cadena final
    for (j = 0; i > 0; j++, i--) {
        binario[j] = temp[i - 1];
    }
    binario[j] = '\0'; // Agrega el caracter nulo al final de la cadena
}


int main(){
    char binario[32];
    Objeto objetos[8];

    objetos[0].peso = 1;
    objetos[1].peso = 10;
    objetos[2].peso = 30;
    objetos[3].peso = 20;
    objetos[4].peso = 5;
    objetos[5].peso = 10;
    objetos[6].peso = 1;
    objetos[7].peso = 50;
    
    objetos[0].valor = 4000;
    objetos[1].valor = 2000;
    objetos[2].valor = 1000;
    objetos[3].valor = 5000;
    objetos[4].valor = 1500;
    objetos[5].valor = 1200;
    objetos[6].valor = 800;
    objetos[7].valor = 2500;
    
    
    
    for(int i = 0; i<=pow(2,8)-1; i++){
        printf("El valor de %d en binario es: ", i);
        decimal_a_binario(i, binario);
        printf("%s\n", binario);
    }
    

    return 0;
}