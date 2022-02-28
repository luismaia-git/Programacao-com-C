/*
Faça um programa em linguagem C que defina e utilize uma função que receba as
coordenadas de um ponto A no plano (𝑥!, 𝑦!), os coeficientes de uma equação geral de uma reta R (a, b, c) e calcule e retorne as coordenadas do ponto B (𝑥", 𝑦") que é simétrico ao ponto A.

Equação Geral de uma Reta: 𝑎𝑥 + 𝑏𝑦 + 𝑐 = 0

*/

#include <stdio.h>
#include <stdlib.h>

void simetrico(int x, int y, double a, double b, double c, int *xr, int *yr) {
    double m = -a / b; // coeficiente angular da primeira reta
    double k = -1 / m; // coeficiente angular da segunda reta

    double n = y - k * x; // coeficiente linear da segunda reta

    double p = -1;
    double ya = (k * c - a * n) / (a * p - k * b);
    double xa = (-b * ya - c) / a;

    double yrt = 2 * ya - y;
    double xrt = 2 * xa - x;

    *xr = xrt;
    *yr = yrt;

    printf("x: %d y: %d ", *xr, *yr);
}


int main (int narg, char *argv[]) {
  int x, y;
  
  simetrico(5, 7, 4, -1, 3, &x, &y);
  
  printf("Ponto B(%d,%d) \n", x,y);

  return EXIT_SUCCESS;

}