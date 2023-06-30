#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura del producto
typedef struct {
    int id;
    char nombre[50];
    char descripcion[100];
    int cantidad;
    float precio;
} Producto;

// Definición de la estructura de la pila
typedef struct nodo {
    Producto producto;
    struct nodo* siguiente;
} Nodo;

// Estructura de datos para almacenar información del usuario
typedef struct {
    char username[50];
    char password[50];
    int tipoUsuario; // 0: Administrador, 1: Cliente
} Usuario;

int verificarCredenciales(Usuario* usuarios, int numUsuarios, char* username, char* password);
Nodo* crearPila();
void cargarProductosDesdeArchivo(Nodo** pila);
void imprimirProductos(Nodo* pila);
void agregarProducto(Nodo** pila, Producto producto);


int main() {
    Nodo* productosExistentes = crearPila();
    cargarProductosDesdeArchivo(&productosExistentes);
    printf("==== Productos Registrados ====\n");
    imprimirProductos(productosExistentes);

    int opcion;

    // Arreglo de usuarios para verificar las credenciales
    Usuario usuarios[] = {
        {"admin", "adminpass", 0}, // Administrador
        {"cliente", "clientepass", 1} // Cliente
    };

    int numUsuarios = sizeof(usuarios) / sizeof(usuarios[0]);

    char username[50];
    char password[50];

    // Tu código de inicio de sesión aquí
    // Inicio de sesión
    printf("===== Inicio de Sesión =====\n");
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", username);
    printf("Ingrese su contraseña: ");
    scanf("%s", password);

    int tipoUsuario = verificarCredenciales(usuarios, numUsuarios, username, password);

    // Ciclo principal del programa
    while (1) {
        // Mostrar menú según el tipo de usuario logueado

        if (tipoUsuario == 0) {
            printf("===== Menú Administrador =====\n");
            printf("1. Agregar un producto\n");
            printf("2. Modificar un producto\n");
            printf("3. Eliminar un producto\n");
            printf("4. Consultar productos\n");
            printf("5. Salir\n");
            printf("Seleccione una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    {
                        Producto nuevoProducto;
                        // Aquí puedes asignar valores a las propiedades del nuevo producto
                        agregarProducto(&productosExistentes, nuevoProducto); // Pasando la dirección de la pila
                        printf("Producto agregado correctamente.\n");
                    }
                    break;
                case 2:
                    // Lógica para modificar un producto
                    break;
                case 3:
                    // Lógica para eliminar un producto
                    break;
                case 4:
                    // Lógica para consultar productos
                    imprimirProductos(productosExistentes);
                    break;
                case 5:
                    // Lógica para salir
                    return 0;
                default:
                    printf("Opción inválida. Por favor, seleccione una opción válida.\n");
            }
        } else if (tipoUsuario == 1) {
            printf("===== Menú Cliente =====\n");
            printf("1. Realizar una compra\n");
            printf("2. Salir\n");
            printf("Seleccione una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    // Lógica para realizar una compra
                    break;
                case 2:
                    // Lógica para salir
                    return 0;
                default:
                    printf("Opción inválida. Por favor, seleccione una opción válida.\n");
            }
        }
    }

    return 0;
}


// Función para verificar las credenciales del usuario
int verificarCredenciales(Usuario* usuarios, int numUsuarios, char* username, char* password) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].username, username) == 0 && strcmp(usuarios[i].password, password) == 0) {
            return usuarios[i].tipoUsuario; // Devuelve el tipo de usuario (0 o 1)
        }
    }
    return -1; // Credenciales inválidas
}

// Funcion para crear una pila
Nodo* crearPila() {
    return NULL; // La pila está vacía al inicio
}


//Funcion para leer los 
void cargarProductosDesdeArchivo(Nodo** pila) {
    FILE* archivo = fopen("Productos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    char linea[256];
    while (fgets(linea, sizeof(linea), archivo)) {
        Producto producto;
        producto.id = atoi(linea);

        fgets(linea, sizeof(linea), archivo);
        linea[strcspn(linea, "\n")] = '\0';
        strcpy(producto.nombre, linea);

        fgets(linea, sizeof(linea), archivo);
        linea[strcspn(linea, "\n")] = '\0';
        strcpy(producto.descripcion, linea);

        fgets(linea, sizeof(linea), archivo);
        producto.cantidad = atoi(linea);

        fgets(linea, sizeof(linea), archivo);
        producto.precio = atof(linea);

        agregarProducto(pila, producto);
    }

    fclose(archivo);
}


void imprimirProductos(Nodo* pila) {
    /*if (pila == NULL) {
        printf("No hay productos registrados.\n");
        return;
    }*/

    imprimirProductos(pila->siguiente);

    
    printf("ID: %d\n", pila->producto.id);
    printf("Nombre: %s\n", pila->producto.nombre);
    printf("Descripción: %s\n", pila->producto.descripcion);
    printf("Cantidad: %d\n", pila->producto.cantidad);
    printf("Precio: %.2f\n", pila->producto.precio);
    printf("-----------------------------\n");
}




// Función para agregar un producto
void agregarProducto(Nodo** pila, Producto producto) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->producto = producto;

    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}
