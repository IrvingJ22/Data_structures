/*  Realiza una función copyStack(), que copie el contenido de una pila en otra. La función tendrá dos
argumentos de tipo pila, una será la pila a copiar y la otra la pila donde se realizará la copia. Utiliza las
operaciones definidas sobre el tipo de datos Pila.  */

#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

void copyStack(nodo** source_pila, nodo** dest_pila) {
    nodo* aux_pila = NULL; // Pila auxiliar para invertir el orden de los elementos

    // Vaciamos la pila destino en caso de contener elementos previos
    while (!esta_vacia(*dest_pila)) {
        pop(dest_pila);
    }

    // Copiamos los elementos de la pila fuente a la pila auxiliar
    while (!esta_vacia(*source_pila)) {
        element dato = pop(source_pila);
        push(&aux_pila, dato);
    }

    // Copiamos los elementos de la pila auxiliar a la pila destino
    while (!esta_vacia(aux_pila)) {
        element dato = pop(&aux_pila);
        push(dest_pila, dato);
        push(source_pila, dato); // Restauramos la pila fuente al estado original
    }
}
