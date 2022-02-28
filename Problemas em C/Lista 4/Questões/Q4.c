/*
O máximo divisor comum de três números inteiros positivos, MDC(x,y,z), é igual a MDC(MDC(x,y),z).
Escreva um programa que capture três números inteiros fornecidos via teclado e imprima o MDC deles,
usando a função MDC implementada no item 2.
*/

#include <stdio.h>
#include <stdlib.h>

int MDC(int x, int y);

int main (int narg, char *argv[]) {
  int x,y,z, resultado, a;

  //entrada de dados
  printf("Digite o valor de x: ");
  scanf("%d", &x);

  printf("Digite o valor de y: ");
  scanf("%d", &y);

  printf("Digite o valor de z: ");
  scanf("%d", &z);

  a= MDC(x,y);
  resultado = MDC(a,z);
  
  printf("O resultado do MDC de %d, %d e %d é: %d\n", x,y,z,resultado);

  return EXIT_SUCCESS;
}

//calculo do MDC com recursividade
int MDC(int x, int y){

  if (y == 0)
      return x;
  else
      return MDC(y, x % y);

};