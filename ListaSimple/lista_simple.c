#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    char dato;
    struct Nodo* next;
} Nodo;

typedef struct {
    Nodo* head;
    Nodo* tail;
} List;

void inicializarLista(List* lista) {
    lista->head = NULL;
    lista->tail = NULL;
}

List crearLista() {
    List nuevaLista;
    inicializarLista(&nuevaLista);
    return nuevaLista;
}

void insertarAlInicio(List* lista, char dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;

    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        nuevoNodo->next = lista->head;
        lista->head = nuevoNodo;
    }
}

void insertarAlFinal(List* lista, char dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;

    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        lista->tail->next = nuevoNodo;
        lista->tail = nuevoNodo;
    }
}

void insertarDespuesDe(List* lista, Nodo* nodoAnterior, char dato) {
    if (nodoAnterior == NULL) {
        printf("Error: El nodo anterior no puede ser NULL.\n");
        return;
    }

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->next = nodoAnterior->next;
    nodoAnterior->next = nuevoNodo;

    if (nodoAnterior == lista->tail) {
        lista->tail = nuevoNodo;
    }
}

void insertarAntesDe(List* lista, Nodo* nodoSiguiente, char dato) {
    if (nodoSiguiente == NULL) {
        printf("Error: El nodo siguiente no puede ser NULL.\n");
        return;
    }

    if (lista->head == nodoSiguiente) {
        insertarAlInicio(lista, dato);
        return;
    }

    Nodo* actual = lista->head;
    while (actual != NULL) {
        if (actual->next == nodoSiguiente) {
            Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
            nuevoNodo->dato = dato;
            nuevoNodo->next = nodoSiguiente;

            actual->next = nuevoNodo;
            return;
        }
        actual = actual->next;
    }

    printf("Error: El nodo siguiente no se encontró en la lista.\n");
}

void imprimir(List* lista) {
    Nodo* actual = lista->head;
    while (actual != NULL) {
        printf("%c ", actual->dato);
        actual = actual->next;
    }
    printf("\n");
}

bool estaVacia(List* lista) {
    return lista->head == NULL;
}

int main() {
    List lista = crearLista();

    insertarAlInicio(&lista, 'C');
    insertarAlInicio(&lista, 'B');
    insertarAlInicio(&lista, 'A');
    insertarAlFinal(&lista, 'E');

    imprimir(&lista);

    Nodo* nodoB = lista.head->next;
    insertarDespuesDe(&lista, nodoB, 'D');

    imprimir(&lista);

    Nodo* nodoC = lista.head->next;
    insertarAntesDe(&lista, nodoC, 'X');

    imprimir(&lista);

    if (estaVacia(&lista)) {
        printf("La lista está vacía\n");
    } else {
        printf("La lista no está vacía\n");
    }

    return 0;
}
