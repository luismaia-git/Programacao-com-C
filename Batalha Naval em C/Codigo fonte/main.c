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
#include "funcoes_aux.c"

int main() {
    int player_pontos = 0, computador_pontos = 0;   // Inicializando a computação dos pontos do humano e do computador

    srand(time(NULL));

    while(1) {
        Coord ultimos_acertos[100];

        int indice = 0;

        jogada ultima_jogada_player;
        jogada ultima_jogada_comp;

        int x_player, y_player;
        int x_comp,   y_comp;

        Casa* player = NULL, *computador = NULL;

        liberar_memoria(&player);                   // Liberando memoria para o jogo do humano
        liberar_memoria(&computador);               // Liberando memoria para o jogo do computador

        limpar_objetos();                           // Limpando dados das embarcaçoes passadas da memoria

        player     = criar_tabuleiro();             // Criando o tabuleiro do humano
        computador = criar_tabuleiro();             // Criando o tabuleiro do computador

        int idx = 0;

        criar_embarcacoes(player, &idx);            // Inserindo as embarcaçoes no tabuleiro do humano
        criar_embarcacoes(computador, &idx);        // Inserindo as embarcaçoes no tabuleiro do computador

        inicializar_matrizes(player, computador);

        for(int i = 0; i < 9; i++) {
            printar_embacacao(mat_player, objetos[i]);
        }

        int jogador_vez = 1;

        int pl_joga = 0, cm_joga = 0;

        while (1) {
            limpar_tela();
            menu();
            
            // Computando a ultima jogada dos jogadores
            if(cm_joga == 1) {
                printf("Ultima jogada do computador: %c%d\n", ultima_jogada_comp.ultima_jogada.x,
                                                            ultima_jogada_comp.ultima_jogada.y);
            }

            if(pl_joga == 1) {
                printf("Ultima jogada do humano: %c%d\n\n",  ultima_jogada_player.ultima_jogada.x,
                                                        ultima_jogada_player.ultima_jogada.y);
            }


            if (jogador_vez == 1) {
                pl_joga = 1;

                interface_de_comando(&x_player, &y_player); //entrada do player

                ultima_jogada_player.ultima_jogada.x = 'A' + y_player;
                ultima_jogada_player.ultima_jogada.y = x_player + 1;

                Casa* no_atacado = acessar_tabuleiro(computador, x_player, y_player);

                if (no_atacado->valor == ' ') { //acertou um 'espaco em branco'
                    mat_computer[x_player][y_player] = 'O';     // Escreve O se errar o ataque
                    jogador_vez = 0;
                }
                else {
                    int indice_alvo = no_atacado->valor - '0';

                    int tipo_acerto = marcar_acerto(&objetos[indice_alvo], x_player, y_player);

                    if (checa_se_foi_destruido(objetos[indice_alvo]) == 1) {
                        if(objetos[indice_alvo].tipo == 4) { //se o objeto for uma jangada
                            jogador_vez = 0;

                            // PERDER SUBMARINO

                            for(int i = 0; i < 9; i++) {
                                if(checa_se_foi_destruido(objetos[i]) == 0) {
                                    if(objetos[i].tipo == 3) { //se o objeto for um submarino
                                        objetos[i].acertos[0] = 1; //ele 'ganha' um acerto
                                        mat_player[objetos[i].x1][objetos[i].y1] = '*'; //print de: o computador acertou algo (nesse caso, o player perdeu automaticamente um submarino, pois acertou uma jangada)
                                        break;
                                    }
                                }
                            }
                        }

                        printar_embacacao(mat_computer, objetos[indice_alvo]);

                        limpar_tela();
                        printf("O humano acabou de afundar um(a) %s do computador\n",
                        embarcacao[objetos[indice_alvo].tipo]);

                        getchar();
                        getchar();
                        //flag 1 = computador perdeu
                        if(alguem_perdeu(1) == 1) { //se o computador perdeu
                            limpar_tela();
                            printf("O ganhador foi o humano\n\n");
                            player_pontos++;                            // Se o humano ganhou, incrementa um ponto na contagem
                            placar(player_pontos, computador_pontos);   // Mostra o placar
                            getchar();
                            getchar();

                            if(continuar_jogando() == 1) {
                                break;
                            } else {
                                exit(0);
                            }
                        }

                        continue;
                    }
                    else {
                        mat_computer[x_player][y_player] = '*'; //player acertou algo
                    }
                }
            }
            else {
                cm_joga = 1;
                if(indice > 0) {
                    Coord aux = gerar_jogada_precisa(player, ultimos_acertos[indice-1]);

                    if(aux.x == -1) {
                        indice--;
                        continue;
                    }
                    x_comp = aux.x;
                    y_comp = aux.y;

                } else {
                    gerar_jogada_aleatoria(&x_comp, &y_comp);

                    ultima_jogada_comp.ultima_jogada.x = 'A' + y_comp;
                    ultima_jogada_comp.ultima_jogada.y = x_comp + 1;
                }

                printf("Jogada do computador: %c%d\n", 'A'+y_comp, x_comp+1);
                getchar();
                getchar();

                Casa* no_atacado = acessar_tabuleiro(player, x_comp, y_comp);

                if (no_atacado->valor == ' ') { //acertou a agua
                    mat_player[x_comp][y_comp] = 'O';   // Escreve O se errar o ataque
                    jogador_vez = 1;
                } else {
                    int indice_alvo = no_atacado->valor - '0';

                    int tipo_acerto = marcar_acerto(&objetos[indice_alvo], x_comp, y_comp);

                    if (checa_se_foi_destruido(objetos[indice_alvo]) == 1) {
                        if(objetos[indice_alvo].tipo == 4) { //se acertou uma jangada
                            jogador_vez = 1;

                            // PERDER SUBMARINO
                            for(int i = 9; i < 18; i++) {
                                if(checa_se_foi_destruido(objetos[i]) == 0) {
                                    if(objetos[i].tipo == 3) { //se o objeto for um submarino
                                        objetos[i].acertos[0] = 1; //ele ganha um acerto
                                        mat_computer[objetos[i].x1][objetos[i].y1] = '@'; //printa o submarino
                                        break;
                                    }
                                }
                            }
                        }

                        mat_player[x_comp][y_comp] = '*'; //print, o computador acertou algo
                        limpar_tela();
                        printf("O computador acabou de afundar um %s do humano\n",
                        embarcacao[objetos[indice_alvo].tipo]);

                        getchar();
                        getchar();
                        //flag 0 = player perdeu 
                        if(alguem_perdeu(0) == 1) {
                            limpar_tela();
                            printf("O ganhador foi o computador\n\n");
                            computador_pontos++;                        // Se o computador ganhou, incrementa um ponto na contagem
                            placar(player_pontos, computador_pontos);   // Mostra o placar
                            getchar();
                            getchar();
                            if(continuar_jogando() == 1) {
                                break;
                            } else {
                                exit(0);
                            }
                            break;
                        }
                        continue;
                    }
                    else {
                        Coord coord;
                        mat_player[x_comp][y_comp] = '*'; //computador acertou algo

                        coord.x = x_comp;
                        coord.y = y_comp;

                        ultimos_acertos[indice] = coord;
                        indice++;
                    }
                }
            }
        }
    }

    return 0;
}