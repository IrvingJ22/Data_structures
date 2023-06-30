#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

void inicializar(nodo** cima_pila) {
    *cima_pila = NULL;
}

int esta_vacia(nodo* cima_pila) {
    return (cima_pila == NULL);
}

void push(nodo** cima_pila, element x) {
    nodo* nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo->dato = x;
    nuevo_nodo->siguiente = *cima_pila;
    *cima_pila = nuevo_nodo;
}

element pop(nodo** cima_pila) {
    if (esta_vacia(*cima_pila)) {
        printf("La pila esta vacia.\n");
        exit(EXIT_FAILURE);
    }
    element resultado = (*cima_pila)->dato;
    nodo* nodo_borrar = *cima_pila;
    *cima_pila = (*cima_pila)->siguiente;
    free(nodo_borrar);
    return resultado;
}

void mostrar_pila(nodo* cima_pila) {
    if (esta_vacia(cima_pila)) {
        printf("La pila esta vacia.\n");
        return;
    }
    printf("La pila es:\n");
    nodo* actual = cima_pila;
    while (actual != NULL) {
        printf("%c\n", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}