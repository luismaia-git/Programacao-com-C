/*
Faça um programa em linguagem C que receba
um valor inteiro positivo N e mostre os N primeiros
números primos, considerando o primeiro
número primo como sendo 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int narg, char *argv[]) {
  int N, i, j;
  bool isPrime = true;

  //entrada de dados
  printf("Digite um valor inteiro positivo: ");
  scanf("%d", &N);

  i = 2;

  while(N) {

    if (i <= 2 ){
      isPrime = false;
      
    }
    if ( i == 2 ) {
      isPrime = true;
    }

    for (int j = 2; j < i ; j ++){
      if (i % j == 0){
        isPrime = false;
      }
    }

    if (isPrime) {
      printf("%d \n", i);
      N--;
    }
    isPrime = true;
    i++;
  }
  
  return EXIT_SUCCESS;
}