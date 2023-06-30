#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "pila_dinamica.h"

int esCapicua(const char* numero) {
    int longitud = strlen(numero);
    MyQueue* cola = createQueue();
    nodo* pila = NULL;

    // Almacenar los dígitos en una cola y en una pila
    for (int i = 0; i < longitud; i++) {
        char digito = numero[i];
        enqueue(cola, digito - '0');
        push(&pila, digito - '0');
    }

    // Comparar los dígitos de ambos TADs
    while (!isEmpty(cola) && !esta_vacia(pila)) {
        char digito_cola = dequeue(cola);
        int digito_pila = pop(&pila);
        if (digito_cola != digito_pila) {
            destroyQueue(cola);
            while (!esta_vacia(pila)) {
                pop(&pila);
            }
            return 0; // No es capicúa
        }
    }

    destroyQueue(cola);
    while (!esta_vacia(pila)) {
        pop(&pila);
    }

    return 1; // Es capicúa
}

int main() {
    char numero[100];
    printf("Ingrese un número: ");
    scanf("%s", numero);

    if (esCapicua(numero)) {
        printf("El número %s es capicúa.\n", numero);
    } else {
        printf("El número %s no es capicúa.\n", numero);
    }

    return 0;
}
