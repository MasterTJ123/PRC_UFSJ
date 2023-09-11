#include <stdio.h>
#include <stdlib.h>

int Funcao_Quantidade_Numero_Primo(int N){

    int Contador_Numero_Primo = 0;
    int Contador_Numeros_Divisiveis = 0;

    // Como e abaixo de N, entao comecamos o contador em N - 1

    for(int i = N - 1; i > 0; i--){
        Contador_Numeros_Divisiveis = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                Contador_Numeros_Divisiveis++;
            }
        }
        if(Contador_Numeros_Divisiveis == 2){
            Contador_Numero_Primo++;
        }
    }

    return Contador_Numero_Primo;

}

int main(){

    int N = 0;
    int Quantidade_Numero_Primo = 0;

    printf("Informe um numero inteiro N: ");
    scanf("%d", &N);

    Quantidade_Numero_Primo = Funcao_Quantidade_Numero_Primo(N);

    printf("\nA quantidade de numeros primos abaixo de N e %d\n\n", Quantidade_Numero_Primo);

    system("pause");

    return 0;

}
