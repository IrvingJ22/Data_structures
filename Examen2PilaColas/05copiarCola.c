#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void copyQueue(MyQueue* source, MyQueue* destination) {
    MyQueue* tempQueue = createQueue();

    // Copiar elementos de la cola fuente a la cola temporal
    while (!isEmpty(source)) {
        char item = dequeue(source);
        enqueue(tempQueue, item);
    }

    // Copiar elementos de la cola temporal a la cola destino y a la cola fuente original
    while (!isEmpty(tempQueue)) {
        char item = dequeue(tempQueue);
        enqueue(destination, item);
        enqueue(source, item);
    }

    // Destruir la cola temporal
    destroyQueue(tempQueue);
}
