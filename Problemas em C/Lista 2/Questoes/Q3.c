/*
Faça um programa em linguagem C que exiba os
1.000 primeiros números inteiros positivos que
são ímpares e que não são divisíveis nem por 3
nem por 7.
*/

#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  long int i;
  int count = 1;

  i=1;

  while (i <= 1000)
  {

    if (count%3!=0 && count%7!=0){
      printf("%ld ", count);
      i++;
    }
    count++;
  }
  
  printf("\n");

  return EXIT_SUCCESS;
}