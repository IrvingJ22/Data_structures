#ifndef COLADINAMICA_H
#define COLADINAMICA_H

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct MyQueue {
    Node* head;
    Node* tail;
} MyQueue;

MyQueue* createQueue();
int isEmpty(MyQueue* queue);
void enqueue(MyQueue* queue, char item);
char dequeue(MyQueue* queue);
void display(MyQueue* queue);
void destroyQueue(MyQueue* queue);

#endif  // COLADINAMICA_H
