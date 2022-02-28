#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./listaencadeada.h"



void ordenar(Agenda **agenda){

    Agenda *aux = *agenda, *t;
    int temp_int;
    char nome[20];

    if (*agenda == NULL || (*agenda)->prox == NULL) return; // se a lista for vazia ou tiver apenas um elemento

    while (aux != NULL){
        t = aux->prox;
        while(t != NULL){
            if(strcmp(aux->nome, t->nome) > 0){

                temp_int = aux->matricula;
                aux->matricula = t->matricula;
                t->matricula = temp_int;

                temp_int = aux->ddd;
                aux->ddd = t->ddd;
                t->ddd = temp_int;

                temp_int = aux->telefone;
                aux->telefone = t->telefone;
                t->telefone = temp_int;

                strcpy(nome, aux->nome);
                strcpy(aux->nome, t->nome);
                strcpy(t->nome, nome);
                
                strcpy(nome, aux->tipo);
                strcpy(aux->tipo, t->tipo);
                strcpy(t->tipo, nome);

            }
            t = t->prox;
        }
        aux = aux->prox;
    }


}


Agenda *agd_inicializar(){
    return NULL;
}

Agenda receber_dados(){
    Agenda *dados;

    dados = malloc(sizeof(Agenda));

    printf("Entre com a matrícula: ");
    fscanf(stdin, "%d", &dados->matricula);
    
    printf("Entre com o nome: ");
    fscanf(stdin, "%s", dados->nome);

    printf("Entre com o ddd: ");
    fscanf(stdin, "%d", &dados->ddd);

    printf("Entre com o numero do telefone: ");
    fscanf(stdin, "%d", &dados->telefone);

    printf("Entre com o tipo de telefone: ");
    fscanf(stdin, "%s", dados->tipo);    

    return *dados;
}

void receber_dados_arquivo(Agenda **agenda){

    FILE *entrada;
    entrada = fopen("./entrada.txt", "rt");

    Agenda *dados;
    
    while(!feof(entrada)){
        dados = malloc(sizeof(Agenda));
        fscanf(entrada, "%d", &dados->matricula);
        fscanf(entrada, "%s", dados->nome);
        fscanf(entrada, "%d", &dados->ddd);
        fscanf(entrada, "%d", &dados->telefone);
        fscanf(entrada, "%s", dados->tipo);

        dados->prox = NULL;

        if (*agenda != NULL)
            dados->prox = *agenda;
        
        *agenda = dados;
    }
   
    fclose(entrada);
}

void enviar_dados_arquivo(Agenda **agenda){
    FILE *saida;
    Agenda *aux;
    saida = fopen("./saida.txt", "wt");

    aux = *agenda;

    while (aux != NULL){

        fprintf(saida, "%d", aux->matricula);
        fputc('\n', saida);

        fprintf(saida, "%s", aux->nome);
        fputc('\n', saida);

        fprintf(saida, "%d", aux->ddd);
        fputc('\n',saida);

        fprintf(saida, "%d", aux->telefone);
        fputc('\n',saida);

        fprintf(saida, "%s", aux->tipo);
        fputc('\n',saida);

        aux = aux->prox;
    }
    
    fclose(saida);

}

int agd_inserir(Agenda **agenda){
    Agenda *novo;

    novo = malloc(sizeof(Agenda));

    if (novo == NULL)
        return 0;
   
    *novo = receber_dados();
        

    novo->prox = NULL;

    if (*agenda != NULL)
        novo->prox = *agenda;

    *agenda = novo;
    

    return 1;
}

void agd_percorrer(Agenda *agenda){
    Agenda *aux;

    for (aux = agenda; aux != NULL; aux = aux->prox){
        printf("Matrícula: %d\tNome: %s\tTelefone: (%d)%d -%s-  \n", aux->matricula, aux->nome, aux->ddd, aux->telefone, aux->tipo);
    }

    if (agenda == NULL)
         printf("----- AGENDA VAZIA -----\n\n");

}