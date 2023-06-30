#ifndef MYQUEUE_H
#define MYQUEUE_H

#define MAX 10

typedef struct MyQueue {
    int head, tail;
    char items[MAX];
} MyQueue;

MyQueue* createQueue();

int isEmpty(MyQueue* queue);
int isFull(MyQueue* queue);
void enqueue(MyQueue* queue, char item);
char dequeue(MyQueue* queue);
void display(MyQueue* queue);
void destroyQueue(MyQueue* queue);

#endif /* MYQUEUE_H */
