/*
Trabalho Final – Batalha Naval
Disciplina Programação (CK0226) – Semestre 2021.2
Equipe: Luís Antonio da Silva Maia - 493458
        Italo Sousa de Alencar - 495638
        
    Luís atuou mais no desenvolvimento das funcoes auxiliares (funcoes_aux.c) e tambem nas estruturas de dados (estrutura_de_dados.h)

    Italo atuou no desenvolvimento do programa principal(main) e tambem nas estruturas de dados (estrutura_de_dados.h)

    Ambos atuaram no planejamento de como seria o projeto como um todo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "estrutura_de_dados.h"

#define N 12

char symbol = '0';

void limpar_tela() {
    system("cls||clear");
}

int printar_embacacao(int mat[12][12], Objeto objeto) { // funcao para mostrar as embarcacoes do player
    int tam = tamanhos[objeto.tipo];

    if (tam == 1) {
        if (objeto.tipo == 3) {
            mat[objeto.x1][objeto.y1] = '@'; //acertou um submarino
        }
        else {
            mat[objeto.x1][objeto.y1] = '&';
            return 1; // indica que tenho que deletar um submarino e não posso jogar
        }

        return 0;
    }


    if (objeto.orientacao == 0) { //se a embarcacao esta na horizontal
        for (int i = 0; i < tam; i++) {
            if (i == 0)
                mat[objeto.x1][objeto.y1+i] = '<';
            else if(i == tam-1) {
                mat[objeto.x1][objeto.y1 + i] = '>';
            }
            else {
                mat[objeto.x1][objeto.y1 + i] = '#';
            }
        }
    }
    else {
        for (int i = 0; i < tam; i++) { //se a embarcacao esta na vertical
            if (i == 0)
                mat[objeto.x1+i][objeto.y1] = '^';
            else if (i == tam - 1) {
                mat[objeto.x1+i][objeto.y1] = 'v';
            }
            else {
                mat[objeto.x1+i][objeto.y1] = '#';
            }
        }
    }

    return 0;
}

int checa_se_foi_destruido(Objeto objeto) {
    int tam = tamanhos[objeto.tipo];
    int aux = 0;
    for (int i = 0; i < tam; i++) {
        if (objeto.acertos[i] == 1) {
            aux++;
        }
    }

    if (aux == tam) {
        return 1; // se o numero de acertos for = ao tamanho da embarcacao, entao ela foi destruida
    }

    return 0;
}

int marcar_acerto(Objeto* objeto, int x, int y) {
    if (objeto->orientacao == 0) {
        objeto->acertos[y - objeto->y1] = 1;
        if (y - objeto->y1 == 0) {
            return 1; // acertei a cabeça
        }

        if (y - objeto->y1 == tamanhos[objeto->tipo] - 1) {
            return 2; // acertou a cauda
        }

        return 3; // acertou no meio do corpo
    }
    else {
        objeto->acertos[x - objeto->x1] = 1;
        if (x - objeto->x1 == 0) {
            return 1; // acertei a cabeça
        }

        if (x - objeto->x1 == tamanhos[objeto->tipo] - 1) {
            return 2; // acertou a cauda
        }

        return 3; // acertou no meio do corpo
    }
}

int colisao(Objeto obj, int idx) { //funcao para checar colisao entre embarcacao
    int tam = tamanhos[obj.tipo];
    for (int i = 0; i < idx; i++) {
        // horizontal
        if (obj.orientacao == 0) {
            for (int j = obj.y1; j < obj.y1 + tam; j++) {
                if (objetos[i].orientacao == 0) {
                    for (int k = objetos[i].y1; k < objetos[i].y1 + tamanhos[objetos[i].tipo]; k++) {
                        if (k == j && obj.x1 == objetos[i].x1) {
                            return 1;
                        }
                    }
                }
                else {
                    for (int k = objetos[i].x1; k < objetos[i].x1 + tamanhos[objetos[i].tipo]; k++) {
                        if (k == obj.x1 && objetos[i].y1 == j) {
                            return 1;
                        }
                    }
                }
            }
        }
        else { //vertical
            for (int j = obj.x1; j < obj.x1 + tam; j++) {
                if (objetos[i].orientacao == 1) {
                    for (int k = objetos[i].x1; k < objetos[i].x1 + tamanhos[objetos[i].tipo]; k++) {
                        if (k == j && obj.y1 == objetos[i].y1) {
                            return 1;
                        }
                    }
                }
                else {
                    for (int k = objetos[i].y1; k < objetos[i].y1 + tamanhos[objetos[i].tipo]; k++) {
                        if (k == obj.y1 && j == objetos[i].x1) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// é necessário que haja espaço no tabuleiro pra criação do objeto.
Objeto gerar_objeto(int tipo, int* idx) { // gera uma embarcacao no tabuleiro
    Objeto aux;

    aux.tipo = tipo;
    aux.orientacao = rand() % 2;

    for (int i = 0; i < 5; i++)
        aux.acertos[i] = 0;

    int tam = tamanhos[aux.tipo];

    while (1) {
        int x = rand() % 12;
        int y = rand() % 12;

        aux.x1 = x;
        aux.y1 = y;

        if (aux.orientacao == 0 && y + tam - 1 >= N)
            continue;

        if (aux.orientacao == 1 && x + tam - 1 >= N)
            continue;

        if (colisao(aux, *idx) == 0) {
            objetos[*idx] = aux;
            *idx = *idx + 1;
            return aux;
        }
    }
}

Casa* acessar_tabuleiro(Casa* no, int x, int y) { //acessa o tabuleiro
    int i = 0;
    while (i < x) {
        no = no->baixo;
        i++;
    }
    i = 0;
    while (i < y) {
        no = no->dir;
        i++;
    }

    return no;
}

void desenhar_objeto(int tipo, int* idx, Casa* no) {//acessa o tabuleiro e printa a embarcacao
    Objeto aux = gerar_objeto(tipo, idx);
    if (aux.orientacao == 0) {
        for (int i = aux.y1; i < aux.y1 + tamanhos[aux.tipo]; i++) {
            acessar_tabuleiro(no, aux.x1, i)->valor = symbol;
        }
    }
    else {
        for (int i = aux.x1; i < aux.x1 + tamanhos[aux.tipo]; i++) {
            acessar_tabuleiro(no, i, aux.y1)->valor = symbol;
        }
    }
    symbol++;
}

Casa* inicializar(int val) { //inicializa um noh casa (alocando memoria)
    Casa* aux = (Casa*)malloc(sizeof(Casa));
    aux->cima = NULL;
    aux->baixo = NULL;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->valor = val;
    return aux;
}

Casa* criar_tabuleiro() { //cria o tabuleiro, com cada no apontando pra cima, pra baixo, esquerda e direita
    Casa* mat[N][N];

    int contador = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = inicializar(' ');
            contador++;
        }
    }
    //i percorre a linha
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                if (j < N - 1 && j > 0) {
                    mat[i][j]->esq = mat[i][j - 1];
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->baixo = mat[i + 1][j];
                }
                else if (j == 0) {
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->baixo = mat[i + 1][j];
                }
                else {
                    mat[i][j]->esq = mat[i][j - 1];
                    mat[i][j]->baixo = mat[i + 1][j];
                }
                continue;
            }
            else if (i == N - 1) {
                if (j < N - 1 && j > 0) {
                    mat[i][j]->esq = mat[i][j - 1];
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->cima = mat[i - 1][j];
                }
                else if (j == 0) {
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->cima = mat[i - 1][j];
                }
                else {
                    mat[i][j]->esq = mat[i][j - 1];
                    mat[i][j]->cima = mat[i - 1][j];
                }
                continue;
            }

            //j percorre a coluna
            if (j == 0) {
                if (i < N - 1 && i > 0) {
                    mat[i][j]->cima = mat[i - 1][j];
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->baixo = mat[i + 1][j];
                }
                else {
                    mat[i][j]->dir = mat[i][j + 1];
                    mat[i][j]->cima = mat[i - 1][j];
                }
                continue;
            }
            else if (j == N - 1) {
                if (i < N - 1 && i > 0) {
                    mat[i][j]->esq = mat[i][j - 1];
                    mat[i][j]->baixo = mat[i + 1][j];
                    mat[i][j]->cima = mat[i - 1][j];
                }
                continue;
            }

            mat[i][j]->esq = mat[i][j - 1];
            mat[i][j]->dir = mat[i][j + 1];
            mat[i][j]->cima = mat[i - 1][j];
            mat[i][j]->baixo = mat[i + 1][j];
        }
    }

    return mat[0][0];
}

void liberar_memoria(Casa** no) { //libera espaco na memoria dos noh casa, para o jogo recomecar posteriormente
    if(*no != NULL) {
        if((*no)->esq != NULL) {
            liberar_memoria(&(*no)->esq);
        }

        if((*no)->dir != NULL) {
            liberar_memoria(&(*no)->dir);
        }

        if((*no)->cima != NULL) {
            liberar_memoria(&(*no)->cima);
        }

        if((*no)->baixo != NULL) {
            liberar_memoria(&(*no)->baixo);
        }

        free((*no));
        *no = NULL;
    }
}

void limpar_objetos() { //limpando os dados antigos de cada objeto (embarcacao)
    Objeto obj;

    for(int i = 0; i < 5; i++) {
        obj.acertos[i] = 0;
    }


    for(int i = 0; i < 20; i++) {
        objetos[i] = obj;
    }
}

void mostrar_tabuleiro(Casa* no) { // printa o tabuleiro
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", acessar_tabuleiro(no, i, j)->valor); //printa o valor acessado no tabuleiro
        }
        printf("\n");
    }
}

void inicializar_matrizes(Casa* P, Casa* C) { //inicializa uma matriz
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            mat_player[i][j] = acessar_tabuleiro(P, i, j)->valor; //preenchimento da matriz com valor no tabuleiro
            mat_computer[i][j] = ' '; //preenchimento da matriz com 'espacos em branco'
        }
    }
}

void desenhar_linha_menu(int linha) {//printa uma linha da matriz
    if (linha < 10) {
        printf(" %d|", linha);
    }
    else
        printf("%d|", linha);

    for (int i = 0; i < 12; i++) {
        printf("%c", mat_player[linha - 1][i]);
    }
    printf("+ ");

    if (linha < 10) {
        printf(" %d|", linha);
    }
    else
        printf("%d|", linha);

    for (int i = 0; i < 12; i++) {
        printf("%c", mat_computer[linha - 1][i]);
    }

    printf("|\n");
}

void menu() { //printa o menu formatado
    printf("      Humano         Computador\n\n   ");

    for (int j = 0; j < 2; j++) {
        for (int i = 'A'; i <= 'L'; i++) {
            printf("%c", i);
        }
        printf("     ");
    }

    printf("\n");

    // BORDA SUPERIOR ---------------------

    printf("  +");

    for (int i = 0; i < 12; i++) {
        printf("-");
    }

    printf("+   +");

    for (int i = 0; i < 12; i++) {
        printf("-");
    }

    printf("+\n");

    // BORDA SUPERIOR ---------------------

    for (int i = 0; i < 12; i++) {
        desenhar_linha_menu(i + 1);
    }


    // BORDA INFERIOR

    printf("  +");

    for (int i = 0; i < 12; i++) {
        printf("-");
    }

    printf("+   +");

    for (int i = 0; i < 12; i++) {
        printf("-");
    }

    printf("+\n\n");

    // BORDA INFERIOR
}

void criar_embarcacoes(Casa* no, int* idx) {
    desenhar_objeto(0, idx, no); //Porta Avioes

    desenhar_objeto(1, idx, no); //Destroyers
    desenhar_objeto(1, idx, no); //Destroyers

    desenhar_objeto(2, idx, no); // Fragatas
    desenhar_objeto(2, idx, no); // Fragatas
    desenhar_objeto(2, idx, no); // Fragatas

    desenhar_objeto(3, idx, no); //Submarinos
    desenhar_objeto(3, idx, no); //Submarinos

    desenhar_objeto(4, idx, no); //Jangada
}


void gerar_jogada_aleatoria(int* x, int* y) { //gera uma jogada aleatoria (computador)
    while (1) {
        *x = rand() % 12;
        *y = rand() % 12;

        if (mat_player[*x][*y] != '*') { //condicao para a jogada acertar uma posicao valida
            return;
        }
    }
}

void interface_de_comando(int* x, int* y) {

    char comando[10], comando_formatado[10];
    
    while(1){
        printf("Entre a sua jogada: ");
        fgets(comando, 8, stdin);
    
        if (strlen(comando) <= 1) { // se o player digitar nada
            printf("Voce nao digitou nada\n");
            getchar();
            continue;
        }
        break;
    }
    // só pra tira o newline character
    if(comando[strlen(comando)-1] == '\n')
        comando[strlen(comando)-1] = 0;

    int i= 0, cont=1;
    //formatando a entrada do player
    //Exemplo: entrada = b,4 / saida = B4
    while (comando[i] != '\0') {
        if (comando[i] >= '1' && comando[i] <= '9') {
            comando_formatado[cont] = comando[i];
            cont++;
        }
        else if (comando[i] >= 'A' && comando[i] <= 'z') {
            if(comando[i] >= 'a')
                comando_formatado[0] = comando[i] - 32;
            else
                comando_formatado[0] = comando[i];
        }
        else if (comando[i] >= '0' && comando[i] <='9' ) {
            comando_formatado[2] = comando[i];
        }
        i++;
    }


    comando_formatado[cont] = '\0';// comando formatado. EX: B12

    if (strlen(comando_formatado) > 3 || strlen(comando_formatado) <= 1) {
        printf("Voce digitou um comando incorreto\n");
        return;
    }

    if (comando_formatado[0] > 'L' || comando_formatado[0] < 'A') {
        printf("Voce digitou um comando incorreto\n");
        return;
    }

    int casa;

    // D12

    if (strlen(comando_formatado) == 3) {
        if (comando_formatado[1] > '9' || comando_formatado[1] < '1') {
            return;
        }

        if (comando_formatado[2] > '9' || comando_formatado[2] < '0') {
            return;
        }

        casa = (comando_formatado[1] - '0') * 10 + (comando_formatado[2] - '0');
    }
    else {
        if (comando_formatado[1] > '9' || comando_formatado[1] < '1') {
            return;
        }

        casa = comando_formatado[1] - '0';
    }

    *x = casa - 1;
    *y = comando_formatado[0] - 'A';
}




// flag = 0, PLAYER
// flag = 1, COMPUTADOR
int alguem_perdeu(int flag) { //checar se alguem destruiu todas as embarcacoes ou destruiu todas menos a jangada
    int aux = 0;
    for(int i = flag*9; i < flag*9+9; i++) {
        if(checa_se_foi_destruido(objetos[i]) == 1) {
            aux++;
        }
    }


    if(aux == 9) {
        return 1; // destruiu todas as embarcacoes
    } else if(aux == 8) {
        for(int i = flag*9; i < flag*9+9; i++) {
            if(checa_se_foi_destruido(objetos[i]) == 0) {
                if(objetos[i].tipo == 4) { // destruiu todas as embarcacoes menos a jangada
                    return 1;
                } else {
                    return 0; // ainda nao destruiu todas
                }
            }
        }
    }

    return 0;
}

void placar(int player, int computador) { //printa o placar
    printf("--------- PLACAR ---------\n\n");
    printf("Numero de partidas vencidas pelo humano: %d\n", player);
    printf("Numero de partidas vencidas pelo computador: %d\n\n", computador);
}

int continuar_jogando() { //pergunta se o player quer continuar ou nao
    while(1) {
        printf("Voce gostaria de jogar mais uma vez? 1-Sim, 0-Nao\n");
        int n; scanf("%d", &n);
        if(n != 1 && n != 0) {
            printf("Voce digitou um comando incorreto, digite novamente\n");
            getchar(); getchar();
            limpar_tela();
        } else {
            return n; // se retorna 1, entao eh liberado na memoria todas as alocacoes, e eh limpado todos os dados das embarcoes
        }             // se retorna 0, entao o programa eh encerrado
    }
}

Coord gerar_jogada_precisa(Casa* player, Coord ultima_pos) { //gera uma jogada aleatoria em uma casa adjacente
    Casa* posicao = acessar_tabuleiro(player, ultima_pos.x, ultima_pos.y);

    Coord aux;

    aux.x = -1;
    aux.y = -1;

    int tipo = rand() % 4;

    if(tipo == 0) {
        if(posicao->cima != NULL && (mat_player[ultima_pos.x-1][ultima_pos.y] != '*' && mat_player[ultima_pos.x-1][ultima_pos.y] != 'O')) {
            aux.x = ultima_pos.x-1;
            aux.y = ultima_pos.y;
            return aux;
        }
    } else if(tipo == 1) {
        if(posicao->baixo != NULL && (mat_player[ultima_pos.x+1][ultima_pos.y] != '*' && mat_player[ultima_pos.x+1][ultima_pos.y] != 'O')) {
            aux.x = ultima_pos.x+1;
            aux.y = ultima_pos.y;
            return aux;
        }
    } else if(tipo == 2) {
        if(posicao->dir != NULL && (mat_player[ultima_pos.x][ultima_pos.y+1] != '*' && mat_player[ultima_pos.x][ultima_pos.y+1] != 'O')) {
            aux.x = ultima_pos.x;
            aux.y = ultima_pos.y+1;
            return aux;
        }
    } else {
        if(posicao->esq != NULL && (mat_player[ultima_pos.x][ultima_pos.y-1] != '*' && mat_player[ultima_pos.x][ultima_pos.y-1] != 'O')) {
            aux.x = ultima_pos.x;
            aux.y = ultima_pos.y-1;
            return aux;
        }
    }


    return aux;
}
