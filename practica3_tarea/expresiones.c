#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Definimos la estructura de la pila
typedef struct stack {
    char data[MAX_LENGTH];
    int top;
} Stack;

// Función para inicializar una pila vacía
void initialize(Stack *s) {
    s->top = -1;
}

// Función para agregar un elemento a la pila
void push(Stack *s, char c) {
    if (s->top == MAX_LENGTH - 1) {
        printf("Error: La pila esta llena\n");
        exit(1);
    }
    s->top++;
    s->data[s->top] = c;
}

// Función para remover el elemento en la cima de la pila
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Error: La pila esta vacia\n");
        exit(1);
    }
    char c = s->data[s->top];
    s->top--;
    return c;
}

// Función para verificar si una expresión está balanceada
int is_balanced(char exp[]) {
    Stack s;
    initialize(&s);
    int len = strlen(exp);

    for (int i = 0; i < len; i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.top == -1) {
                printf("La expresion no esta balanceada. Faltan llaves de apertura\n");
                return 0;
            }
            char top = pop(&s);
            if (c == ')' && top != '(') {
                printf("La expresion no esta balanceada. Falta '(' \n");
                return 0;
            } else if (c == ']' && top != '[') {
                printf("La expresion no esta balanceada. Falta '[' \n");
                return 0;
            } else if (c == '}' && top != '{') {
                printf("La expresion no esta balanceada. Falta '{' \n");
                return 0;
            }
        }
    }
    if (s.top != -1) {
        printf("La expresion no esta balanceada. Faltan llaves de cierre\n");
        return 0;
    }
    printf("La expresion esta balanceada\n");
    return 1;
}

// Función principal
int main() {
    char exp[MAX_LENGTH];
    printf("Ingresa una expresion matematica: ");
    fgets(exp, MAX_LENGTH, stdin);

    // Eliminamos el salto de línea al final de la expresión ingresada
    exp[strcspn(exp, "\n")] = '\0';

    is_balanced(exp);
    return 0;
}
