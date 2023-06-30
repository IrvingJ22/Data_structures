#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    char name[50];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int id, char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int id, char name[]) {
    if (root == NULL) {
        return createNode(id, name);
    }

    if (id <= root->id) {
        root->left = insertNode(root->left, id, name);
    } else {
        root->right = insertNode(root->right, id, name);
    }

    return root;
}

void printElements(Node* root) {
    if (root != NULL) {
        printElements(root->left);
        printf("ID: %d, Producto: %s\n", root->id, root->name);
        printElements(root->right);
    } else {
        printf("Arbol vacio\n");
    }
}

Node* search(Node* root, int id) {
    if (root == NULL || root->id == id) {
        return root;
    }

    if (id < root->id) {
        return search(root->left, id);
    } else {
        return search(root->right, id);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* tree = NULL;

    tree = insertNode(tree, 10, "plancha");
    tree = insertNode(tree, 51, "refrigerador");
    tree = insertNode(tree, 8, "cobija");
    tree = insertNode(tree, 90, "mesa");
    tree = insertNode(tree, 7, "silla");
    tree = insertNode(tree, 2, "espejo");
    tree = insertNode(tree, 13, "buro");

    int option = 0;
    int idSearch;  // Mover la declaración de idSearch aquí

    while (option != 3) {
        printf("\n--- Menu ---\n");
        printf("1. Ver productos\n");
        printf("2. Buscar por id\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nProductos:\n");
                printElements(tree);
                break;
            case 2:
                printf("\nIngrese el id a buscar: ");
                scanf("%d", &idSearch);

                Node* find = search(tree, idSearch);
                if (find != NULL) {
                    printf("\nElemento encontrado; ID: %d, Producto: %s\n", find->id, find->name);
                } else {
                    printf("Producto no encontrado.\n");
                }
                break;
            case 3:
                freeTree(tree);
                printf("\nÁrbol eliminado. Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    }

    return 0;
}
