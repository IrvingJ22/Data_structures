#include <stdio.h>
#include <stdlib.h>
#include "colaDinamica.h"

int main() {
    MyQueue* queue = createQueue();
    int opcion = 0;

    do {
        printf("\n--- Menu de Cola ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Eliminar elemento\n");
        printf("3. Mostrar elementos\n");
        printf("4. Salir\n");
        printf("--------------------\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char item;
                printf("\nIngrese el elemento a insertar: ");
                scanf(" %c", &item);
                enqueue(queue, item);
                break;
            }
            case 2: {
                dequeue(queue);
                break;
            }
            case 3: {
                display(queue);
                break;
            }
            case 4: {
                printf("\nSaliendo...\n");
                break;
            }
            default: {
                printf("\nOpcion invalida, intente de nuevo.\n");
                break;
            }
        }
    } while (opcion != 4);

    destroyQueue(queue);
    return 0;
}
