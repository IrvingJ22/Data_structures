#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>


typedef struct Obj{
    float costo; //Precio del objeto
    float peso; //Cuanto pesa el objeto
    float indice; //Indice del objeto => valor / peso
}Objeto; //Tambien podrias entenderla como structura de mochila

int main(){
    int n_elementos, i, max;
    float w_max_mochila; // Es el peso maximo que soporta la mochila
    float valor_max=0; //Es el costo total de la mochia, ira aumentando


    printf("Ingrese el numero de elementos de la mochila: "); 
    scanf("%d",&n_elementos);

    Objeto objetos[n_elementos], aux;

    printf("Ingresar el elemento en la mochila: \n");
    for(int i = 0; i < n_elementos; i++){
        printf("Costo del elemento: ");
        scanf("%f",&objetos[i].costo);
        printf("Peso del elemento: ");
        scanf("%f",&objetos[i].peso);
        objetos[i].indice = objetos[i].costo / objetos[i].peso;
    }

    //Ordenamos de mayor a menor segun los indices
    for(int i=0; i<n_elementos; i++){
        max = i;
        for (int j=i+1; j<n_elementos; j++){
            if(objetos[j].indice > objetos[max].indice){
                max = j;
            }
        }
        aux = objetos[i];
        objetos[i] = objetos[max];
        objetos[max] = aux;
    }

    printf("\n");

    printf("Peso maximo de la mochila: \n");
    scanf("%f", &w_max_mochila);

    //Ingresamos los elementos a la mochila

    while(w_max_mochila > 0){
        if(w_max_mochila>objetos[i].peso){
            w_max_mochila -= objetos[i].peso;
            valor_max += objetos[i].costo;
        }
        else{
            valor_max += (objetos[i].costo * (w_max_mochila/objetos[i].peso));
            w_max_mochila = 0;
        }
        i++;
    }

    printf("El valor maximo de la mochila es: %f\n", valor_max);


    return 0;
}