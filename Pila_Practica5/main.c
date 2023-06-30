#include "pila.h"
#include <stdio.h>

int main() {
    int opcion, elemento;
    int bandera = 0;
    My_stack pila;
    inicializar(&pila);

    do {
        printf("\n----------------\n");
        printf("MENU:\n");
        printf("1. Agregar elemento\n");
        printf("2. Quitar elemento\n");
        printf("3. Mostrar pila\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (bandera<MAX_SIZE){
                    printf("Ingresa el valor a agregar: ");
                    scanf("%d", &elemento);
                    push(&pila, elemento);
                    printf("El valor %d ha sido agregado a la pila.\n", elemento);
                    bandera++;
                } else{
                    printf("La pila esta llena, ya NO puedes agregar mas elementos.\n");
                }
                break;
            case 2:
                elemento = pop(&pila);
                if (elemento != -1) {
                    printf("El valor %d ha sido removido de la pila.\n", elemento);
                    bandera--;
                }
                break;
            case 3:
                show(&pila);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}