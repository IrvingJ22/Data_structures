#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

typedef char element;

typedef struct Nodo {
    element dato;
    struct Nodo* siguiente;
} nodo;

void inicializar(nodo** cima_pila);
int esta_vacia(nodo* cima_pila);
void push(nodo** cima_pila, element x);
element pop(nodo** cima_pila);
void mostrar_pila(nodo* cima_pila);

#endif /* PILA_DINAMICA_H */