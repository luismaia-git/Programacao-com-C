/*
Faça um programa em linguagem C que receba
um valor inteiro positivo N e mostre todos os
números da sequência Fibonacci que sejam menores
do que N.

0, 1, 1, 2, 3, 5, 8, 13, 21

*/

#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  int N, a=0,b=1,i;

  printf("Digite um valor inteiro positivo: ");
  scanf("%d", &N);

  if (N==1)
    printf("%d ",a);
  
  else {
    printf("%d ",a);
    printf("%d ",b);
    
    i=0;
    while (i<N){
      i=a+b;
      a=b;
      b=i;
      
      printf("%d ",i);
      i=a+b;
    }
  }
  printf("\n");

  return EXIT_SUCCESS;
}