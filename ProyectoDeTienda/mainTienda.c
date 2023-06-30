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
void modificarProducto(Nodo** pila);


int main() {
    Nodo* productosExistentes = crearPila();
    cargarProductosDesdeArchivo(&productosExistentes);
   
    int opcion;
    int regresarInicio = 0; // Controla el regreso al inicio de sesión

    char username[50];
    char password[50];

    // Arreglo de usuarios para verificar las credenciales
    Usuario usuarios[] = {
        {"admin", "adminpass", 0}, // Administrador
        {"cliente", "clientepass", 1} // Cliente
    };

    int numUsuarios = sizeof(usuarios) / sizeof(usuarios[0]);

    while (!regresarInicio) {
        // Inicio de sesión
        int tipoUsuario = -1;

        while (tipoUsuario == -1) {
            printf("===== Inicio de Sesión =====\n");
            printf("Ingrese su nombre de usuario: ");
            scanf("%s", username);
            printf("Ingrese su contraseña: ");
            scanf("%s", password);

            tipoUsuario = verificarCredenciales(usuarios, numUsuarios, username, password);

            if (tipoUsuario == -1) {
                printf("Credenciales inválidas. Por favor, intente de nuevo.\n");
            }
        }

        // Ciclo principal del programa
        while (!regresarInicio) {
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
                    case 1: {
                        Producto nuevoProducto;
                        // Aquí puedes asignar valores a las propiedades del nuevo producto
                        agregarProducto(&productosExistentes, nuevoProducto); // Pasando la dirección de la pila
                        printf("Producto agregado correctamente.\n");
                        break;
                    }
                    case 2:
                        // Lógica para modificar un producto
                        modificarProducto(&productosExistentes);
                        break;
                    case 3:
                        // Lógica para eliminar un producto
                        break;
                    case 4:
                        // Lógica para consultar productos
                        printf("==== Productos Registrados ====\n");
                        if (productosExistentes == NULL) {
                            printf("No hay productos registrados.\n");
                        } else {
                            imprimirProductos(productosExistentes);
                        }
                        break;
                    case 5:
                        // Lógica para salir
                        regresarInicio = 1;
                        break;
                    default:
                        printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                }

                if (regresarInicio) {
                    tipoUsuario = -1;
                    break; // Salir del ciclo del menú del administrador
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
                        regresarInicio = 1;
                        break;
                    default:
                        printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                }

                if (regresarInicio) {
                    tipoUsuario = -1;
                    break; // Salir del ciclo del menú cliente
                }
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

Nodo* crearPila() {
    return NULL; // La pila está vacía al inicio
}

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
    if (pila == NULL) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("=====================================================================================================\n");
    printf("| %-4s | %-20s | %-40s | %-9s | %-10s |\n", "ID", "Nombre", "Descripción", "Cantidad", "Precio");
    printf("=====================================================================================================\n");

    Nodo* actual = pila;
    while (actual != NULL) {
        printf("| %-4d | %-20s | %-40s | %-9d | $%-9.2f |\n",
               actual->producto.id,
               actual->producto.nombre,
               actual->producto.descripcion,
               actual->producto.cantidad,
               actual->producto.precio);

        actual = actual->siguiente;
    }

    printf("=====================================================================================================\n");
}

void agregarProducto(Nodo** pila, Producto producto) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->producto = producto;

    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
}


void modificarProducto(Nodo** pila) {
    int id;
    printf("Ingrese el ID del producto que desea modificar: ");
    scanf("%d", &id);

    Nodo* actual = *pila;
    while (actual != NULL) {
        if (actual->producto.id == id) {
            printf("Registro del producto:\n");
            printf("ID: %d\n", actual->producto.id);
            printf("Nombre: %s\n", actual->producto.nombre);
            printf("Descripción: %s\n", actual->producto.descripcion);
            printf("Cantidad: %d\n", actual->producto.cantidad);
            printf("Precio: %.2f\n", actual->producto.precio);

            int opcion;
            printf("Seleccione la característica que desea modificar:\n");
            printf("1. Nombre\n");
            printf("2. Descripción\n");
            printf("3. Cantidad\n");
            printf("4. Precio\n");
            printf("Ingrese una opción: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1: {
                    char nuevoNombre[50];
                    printf("Ingrese el nuevo nombre: ");
                    scanf("%s", nuevoNombre);
                    strcpy(actual->producto.nombre, nuevoNombre);
                    break;
                }
                case 2: {
                    char nuevaDescripcion[100];
                    printf("Ingrese la nueva descripción: ");
                    scanf(" %[^\n]", nuevaDescripcion);
                    strcpy(actual->producto.descripcion, nuevaDescripcion);
                    break;
                }
                case 3:
                    printf("Ingrese la nueva cantidad: ");
                    scanf("%d", &(actual->producto.cantidad));
                    break;
                case 4:
                    printf("Ingrese el nuevo precio: ");
                    scanf("%f", &(actual->producto.precio));
                    break;
                default:
                    printf("Opción inválida. No se realizarán modificaciones.\n");
            }

            // Guardar las modificaciones en el archivo
            FILE* archivo = fopen("Productos.txt", "w");
            if (archivo == NULL) {
                printf("Error al abrir el archivo.\n");
                return;
            }

            actual = *pila;
            while (actual != NULL) {
                fprintf(archivo, "%d\n", actual->producto.id);
                fprintf(archivo, "%s\n", actual->producto.nombre);
                fprintf(archivo, "%s\n", actual->producto.descripcion);
                fprintf(archivo, "%d\n", actual->producto.cantidad);
                fprintf(archivo, "%.2f\n", actual->producto.precio);

                actual = actual->siguiente;
            }

            fclose(archivo);

            printf("Producto modificado correctamente.\n");
            return;
        }

        actual = actual->siguiente;
    }

    printf("No se encontró ningún producto con el ID especificado.\n");
}
