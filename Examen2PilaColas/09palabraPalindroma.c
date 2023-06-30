#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mypila.h"
#include "mycola.h"

int esPalindromo(char* frase) {
    int longitud = strlen(frase);
    Pila* pila = crearPila();
    Cola* cola = crearCola();

    // Almacenar los caracteres de la frase en la pila y la cola
    for (int i = 0; i < longitud; i++) {
        char caracter = frase[i];
        if (caracter != ' ') {  // Ignorar espacios en blanco
            apilar(pila, caracter);
            encolar(cola, caracter);
        }
    }

    // Comparar los caracteres de la pila y la cola
    while (!pilaVacia(pila) && !colaVacia(cola)) {
        char caracterPila = desapilar(pila);
        char caracterCola = desencolar(cola);
        if (caracterPila != caracterCola) {
            destruirPila(pila);
            destruirCola(cola);
            return 0;  // No es un palíndromo
        }
    }

    destruirPila(pila);
    destruirCola(cola);
    return 1;  // Es un palíndromo
}

int main() {
    char frase[100];
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Eliminar el salto de línea al final de la frase ingresada
    frase[strcspn(frase, "\n")] = '\0';

    if (esPalindromo(frase)) {
        printf("La frase es un palindromo.\n");
    } else {
        printf("La frase no es un palindromo.\n");
    }

    return 0;
}
