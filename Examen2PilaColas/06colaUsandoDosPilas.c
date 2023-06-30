#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

typedef struct {
    nodo* pila_enqueue;
    nodo* pila_dequeue;
} MyQueueUsingStacks;

MyQueueUsingStacks* createQueueUsingStacks() {
    MyQueueUsingStacks* queue = (MyQueueUsingStacks*)malloc(sizeof(MyQueueUsingStacks));
    inicializar(&(queue->pila_enqueue));
    inicializar(&(queue->pila_dequeue));
    return queue;
}

int isEmptyQueueUsingStacks(MyQueueUsingStacks* queue) {
    return esta_vacia(queue->pila_enqueue) && esta_vacia(queue->pila_dequeue);
}

void enqueueUsingStacks(MyQueueUsingStacks* queue, element x) {
    push(&(queue->pila_enqueue), x);
}

element dequeueUsingStacks(MyQueueUsingStacks* queue) {
    if (isEmptyQueueUsingStacks(queue)) {
        printf("La cola está vacía, no se puede eliminar ningún elemento.\n");
        exit(EXIT_FAILURE);
    }

    if (esta_vacia(queue->pila_dequeue)) {
        while (!esta_vacia(queue->pila_enqueue)) {
            element x = pop(&(queue->pila_enqueue));
            push(&(queue->pila_dequeue), x);
        }
    }

    return pop(&(queue->pila_dequeue));
}

void displayQueueUsingStacks(MyQueueUsingStacks* queue) {
    if (isEmptyQueueUsingStacks(queue)) {
        printf("La cola está vacía.\n");
        return;
    }

    printf("Los elementos de la cola son: ");

    nodo* actual = queue->pila_dequeue;
    while (actual != NULL) {
        printf("%c ", actual->dato);
        actual = actual->siguiente;
    }

    nodo* auxiliar = queue->pila_enqueue;
    while (auxiliar != NULL) {
        printf("%c ", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
    }

    printf("\n");
}

void destroyQueueUsingStacks(MyQueueUsingStacks* queue) {
    while (!esta_vacia(queue->pila_enqueue)) {
        pop(&(queue->pila_enqueue));
    }
    while (!esta_vacia(queue->pila_dequeue)) {
        pop(&(queue->pila_dequeue));
    }
    free(queue);
    printf("La cola ha sido destruida correctamente.\n");
}
