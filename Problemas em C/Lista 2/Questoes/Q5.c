/*
Faça um programa em linguagem C que receba
do usuário um valor inteiro de até 10 dígitos e
mostre o número inteiro invertido. A inversão
deve ser feita através de cálculos apenas.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[])
{
  long int v;

  printf("Digite um valor inteiro positivo de ate 10 digitos: ");
  scanf("%ld", &v);

  int resto = 0;

  while (v)
  {
    resto = (v % 10);
    printf("%d", resto);
    v = (v - resto) / 10;

  }
  printf("\n");
  return EXIT_SUCCESS;
}