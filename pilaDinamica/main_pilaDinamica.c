#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

int main() {
    nodo* pila = NULL;
    int opcion = 0;

    printf("Programa de prueba para pila dinamica\n");

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Crear pila\n");
        printf("2. Agregar elemento\n");
        printf("3. Quitar elemento\n");
        printf("4. Mostrar pila\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                if(pila == NULL) {
                    pila = crear_pila();
                    printf("Se ha creado una pila vacia.\n");
                } else {
                    printf("La pila ya ha sido creada anteriormente.\n");
                }
                break;
            case 2:
                if(pila == NULL) {
                    printf("Error: la pila no ha sido creada.\n");
                } else {
                    element valor;
                    printf("Ingrese el valor a agregar: ");
                    scanf("%d", &valor);
                    push(pila, valor);
                    printf("Se ha agregado el valor %d a la pila.\n", valor);
                }
                break;
            case 3:
                if(pila == NULL) {
                    printf("Error: la pila no ha sido creada.\n");
                } else if(esta_vacia(pila)) {
                    printf("Error: la pila esta vacia.\n");
                } else {
                    element valor = pop(pila);
                    printf("Se ha quitado el valor %d de la pila.\n", valor);
                }
                break;
            case 4:
                if(pila == NULL) {
                    printf("Error: la pila no ha sido creada.\n");
                } else if(esta_vacia(pila)) {
                    printf("La pila esta vacia.\n");
                } else {
                    printf("La pila contiene los siguientes valores:\n");
                    mostrar_pila(pila);
                }
                break;
            case 5:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }

    } while(opcion != 5);

    return 0;
}