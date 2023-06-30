#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void insertionSort( int arr[], int tamano){
    double time_spent = 0.0;
    clock_t begin = clock();
    
    int i, llave, j;
    for (i = 1; i < tamano; i++){
        llave = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > llave){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = llave;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nEl tiempo transcurrido en ordenar es %f segundos", time_spent);
    printf("\nValores ya ordenados:\n");
}


void selectionSort(int arr[], int tamano){
    double time_spent = 0.0;
    clock_t begin = clock();
    
    
    int minimo;
    int aux;
    for (int i=0; i<tamano;i++){
        minimo = i;
        for (int j=i+1; j<tamano; j++){
            if(arr[j] < arr[minimo]){
                minimo=j;
            }
        }
        aux = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = aux;
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nEl tiempo transcurrido en ordenar es %f segundos", time_spent);
    printf("\nValores ya ordenados:\n");
}

void mezclar(int arr[], int izquierda[], int sizeIzq, int derecha[], int sizeDer){
    int indiceIzq = 0;
    int indiceDer = 0;
    int indiceArr = 0;


    while(indiceIzq < sizeIzq && indiceDer < sizeDer){
        if(izquierda[indiceIzq] < derecha[indiceDer]){
            arr[indiceArr] = izquierda[indiceIzq];
            indiceIzq += 1;
        }
        else{
            arr[indiceArr] = derecha[indiceDer];
            indiceDer += 1;
        }
        indiceArr += 1;
    }

    //Verifica si aun hay elementos en alguna de las mitades
    while (indiceIzq < sizeIzq){
        arr[indiceArr] = izquierda[indiceIzq];
        indiceIzq += 1;
        indiceArr += 1;
    }

    while (indiceDer < sizeDer){
        arr[indiceArr] = derecha[indiceDer];
        indiceDer += 1;
        indiceArr += 1;
    }

}


void ordenar(int arr[], int tamano){
    if(tamano>1){
        
        int mitad = tamano/2;
        int n1 = mitad;
        int n2 = tamano - mitad;

        // Crear arreglos temporales para las dos mitades
        int izquierda[n1];
        int derecha[n2];

        // Copia los elementos que corresponden en cada mitad
        for (int indiceIzq = 0; indiceIzq < n1; ++indiceIzq){
            izquierda[indiceIzq] = arr[indiceIzq];
        }
        for (int indiceDer = 0; indiceDer < n2; ++indiceDer){
            derecha[indiceDer] = arr[mitad + indiceDer];
        }

        ordenar(izquierda,n1); //Odenar la primera mitad
        ordenar(derecha, n2); //Ordenar la segunda mitad
        mezclar(arr, izquierda, n1, derecha, n2); //Mezcla las dos mitades 

    }
}


int main(){
    
    int num, opc;
    int *arreglo;
    int maximo = 0;


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
    else{
        maximo = 800;
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
    
    printf("\nMetodos para ordenar el arreglo\n");
    printf("1. Insertion Sort\n");
    printf("2. Merge Sort\n");
    printf("3. Selection Sort\n");
    
    printf("\nDigite el metodo por el que quiere ordenar: ");
    scanf("%d", &opc);
    
    if(opc == 1){
        insertionSort(arreglo, num);
        //for(int p=0;p<num;p++){
            //printf("Pos %d = valor %d\n", p, arreglo[p]);
        //}
    }
    
    if(opc == 3){
        selectionSort(arreglo, num);
        //printf("\nValores ya ordenados:\n");
        //for(int p=0;p<num;p++){
            //printf("Pos %d = valor %d\n", p, arreglo[p]);
        //}
    }
    
    if(opc == 2){
        double time_spent = 0.0;
        clock_t begin = clock();

        ordenar(arreglo, num);

        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nEl tiempo transcurrido en ordenar es %f segundos\n", time_spent);
        

        //for(int p=0;p<num;p++){
            //printf("Pos %d = valor %d\n", p, arreglo[p]);
        //}
    }
    
    free(arreglo);
    return 0;
}
