#include <stdio.h>
#include <stdlib.h>

int main (int narg, char *argv[]) {
  float salario_bruto, salario_final, valor_por_horas_trabalhadas, acrescimo, numero_de_filhos, horas_trabalhadas, aut;

  //entrada de dados
  printf("Digite o a quantidade de horas trabalhadas: ");
  scanf("%f", &horas_trabalhadas);
  
  printf("Digite o valor que recebe por horas trabalhadas: ");
  scanf("%f", &valor_por_horas_trabalhadas);

  printf("Digite o numero de filhos: ");
  scanf("%f", &numero_de_filhos);

  //calculos
  salario_bruto= valor_por_horas_trabalhadas * horas_trabalhadas;

  salario_final= salario_bruto+ ((salario_bruto*0.03) * numero_de_filhos);
  
  acrescimo = (salario_bruto*0.03) * numero_de_filhos;

  if (numero_de_filhos==0) 
    printf("Não teve gratificação");

  printf("Salário: %.2f\nGratificação: %.2f\n", salario_final, acrescimo);

  return EXIT_SUCCESS;

}