/*
Trabalho Final – Batalha Naval
Disciplina Programação (CK0226) – Semestre 2021.2
Equipe: Luís Antonio da Silva Maia - 493458
        Italo Sousa de Alencar - 495638	
        
    Luís atuou mais no desenvolvimento das funcoes auxiliares (funcoes_aux.c) e tambem nas estruturas de dados (estrutura_de_dados.h)

    Italo atuou no desenvolvimento do programa principal(main) e tambem nas estruturas de dados (estrutura_de_dados.h)

    Ambos atuaram no planejamento de como seria o projeto como um todo.
*/

#ifndef ESTRUTURA_DE_DADOS
#define ESTRUTURA_DE_DADOS

#define OBJETOS 18

typedef struct Coord { //coordenadas
    int x, y;
} Coord;

typedef struct jogada { //jogada
    Coord ultima_jogada;
} jogada;

typedef struct casa { //noh Casa que aponta pra cima, baixo, esquerda e direita.
    int valor;
    struct casa* cima; //aponta pra cima
    struct casa* baixo; //aponta pra baixo
    struct casa* esq; //aponta pra esquerda
    struct casa* dir; //aponta pra direita
} Casa;

int  tamanhos[5] = { 5, 3, 2, 1, 1 }; //tamanho das embarcacoes
char embarcacao[5][30] = { "Porta Aviao", "Destroyer", "Fragata", "Submarino", "Jangada" }; //tipos de embarcacoes

// tamanho 5
typedef struct Objeto {
    int tipo;       // 0..4
    int orientacao; // 0 ou 1.
    int x1, y1;     // ponta
    int acertos[5]; // 0, 0, 0, 0, 0
} Objeto;

Objeto objetos[OBJETOS];

int mat_player[12][12]; //matriz do player 12x12
int mat_computer[12][12]; //matriz do computador 12x12

#endif