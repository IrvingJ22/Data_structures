#include "pila.h"
#include <stdio.h>

void inicializar(My_stack *pila) {
    pila->top = -1;
}

void push(My_stack *pila, int value) { // es la funcion de agregra un elemento
    if (pila->top < MAX_SIZE - 1) {
        pila->top++;
        pila->data[pila->top] = value;
    } //else {
        //printf("Error: la pila esta llena.\n");
    //}
}

int pop(My_stack *pila) { // es la funcion para remover un elemento
    int value = -1;
    if (pila->top >= 0) {
        value = pila->data[pila->top];
        pila->top--;
    } else {
        printf("Error: la pila esta vacia.\n");
    }
    return value;
}

void show(My_stack *pila) { //mostrar la pila
    if (pila->top >= 0) {
        printf("Elementos en la pila:\n");
        for (int i = pila->top; i >= 0; i--) {
            printf("%d\n", pila->data[i]);
        }
    } else {
        printf("La pila esta vacia.\n");
    }
}