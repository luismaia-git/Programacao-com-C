#include <stdlib.h>
#include <stdio.h>

/* vetor_dinamico */

void *criar_vetor (int tamanho) {
  int *v;

  v = (int*) malloc(tamanho*sizeof(double));

  if ( v == NULL ){
    printf("Memoria insuficiente. \n");
  }

}

double obter_vetor (void *mem, int x) {

  double *p = (double*) mem;
  
  return p[x];

}

int atribuir_vetor(void *mem, int x, double valor) {

  double *v = (double*) mem; 
  v[x] = valor;

}

void liberar_vetor(void *mem) {
  free(mem);
}


/* Matriz dinamica */

void *criar_matriz (int tamanho_x, int tamanho_y){
  double **matriz;
  matriz = (double**) malloc(tamanho_x*sizeof(double*));
  
  if ( matriz == NULL ){
    printf("Memoria insuficiente. \n");
  }

  for ( int i = 0; i < tamanho_x; i++ ) {
      matriz[i] = (double*) malloc(tamanho_y*sizeof(double));
      if (matriz[i] == NULL) {
         printf ("Memoria Insuficiente.");
         }
      }
  
  return matriz;
  /*
  matriz[0] = (double *) malloc(tamanho_x *tamanho_y * sizeof(double));
  */


}

double obter_matriz(void *mem, int x, int y){
  double **matriz = (double**) mem;
  
  return matriz[x][y];
}

int atribuir_matriz(void *mem, int x, int y, double valor){
  double **matriz = (double**) mem; 
  
  matriz[x][y] = valor;
}


void liberar_matriz(void *mem, int tamanho_x){
  double **matriz = (double**) mem;

  for(int i= 0; i < tamanho_x; i++){
    free(matriz[i]);
  }
  free(matriz);

}


