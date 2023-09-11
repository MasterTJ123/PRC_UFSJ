#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato{
    char nome[30];
    char sobrenome[30];
    long long int telefone;
    char email[50];
} CONTATO;

void adicionarContatoTeclado(CONTATO contatos[150], int* contador_contatos){

    printf("ADICIONAR CONTATO VIA TECLADO\n");
    printf("\nInsira o nome: ");
    scanf("%30s", contatos[*contador_contatos].nome);
    fflush(stdin);
    printf("Insira o sobrenome: ");
    scanf("%30[^\n]", contatos[*contador_contatos].sobrenome);
    fflush(stdin);
    printf("Insira o telefone: ");
    scanf("%lld", &(contatos[*contador_contatos].telefone));
    fflush(stdin);
    printf("Insira o e-mail: ");
    scanf("%50s", contatos[*contador_contatos].email);
    fflush(stdin);

    (*contador_contatos)++;

    printf("\nContato adicionado com sucesso!\n\n");
    system("pause");
    system("cls");

}

void adicionarContatoArquivo(CONTATO contatos[150], int* contador_contatos, int* flag_arquivo){

    FILE* arquivo = NULL;

    if(*flag_arquivo == 1){
        printf("Erro! Voce ja leu esse arquivo uma vez durante a execucao desse programa!");
    } else {
        arquivo = fopen("agenda.txt", "r");

        if(arquivo == NULL){
            printf("Erro! Nao foi possivel ler o arquivo!");
        } else {
            *flag_arquivo = 1;

            for(int i = 0; feof(arquivo) == 0 ; i++){
                fscanf(arquivo, "%30s %30[^\n] %lld %50s", contatos[i].nome, contatos[i].sobrenome, &(contatos[i].telefone), contatos[i].email);
                (*contador_contatos)++;
            }

            printf("Arquivo lido com sucesso!");
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

    fclose(arquivo);
}

void pesquisarContato(CONTATO contatos[150], int contador_contatos){

    char nome_auxiliar[30];
    char sobrenome_auxiliar[30];

    printf("PESQUISAR CONTATO");

     if(contador_contatos == 0){
        printf("\n\nNao existem contatos na agenda!");
    } else {
        printf("\n\nInsira o nome completo do contato: ");
        scanf("%30s %30[^\n]", nome_auxiliar, sobrenome_auxiliar);
        fflush(stdin);

        int i;
        int flag_encontrou = 0;

        for(i = 0; i < contador_contatos; i++){
            if( (!(strcmp(contatos[i].nome, nome_auxiliar))) && (!(strcmp(contatos[i].sobrenome, sobrenome_auxiliar))) ){
                flag_encontrou = 1;
                break;
            }
        }

        if(flag_encontrou == 1){
            printf("\nNome: %s", contatos[i].nome);
            printf("\nSobrenome: %s", contatos[i].sobrenome);
            printf("\nTelefone: %lld", contatos[i].telefone);
            printf("\nE-mail: %s", contatos[i].email);
        } else {
            printf("\nErro! Contato nao encontrado!");
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

}

void listarContatos(CONTATO contatos[150], int contador_contatos){

    printf("LISTAR CONTATOS");

    if(contador_contatos == 0){
        printf("\n\nNao existem contatos na agenda!");
    } else {
        int i;

        for(i = 0; i < contador_contatos; i++){
            printf("\n\nNome: %s", contatos[i].nome);
            printf("\nSobrenome: %s", contatos[i].sobrenome);
            printf("\nTelefone: %lld", contatos[i].telefone);
            printf("\nE-mail: %s", contatos[i].email);
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

}

void excluirContato(CONTATO contatos[150], int* contador_contatos){

    char nome_auxiliar[30];
    char sobrenome_auxiliar[30];

    printf("EXCLUIR CONTATO");

    if(*contador_contatos == 0){
        printf("\n\nNao existem contatos na agenda!");
    } else {
        printf("\n\nInsira o nome completo do contato: ");
        scanf("%30s %30[^\n]", nome_auxiliar, sobrenome_auxiliar);
        fflush(stdin);

        int i;
        int flag_encontrou = 0;

        for(i = 0; i < *contador_contatos; i++){
            if( (!(strcmp(contatos[i].nome, nome_auxiliar))) && (!(strcmp(contatos[i].sobrenome, sobrenome_auxiliar))) ){
                flag_encontrou = 1;
                break;
            }
        }

        if(flag_encontrou == 1){
            while(i < *contador_contatos){
                contatos[i] = contatos[i+1];
                i++;
            }
            (*contador_contatos)--;
            printf("\nContato excluido com sucesso!");
        } else {
            printf("\nErro! Contato nao encontrado!");
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

}

void salvarInformacoes(CONTATO contatos[150], int contador_contatos){

    FILE* arquivo = NULL;
    int flag_erro = 0;

    arquivo = fopen("agenda.txt", "w");

    if(arquivo == NULL){
        printf("Erro! Nao foi possivel ler o arquivo!");
    } else {
        for(int i = 0; i < contador_contatos; i++){
            flag_erro = fprintf(arquivo, "%s\n%s\n%lld\n%s\n\n", contatos[i].nome, contatos[i].sobrenome, contatos[i].telefone, contatos[i].email);

            if(flag_erro == EOF){
                printf("Erro ao salvar os contatos no arquivo!");
            }
        }
    }

    if(flag_erro != EOF){
        printf("Contatos salvos com sucesso!");
    }

    printf("\n\n");
    system("pause");
    system("cls");

    fclose(arquivo);
}

void main(){

    CONTATO agenda[150];
    int contador_contatos = 0;
    int flag_arquivo = 0;

    while(1){

        int comando_menu = 0;

        printf("MENU AGENDA\n\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Pesquisar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Excluir contato\n");
        printf("5 - Salvar informacoes em um arquivo de texto\n");
        printf("6 - Fechar o programa\n\n");
        printf("Insira um comando: ");

        scanf("%d", &comando_menu);
        fflush(stdin);

        system("cls");

        if(comando_menu == 1){

            while(1){

                printf("ADICIONAR CONTATO\n\n");
                printf("1 - Adicionar contato via teclado\n");
                printf("2 - Adicionar contato via arquivo\n");
                printf("3 - Voltar\n\n");
                printf("Insira um comando: ");

                scanf("%d", &comando_menu);
                fflush(stdin);

                system("cls");

                if (comando_menu == 1){
                    adicionarContatoTeclado(agenda, &contador_contatos);
                } else if (comando_menu == 2){
                    adicionarContatoArquivo(agenda, &contador_contatos, &flag_arquivo);
                } else if (comando_menu == 3){
                    system("cls");
                    break;
                } else {
                    printf("Erro! Informe uma opcao valida!\n\n");
                    system("pause");
                    system("cls");
                }

            }

        } else if (comando_menu == 2){
            pesquisarContato(agenda, contador_contatos);
        } else if (comando_menu == 3){
            listarContatos(agenda, contador_contatos);
        } else if (comando_menu == 4){
            excluirContato(agenda, &contador_contatos);
        } else if (comando_menu == 5){
            salvarInformacoes(agenda, contador_contatos);
        } else if (comando_menu == 6){

            printf("Programa finalizado com sucesso!\n\n");
            system("pause");
            exit(0);

        } else {
            printf("Erro! Informe uma opcao valida!\n\n");
            system("pause");
            system("cls");
        }

    }

}
