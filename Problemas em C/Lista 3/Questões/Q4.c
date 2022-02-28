/*
As fórmulas para o cálculo do volume e da área de uma esfera são: 𝑉 = !
" 𝜋𝑟" e 𝐴 = 4𝜋𝑟#. Escreva as
funções para calcular o volume e a área de uma esfera. (Dica: defina 𝜋 como uma constante #define
Pi 3.14)
*/

#include <stdio.h>
#include <stdlib.h>
#define Pi 3.14

float volume(float r);
float area(float r);

int main (int narg, char *argv[]) {
  float r, are, vol;

  //entrada de dados
  printf("Digite o raio da esfera: ");
  scanf("%f", &r);

  are = area(r);
  vol = volume(r);

  printf("O Volume da esfera eh: %f\n", vol);
  printf("A Area da esfera eh: %f\n", are);
  
  return EXIT_SUCCESS;

}

//calculo do volume
float volume(float r){
  float v, aux= 4 , aux2=3;
  
  v = (aux/aux2)*Pi*(r*r*r);

  return v;
}

//calculo da area
float area(float r){
  float a;

  a= 4*Pi*(r*r);

  return a;
}