/*
Faça um programa em linguagem C que permita
ao usuário entrar números inteiros até que sejam
entrados 10 números divisíveis por 3. O programa
deverá, então, mostrar a média aritmética
dos números divisíveis por 3 e a média aritmética
dos demais números entrados.
*/


#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  int N, cont_outros, i;
  float media_outros, media, somatorio, somatorio_outros;

  cont_outros = 1;
  i = 0;

  media = 0;
  media_outros = 0;
  
  while (i < 10)
  {
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &N);

    if(N % 3 == 0 ){
      somatorio = somatorio + N;
      i++;
    }
    else{
      somatorio_outros= somatorio_outros + N;
      cont_outros++;
    }

  }

  media = somatorio / 10;
  media_outros= somatorio_outros / cont_outros;
  
  printf("Média dos numeros divisíveis por 3: %.2f\n", media);
  printf("Média dos outros numeros: %.2f\n", media_outros);
  return EXIT_SUCCESS;
}