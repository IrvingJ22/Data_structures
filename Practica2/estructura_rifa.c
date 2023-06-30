#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_TICKETS 50
#define NUM_NAMES 40

typedef struct {
    int num_ticket;
    char nombre[20];
} ticket;

int main() {
    
    ticket tickets[NUM_TICKETS];
    for (int i = 0; i < NUM_TICKETS; i++) {
        tickets[i].num_ticket = i + 1;
        strcpy(tickets[i].nombre, "Sin asignar");
    }

    // Llenar arreglo con nombres aleatorios
    char nombres[NUM_NAMES][20] = {"Juan", "Pedro", "Maria", "Ana", "Luis", "Carlos", "Rosa", "Miguel", "Sofia", "Julio",
                                   "Fernando", "Lucia", "Adrian", "Andrea", "David", "Isabel", "Karen", "Ruben", "Carmen", "Hector",
                                   "Gerardo", "Miriam", "Diego", "Estela", "Oscar", "Cristina", "Jose", "Fabiola", "Lorenzo", "Alicia",
                                   "Santiago", "Elena", "Gabriel","Irving", "Gloria", "Martha", "Mauricio", "Nancy", "Arturo", "Veronica"};

    srand(time(NULL)); 

    for (int i = 0; i < NUM_NAMES; i++) {
        int index = rand() % NUM_TICKETS;
        while (strcmp(tickets[index].nombre, "Sin asignar") != 0) {
            index = rand() % NUM_TICKETS;
        }
        strcpy(tickets[index].nombre, nombres[i]);
    }

    // Imprimir lista de tickets
    printf("Lista de tickets:\n");
    for (int i = 0; i < NUM_TICKETS; i++) {
        printf("Ticket %d: %s\n", tickets[i].num_ticket, tickets[i].nombre);
    }

    // Generar número aleatorio para el boleto ganador
    int boleto_ganador = rand() % NUM_TICKETS + 1;

    // Busqueda indexada para encontrar el boleto ganador y su participante
    int index[5] = {0, 10, 20, 30, 40}; // Arreglo de índices
    int j = 0;
    while (j < 4 && tickets[index[j+1]].num_ticket <= boleto_ganador) {
        j++;
    }
    for (int i = index[j]; i < index[j+1]; i++) {
        if (tickets[i].num_ticket == boleto_ganador) {
            printf("¡El boleto ganador es el número %d! \nEl nombre del participante ganador es: %s\n", tickets[i].num_ticket, tickets[i].nombre);
            break;
        }
    }

    // Busqueda secuencial para encontrar el boleto ganador y su nombre
    for (int i = 0; i < NUM_TICKETS; i++) {
        if (tickets[i].num_ticket == boleto_ganador) {
            printf("¡El boleto ganador es el número %d! \nEl nombre del participante ganador es: %s\n", tickets[i].num_ticket, tickets[i].nombre);
        }
    }

    return 0;
}