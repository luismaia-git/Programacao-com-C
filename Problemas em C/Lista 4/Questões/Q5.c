/*
Escreva uma função de potenciação recursiva, considerando o expoente como sendo um valor inteiro
positivo (𝑥!, 𝑘 > 0). A função deve seguir o protótipo: double pot (double x, int k). Escreva uma
função main para testar sua implementação. Compare o resultado da sua função com o valor retornado
pela função de potenciação pow, da biblioteca de math.h padrão de C.
Obs. Quando for compilar um programa em C que utilize o math.h, é necessário adicionar a opção
‘-lm’ no final da linha do GCC. Exemplo: gcc main.c -o main -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double poten(double x, int y);

int main (int narg, char *argv[]) {
  int expoente;
  double base, resultado, resultadoPoten;

  printf("Digite a base: ");
  scanf("%lf", &base);

  printf("Digite o denominador: ");
  scanf("%d", &expoente);

  resultado = pow(base, expoente);
  resultadoPoten= poten(base, expoente);

  printf("Minha funcao: %.2lf\n", resultadoPoten );
  printf("Função 'pow': %.2lf\n", resultado);

  return EXIT_SUCCESS;
}

double poten(double x, int y){
  if(y <= 0){
    return 1;
  }
  return poten(x,y-1)*x;

}