/*
1. Faça um algoritmo que receba N (6 ≤ 𝑁 ≤ 10) números de uma cartela da Mega Sena jogada por um usuário. Em seguida, leia os seis números sorteados na Mega Sena. O algoritmo deverá mostrar a quantidade de acertos do apostador com sua cartela, os números que ele acertou e se ele fez a Mega-Sena (6 acertos), a Quina (5 acertos) ou a Quadra (4 acertos).
*/

#include <stdio.h>
#include <stdlib.h>


int main (int narg, char *argv[]) {
  int N;
  
  //entrada de dados
  printf("Digite o valor de N: ");
  scanf("%d", &N);

  int Vetor[10];
  //entrada de dados
  for (int i = 0; i < N; i++) {
    printf ("Digite o %dº numero da cartela: \n", i+1);
    scanf("%d", &Vetor[i]);
  }
  //entrada de dados
  int Vetor2[6];
  for (int i= 0; i < N; i++){
    printf ("Digite o %dº numero sorteado: \n", i+1);
    scanf("%d", &Vetor2[i]);
  }

  int count = 0;
  
  //calculo de acertos
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Vetor[i] == Vetor2[j]){
        printf("%d ", Vetor[i]);
        count++;
      }
    }

  }
  printf("\n");
  //resultado
  if (count == 6) 
    printf("Ganhou na Mega-Sena, parabens\n");
  else if (count == 5)
    printf("Ganhou na Quina\n");
  else if (count == 4)
    printf("Ganhou na Quadra\n");
  else
    printf("Ganhou nada :( \n");

  return EXIT_SUCCESS;
}

