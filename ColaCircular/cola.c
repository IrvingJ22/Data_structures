#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

MyQueue* createQueue() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->head = -1;
    queue->tail = -1;
    return queue;
}

int isEmpty(MyQueue* queue) {
    return queue->head == -1;
}

int isFull(MyQueue* queue) {
    return ((queue->tail + 1) % MAX) == queue->head;
}

void enqueue(MyQueue* queue, char item) {
    if (isFull(queue)) {
        printf("La cola está llena, no se puede insertar %c.\n", item);
        return;
    } else if (isEmpty(queue)) {
        queue->head = 0;
        queue->tail = 0;
    } else {
        queue->tail = (queue->tail + 1) % MAX;
    }

    queue->items[queue->tail] = item;
    printf("'%c' se ha insertado correctamente en la cola.\n", item);
}

char dequeue(MyQueue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía, no se puede eliminar ningún elemento.\n");
        return '\0';
    }

    char item = queue->items[queue->head];
    if (queue->head == queue->tail) {
        queue->head = -1;
        queue->tail = -1;
    } else {
        queue->head = (queue->head + 1) % MAX;
    }

    printf("%c se ha eliminado correctamente de la cola.\n", item);
    return item;
}

void display(MyQueue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía\n");
        return;
    }
  
    printf("Los elementos de la cola son: ");

    int i = queue->head;
    while (i != queue->tail) {
        printf("%c ", queue->items[i]);
        i = (i + 1) % MAX;
    }

    printf("%c\n", queue->items[queue->tail]);
}

void destroyQueue(MyQueue* queue) {
    free(queue);
    printf("La cola ha sido destruida correctamente.\n");
}
