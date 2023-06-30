#ifndef PILA_H
#define PILA_H

#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} My_stack;

void inicializar(My_stack *pila);
void push(My_stack *pila, int value);
int pop(My_stack *pila);
void show(My_stack *pila);

#endif /* PILA_H */