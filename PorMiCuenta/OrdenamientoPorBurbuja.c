#include<stdio.h>

int main(){
    int numeros[]={2,5,3,1,4};
    int i,j,aux;

    //Algoritmo del metodo burbuja
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(numeros[j]>numeros[j+1]){
                aux=numeros[j];
                numeros[j]=numeros[j+1];
                numeros[j+1]=aux;
            }
        }
    }

    printf("Imprimiendo de menor a mayor con burbuja\n");
    for(i=0;i<5;i++){
        printf("%i", numeros[i]);
        printf(" ");
    }

    return 0;   
}