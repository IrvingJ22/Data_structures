#include <stdio.h>
#include <stdlib.h>
#include "colaDinamica.h"

MyQueue* createQueue() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int isEmpty(MyQueue* queue) {
    return queue->head == NULL;
}

void enqueue(MyQueue* queue, char item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    printf("%c se ha insertado correctamente en la cola.\n", item);
}

char dequeue(MyQueue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía, no se puede eliminar ningún elemento.\n");
        return '\0';
    }

    Node* nodeToRemove = queue->head;
    char item = nodeToRemove->data;

    queue->head = queue->head->next;
    free(nodeToRemove);

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    printf("%c se ha eliminado correctamente de la cola.\n", item);
    return item;
}

void display(MyQueue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return;
    }

    printf("Los elementos de la cola son: ");

    Node* currentNode = queue->head;
    while (currentNode != NULL) {
        printf("%c ", currentNode->data);
        currentNode = currentNode->next;
    }

    printf("\n");
}

void destroyQueue(MyQueue* queue) {
    Node* currentNode = queue->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(queue);
    printf("La cola ha sido destruida correctamente.\n");
}
