#include<stdio.h>
//#include<conio.h>

int main(){
    int numeros[]={2,5,1,4,3};
    int i, pos, auxValor;

    printf("Impresion de los numeros sin ordenar: \n");
    for(i=0;i<5;i++){
        printf("%i",numeros[i]);
        printf("\n");
    }

    for(i=0;i<5;i++){
        pos=i;
        auxValor=numeros[i];

        while((pos>0)&&(numeros[pos-1]>auxValor)){
            numeros[pos]=numeros[pos-1];
            pos--;
        }
        numeros[pos]=auxValor;
    }

    //Impresion de los numeros
    printf("Impresion de los numeros ascendentemente: \n");
    for(i=0;i<5;i++){
        printf("%i",numeros[i]);
        printf("\n");
    }

    return 0;
}