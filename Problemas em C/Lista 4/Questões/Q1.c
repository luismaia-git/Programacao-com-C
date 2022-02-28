/*
Escreva uma função recursiva que calcule o resto da divisão de um número inteiro positivo por outro.
Não utilizar o operador de resto de divisão (%).
*/
#include <stdio.h>
#include <stdlib.h>

int resto(int x, int y);


int main (int narg, char *argv[]) {
  int numerador, denominador;

  printf("Digite o numerador: ");
  scanf("%d", &numerador);

  printf("Digite o denominador: ");
  scanf("%d", &denominador);

  printf("%d\n", resto(numerador, denominador));

  
  return EXIT_SUCCESS;

}

int resto(int x, int y){
  if (x >= y){
    return resto(x-y,y);
  }
  else
    return x;
}