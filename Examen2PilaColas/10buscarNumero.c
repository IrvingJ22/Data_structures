#include <stdio.h>
#include <stdlib.h>
#include "mycola.h"

int buscarEnCola(Cola* cola, int elemento) {
    int encontrado = 0;
    Cola* colaAuxiliar = crearCola(); // Cola auxiliar para preservar el estado original de la cola

    // Recorrer la cola y buscar el elemento
    while (!colaVacia(cola)) {
        int elementoActual = desencolar(cola);
        encolar(colaAuxiliar, elementoActual);

        if (elementoActual == elemento) {
            encontrado = 1;
            break;
        }
    }

    // Restaurar el estado original de la cola
    while (!colaVacia(colaAuxiliar)) {
        int elementoAuxiliar = desencolar(colaAuxiliar);
        encolar(cola, elementoAuxiliar);
    }

    destruirCola(colaAuxiliar);

    return encontrado;
}

int main() {
    Cola* cola = crearCola();
    int elemento;

    // Agregar elementos a la cola
    encolar(cola, 10);
    encolar(cola, 20);
    encolar(cola, 30);
    encolar(cola, 40);
    encolar(cola, 50);

    // Pedir al usuario que ingrese el elemento a buscar
    printf("Ingrese un entero: ");
    scanf("%d", &elemento);

    // Verificar si el elemento se encuentra en la cola
    if (buscarEnCola(cola, elemento)) {
        printf("El elemento %d se encuentra en la cola.\n", elemento);
    } else {
        printf("El elemento %d no se encuentra en la cola.\n", elemento);
    }

    // Liberar memoria de la cola
    destruirCola(cola);

    return 0;
}
