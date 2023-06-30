#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Estructura de datos para almacenar información del usuario
typedef struct {
    char username[50];
    char password[50];
    int tipoUsuario; // 0: Administrador, 1: Cliente
} Usuario;


int verificarCredenciales(Usuario* usuarios, int numUsuarios, char* username, char* password);



int main() {
    //Nodo* productosExistentes = crearPila();
    //cargarProductosDesdeArchivo(&productosExistentes);
   
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

    // Inicio de sesión
    int tipoUsuario = -1;

    if(tipoUsuario == -1) {
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
    while (regresarInicio == 0) {
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
                    //Producto nuevoProducto;
                    // Aquí puedes asignar valores a las propiedades del nuevo producto
                    //agregarProducto(&productosExistentes, nuevoProducto); // Pasando la dirección de la pila
                    printf("Producto agregado correctamente.\n");
                    break;
                case 2:
                    // Lógica para modificar un producto
                    break;
                case 3:
                    // Lógica para eliminar un producto
                    break;
                case 4:
                    // Lógica para consultar productos
                    printf("==== Productos Registrados ====\n");
                    break;
                case 5:
                    // Lógica para salir
                    regresarInicio = -1;
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
    

    return 0;
}


int verificarCredenciales(Usuario* usuarios, int numUsuarios, char* username, char* password) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].username, username) == 0 && strcmp(usuarios[i].password, password) == 0) {
            return usuarios[i].tipoUsuario; // Devuelve el tipo de usuario (0 o 1)
        }
    }
    return -1; // Credenciales inválidas
}