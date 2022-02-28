#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  unsigned int numero, centena, dezena, unidade, aux, resultado;


  //entrada de dados
  printf("Digite um numero inteiro positivo de 3 digitos: ");
  scanf("%d", &numero);

  //calculo
   centena = numero / 100; // pega o valor de primeiro digito da esquerda
   
   aux= numero % 100; // pega os 2 valores depois do primeiro digito da esquerda
   
   dezena = aux / 10; //pega o valor do segundo digito a partir da esquerda

   unidade= numero % 10; //pega o valor do terceiro digitado a partir da esquerda

   resultado= (unidade * 100) + (dezena * 10) +(centena * 1); //calculo para inverter os digitos

  printf("Entrada: %d\nSaída: %d\n", numero, resultado); // Saída com os resultados


  return EXIT_SUCCESS;


}