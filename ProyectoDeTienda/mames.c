#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 10

// Estructura para representar un producto
typedef struct {
    int id;
    char nombre[50];
    char descripcion[100];
    int cantidad;
    float precio;
} Producto;

// Estructura para representar un nodo de la pila o cola
typedef struct Nodo {
    Producto producto;
    struct Nodo* siguiente;
} Nodo;

// Prototipos de funciones
void leerProductos(Nodo** pila);
void guardarProductos(Nodo* pila);
void agregarProducto(Nodo** pila);
void modificarProducto(Nodo** pila);
void eliminarProducto(Nodo** pila);
void consultarProductos(Nodo* pila);
void realizarCompra(Nodo** pila, Nodo** cola);
void mostrarCarrito(Nodo* cola);

// Funci�n principal
int main() {
    Nodo* pila = NULL; // Pila de productos
    Nodo* cola = NULL; // Cola de productos en el carrito
    int opcion;
    char usuario[20];
    char contrasena[20];

    leerProductos(&pila);

    while (1) {
        printf("==== Login ====\n");
        printf("Usuario: ");
        scanf("%s", usuario);
        printf("Contrasena: ");
        scanf("%s", contrasena);

        if (strcmp(usuario, "admin") == 0 && strcmp(contrasena, "adminpass") == 0) {
            // Usuario Administrador
            while (1) {
                printf("\n==== Menu Administrador ====\n");
                printf("1. Agregar producto\n");
                printf("2. Modificar producto\n");
                printf("3. Eliminar producto\n");
                printf("4. Consultar productos\n");
                printf("5. Salir\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        agregarProducto(&pila);
                        break;
                    case 2:
                        modificarProducto(&pila);
                        break;
                    case 3:
                        eliminarProducto(&pila);
                        break;
                    case 4:
                        consultarProductos(pila);
                        break;
                    case 5:
                        printf("Guardando cambios y cerrando sesion de administrador...\n");
                        guardarProductos(pila);
                        break;
                    default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                }

                if (opcion == 5) {
                    break;
                }
            }
        } else if (strcmp(usuario, "cliente") == 0 && strcmp(contrasena, "clientepass") == 0) {
            // Usuario Cliente
            while (1) {
                printf("\n==== Menu Cliente ====\n");
                printf("1. Realizar compra\n");
                printf("2. Salir\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                            realizarCompra(&pila, &cola);
                        break;
                    case 2:
                        printf("Cerrando sesion de cliente...\n");
                        break;
                    default:
                        printf("Opcion invalida. Intente nuevamente.\n");
                }

                if (opcion == 2) {
                    break;
                }
            }
            mostrarCarrito(cola);
        } else {
            printf("Credenciales invalidas. Intente nuevamente.\n");
        }
    }

    return 0;
}

// Funci�n para leer los productos desde un archivo
void leerProductos(Nodo** pila) {
    FILE* archivo = fopen("Productos.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de productos.\n");
        return;
    }

    while (!feof(archivo)) {
        Producto producto;
        fscanf(archivo, "%d\n", &producto.id);
        fgets(producto.nombre, sizeof(producto.nombre), archivo);
        producto.nombre[strcspn(producto.nombre, "\n")] = '\0'; // Eliminar el salto de l�nea
        fgets(producto.descripcion, sizeof(producto.descripcion), archivo);
        producto.descripcion[strcspn(producto.descripcion, "\n")] = '\0'; // Eliminar el salto de l�nea
        fscanf(archivo, "%d\n", &producto.cantidad);
        fscanf(archivo, "%f\n", &producto.precio);

        Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
        nuevoNodo->producto = producto;
        nuevoNodo->siguiente = *pila;
        *pila = nuevoNodo;
    }

    fclose(archivo);
}

// Funci�n para guardar los productos en el archivo
void guardarProductos(Nodo* pila) {
    FILE* archivo = fopen("Productos.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de productos para guardar los cambios.\n");
        return;
    }

    Nodo* actual = pila;
    while (actual != NULL) {
        fprintf(archivo, "%d\n", actual->producto.id);
        fprintf(archivo, "%s\n", actual->producto.nombre);
        fprintf(archivo, "%s\n", actual->producto.descripcion);
        fprintf(archivo, "%d\n", actual->producto.cantidad);
        fprintf(archivo, "%.2f\n", actual->producto.precio);
        actual = actual->siguiente;
    }

    fclose(archivo);
}

// Funci�n para agregar un producto
void agregarProducto(Nodo** pila) {
    Producto producto;
    printf("Ingrese el ID del producto: ");
    scanf("%d", &producto.id);
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]s", producto.nombre);
    printf("Ingrese la descripcion del producto: ");
    scanf(" %[^\n]s", producto.descripcion);
    printf("Ingrese la cantidad disponible del producto: ");
    scanf("%d", &producto.cantidad);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &producto.precio);

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->producto = producto;
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;

    printf("El producto se ha agregado correctamente.\n");
}

