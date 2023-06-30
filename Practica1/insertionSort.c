#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/*
int main() {
	int numero; //Variable donde se guardará nuestro numero aleatorio
	
	srand(time(NULL)); //Generamos numero aleatorio en base al tiempo
	numero=rand() % 11; //Le indicamos que el numero será entre 0-10
	
	printf("%d",numero); //Mostramos el resultado
	return 0;
} 
*/

int main(){
    int num;
    int aux;
    int rango = 0;
    

    printf("Digite el tamaño del arrego: ");
    scanf("%d", &num);
    int arregoDeNumeros[num];
    
    //fflush( stdin );
    
    if(num==10){
        rango=20;
    } 
    
    if(num == 100){
        rango=200;
    }
    if(num == 1000){
        rango=2000;
    }
    if(num == 5000){
        rango=1000;
    }
    if(num == 10000){
        rango=20000;
    }
    if(num == 100000){
        rango=200000;
    }
    if(num == 1000000){
        rango= 2000000;
    }
    printf("%d", rango);
    printf("\n-----------\n");
    // Generando el arreglo dinamico de numeros alearorios de acuerdo con el rango
    for(int i=0; i<num; i++){
        arregoDeNumeros[i]= rand() % rango + 1; //Le indicamos que el numero será entre 0-10
    }

    //Imprimiendo arreglo de numeros aleatorios
    for (int j=0; j<num; j++){
        printf("%d\n", arregoDeNumeros[j]);
    }
    
}

