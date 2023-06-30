#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

void sumarEnterosGrandes(const char* num1, const char* num2) {
    nodo* pila1 = NULL; // Pila para almacenar el primer número
    nodo* pila2 = NULL; // Pila para almacenar el segundo número
    nodo* resultado = NULL; // Pila para almacenar el resultado de la suma
    int acarreo = 0; // Variable para almacenar el acarreo

    // Convertir los números en caracteres a pilas de dígitos
    for (int i = 0; num1[i] != '\0'; i++) {
        int digito = num1[i] - '0'; // Convertir el dígito de carácter a entero
        push(&pila1, digito);
    }

    for (int i = 0; num2[i] != '\0'; i++) {
        int digito = num2[i] - '0'; // Convertir el dígito de carácter a entero
        push(&pila2, digito);
    }

    // Realizar la suma de los dígitos
    while (!esta_vacia(pila1) || !esta_vacia(pila2) || acarreo > 0) {
        int digito1 = esta_vacia(pila1) ? 0 : pop(&pila1);
        int digito2 = esta_vacia(pila2) ? 0 : pop(&pila2);
        int suma = digito1 + digito2 + acarreo;
        int digito_resultado = suma % 10;
        acarreo = suma / 10;
        push(&resultado, digito_resultado);
    }

    // Mostrar el resultado de la suma
    printf("La suma de %s y %s es: ", num1, num2);
    mostrar_pila(resultado);

    // Liberar la memoria de las pilas
    while (!esta_vacia(pila1)) {
        pop(&pila1);
    }

    while (!esta_vacia(pila2)) {
        pop(&pila2);
    }

    while (!esta_vacia(resultado)) {
        pop(&resultado);
    }
}
