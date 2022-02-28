/*
Implemente uma função iterativa (usando laços) para calcular o máximo divisor comum de dois números
inteiros positivos, MDC(x, y), usando o algoritmo de Euclides. Este algoritmo é baseado no fato de
que se o resto da divisão de x por y, representado por r, for igual a zero, y é o MDC. Se o resto r for diferente
de zero, o MDC de x e y é igual ao MDC de y e r. O processo se repete até que o valor do resto
da divisão seja zero.
*/

#include <stdio.h>
#include <stdlib.h>


int MDC (int x, int y);

int main (int narg, char *argv[]) {
  int resultado, x,y;

  //entrada de dados
  printf("Digite o valor de x: ");
  scanf("%d", &x);

  printf("Digite o valor de y: ");
  scanf("%d", &y);

  resultado = MDC(x, y);

  printf("O resultado do MDC de %d e %d é: %d\n", x,y,resultado);
  
  return EXIT_SUCCESS;

};

//calculo do MDC com recursividade
int MDC(int x, int y){
  
  if (y == 0)
      return x;
  else
      return MDC(y, x % y);

};