// Funci�n para buscar un producto por ID
Nodo* buscarProducto(Nodo* pila, int id) {
    Nodo* actual = pila;
    while (actual != NULL) {
        if (actual->producto.id == id) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

// Funci�n para modificar un producto
void modificarProducto(Nodo** pila) {
    int id;
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &id);

    Nodo* producto = buscarProducto(*pila, id);
    if (producto == NULL) {
        printf("No se encontro un producto con el ID especificado.\n");
        return;
    }

    printf("Ingrese el nuevo nombre del producto: ");
    scanf(" %[^\n]s", producto->producto.nombre);
    printf("Ingrese la nueva descripcion del producto: ");
    scanf(" %[^\n]s", producto->producto.descripcion);
    printf("Ingrese la nueva cantidad disponible del producto: ");
    scanf("%d", &producto->producto.cantidad);
    printf("Ingrese el nuevo precio del producto: ");
    scanf("%f", &producto->producto.precio);

    printf("El producto se ha modificado correctamente.\n");
}

// Funci�n para eliminar un producto
void eliminarProducto(Nodo** pila) {
    int id;
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);

    Nodo* actual = *pila;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->producto.id == id) {
            if (anterior == NULL) {
                // El producto a eliminar es el primer elemento de la pila
                *pila = actual->siguiente;
            } else {
                // El producto a eliminar est� en medio o al final de la pila
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("El producto se ha eliminado correctamente.\n");
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    printf("No se encontro un producto con el ID especificado.\n");
}

// Funci�n para consultar los productos
void consultarProductos(Nodo* pila) {
    if (pila == NULL) {
        printf("No hay productos disponibles.\n");
        return;
    }

    printf("==== Productos Disponibles ====\n");
    Nodo* actual = pila;
    while (actual != NULL) {
        printf("ID: %d\n", actual->producto.id);
        printf("Nombre: %s\n", actual->producto.nombre);
        printf("Descripcion: %s\n", actual->producto.descripcion);
        printf("Cantidad Disponible: %d\n", actual->producto.cantidad);
        printf("Precio: %.2f\n", actual->producto.precio);
        printf("----------------------\n");
        actual = actual->siguiente;
    }
}

// Funci�n para realizar una compra
// Funci�n para realizar una compra
void realizarCompra(Nodo** pila, Nodo** cola) {
    int id, cantidad;
    printf("Ingrese el ID del producto que desea comprar: ");
    scanf("%d", &id);

    Nodo* producto = buscarProducto(*cola, id);
    if (producto != NULL) {
        printf("El producto ya se encuentra en el carrito de compras.\n");
        return;
    }

    producto = buscarProducto(*pila, id);
    if (producto == NULL) {
        printf("No se encontro un producto con el ID especificado.\n");
        return;
    }

    printf("Ingrese la cantidad que desea comprar: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("La cantidad ingresada es invalida.\n");
        return;
    }

    if (cantidad > producto->producto.cantidad) {
        cantidad = producto->producto.cantidad;
        printf("La cantidad solicitada excede la cantidad disponible. Se agregara la maxima cantidad posible (%d).\n", cantidad);
    }

    Producto productoCompra = producto->producto;
    productoCompra.cantidad = cantidad;

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->producto = productoCompra;
    nuevoNodo->siguiente = NULL;

    if (*cola == NULL) {
        *cola = nuevoNodo;
    } else {
        Nodo* actual = *cola;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }

    printf("El producto se ha agregado al carrito de compras.\n");
}

// Funci�n para mostrar el carrito de compras
void mostrarCarrito(Nodo* cola) {
    if (cola == NULL) {
        printf("El carrito de compras esta vacio.\n");
        return;
    }

    printf("==== Carrito de Compras ====\n");
    float total = 0.0;
    Nodo* actual = cola;
    while (actual != NULL) {
        printf("ID: %d\n", actual->producto.id);
        printf("Nombre: %s\n", actual->producto.nombre);
        printf("Descripcion: %s\n", actual->producto.descripcion);
        printf("Cantidad: %d\n", actual->producto.cantidad);
        printf("Precio unitario: %.2f\n", actual->producto.precio);
        printf("Total: %.2f\n", actual->producto.precio * actual->producto.cantidad);
        printf("----------------------\n");
        total += actual->producto.precio * actual->producto.cantidad;
        actual = actual->siguiente;
    }
    printf("Total a pagar: %.2f\n", total);
}


