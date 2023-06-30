#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un nodo de la pila
struct Node {
    int data;
    struct Node* next;
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Función para insertar un elemento en la pila
void push(struct Node** top, int data) {
    struct Node* node = createNode(data);
    node->next = *top;
    *top = node;
}

// Función para sacar un elemento de la pila
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Error: la pila está vacía.\n");
        exit(1);
    }
    int data = (*top)->data;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Función para sumar dos números grandes utilizando pilas
void sumar_enteros_grandes(char* num1, char* num2) {
    // Crear pilas vacías para los dígitos de los números y para el resultado
    struct Node* pila1 = NULL;
    struct Node* pila2 = NULL;
    struct Node* resultado = NULL;

    // Agregar los dígitos de los números a las pilas correspondientes
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    for (int i = 0; i < len1; i++) {
        push(&pila1, num1[i] - '0');
    }
    for (int i = 0; i < len2; i++) {
        push(&pila2, num2[i] - '0');
    }

    // Sumar los dígitos y llevar acarreo mientras ambas pilas no estén vacías
    int acarreo = 0;
    while (pila1 != NULL || pila2 != NULL) {
        int suma = acarreo;
        if (pila1 != NULL) {
            suma += pop(&pila1);
        }
        if (pila2 != NULL) {
            suma += pop(&pila2);
        }
        push(&resultado, suma % 10);
        acarreo = suma / 10;
    }

    // Agregar el acarreo final, si lo hay, al resultado
    if (acarreo > 0) {
        push(&resultado, acarreo);
    }

    // Imprimir el resultado en orden inverso
    printf("El resultado de la suma es:\n");
    while (resultado != NULL) {
        printf("%d", pop(&resultado));
    }
    printf("\n");
}

// Función principal
int main() {
    // Pedir al usuario que ingrese los dos números a sumar
    char num1[1000], num2[1000];
    printf("Ingrese el primer número: ");
    scanf("%s", num1);
    printf("Ingrese el segundo número: ");
    scanf("%s", num2);

    // Sumar los dos números y mostrar el resultado
    sumar_enteros_grandes(num1, num2);
    printf("\n");

    return 0;
}
