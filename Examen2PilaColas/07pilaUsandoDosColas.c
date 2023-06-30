#include <stdio.h>
#include <stdlib.h>
#include "myqueue.h"

typedef struct {
    MyQueue* queue_main;
    MyQueue* queue_aux;
} MyStackUsingQueues;

MyStackUsingQueues* createStackUsingQueues() {
    MyStackUsingQueues* stack = (MyStackUsingQueues*)malloc(sizeof(MyStackUsingQueues));
    stack->queue_main = createQueue();
    stack->queue_aux = createQueue();
    return stack;
}

int isEmptyStackUsingQueues(MyStackUsingQueues* stack) {
    return isEmpty(stack->queue_main);
}

void pushUsingQueues(MyStackUsingQueues* stack, char item) {
    enqueue(stack->queue_main, item);
}

char popUsingQueues(MyStackUsingQueues* stack) {
    if (isEmptyStackUsingQueues(stack)) {
        printf("La pila está vacía, no se puede eliminar ningún elemento.\n");
        exit(EXIT_FAILURE);
    }

    // Transferir elementos a la cola auxiliar, excepto el último elemento
    while (size(stack->queue_main) > 1) {
        char item = dequeue(stack->queue_main);
        enqueue(stack->queue_aux, item);
    }

    // Extraer el último elemento de la cola principal (que es el tope de la pila)
    char popped_item = dequeue(stack->queue_main);

    // Intercambiar las colas principal y auxiliar
    MyQueue* temp = stack->queue_main;
    stack->queue_main = stack->queue_aux;
    stack->queue_aux = temp;

    return popped_item;
}

void displayStackUsingQueues(MyStackUsingQueues* stack) {
    display(stack->queue_main);
}

void destroyStackUsingQueues(MyStackUsingQueues* stack) {
    destroyQueue(stack->queue_main);
    destroyQueue(stack->queue_aux);
    free(stack);
    printf("La pila ha sido destruida correctamente.\n");
}
