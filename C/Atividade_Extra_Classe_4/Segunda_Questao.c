#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_hexa(float l, float *area, float *perimetro){

    *area = ( (3.0) * (l * l) * ( sqrtf(3.0) ) ) / (2.0);

    *perimetro = (6.0) * (l);

}

int main(){

    float l = 0.0, area = 0.0, perimetro = 0.0;

    while(1){

        printf("Insira o lado do hexagono regular: ");
        scanf("%f", &l);

        if(l < 0.0){
            break;
        }

        calc_hexa(l, &area, &perimetro);

        printf("\nA area do poligono e %.2f e o perimetro e %.2f\n\n", area, perimetro);

    }

    printf("\n");
    system("pause");

    return 0;

}
