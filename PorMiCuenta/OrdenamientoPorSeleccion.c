#include<stdio.h>

int main(){
    int numeros[] = {2,4,1,3,5};
    int i,j,aux,min;
    int longitudArray;
    longitudArray=sizeof(numeros)/sizeof(numeros[0]);
    
    // aux para hacer el intercambio de valores
    // min para guardar el numero manor en cada iteración
    //printf("%i",longitudArray);

    for(i=0;i<longitudArray;i++){
        min=i;
        for(j=i+1;j<longitudArray;j++){
            if(numeros[j]<numeros[min]){
                min=j;
            }
        }
        aux = numeros[i];
        numeros[i]=numeros[min];
        numeros[min]=aux;
    }

    printf("Imprimiendo de menor a mayor\n");
    for(int i=0;i<longitudArray;i++){
        printf("%i", numeros[i]);
        printf(" ");
    }

    return 0;
}

/*for(i=0;i<longitudArray;i++){
        min=i;
        for(j=i+1;j<longitudArray;j++){
            if(numeros[j]<numeros[min]){
                min=j;
            }
        }
        aux = numeros[i];
        numeros[i]=numeros[min];
        numeros[min]=aux;
    }
    */

