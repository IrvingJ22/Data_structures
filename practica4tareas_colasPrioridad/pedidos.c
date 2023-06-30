#include <stdio.h>
#include <stdlib.h>

// Estructura que representa un pedido
typedef struct {
    char cliente[50];
    int cantidad;
    int prioridad;
} Pedido;

// Nodo de la cola
typedef struct nodo {
    Pedido pedido;
    struct nodo* siguiente;
} Nodo;

// Cola de prioridad
typedef struct {
    Nodo* frente;
    Nodo* final;
} ColaPrioridad;

// Inicializar la cola
void inicializarCola(ColaPrioridad* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

// Comprobar si la cola está vacía
int estaVacia(ColaPrioridad* cola) {
    return (cola->frente == NULL);
}

// Insertar un pedido en la cola de acuerdo a su prioridad
void encolar(ColaPrioridad* cola, Pedido pedido) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->pedido = pedido;
    nuevoNodo->siguiente = NULL;

    if (estaVacia(cola)) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        Nodo* actual = cola->frente;
        Nodo* anterior = NULL;

        while (actual != NULL && actual->pedido.prioridad >= pedido.prioridad) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (anterior == NULL) {
            nuevoNodo->siguiente = cola->frente;
            cola->frente = nuevoNodo;
        } else {
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = actual;
        }

        if (actual == NULL) {
            cola->final = nuevoNodo;
        }
    }
}

// Atender un pedido de mayor prioridad
// La mayot prioridad es 3, la prioridad 1 es la ultima en atenderse
void atenderPedido(ColaPrioridad* cola, int* cantidadProducto) {
    if (estaVacia(cola)) {
        printf("No hay pedidos en la cola de prioridad.\n");
        return;
    }

    Nodo* nodoAtendido = cola->frente;
    Pedido pedidoAtendido = nodoAtendido->pedido;

    if (pedidoAtendido.cantidad <= *cantidadProducto) {
        *cantidadProducto -= pedidoAtendido.cantidad;
        cola->frente = nodoAtendido->siguiente;
        free(nodoAtendido);
        printf("Pedido atendido: Cliente: %s, Cantidad: %d, Prioridad: %d\n", pedidoAtendido.cliente, pedidoAtendido.cantidad, pedidoAtendido.prioridad);
        printf("Cantidad de producto restante: %d\n", *cantidadProducto);
        printf("--------------------------------\n");
    } else {
        printf("No hay suficiente cantidad de producto para atender el pedido de %s.\n", pedidoAtendido.cliente);
        cola->frente = nodoAtendido->siguiente; // Avanzar al siguiente pedido sin atenderlo
        free(nodoAtendido);
    }
}

// Vaciar la cola de prioridad
void vaciarCola(ColaPrioridad* cola) {
    while (!estaVacia(cola)) {
        Nodo* nodoActual = cola->frente;
        cola->frente = nodoActual->siguiente;
        free(nodoActual);
    }

    cola->final = NULL;
}

int main() {
    ColaPrioridad colaPedidos;
    Pedido pedido;
    int cantidadProducto = 100; // Cantidad inicial de producto
    int opcion=0; 

    inicializarCola(&colaPedidos);

    do {
        printf("\tMENU\n");
        printf("1. Ingresar un nuevo pedido\n");
        printf("2. Atender pedidos\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del cliente: ");
                scanf("%s", pedido.cliente);
                printf("Ingrese la cantidad de producto: ");
                scanf("%d", &pedido.cantidad);
                printf("Ingrese la prioridad del pedido: ");
                scanf("%d", &pedido.prioridad);
                encolar(&colaPedidos, pedido);
                break;
            case 2:
                if (estaVacia(&colaPedidos)) {
                    printf("No hay pedidos en la cola de prioridad.\n");
                } else {
                    while (!estaVacia(&colaPedidos) && cantidadProducto > 0) {
                        atenderPedido(&colaPedidos, &cantidadProducto);
                    }
                }
                break;
            case 3:
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }

        printf("\n");
    } while (opcion != 3);

    vaciarCola(&colaPedidos);

    return 0;
}
