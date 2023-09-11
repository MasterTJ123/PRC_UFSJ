#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    int nota_primeira_prova;
    int nota_segunda_prova;
    int nota_terceira_prova;
} ALUNO;

int main(){

    ALUNO alunos[5];
    int maior_nota_primeira_prova = 0, indice_maior_nota = 0;
    float media_geral[5] = {0};
    float maior_media_geral = 0.0, menor_media_geral = 0.0;
    int indice_maior_media_geral = 0, indice_menor_media_geral = 0;

    for(int i = 0; i < 5; i++){
        printf("Entre com a matricula, Nome do aluno e Notas 1, 2 e 3, separando-as por um espaco:\n");
        scanf("%d %30s %d %d %d", &alunos[i].matricula,
                                  alunos[i].nome,
                                  &alunos[i].nota_primeira_prova,
                                  &alunos[i].nota_segunda_prova,
                                  &alunos[i].nota_terceira_prova
             );
        fflush(stdin);
        printf("\n");
    }

    maior_nota_primeira_prova = alunos[0].nota_primeira_prova;
    for(int i = 1; i < 5; i++){
        if(maior_nota_primeira_prova < alunos[i].nota_primeira_prova){
            maior_nota_primeira_prova = alunos[i].nota_primeira_prova;
            indice_maior_nota = i;
        }
    }

    for(int i = 0; i < 5; i++){
        media_geral[i] = ( (float) alunos[i].nota_primeira_prova + (float) alunos[i].nota_segunda_prova + (float) alunos[i].nota_terceira_prova) / 3.0;
    }

    maior_media_geral = media_geral[0];
    menor_media_geral = media_geral[0];
    for(int i = 1; i < 5; i++){
        if(maior_media_geral < media_geral[i]){
            maior_media_geral = media_geral[i];
            indice_maior_media_geral = i;
        }
        if(menor_media_geral > media_geral[i]){
            menor_media_geral = media_geral[i];
            indice_menor_media_geral = i;
        }
    }

    printf("\tFIM DO PROGRAMA!!!\n\n\n");

    printf("O aluno com maior nota da primeira prova: %s\n\n", alunos[indice_maior_nota].nome);
    printf("O aluno com maior media geral: %s\n\n", alunos[indice_maior_media_geral].nome);
    printf("O aluno com menor media geral: %s\n\n", alunos[indice_menor_media_geral].nome);

    printf("\t\tResultado Final:\n\n");

    printf("\tNome do Aluno\t\tMedia Final\t\t\tStatus\n");

    for(int i = 0; i < 5; i++){
        printf("\t\t%s\t\t\t%.1f\t\t\t", alunos[i].nome, media_geral[i]);
        if(media_geral[i] > 6){
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }

    printf("\n");
    system("pause");

    return 0;

}
