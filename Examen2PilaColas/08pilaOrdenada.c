#include <stdio.h>
#include <stdlib.h>
#include "mypila.h"

int estaOrdenadaAscendente(Pila* pila) {
    Pila* pilaAux = crearPila();
    int ordenada = 1;

    while (!pilaVacia(pila) && ordenada) {
        int elementoActual = cima(pila);
        apilar(pilaAux, desapilar(pila));

        if (!pilaVacia(pila) && elementoActual > cima(pila)) {
            ordenada = 0;
        }
    }

    while (!pilaVacia(pilaAux)) {
        apilar(pila, desapilar(pilaAux));
    }

    destruirPila(pilaAux);
    return ordenada;
}
