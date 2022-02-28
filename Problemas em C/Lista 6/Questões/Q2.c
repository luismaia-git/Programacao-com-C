
/*
Fazer um programa em linguagem C que defina uma função para receber um vetor de
numéricos qualquer e classificá-lo, utilizando o método de ordenação Selection Sort. O
tamanho do vetor deve ser passado como parâmetro na função.
*/

#include <stdio.h>
#include <stdlib.h>

//procedimento
void selectionSort(int n, int *v) {
  int i, j , min , aux;

  for (int i = 0; i < (n-1); i++){
    

    min = i;
    for (int j = i+1; j < n; j++){
      if (v[j] < v[min]) {
          min = j;
      }
    }
    

    if (i != min) {
      aux = v[i];
      v[i] = v[min];
      v[min] = aux;
    }
  }

}

int main (int narg, char *argv[]) {
  int v[] = {1,2,5,7,0,8};

  selectionSort(6, v);
  
  for (int i = 0; i < 6; i++) {
    printf("%d ", v[i]);
  }

  return EXIT_SUCCESS;
}