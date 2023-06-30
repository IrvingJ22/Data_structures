#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void merge(int arr[],int inicio, int mitad, int fin){
    int i,j,k;
    int tam1 = mitad - inicio + 1;
    int tam2 = fin - mitad;
    //printf("Tamaño 1: %d", tam1);
    
    int izquierda[tam1];
    int derecha[tam2];
    
    for (i=0; i<tam1; i++){
        izquierda[i]=arr[inicio + 1];
    }
    for (j=0; j<tam2; j++){
        derecha[j] = arr[mitad + j + 1];
    }
    
    i=0;
    j=0;
    k=inicio;
    
    
    while(i<tam1 && j<tam2){
        if(izquierda[i] <= derecha[j]){
            arr[k] = izquierda[i];
            i++;
        }else{
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }
    
    while(i<tam1){
        arr[k] = izquierda[i];
        i++;
        k++;
    }
    while(j<tam2){
        arr[k] = derecha[j];
        j++;
        k++;
    }
    
}

void mergeSort(int arr[], int inicio, int fin){
    
    if (inicio < fin){
        int mitad = inicio + (fin-inicio)/2;
        mergeSort(arr, inicio, mitad);
        mergeSort(arr, mitad + 1, fin);
        merge(arr,inicio, mitad, fin); 
    }
    
}

int main(){
    int *arreglo;
    int maximo = 0;
    int num;

    int A[]={1,3,5,1,3,5,67,0};


    printf("Cantidad de valores del array: ");
    scanf("%d",&num);

    if(num == 10){
        maximo = 20;
    }
    if(num == 100){
        maximo = 200;
    }
    if(num == 1000){
        maximo = 1000;
    }
    if(num == 5000){
        maximo = 2000;
    }
    if(num == 10000){
        maximo = 20000;
    }
    if(num == 100000){
        maximo = 200000;
    }
    if(num == 1000000){
        maximo = 2000000;
    }

    arreglo = (int*)malloc(num*sizeof(int));
    srand(time(NULL));

    int u=0;
    for(u=0;u<num;u++){
        arreglo[u]=rand() % maximo;
    }

    printf("\nValores sin ordenar");
    for(int p=0;p<num;p++){
        printf("\nPos %d = valor %d", p, arreglo[p]);
    }

    printf("\n----------------------\n");

    mergeSort(A, 0, num);
    for(int p=0;p<num;p++){
            printf("Pos %d = valor %d\n", p, A[p]);
    }

    return 0;

}