#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE* arquivo_clientes = fopen("clientes.txt", "r");

    if(arquivo_clientes == NULL){
        printf("Erro, nao foi possivel abrir o arquivo clientes.txt!\n\n");
        system("pause");
        return 1;
    } else {
        FILE* arquivo_lancamentos = fopen("lancamentos.txt", "r");
        if(arquivo_lancamentos == NULL){
            printf("Erro, nao foi possivel abrir o arquivo lancamentos.txt");
            system("pause");
            return 1;
        } else {
            for(int i = 0; feof(arquivo_clientes) == 0; i++){
                int codigo_cliente = 0;
                float saldo_inicio_mes = 0.0;
                int codigo_cliente_auxiliar = 0;
                int codigo_lancamento = 0;
                float valor_lancamento = 0.0;
                float saldo_atual = 0.0;
                fscanf(arquivo_clientes, "%d %f", &codigo_cliente, &saldo_inicio_mes);
                saldo_atual = saldo_inicio_mes;
                printf("Qual e o saldo do cliente %d?\n\n", codigo_cliente);
                printf("%.2f", saldo_atual);
                for(int j = 0; feof(arquivo_lancamentos) == 0; j++){
                    fscanf(arquivo_lancamentos, "%d %d %f", &codigo_cliente_auxiliar, &codigo_lancamento, &valor_lancamento);
                    if(codigo_cliente_auxiliar == codigo_cliente){
                        if(codigo_lancamento == 1){
                            printf(" + %.2f", valor_lancamento);
                            saldo_atual += valor_lancamento;
                        } else if(codigo_lancamento == -1) {
                            printf(" - %.2f", valor_lancamento);
                            saldo_atual -= valor_lancamento;
                        }
                    }
                }
                printf(" = %.2f\n\n", saldo_atual);
                rewind(arquivo_lancamentos);
            }
        }
        fclose(arquivo_lancamentos);
    }

    system("pause");

    fclose(arquivo_clientes);

    return 0;

}
