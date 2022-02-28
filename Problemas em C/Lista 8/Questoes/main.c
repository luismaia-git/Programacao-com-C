#include <stdlib.h>
#include <stdio.h>
#include "./api_dinamica.h"

int main (int narg, char *argv[]) {
  void *p_v, *p_m;

  p_v = criar_vetor(6);

  atribuir_vetor(p_v, 8 , 456.0);
  printf("a pos. 8 do vetor contem %f.\n", obter_vetor(p_v, 8));
  liberar_vetor(p_v);


  p_m = criar_matriz(10,10);
  atribuir_matriz(p_m, 5 , 4, 12.0);
  printf("A pos. (5,4) da matriz = %f. \n", obter_matriz(p_m, 5 , 4));
  liberar_matriz(p_m, 5);

  return EXIT_SUCCESS;
}