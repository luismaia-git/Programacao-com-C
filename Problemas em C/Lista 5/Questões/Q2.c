/*
2. Faça um algoritmo que receba um determinado valor N e, em seguida, receba N valores
inteiros do usuário. O algoritmo deverá determinar se estes números, na ordem em que
foram entrados, são ou não uma progressão geométrica. Se sim, mostrar a razão desta
progressão geométrica. Considere N no intervalo [0;1000].
*/

#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  int N;
  //entrada de dados
  printf("Digite o valor de N: ");
  scanf("%d", &N);

  int vetor[1000];
  //entrada de dados
  for (int i = 0; i < N; i++){
    printf("Digite um valor: ");
    scanf("%d", &vetor[i]);

  }

  double R;
  
  if (N >= 2){
    R = vetor[1]/vetor[0];
  }

  for (int j = 0; j < N-1; j++){
    if(vetor[j+1]/vetor[j] != R) {
      printf("Nao eh uma progressao geometrica\n");
      return EXIT_SUCCESS;
    }
  }

  printf("Eh uma progressao geometrica e a razão eh %.2lf\n", R);

}