// Ejemplo con suma de fracciones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>

typedef struct fraccion{
    int numerator, denomin;
} Fraccion;

Fraccion substraction_fraccion(Fraccion f1, Fraccion f2){
    Fraccion res;
    res.numerator = (f1.numerator * f2.denomin) - (f2.numerator * f1.denomin);
    res.denomin = f1.denomin * f2.denomin;
    return res;
}


int main(){
    Fraccion f1,f2,res;
    Fraccion fracciones[3];

    int i;
    
    f1.numerator = 3;
    f1.denomin = 8;

    f2.numerator = 1;
    f2.denomin = 2;

    srand(time(NULL));
    for(i = 0; i < 2; i++){
        fracciones[i].numerator = rand() % 11;
        fracciones[i].denomin = rand() % 11;
    }

    fracciones[2] = substraction_fraccion(fracciones[0], fracciones[1]);

    printf("\n\t\t %d / %d", fracciones[0].numerator, fracciones[0].denomin);
    printf("\n\t\t %d / %d", fracciones[1].numerator, fracciones[1].denomin);
    printf("\n\t\t %d / %d", fracciones[2].numerator, fracciones[2].denomin);


    return 0;
}