#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//int buscarEnArreglo(const int, int, int );
//int numeroRepetido(int *, int , int );



int main(){
    int num;
    int buscar;
    int *arreglo, aux;
    int valor;

    printf("Cantidad de valores del array: ");
    scanf("%d",&num);
    int maximo = num+5;
     
    arreglo = (int*)malloc(num*sizeof(int));
    srand(time(NULL));
    
    /*for (int i=0; i<num; i++){
        arreglo[i] = rand() % maximo;
        arreglo[i] = arreglo[i] + i;
    }*/
    
    int u=0;
    while(u<num){
        valor=rand() % maximo;
        if(numeroRepetido(arreglo,valor,num)==0){
            arreglo[u] =  valor;
            u++;
        }else{
            continue;
        }
    }
    
    
    for(int p=0;p<num;p++){
        printf("\nPos %d = valor %d", p, arreglo[p]);
    }
    
    printf("\nDigite elemento a buscar en array dentro de un rango de 0 a %d: ", maximo);
    scanf("%d",&buscar);
    
    int existe = buscarEnArreglo(arreglo, buscar, num);
    if (existe==-1){
        printf("No existe el elemento en el arreglo");
    } else{
        printf("Posicion de %d en arreglo: %d ", buscar, existe);
    }
    

    return 0;
}

int buscarEnArreglo(const int arreglo[], int busqueda, int longitud) {
    for (int x = 0; x < longitud; x++) {
        if (arreglo[x] == busqueda) return x;
    }
    return -1;
}

int numeroRepetido(int *arreglo, int valor, int num){
    for(int i=0; i < num; i++){
        if(arreglo[i] == valor){
            return 1;
        }
    }
    return 0;
}