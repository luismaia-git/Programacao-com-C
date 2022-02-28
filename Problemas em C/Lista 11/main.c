#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "./listaencadeada.h"

Agenda *agenda;

void opcoes(){

    char opcao;

    printf("-I- INSERIR NOVO REGISTRO NA AGENDA\n");
    printf("-P- EXIBIR AGENDA NA TELA\n");
    printf("-C- CARREGAR DADOS DE UM ARQUIVO\n");
    printf("-S- SALVAR AGENDA EM UM ARQUIVO\n");
    printf("-E- PARA ENCERRAR O PROGRAMA\n");

    printf("\nEntre com a opcao desejada: ");
    scanf("%s", &opcao);

    opcao = toupper(opcao);

    if (opcao == 'I'){
        system("tput reset");
        printf("\n ##### INSERÇÃO DE DADOS #####\n\n");
        agd_inserir(&agenda);
        system("tput reset");
        printf("\n ##### DADOS INSERIDOS COM SUCESSO #####\n\n");
        opcoes();
    }else if (opcao == 'P'){
        system("tput reset");
        printf("\n ##### DADOS REGISTRADOS #####\n\n");
        ordenar(&agenda);
        agd_percorrer(agenda);
        printf("\n");
        opcoes();
    }else if (opcao == 'C'){
        system("tput reset");
        printf("\n ##### CARREGADO DADOS DE UM ARQUIVO #####\n\n");
        receber_dados_arquivo(&agenda);
        opcoes();
    }else if (opcao == 'S'){
        system("tput reset");
        printf("\n ##### DADOS DA AGENDA SALVO EM UM ARQUIVO #####\n\n");
        ordenar(&agenda);
        enviar_dados_arquivo(&agenda);
        opcoes();
    }else if(opcao == 'E'){
        system("tput reset");
        printf("\n ##### ATÉ A PRÓXIMA #####\n\n");
    }else{
        system("tput reset");
        printf("\n ##### DIGITE UMA OPCAO VÁLIDA #####\n\n");
        opcoes();
    }
}

int main (int narg, char *argv[]){
    system("tput reset");
    agenda = agd_inicializar();

    printf("\n ##### BEM VINDO(A) À AGENDA ENCADEADA #####\n\n");

    if (narg > 1){
        printf("-----CARREGADO OS DADOS DO ARQUIVO----\n\n");

        receber_dados_arquivo(&agenda);
        opcoes();

    }else{
        opcoes();
    }



    return EXIT_SUCCESS;
}
