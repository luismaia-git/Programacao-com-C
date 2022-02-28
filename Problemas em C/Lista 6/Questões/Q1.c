/*
Fazer um programa em linguagem C que defina uma função para receber um vetor de
numéricos qualquer e classificá-lo, utilizando o método de ordenação Bubble Sort. O tamanho
do vetor deve ser passado como parâmetro na função.
*/



#include <stdio.h>
#include <stdlib.h>


void troca(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

//procedimento
void ordenacaoBubble(int v[], int n)
{
   int trocado;
   for (int i = 0; i < n-1; i++)
   {
     trocado = 0;

     for (int j = 0; j < n-i-1; j++)
     {
        if (v[j] > v[j+1])
        {
           troca(&v[j], &v[j+1]);
           trocado = 1;
        }
     }
 
     // se não tiver nenhuma troca mais, entao ele para
     if (trocado == 0)
        return;
   }
}
  

int main (int narg, char *argv[]) {
  int v[] = {5,6,7,1,2,3};

  ordenacaoBubble(v, 6);

  for(int i=0; i<6; i++){
    printf("%d ", v[i]);
  }
    

  return EXIT_SUCCESS;
}