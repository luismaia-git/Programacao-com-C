/*
Faça um algoritmo que receba do usuário um
número inteiro e exiba o maior número primo
que seja menor do que o número digitado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int narg, char *argv[])
{

  int n;
  bool isPrime;

  printf("Digite um numero inteiro positivo: ");
  scanf("%d", &n);

  while (n)
  {
    
    n = n - 1;
    if (n <= 2)
      isPrime = false;

    if (n == 2)
      isPrime = true;

    for (int j = 2; j < n; j++)
    {
      if (n % j == 0)
      {

        isPrime = false;
      }
    }

    if (isPrime)
    {
      printf("%d\n",n);
      break;
    }
    isPrime = true;
  }

  return EXIT_SUCCESS;
}
