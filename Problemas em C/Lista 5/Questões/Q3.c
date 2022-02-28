/*
Faça um algoritmo que receba do usuário um número inteiro positivo de até 10 dígitos e
mostre se este número é um palíndromo. Um palíndromo é um número que é igual a ele
próprio quando lido no sentido inverso. (Ex. 473848374 é um palíndromo). Utilizar apenas
vetores e variáveis numéricas ou lógicas.
*/

#include <stdio.h>
#include <stdlib.h>


int main (int narg, char *argv[]) {
  long int N;
  int vetor[10];
  int i = 0;

  //entrada de dados
  printf("Digite o valor de N: ");
  scanf("%ld", &N);

  while (N>0){
    vetor[i] = N%10;
    i++;
    N = N/10;
  }


  for(int j= 0;  j < i/2; j++){
    if (vetor[j] != vetor[i-j-1]) {
      printf("nao eh palindromo\n");
      return EXIT_SUCCESS;
    }
  }

  printf("eh palindromo\n");
  
}
